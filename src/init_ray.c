/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 16:28:40 by scebula           #+#    #+#             */
/*   Updated: 2016/10/01 16:34:36 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		copy_ray_value(t_ray *r1, t_ray r2)
{
	r1->ori = copy_vector(r2.ori);
	r1->dir = copy_vector(r2.dir);
}

t_ray		init_ray(t_vect ori, t_vect dir)
{
	t_ray ray;

	ray.ori = ori;
	ray.dir = dir;
	return (ray);
}
