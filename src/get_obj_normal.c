/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_obj_normal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 15:46:51 by scebula           #+#    #+#             */
/*   Updated: 2017/01/03 12:25:22 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vect	get_cylinder_normal(t_obj *obj, t_vect n, t_thread *thread)
{
	(void)obj;
	(void)thread;
	n.y = 0;
	normalize_vector(&n);
	n.w = 0;
	return (n);
}

t_vect	get_sphere_normal(t_obj *obj, t_vect n, t_thread *thread)
{
	(void)thread;
	(void)obj;
	normalize_vector(&n);
	n.w = 0;
	return (n);
}

t_vect	get_plane_normal(t_obj *obj, t_vect n, t_thread *thread)
{
	(void)thread;
	(void)n;
	return (TO_PLANE->normal);
}

t_vect	get_cone_normal(t_obj *obj, t_vect n, t_thread *thread)
{
	t_vect normal;

	(void)thread;
	normal = init_vector(2 * n.x, -2 * TO_CONE->tan_alpha *
			n.y, 2 * n.z, 0);
	normalize_vector(&normal);
	return (normal);
}
