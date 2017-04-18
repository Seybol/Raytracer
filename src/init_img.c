/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrahy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 04:56:29 by ntrahy            #+#    #+#             */
/*   Updated: 2017/01/05 14:02:37 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		init_img_zero(t_img *img)
{
	img->img = NULL;
	img->data = NULL;
}

t_img			*free_img(void *mlx, t_img *img)
{
	if (img)
	{
		if (img->img)
			mlx_destroy_image(mlx, img->img);
		free(img);
		img = NULL;
	}
	return (NULL);
}

t_img			*init_img(void *mlx, int width, int height)
{
	t_img *a;

	a = (t_img*)ft_memalloc(sizeof(t_img));
	init_img_zero(a);
	if ((a->img = mlx_new_image(mlx, width, height)) == NULL)
		ft_malloc_error();
	if ((a->data = mlx_get_data_addr(a->img, &(a->bpp), &(a->sl),
					&(a->endian))) == NULL)
		ft_malloc_error();
	a->x = width;
	a->y = height;
	return (a);
}
