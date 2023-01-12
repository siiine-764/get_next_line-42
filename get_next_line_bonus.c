/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:26:56 by mayache-          #+#    #+#             */
/*   Updated: 2022/11/09 16:38:42 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*clean_last_line(char *buff)
{
	char	*chronos_jawoll;
	int		utopia;
	int		last_line;

	last_line = 0;
	utopia = 0;
	while (buff[last_line] && buff[last_line] != '\n')
		last_line++;
	if (!buff[last_line] || (buff[last_line] == '\n'
			&& buff[last_line + 1] == '\0'))
	{
		free(buff);
		return (0x00000000);
	}
	chronos_jawoll = (char *)malloc(str_len(buff) - last_line);
	if (!chronos_jawoll)
		return (0x00000000);
	last_line++;
	while (buff[last_line])
		chronos_jawoll[utopia++] = buff[last_line++];
	chronos_jawoll[utopia] = '\0';
	free(buff);
	return (chronos_jawoll);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*buff[OPEN_MAX];

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buff[fd] = write_save(buff[fd], fd);
	if (!buff[fd])
		return (NULL);
	str = ft_get_line(buff[fd]);
	buff[fd] = clean_last_line(buff[fd]);
	return (str);
}

// int main()
// {
// 	printf("\nFile Descriptors 1\n");
// 	int fd = open("heilen.txt", O_RDONLY);
// 	printf("%s\n",get_next_line(fd));
// 	printf("%s\n",get_next_line(fd));
// 	printf("%s\n",get_next_line(fd));
// 	printf("%s\n",get_next_line(fd));

// 	printf("\nFile Descriptors 2\n");
// 	int fd1 = open("heal.txt", O_RDONLY);
// 	printf("%s\n",get_next_line(fd1));
// 	printf("%s\n",get_next_line(fd1));
// 	printf("%s\n",get_next_line(fd1));
// 	printf("%s\n",get_next_line(fd1));

// 	printf("\nFile Descriptors 3\n");
// 	int fd2 = open("uranus.txt", O_RDONLY);
// 	printf("%s\n",get_next_line(fd2));
// 	printf("%s\n",get_next_line(fd2));
// 	printf("%s\n",get_next_line(fd2));
// 	printf("%s\n",get_next_line(fd2));
// }