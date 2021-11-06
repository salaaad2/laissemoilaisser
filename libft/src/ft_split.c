/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbousset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:07:05 by rbousset          #+#    #+#             */
/*   Updated: 2020/02/14 17:07:05 by rbousset         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stddef.h>
#include <stdlib.h>

static size_t	ft_count_words(const char *s, char c)
{
	size_t	i;
	size_t	count;
	t_bool	ibool;

	i = 0;
	count = 0;
	ibool = TRUE;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			if (ibool == TRUE)
				count++;
			ibool = FALSE;
			i++;
		}
		ibool = TRUE;
	}
	return (count);
}

static size_t	ft_splitlen(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	return (i);
}

static char		*ft_splitdup(const char *str, char c)
{
	char	*word;
	size_t	i;

	i = 0;
	if (!(word = (char*)malloc((ft_splitlen(str, c) + 1) * sizeof(char))))
		return (NULL);
	while (str[i] != c && str[i])
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char		**ft_splitfree(char **best_split, size_t j)
{
	while (j > 0)
	{
		ft_memdel((void*)&best_split[j]);
		j--;
	}
	ft_memdel((void*)&best_split);
	return (NULL);
}

char			**ft_split(const char *s, char c)
{
	char	**best_split;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if ((best_split = (char **)malloc((ft_count_words(s, c) + 1)
		* sizeof(char *))) == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			if ((best_split[j] = ft_splitdup(s + i, c)) == NULL)
				return (ft_splitfree(best_split, j));
			i += ft_splitlen(s + i, c);
			j++;
		}
	}
	best_split[j] = NULL;
	return (best_split);
}
