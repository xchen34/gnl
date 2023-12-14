/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:01:50 by leochen           #+#    #+#             */
/*   Updated: 2023/12/14 17:37:32 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*add_to_stock(char *stock, char *buf)
{
	size_t	i;
	size_t	j;
	char	*s3;

	if (stock == NULL)
	{
		stock = (char *)malloc(sizeof(char) * 1);
		stock[0] = '\0';
	}
	if (stock == NULL || buf == NULL)
		return (NULL);
	s3 = (char *)malloc(sizeof(char) * (ft_strlen(stock) + ft_strlen(buf) + 1));
	if (s3 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (stock[i])
		s3[j++] = stock[i++];
	i = 0;
	while (buf[i])
		s3[j++] = buf[i++];
	s3[j] = '\0';
	free(stock);
	return (s3);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}
