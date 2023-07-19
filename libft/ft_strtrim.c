/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:21:36 by luizedua          #+#    #+#             */
/*   Updated: 2023/07/19 12:30:48 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set_search(char c, char const *set)
{
	size_t	index_set;

	index_set = 0;
	while (set[index_set])
	{
		if (set[index_set] == c)
			return (1);
		index_set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*index_final;
	char		*newl_s;

	index_final = s1 + ft_strlen(s1) - 1;
	while (s1 && set_search(*s1, set))
		s1++;
	while (index_final > s1 && set_search(*index_final, set))
		index_final--;
	newl_s = malloc((ft_strlen(s1) - ft_strlen(index_final) + 2) * \
		sizeof(char));
	if (newl_s == NULL)
		return (NULL);
	ft_strlcpy(newl_s, s1, index_final - s1 + 2);
	return (newl_s);
}
