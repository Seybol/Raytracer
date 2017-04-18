/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrahy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 23:04:46 by ntrahy            #+#    #+#             */
/*   Updated: 2017/01/09 20:33:50 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			ft_load_image(t_data *d, t_texture *tex, char *path)
{
	tex->img.endian = 0;
	tex->img.img =
			mlx_xpm_file_to_image(d->mlx, path, &tex->img.x, &tex->img.y);
	if (!tex->img.img)
		ft_malloc_error();
	tex->img.data = mlx_get_data_addr(tex->img.img, &tex->img.bpp,
				&tex->img.sl, &tex->img.endian);
	tex->path = ft_strdup(path);
	return (0);
}

t_texture	*get_texture_data(t_data *d, char *path)
{
	t_texture	*lst;

	lst = d->texturelist;
	while (lst != NULL)
	{
		if (ft_strcmp(lst->path, path) == 0)
			return (lst);
		lst = lst->next;
	}
	lst = (t_texture *)ft_memalloc(sizeof(t_texture));
	ft_load_image(d, lst, path);
	lst->next = d->texturelist;
	d->texturelist = lst;
	return (lst);
}
