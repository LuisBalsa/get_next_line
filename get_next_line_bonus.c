/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:28:00 by luide-so          #+#    #+#             */
/*   Updated: 2023/05/11 10:09:48 by luide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*get_buffer(char *buff, int fd)
{
	int		bytes;
	char	*temp;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(buff, '\n') && bytes)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(temp);
			free(buff);
			return (NULL);
		}
		temp[bytes] = '\0';
		buff = ft_strjoin_mod(buff, temp);
	}
	free (temp);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buff[MAX_FILES];
	char		*line;

	if (fd < 0 || fd > MAX_FILES || BUFFER_SIZE <= 0)
		return (NULL);
	buff[fd] = get_buffer(buff[fd], fd);
	if (!buff[fd])
		return (NULL);
	line = ft_substr_line(buff[fd]);
	buff[fd] = ft_memmove_mod(buff[fd]);
	return (line);
}

/* int	main(void)
{
	char	*line;
	int		i;
	int		j;
	int		fd[3];

	fd[0] = open("text0.txt", O_RDONLY);
	fd[1] = open("text1.txt", O_RDONLY);
	fd[2] = open("text2.txt", O_RDONLY);
	j = 3;
		while (--j >= 0)
	{
		printf("Fd=%d\n\n", fd[j]);
	}
	j = 3;
	while (--j >= 0)
	{
		printf("\nFd=%d\n", fd[j]);
		i = 1;
		while (i)
			{
				line = get_next_line(fd[j]);
				if (line)
				{
					printf("-%s", line);
					i = line[0];
					free(line);
				}
				else
					i = 0;
			}
		printf("\n");
	}
	j = 3;
	while (--j >= 0)
	{
		close(fd[j]);
	}
	return (0);
} */