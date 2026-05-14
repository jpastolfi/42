/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 17:45:01 by jastolfi          #+#    #+#             */
/*   Updated: 2026/05/14 12:47:15 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_line(int descriptor)
{
	static char		*line;
	int				bytes_read;
	char			buffer[BUFFER_SIZE + 1];
	char			*final;

	while (!ft_strchr(line, '\n'))
	{
		bytes_read = read(descriptor, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(line), line = NULL, NULL);
		if (bytes_read == 0)
		{
			if (!line || !*line)
				return (free(line), line = NULL, NULL);
			final = line;
			line = NULL;
			return (final);
		}
		buffer[bytes_read] = '\0';
		line = ft_strjoin(line, buffer);
	}
	return (set_line(&line));
}

char	*set_line(char **string)
{
	char	*line_to_return;
	char	*new_remainder;
	int		string_length;
	char	*new_line_pointer;
	int		new_line_index;

	string_length = ft_strlen(*string);
	new_line_pointer = ft_strchr(*string, '\n');
	new_line_index = new_line_pointer - *string;
	line_to_return = ft_substr(*string, 0, new_line_index + 1);
	new_remainder = ft_substr(*string, new_line_index + 1, string_length);
	free(*string);
	*string = new_remainder;
	return (line_to_return);
}

char	*get_next_line(int fd)
{
	if (BUFFER_SIZE <= 0 || !fd)
		return (NULL);
	return (fill_line(fd));
}

// # include <stdio.h>

/* int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	// fd = 0; // To test stdin
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Linha: %s", line);
		free(line);
		// printf("%s\n", line); // To test other character
	}
	close(fd);
	return (0);
} */

/* int main(int argc, char **argv)
{
	int   fd;
	char  *line;

	if (argc != 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Could not open %s\n", argv[1]);
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("[%s]", line);
		printf("\n");
		free(line);
	}
	close(fd);
	return (0);
} */