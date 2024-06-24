/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anquinte <anquinte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:02:58 by anquinte          #+#    #+#             */
/*   Updated: 2024/06/16 11:27:14 by anquinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char delimiter)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != delimiter)
		{
			count++;
			while (s[i] != delimiter && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	word_length(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

static void	free_split(char **buffer, int words_allocated)
{
	while (words_allocated > 0)
	{
		words_allocated = words_allocated - 1;
		free(buffer[words_allocated]);
	}
	free (buffer);
}

static char	**ft_split_init(size_t *word_index, size_t *head, size_t *tail,
	size_t number_of_words)
{
	*word_index = 0;
	*head = 0;
	*tail = 0;
	return (ft_calloc(number_of_words + 1, sizeof(char *)));
}

char	**ft_split(char const *str, char delimiter)
{
	char	**split;
	size_t	number_of_words;
	size_t	word_index;
	size_t	head;
	size_t	tail;

	number_of_words = count_words(str, delimiter);
	split = ft_split_init(&word_index, &head, &tail, number_of_words);
	if (split == NULL)
		return (NULL);
	while (str[head] != '\0')
	{
		if (str[head] != delimiter)
		{
			tail = head + word_length(str, delimiter, head);
			split[word_index] = ft_substr(str, head, tail - head);
			if (!split[word_index])
				return (free_split(split, word_index), NULL);
			word_index++;
			head = tail;
		}
		else
			head ++;
	}
	return (split);
}
