/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_obj_paraboloid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrahy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 23:25:48 by ntrahy            #+#    #+#             */
/*   Updated: 2017/01/07 14:31:16 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_obj	*add_paraboloid(t_paraboloid *paraboloid)
{
	t_obj *obj;

	obj = (t_obj *)ft_memalloc(sizeof(t_obj));
	obj->type = PARABOLOID;
	obj->next = NULL;
	obj->solid = init_solid(paraboloid, PARABOLOID);
	obj->reflectionx = &paraboloid->reflection;
	obj->shinex = &paraboloid->shine;
	obj->cut = paraboloid->cut;
	return (obj);
}

t_obj			*push_paraboloid(t_obj **begin_obj, t_paraboloid *paraboloid)
{
	t_obj *tmp;

	tmp = *begin_obj;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = add_paraboloid(paraboloid);
		return (tmp->next);
	}
	else
		*begin_obj = add_paraboloid(paraboloid);
	return (*begin_obj);
}
