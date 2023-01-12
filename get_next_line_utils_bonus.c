/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:28:39 by mayache-          #+#    #+#             */
/*   Updated: 2022/11/08 17:21:41 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	str_len(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

char	*str_chr(const char *str, int chr)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == chr)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*str_join(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	j = 0;
	i = 0;
	str = (char *)malloc(str_len(s1) + str_len(s2) + 1);
	if (!str)
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*write_save(char *buffer, int fd)
{
	char	*shortbuff;
	int		booll;

	shortbuff = (char *)malloc(BUFFER_SIZE + 1);
	if (!shortbuff)
		return (NULL);
	booll = 1;
	while (!str_chr(buffer, '\n') && booll != 0)
	{
		booll = read(fd, shortbuff, BUFFER_SIZE);
		if (booll == -1)
		{
			free(buffer);
			free(shortbuff);
			return (NULL);
		}
		shortbuff[booll] = '\0';
		buffer = str_join(buffer, shortbuff);
	}
	free(shortbuff);
	return (buffer);
}

char	*ft_get_line(char *buff)
{
	int		i;
	int		len;
	char	*block;

	len = 0;
	i = 0;
	if (!buff[0])
		return (NULL);
	while (buff[len] && buff[len] != '\n')
		len++;
	block = (char *)malloc((len + 2) * sizeof('\0'));
	if (!block)
		return (NULL);
	while (buff[i] && buff[i] != '\n')
	{
		block[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
	{
		block[i] = '\n';
		i++;
	}
	block[i] = '\0';
	return (block);
}
