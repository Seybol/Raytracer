/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_scene_look.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 12:15:48 by scebula           #+#    #+#             */
/*   Updated: 2017/01/08 16:21:43 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	event_mov_look_left(t_data *d)
{
	t_matrix xyz;

	xyz = init_xyzrotation_matrix(10, d->cam.up.x, d->cam.up.y, d->cam.up.z);
	apply_matrix(xyz, &d->cam.dir);
	create_cam(&d->cam, d);
	remake(d);
}

void	event_mov_look_right(t_data *d)
{
	t_matrix xyz;

	xyz = init_xyzrotation_matrix(-10, d->cam.up.x, d->cam.up.y, d->cam.up.z);
	apply_matrix(xyz, &d->cam.dir);
	create_cam(&d->cam, d);
	remake(d);
}

void	event_mov_look_up(t_data *d)
{
	t_matrix xyz;

	xyz = init_xyzrotation_matrix(-10, d->cam.left.x, d->cam.left.y,
		d->cam.left.z);
	apply_matrix(xyz, &d->cam.dir);
	create_cam(&d->cam, d);
	remake(d);
}

void	event_mov_look_down(t_data *d)
{
	t_matrix xyz;

	xyz = init_xyzrotation_matrix(10, d->cam.left.x, d->cam.left.y,
		d->cam.left.z);
	apply_matrix(xyz, &d->cam.dir);
	create_cam(&d->cam, d);
	remake(d);
}
