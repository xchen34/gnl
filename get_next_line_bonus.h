/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:02:47 by leochen           #+#    #+#             */
/*   Updated: 2023/12/14 17:37:06 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_MAX
#  define FD_MAX 1024 
# endif

char	*get_next_line(int fd);
char	*clean_extracted_stock(char *stock);
char	*extract_from_stock(char *stock);
char	*read_and_add(int fd, char *stock);
size_t	ft_strlen(char *s);
char	*add_to_stock(char*stock, char *buf);
char	*ft_strchr(char *s, int c);

#endif
