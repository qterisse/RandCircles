/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tclist_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quteriss <quteriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:04:58 by quteriss          #+#    #+#             */
/*   Updated: 2024/01/12 18:52:13 by quteriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_clist *ft_new_elem(int data[3])
{
	t_clist *elem;

	elem = malloc(sizeof(t_clist));
	elem->data = data;
	elem->next = NULL;
	return (elem);
}

void	push_front(t_clist **clist, t_clist *new_elem)
{
	if (!clist)
	{
		*clist = new_elem;
		return ;
	}
	new_elem->next = *clist;
	*clist = new_elem;
}
