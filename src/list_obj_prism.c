/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_obj_prism.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrahy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 00:28:22 by ntrahy            #+#    #+#             */
/*   Updated: 2017/01/07 14:31:24 by gbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_obj	*add_prism(t_prism *prism)
{
	t_obj *obj;

	obj = (t_obj *)ft_memalloc(sizeof(t_obj));
	obj->type = PRISM;
	obj->next = NULL;
	obj->reflectionx = &prism->reflection;
	obj->shinex = &prism->shine;
	obj->solid = init_solid(prism, TRIANGLE);
	obj->cut = prism->cut;
	return (obj);
}

t_obj			*push_prism(t_obj **begin_obj, t_prism *prism)
{
	t_obj *tmp;

	tmp = *begin_obj;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = add_prism(prism);
		return (tmp->next);
	}
	else
		*begin_obj = add_prism(prism);
	return (*begin_obj);
}
