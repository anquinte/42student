/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anquinte <anquinte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 20:32:48 by anquinte          #+#    #+#             */
/*   Updated: 2024/07/15 13:03:39 by anquinte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *str)
{
    size_t  i;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}
char    *ft_strjoin(char const *s1, char const *s2)
{
    int     i;
    int     j;
    int     k;
    char    *s;
    s = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (s == NULL)
        return (NULL);
    while (s1[i] != '\0')
    {
        s[k] = s1[i];
        k++;
        i++;
    }
    while (s2[j] != '\0')
    {
        s[k] = s2[j];
        k++;
        j++;
    }
    *s = '\0';
    return (s);
}
size_t  ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t len;
    size_t i;

    len = ft_strlen(src);
    i = 0;
    if (size != 0)
    {
        while ((size - 1) > i && src[i] != '\0')
        {
            dst[i] = src[i];
            i++;
        }
        dst[i] = '\0';
    }
    return (len);
}
char    *ft_strdup(const char *s1)
{
    char    *str;
    size_t  len;
    
    len = ft_strlen(s1) + 1;
    str = (char *)malloc(len * sizeof(char));
    if (str == NULL)
        return (NULL);
    ft_strlcpy (str, s1, len);
    return (str);
}
char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *sub;
    size_t  i;
    size_t  j;

    if (s == NULL)
        return (NULL);
    if ((unsigned int)ft_strlen(s) < start)
        return (ft_strdup(""));
    j = ft_strlen(s + start);
    if (j < len)
        len = j;
    sub = (char *)malloc(sizeof(char) * (len + 1));
    if (sub == NULL)
        return (NULL);
    i = 0;
    while (i < len)
    {
        sub[i] = s[start + i];
        i++;
    }
    sub[i] = '\0';
    return (sub);
}
char    *ft_strchr(const char *s, int c)
{
    while (*s != '\0')
    {
        if (*s == (char)c)
        {
            return ((char *)s);
        }
        s++;
    }
    if ((char)c == '\0')
        return ((char *)s);
    return (0);
}