/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tclist_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quteriss <quteriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:04:58 by quteriss          #+#    #+#             */
/*   Updated: 2024/01/12 17:17:10 by quteriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	push_front(t_clist **clist, int *data)
{
	t_clist	*elem;

	elem = malloc(sizeof(t_clist));
	if (!elem)
		return (NULL);
	elem->next = *clist;
	elem->data = data;
	*clist = elem;
}
