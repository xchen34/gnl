#include "get_next_line.h"
#include <unistd.h>
//#include <stdio.h>
//#include <fcntl.h>


size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	free(left_str);
	return (str);
}

char	*ft_get_line(char *left_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!left_str[i])
		return (NULL);
	while (left_str[i] && left_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_left_str(char *left_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free(left_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (left_str[i])
		str[j++] = left_str[i++];
	str[j] = '\0';
	free(left_str);
	return (str);
}

// // 释放内存并将指针设为NULL
// char *ft_free_and_nullify(char **ptr)
// {
//     if (ptr && *ptr)
//     {
//         free(*ptr);
//         *ptr = NULL;
//     }
//     return (NULL);
// }

// // 将两个字符串连接成一个新字符串
// char *concatenate_lines(char *line1, char *line2)
// {
//     char *new_line;

//     new_line = ft_strjoin(line1, line2);
//     ft_free_and_nullify(&line1);
//     return new_line;
// }

// // 提取字符串的一部分
// char *extract_line(char *source, unsigned int start, size_t length)
// {
//     return ft_substr(source, start, length);
// }

// // 更新保存的行，去掉已经读取的部分
// char *update_saved_line(char *saved_line, size_t new_start)
// {
//     char *new_line;

//     new_line = ft_substr(saved_line, new_start, ft_strlen(saved_line) - new_start);
//     ft_free_and_nullify(&saved_line);
//     return new_line;
// }
// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*s2;
// 	size_t	slen;
// 	size_t	end;

// 	if (!s)
// 		return (0);
// 	slen = ft_strlen(s);
// 	end = 0;
// 	if (start > slen)
// 		return (ft_strdup(""));
// 	if (start < slen)
// 		end = slen - start;
// 	if (end > len)
// 		end = len;
// 	s2 = (char *)malloc(sizeof(char) * (end + 1));
// 	if (!s2)
// 		return (0);
// 	ft_strlcpy(s2, s + start, end + 1);
// 	return (s2);
// }
// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*s3;
// 	char	*res;

// 	if (s2 == NULL)
// 		return ((char *)s1);
// 	if (s1 == NULL)
// 		return (NULL);
// 	s3 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
// 	if (s3 == NULL)
// 		return (NULL);
// 	res = s3;
// 	while (*s1)
// 	{
// 		*s3 = *s1;
// 		s3 ++;
// 		s1 ++;
// 	}
// 	while (*s2)
// 	{
// 		*s3 = *s2;
// 		s3 ++;
// 		s2 ++;
// 	}
// 	*s3 = '\0';
// 	return (res);
// }
// char	*ft_strdup(const char *s)
// {
// 	char	*d;
// 	size_t	i;

// 	i = 0;
// 	d = (char *)malloc(ft_strlen(s) + 1);
// 	if (d == NULL)
// 		return (NULL);
// 	while (s[i])
// 	{
// 		d[i] = s[i];
// 		i ++;
// 	}
// 	d[i] = '\0';
// 	return (d);
// }
// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 		i ++;
// 	return (i);
// }
// size_t	ft_strlcpy(char *dst, const char *src, size_t size)
// {
// 	size_t	i;

// 	i = 0;
// 	if (size > 0)
// 	{
// 		while (i < (size - 1) && src[i])
// 		{
// 			dst[i] = src[i];
// 			i ++;
// 		}
// 		dst[i] = '\0';
// 	}
// 	return (ft_strlen(src));
// }