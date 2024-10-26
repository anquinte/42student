/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anquinte <anquinte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:18:49 by anquinte          #+#    #+#             */
/*   Updated: 2024/10/26 15:31:34 by anquinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"
#include "get_next_line.h"
#include <stdio.h>

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

/*int main()
{
	char **sp;
	char *s;


	s = "110\n001\n\n111\n000";
	sp = ft_split(s, '\n');
	while(*sp)
	{
		printf("%s\n", sp[0]);
		printf("%s\n", sp[1]);
		printf("%s\n", sp[2]);
		printf("%s\n", sp[3]);
		printf("%s\n", sp[4]);
	}
	return (0);
}*/