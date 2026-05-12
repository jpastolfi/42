/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jastolfi <jastolfi@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 17:45:01 by jastolfi          #+#    #+#             */
/*   Updated: 2026/05/12 12:24:27 by jastolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_line(int descriptor)
{
	static char		*line;
	int				bytes_read;
	char			*buffer;
	char			*final;

	bytes_read = 0;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	while (!ft_strchr(line, '\n'))
	{
		bytes_read = read(descriptor, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
		{
			if (!line || !*line)
				return (free(line), free(buffer), line = NULL, NULL);
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
	free(new_remainder);
	return (line_to_return);
}

char	*get_next_line(int fd)
{
	return (fill_line(fd));
}

int	main(void)
{
	int	descriptor;

	descriptor = open("test.txt", O_RDWR);
	printf("%s", fill_line(descriptor));
}
