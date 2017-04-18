/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_obj_csg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrahy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 23:23:04 by ntrahy            #+#    #+#             */
/*   Updated: 2017/01/05 14:38:29 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_obj		*add_csg(t_csg *csg)
{
	t_obj *obj;

	obj = (t_obj *)ft_memalloc(sizeof(t_obj));
	obj->type = CSG;
	obj->next = NULL;
	obj->solid = init_solid(csg, CSG);
	obj->reflectionx = NULL;
	obj->shinex = NULL;
	obj->cut = NULL;
	return (obj);
}

t_obj				*push_csg(t_obj **begin_obj, t_csg *csg)
{
	t_obj *tmp;

	tmp = *begin_obj;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = add_csg(csg);
		return (tmp->next);
	}
	else
		*begin_obj = add_csg(csg);
	return (*begin_obj);
}
