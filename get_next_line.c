#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*ft_read_to_left_str(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str = ft_read_to_left_str(fd, left_str);
	if (!left_str)
		return (NULL);
	line = ft_get_line(left_str);
	left_str = ft_new_left_str(left_str);
	return (line);
}


// // 从文件描述符中读取内容并更新保存的行
// char *read_and_update_line(int fd, char *saved_line)
// {
//     char *buffer;
//     size_t bytes_read;

//     buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
//     if (!buffer)
//         return (NULL);
//     bytes_read = read(fd, buffer, BUFFER_SIZE);
//     if (bytes_read <= 0)
//     {
//         free(buffer);
//         return (ft_free_and_nullify(&saved_line));
//     }
//     buffer[bytes_read] = '\0';
//     return concatenate_lines(saved_line, buffer);
// }

// // 读取文件描述符，返回一行
// char *get_next_line(int fd)
// {
//     static char *saved_line;  // 保存上一次读取的剩余文本
//     char *current_line;       // 当前读取的行
//     size_t line_end;          // 行结束位置

//     if (fd < 0 || BUFFER_SIZE <= 0)
//         return (NULL);
//     saved_line = read_and_update_line(fd, saved_line);
//     if (!saved_line)
//         return (NULL);
//     line_end = 0;
//     while (saved_line[line_end] && saved_line[line_end] != '\n')
//         line_end++;
//     current_line = extract_line(saved_line, 0, line_end + (saved_line[line_end] == '\n'));
//     saved_line = update_saved_line(saved_line, line_end + (saved_line[line_end] == '\n'));
//     return (current_line);
// }