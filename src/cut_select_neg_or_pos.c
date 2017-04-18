/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_select_neg_or_pos.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrahy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 22:17:51 by ntrahy            #+#    #+#             */
/*   Updated: 2017/01/02 22:30:04 by ntrahy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			save_nothing(t_research *r, t_cut *cut)
{
	r->dist[0] = 0;
	r->dist[1] = 0;
	r->dist[2] = 0;
	r->current_obj = cut->cutted_obj;
	cut->final_dist = 0;
}

void			save_negative_plane(t_research *r, t_cut *cut)
{
	r->current_obj = cut->closest_negative;
	r->modified_ray = cut->closest_negative_ray;
	cut->final_dist = cut->final_dist_n;
}

void			save_positive_plane(t_research *r, t_cut *cut)
{
	r->current_obj = cut->closest_positive;
	r->modified_ray = cut->closest_positive_ray;
	cut->final_dist = cut->final_dist_p;
}

void			save_cutted_object(t_research *r, t_cut *cut)
{
	r->current_obj = cut->cutted_obj;
	cut->final_dist = 0;
}
