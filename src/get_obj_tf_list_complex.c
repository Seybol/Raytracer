/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_obj_tf_list_complex.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 12:23:27 by scebula           #+#    #+#             */
/*   Updated: 2017/01/08 12:23:39 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_tf_list	*get_prism_tf_list(t_obj *obj)
{
	return (TO_PRISM->tf_list);
}

t_tf_list	*get_cube_tf_list(t_obj *obj)
{
	return (TO_CUBE->tf_list);
}

t_tf_list	*get_paraboloid_tf_list(t_obj *obj)
{
	return (TO_PARABOLOID->tf_list);
}

t_tf_list	*get_hyperboloid_tf_list(t_obj *obj)
{
	return (TO_HYPERBOLOID->tf_list);
}
