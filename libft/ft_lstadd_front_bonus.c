/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizedua <luizedua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:53:05 by luizedua          #+#    #+#             */
/*   Updated: 2023/07/16 17:51:38 by luizedua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *newl)
{
	if (newl == NULL)
		return ;
	if (lst == NULL)
	{
		*lst = newl;
		return ;
	}
	newl->next = *lst;
	*lst = newl;
}
