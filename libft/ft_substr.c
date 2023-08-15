/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:19:25 by luizedua          #+#    #+#             */
/*   Updated: 2023/07/16 17:51:18 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*newl_s;
	size_t	s_len;

	s_len = ft_strlen((char *)s);
	if (start > s_len)
		return (ft_strdup(""));
	if (s_len - start >= len)
		newl_s = malloc((len + 1) * sizeof(char));
	else
		newl_s = malloc((s_len - start + 1) * sizeof(char));
	if (newl_s == NULL)
		return (NULL);
	if (newl_s != NULL)
		ft_strlcpy(newl_s, (s + start), (len + 1));
	return (newl_s);
}
