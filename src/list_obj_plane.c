/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_obj_plane.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrahy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 23:26:06 by ntrahy            #+#    #+#             */
/*   Updated: 2017/01/07 14:31:23 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_obj			*add_plane(t_plane *plane)
{
	t_obj *obj;

	obj = (t_obj *)ft_memalloc(sizeof(t_obj));
	obj->type = PLANE;
	obj->next = NULL;
	obj->solid = init_solid(plane, PLANE);
	obj->reflectionx = &plane->reflection;
	obj->shinex = &plane->shine;
	obj->cut = plane->cut;
	return (obj);
}

t_obj			*push_plane(t_obj **begin_obj, t_plane *plane)
{
	t_obj *tmp;

	tmp = *begin_obj;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = add_plane(plane);
		return (tmp->next);
	}
	else
		*begin_obj = add_plane(plane);
	return (*begin_obj);
}
