#include "get_next_line.h"

char *fill_line(int descriptor)
{
    static char* line;
    int bytes_read;
    char buffer[BUFFER_SIZE + 1];
	char *final;
    bytes_read = 0;
    while (!ft_strchr(line, '\n'))
    {
        bytes_read = read(descriptor, buffer, BUFFER_SIZE);
        if (bytes_read == 0)
		{
			if (!line || !*line)  // nothing to return
			{
				free(line);
				line = NULL;
				return (NULL);
			}
			// there's content but no \n — return it as the final line
			// and reset the static variable
			final = line;
			line = NULL;
			return (final);
		}
        buffer[bytes_read] = '\0';
        line = ft_strjoin(line, buffer);
    }
    return (set_line(&line));
}

char *set_line(char **string)
{
	char *line_to_return;
	char *new_remainder;
	int string_length;
	char *new_line_pointer;
	int new_line_index;

	string_length = ft_strlen(*string);
	new_line_pointer = ft_strchr(*string, '\n');
	new_line_index = new_line_pointer - *string;
	line_to_return = ft_substr(*string, 0, new_line_index + 1);
	new_remainder = ft_substr(*string, new_line_index + 1, string_length);
	free(*string);
	*string = new_remainder;
	return (line_to_return);
}

char *get_next_line(int fd)
{
    int descriptor = open("test.txt", O_RDWR);
    if (descriptor < 0)
        return (NULL);
    return "Festinhas";
}

int main()
{
    int descriptor = open("test.txt", O_RDWR);
    printf("%s", fill_line(descriptor));
}