/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:22:08 by luizedua          #+#    #+#             */
/*   Updated: 2023/07/19 12:31:24 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnewl(void *content)
{
	t_list	*node_alloc;

	node_alloc = malloc(sizeof(t_list));
	if (node_alloc == NULL)
		return (NULL);
	node_alloc->content = content;
	node_alloc->next = NULL;
	return (node_alloc);
}
