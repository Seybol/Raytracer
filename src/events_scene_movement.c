/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_scene_movement.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrahy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 23:20:23 by ntrahy            #+#    #+#             */
/*   Updated: 2017/01/08 12:17:53 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	event_mov_fwd(t_data *d)
{
	normalize_vector(&d->cam.dir);
	add_to_vector(&(d->cam.pos), (d->cam.dir));
	create_cam(&d->cam, d);
	remake(d);
}

void	event_mov_bwd(t_data *d)
{
	normalize_vector(&d->cam.dir);
	substract_to_vector(&(d->cam.pos), (d->cam.dir));
	create_cam(&d->cam, d);
	remake(d);
}

void	event_mov_strafe_lft(t_data *d)
{
	normalize_vector(&d->cam.dir);
	add_to_vector(&(d->cam.pos), (d->cam.left));
	create_cam(&d->cam, d);
	remake(d);
}

void	event_mov_strafe_rgt(t_data *d)
{
	normalize_vector(&d->cam.dir);
	substract_to_vector(&(d->cam.pos), (d->cam.left));
	create_cam(&d->cam, d);
	remake(d);
}
