/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_obj_color_bis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrahy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 15:03:01 by ntrahy            #+#    #+#             */
/*   Updated: 2017/01/07 15:41:40 by ntrahy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color		get_triangle_color(t_obj *obj)
{
	return (TO_TRIANGLE->color);
}

t_color		get_prism_color(t_obj *obj)
{
	return (TO_PRISM->color);
}

t_color		get_cube_color(t_obj *obj)
{
	return (TO_CUBE->color);
}

t_color		get_paraboloid_color(t_obj *obj)
{
	return (TO_PARABOLOID->color);
}

t_color		get_hyperboloid_color(t_obj *obj)
{
	return (TO_HYPERBOLOID->color);
}
