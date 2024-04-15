/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:56:02 by dmdemirk          #+#    #+#             */
/*   Updated: 2023/11/30 14:08:25 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
#define GET_NEXT_LINE_BONUS_H
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list {
  char *str_buf;
  struct s_list *next;
} t_list;

int find_newline(t_list *list);
t_list *find_last_node(t_list *list);
char *get_line(t_list *list);
void copy_str(t_list *list, char *str);
int len_to_newline(t_list *list);
void check_list(t_list **list);
char *get_next_line(int fd);
void dealloc(t_list **list, t_list *clean_node, char *buf);
void create_list(t_list **list, int fd);

#endif
