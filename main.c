/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmdemirk <dmdemirk@student.42london.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:38:58 by dmdemirk          #+#    #+#             */
/*   Updated: 2023/11/30 14:18:32 by dmdemirk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void	check_fd(void)
{
	printf("STDIN_FILENO:  %d\n", fileno(stdin));
	printf("STDOUT_FILENO: %d\n", fileno(stdout));
	printf("STDERR_FILENO: %d\n", fileno(stderr));
}

int	main(void)
{
	char	*file;
	int		fd;
	char	*line;

	check_fd();
	file = "example.txt";
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("error opening file");
		return (1);
	}
	printf("TXT_FILE_OPEN: %d\n", fd);
	line = get_next_line(fd);
	printf("\nLINE OUTPUT-> \n%s\n", line);
	return (0);
}
