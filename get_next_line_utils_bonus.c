/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psimarro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:50:48 by psimarro          #+#    #+#             */
/*   Updated: 2022/06/13 19:50:51 by psimarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_bzero(void *s, size_t n)
{
	int		i;

	i = 0;
	if (n)
		while (n--)
			((unsigned char *)s)[i++] = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*aux;

	if (size > INT_MAX / count || !count || !size)
		return (0);
	aux = malloc(count * size);
	if (!aux)
		return (0);
	ft_bzero(aux, count * size);
	return (aux);
}

char	*ft_free_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i] != '\0')
		str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	ch;

	if (!s)
		return (NULL);
	i = 0;
	ch = (char) c;
	while (s[i] != ch && s[i])
		i++;
	if (s[i] == ch)
		return ((char *) s + i);
	else
		return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
