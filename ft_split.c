/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksorokol <ksorokol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 22:29:51 by ksorokol          #+#    #+#             */
/*   Updated: 2024/09/20 15:23:54 by ksorokol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordscounter(char const *str, char c, char *wordmap);
static void		*ft_freep(void *p);
static char		*ft_getword(char const *str, char *wordmap, size_t n);

char	**ft_split(char const *s, char c)
{
	size_t	idx;
	char	*wordmap;
	size_t	counter;
	char	**result;

	if (!s)
		return (NULL);
	wordmap = ft_calloc (ft_strlen (s) + 1, sizeof (char));
	if (!wordmap)
		return (NULL);
	counter = ft_wordscounter(s, c, wordmap);
	result = (char **) ft_calloc((counter + 1), sizeof(char *));
	if (!result)
		return (ft_freep (wordmap), NULL);
	idx = 0;
	while (idx < counter)
	{
		result[idx] = ft_getword(s, wordmap, idx + 1);
		idx++;
	}
	result[idx] = NULL;
	return (ft_freep (wordmap), result);
}

static size_t	ft_wordscounter(char const *str, char c, char *wordmap)
{
	size_t	idx;
	size_t	counter;

	idx = 0;
	counter = 0;
	while (str[idx])
	{
		if (str[idx] == c)
			wordmap[idx] = 0;
		else
			wordmap[idx] = 1;
		if ((wordmap[idx] && idx == 0)
			|| (!wordmap[idx] && str[idx + 1] != c && str[idx + 1]))
			counter++;
		idx++;
	}
	wordmap[idx] = 0;
	return (counter);
}

static void	*ft_freep(void *p)
{
	free (p);
	p = NULL;
	return (p);
}

static char	*ft_getword(char const *str, char *wordmap, size_t n)
{
	char	*word;
	size_t	idx;
	size_t	idx_;

	idx = -1;
	while (str[++idx])
	{
		if (wordmap[idx] && (!idx || !wordmap[idx - 1]))
			n--;
		if (!n)
		{
			idx_ = 0;
			while (wordmap[idx + idx_])
				idx_++;
			word = (char *) ft_calloc (idx_ + 1, sizeof (char));
			if (!word)
				return (NULL);
			while (idx_-- > 0)
				word[idx_] = str[idx + idx_];
			return (word);
		}
	}
	return (0);
}
