/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_obj_hyperboloid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrahy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 23:25:42 by ntrahy            #+#    #+#             */
/*   Updated: 2017/01/07 14:31:16 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_obj	*add_hyperboloid(t_hyperboloid *hyperboloid)
{
	t_obj *obj;

	obj = (t_obj *)ft_memalloc(sizeof(t_obj));
	obj->type = HYPERBOLOID;
	obj->next = NULL;
	obj->solid = init_solid(hyperboloid, HYPERBOLOID);
	obj->reflectionx = &hyperboloid->reflection;
	obj->shinex = &hyperboloid->shine;
	return (obj);
}

t_obj			*push_hyperboloid(t_obj **begin_obj, t_hyperboloid *hyperboloid)
{
	t_obj *tmp;

	tmp = *begin_obj;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = add_hyperboloid(hyperboloid);
		return (tmp->next);
	}
	else
		*begin_obj = add_hyperboloid(hyperboloid);
	return (*begin_obj);
}
