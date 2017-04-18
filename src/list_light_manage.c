/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_light_manage.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrahy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 23:25:10 by ntrahy            #+#    #+#             */
/*   Updated: 2017/01/02 23:25:11 by ntrahy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		push_light(t_light **begin_light, t_light *light)
{
	t_light *tmp;

	tmp = *begin_light;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = light;
	}
	else
		*begin_light = light;
}

t_light		*free_light_list(t_light **begin_light_list)
{
	t_light *tmp;
	t_light *next_tmp;

	tmp = *begin_light_list;
	while (tmp)
	{
		next_tmp = tmp->next;
		free(tmp);
		tmp = next_tmp;
	}
	*begin_light_list = NULL;
	return (NULL);
}
