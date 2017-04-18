/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrahy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 23:20:58 by ntrahy            #+#    #+#             */
/*   Updated: 2017/01/05 14:04:45 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_light		*init_light(void)
{
	t_light *light;

	light = (t_light *)ft_memalloc(sizeof(t_light));
	light->pos.x = 0;
	light->pos.y = 0;
	light->pos.z = 0;
	light->color.r = 255;
	light->color.g = 255;
	light->color.b = 255;
	light->next = NULL;
	return (light);
}
