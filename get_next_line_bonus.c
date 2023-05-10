/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-so <luide-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:28:00 by luide-so          #+#    #+#             */
/*   Updated: 2023/05/10 22:47:14 by luide-so         ###   ########.fr       */
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
	int		fd;

	fd = open("text1.txt", O_RDONLY);
	i = 1;
	printf("Fd=%d\n\n", fd);
	while (i)
	{
		line = get_next_line(fd);
		if (line)
		{
			printf("-%s", line);
			i = line[0];
			free(line);
		}
		else
			i = 0;
	}
	close(fd);
	return (0);
} */