/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-hzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:07:30 by aben-hzz          #+#    #+#             */
/*   Updated: 2024/11/09 14:21:57 by aben-hzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	int		size;
// 	int		s1_len;
// 	int		s2_len;
// 	char	*join;

// 	if (!s1 && !s2)
//         return (NULL);
//     if (!s1)
//         return (ft_strdup(s2));
//     if (!s2)
//         return (ft_strdup(s1));
// 	s1_len = ft_strlen(s1);
// 	s2_len = ft_strlen(s2);
// 	size = s1_len + s2_len;
// 	join = (char *)malloc((size + 1) * sizeof(char));
// 	if (join == 0)
// 		return (NULL);
// 	ft_strlcpy(join, s1, s1_len + 1);
// 	ft_strlcpy(join + s1_len, s2, s2_len + 1);
// 	return (join);
// }

char	*ft_strjoin(char const *s1, char const *s2)
{
    int		s1_len;
    int		s2_len;
    int		size;
    char	*join;

    if (!s1 && !s2)
        return (NULL);
    if (!s1)
        return (ft_strdup(s2));
    if (!s2)
        return (ft_strdup(s1));
    s1_len = ft_strlen(s1);
    s2_len = ft_strlen(s2);
    size = s1_len + s2_len;
    join = (char *)malloc((size + 1) * sizeof(char));
    if (!join)
        return (NULL);
    ft_strlcpy(join, s1, s1_len + 1);
    ft_strlcpy(join + s1_len, s2, s2_len + 1);
    return (join);
}
