/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_obj_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrahy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 00:44:39 by ntrahy            #+#    #+#             */
/*   Updated: 2017/01/03 12:41:12 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <math.h>

static void	check_for_solutions_cylinder(double *dist)
{
	if (dist[0] > dist[1])
		swap_double(&dist[0], &dist[1]);
	if (dist[0] < 0 && dist[1] > 0)
		dist[2] = dist[1];
	else if (dist[0] > 0 && dist[1] > 0)
		dist[2] = dist[0];
	else
	{
		dist[0] = 0;
		dist[1] = 0;
	}
}

void		get_cylinder_n(t_ray ray, t_obj *obj,
		t_thread *thread, double *dist)
{
	double a;
	double b;
	double c;
	double delta;

	(void)thread;
	(void)obj;
	a = ray.dir.x * ray.dir.x + ray.dir.z * ray.dir.z;
	b = 2 * ray.dir.x * ray.ori.x + 2 * ray.dir.z * ray.ori.z;
	c = ray.ori.x * ray.ori.x + ray.ori.z * ray.ori.z - 1;
	delta = (b * b) - (4 * a * c);
	if (delta > 0)
	{
		dist[0] = (((-1 * b - sqrt(delta))) / (2 * a)) - ACC;
		dist[1] = (((-1 * b + sqrt(delta))) / (2 * a)) - ACC;
		check_for_solutions_cylinder(dist);
	}
}
