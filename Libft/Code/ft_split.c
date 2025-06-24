/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chllee <chllee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:37:20 by chllee            #+#    #+#             */
/*   Updated: 2025/06/13 22:06:59 by chllee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_words(char const *s, char c)
{
	int	w_count;
	int	ind;

	w_count = 0;
	ind = 0;
	while (s[ind] != '\0')
	{
		if (s[ind] == c)
			ind++;
		else
		{
			w_count++;
			while (s[ind] != c && s[ind] != '\0')
				ind++;
		}
	}
	return (w_count);
}

static char	*get_word(char const *s, char c, int sind)
{
	char	*word;
	int		wind;
	int		cind;

	wind = sind;
	while (s[wind] != c && s[wind] != '\0')
		wind++;
	word = (char *)malloc(sizeof(char) * (wind - sind + 1));
	if (!word)
		return (NULL);
	cind = 0;
	while (s[sind] != c && s[sind] != '\0')
	{
		word[cind] = s[sind];
		cind++;
		sind++;
	}
	word[cind] = '\0';
	return (word);
}

static void	free_all(char **final, int w_count)
{
	int	ind;

	ind = 0;
	while (final[ind] && (ind < w_count))
	{
		free(final[ind]);
		final[ind] = NULL;
		ind++;
	}
	free(final);
}

static char	**do_split(char const *s, char c, char **final)
{
	int		sind;
	int		find;

	sind = 0;
	find = 0;
	while (s[sind] != '\0')
	{
		if (s[sind] != c && s[sind] != '\0')
		{
			final[find] = get_word(s, c, sind);
			if (!final[find])
			{
				free_all(final, find);
				return (NULL);
			}
			find++;
			while (s[sind] != c && s[sind] != '\0')
				sind++;
		}
		else
			sind++;
	}
	return (final);
}

char	**ft_split(char const *s, char c)
{
	int		w_count;
	char	**final;

	w_count = count_words(s, c);
	final = (char **)malloc(sizeof(char *) * (w_count + 1));
	if (!final)
		return (NULL);
	final = do_split(s, c, final);
	if (!final)
		return (NULL);
	final[w_count] = 0;
	return (final);
}
