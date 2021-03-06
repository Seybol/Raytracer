/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_obj_triangle.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrahy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 00:29:28 by ntrahy            #+#    #+#             */
/*   Updated: 2017/01/07 14:31:04 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_obj	*add_triangle(t_triangle *triangle)
{
	t_obj *obj;

	obj = (t_obj *)ft_memalloc(sizeof(t_obj));
	obj->type = TRIANGLE;
	obj->next = NULL;
	obj->solid = init_solid(triangle, TRIANGLE);
	obj->reflectionx = &triangle->reflection;
	obj->shinex = &triangle->shine;
	obj->cut = triangle->cut;
	return (obj);
}

t_obj	*push_triangle(t_obj **begin_obj, t_triangle *triangle)
{
	t_obj *tmp;

	tmp = *begin_obj;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = add_triangle(triangle);
		return (tmp->next);
	}
	else
		*begin_obj = add_triangle(triangle);
	return (*begin_obj);
}
