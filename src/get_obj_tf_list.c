/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_obj_tf_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 15:47:04 by scebula           #+#    #+#             */
/*   Updated: 2017/01/08 12:23:30 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_tf_list	*get_cylinder_tf_list(t_obj *obj)
{
	return (TO_CYLINDER->tf_list);
}

t_tf_list	*get_sphere_tf_list(t_obj *obj)
{
	return (TO_SPHERE->tf_list);
}

t_tf_list	*get_plane_tf_list(t_obj *obj)
{
	return (TO_PLANE->tf_list);
}

t_tf_list	*get_cone_tf_list(t_obj *obj)
{
	return (TO_CONE->tf_list);
}

t_tf_list	*get_triangle_tf_list(t_obj *obj)
{
	return (TO_TRIANGLE->tf_list);
}
