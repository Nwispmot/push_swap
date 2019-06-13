/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwispmot <nwispmot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 21:38:43 by nwispmot          #+#    #+#             */
/*   Updated: 2018/12/23 23:04:09 by nwispmot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_free_array(char **str, int i)
{
	while (i)
		free(str[i--]);
	free(str);
	return (NULL);
}

static int		ft_calc_words(char const *s, char c)
{
	int i;

	i = 0;
	while (*s)
	{
		if (*s != c && *s)
		{
			i++;
			while (*s != c && *s)
				s++;
		}
		if (*s)
			s++;
	}
	return (i);
}

static int		ft_calc_letters(char const *s, char c)
{
	int i;

	while (*s)
	{
		i = 0;
		if (*s != c && *s)
		{
			while (*s != c && *s)
			{
				s++;
				i++;
			}
			return (i);
		}
		if (*s)
			s++;
	}
	return (0);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;

	if (!s || !c)
		return (NULL);
	i = 0;
	str = (char**)malloc(sizeof(str) * (ft_calc_words(s, c) + 1));
	if (!str)
		return (NULL);
	while (*s)
	{
		if (*s != c && *s)
		{
			str[i] = ft_strnew(ft_calc_letters(s, c));
			if (!str[i])
				return (ft_free_array(str, i));
			ft_strncpy(str[i++], s, ft_calc_letters(s, c));
			while (*s != c && *s)
				s++;
		}
		if (*s)
			s++;
	}
	str[i] = NULL;
	return (str);
}

// static int		ft_count_words(char const *s, char c)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	if (s[j] != c)
// 		i = 1;
// 	while (s[j] != '\0')
// 	{
// 		if (s[j] == c && s[j + 1] != c && s[j + 1] != '\0')
// 			i++;
// 		j++;
// 	}
// 	return (i);
// }

// static int		ft_count_letter(char const *s, char c, int l)
// {
// 	int i;

// 	if (s[l] == 0)
// 		return (0);
// 	i = 0;
// 	while (s[l] != c && s[l] != '\0')
// 	{
// 		i++;
// 		l++;
// 	}
// 	return (i);
// }

// static void		*free_mysplit(char **str1, int size)
// {
// 	while (size--)
// 	{
// 		free(str1[size]);
// 	}
// 	free(str1);
// 	return (NULL);
// }

// static char		*ft_filler(char *str2, int num, int min, int size)
// {
// 	int		n;
// 	char	*str1;

// 	str1 = ft_strnew(num + 1);
// 	if (!str1)
// 		return (free_mysplit(&str2, size));
// 	n = 0;
// 	while (num--)
// 	{
// 		str1[n] = str2[min];
// 		min++;
// 		n++;
// 	}
// 	str1[n] = '\0';
// 	return (str1);
// }

// char			**ft_strsplit(char const *s, char c)
// {
// 	char	**new;
// 	int		i;
// 	int		size;
// 	int		l;
// 	int		len;

// 	if (s == 0 || c == 0)
// 		return (0);
// 	i = 0;
// 	size = 0;
// 	len = ft_count_words(s, c);
// 	if (!(new = (char **)malloc(sizeof(char *) * (len + 1))))
// 		return (NULL);
// 	l = 0;
// 	while (s[l] && i != len)
// 	{
// 		while (s[l] == c)
// 			l++;
// 		size = ft_count_letter(s, c, l);
// 		new[i] = ft_filler((char *)s, size, l, len);
// 		l = size + l;
// 		i++;
// 	}
// 	new[i] = NULL;
// 	return (new);
// }
