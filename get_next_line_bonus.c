/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:55:11 by dmdemirk          #+#    #+#             */
/*   Updated: 2023/11/30 13:55:25 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void create_list(t_list **list, int fd);
char *get_line(t_list *list);
void check_list(t_list **list);
void append(t_list **list, char *buf, int fd);

char *get_next_line(int fd) {
  static t_list *list[4096];
  char *next_line;

  if (fd < 0 || fd > 4095 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
    return (NULL);
  create_list(list, fd);
  if (list[fd] == NULL)
    return (NULL);
  next_line = get_line(list[fd]);
  check_list(&list[fd]);
  return (next_line);
}

void check_list(t_list **list) {
  t_list *last_node;
  t_list *clean_node;
  int i;
  int k;
  char *buf;

  buf = (char *)malloc(BUFFER_SIZE + 1);
  clean_node = malloc(sizeof(t_list));
  if (!clean_node || !buf)
    return;
  last_node = find_last_node(*list);
  i = 0;
  k = 0;
  while (last_node->str_buf[i] && last_node->str_buf[i] != '\n')
    i++;
  while (last_node->str_buf[i] && last_node->str_buf[++i])
    buf[k++] = last_node->str_buf[i];
  buf[k] = '\0';
  clean_node->str_buf = buf;
  clean_node->next = NULL;
  dealloc(list, clean_node, buf);
}

char *get_line(t_list *list) {
  int str_len;
  char *next_str;
  if (!list)
    return (NULL);
  str_len = len_to_newline(list);
  next_str = (char *)malloc(str_len + 1);
  if (!next_str)
    return (NULL);
  copy_str(list, next_str);
  return (next_str);
}

void append(t_list **list, char *buf, int fd) {
  t_list *new_node;
  t_list *last_node;

  last_node = find_last_node(list[fd]);
  new_node = malloc(sizeof(t_list));
  if (!new_node)
    return;
  if (!last_node)
    list[fd] = new_node;
  else
    last_node->next = new_node;
  new_node->next = NULL;
}

void create_list(t_list **list, int fd) {
  int char_count;
  char *buf;
  while (!find_newline(list[fd])) {
    buf = malloc(BUFFER_SIZE + 1);
    if (!buf)
      return;
    char_count = read(fd, buf, BUFFER_SIZE);
    if (char_count < 0) {
      free(buf);
      return;
    }
    buf[char_count] = '\0';
    append(list, buf, fd);
  }
}
