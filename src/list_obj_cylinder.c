/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_obj_cylinder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrahy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 23:23:17 by ntrahy            #+#    #+#             */
/*   Updated: 2017/01/07 14:31:14 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_obj		*add_cylinder(t_cylinder *cylinder)
{
	t_obj *obj;

	obj = (t_obj *)ft_memalloc(sizeof(t_obj));
	obj->type = CYLINDER;
	obj->next = NULL;
	obj->solid = init_solid(cylinder, CYLINDER);
	obj->reflectionx = &cylinder->reflection;
	obj->shinex = &cylinder->shine;
	obj->cut = cylinder->cut;
	return (obj);
}

t_obj				*push_cylinder(t_obj **begin_obj, t_cylinder *cylinder)
{
	t_obj *tmp;

	tmp = *begin_obj;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = add_cylinder(cylinder);
		return (tmp->next);
	}
	else
		*begin_obj = add_cylinder(cylinder);
	return (*begin_obj);
}
