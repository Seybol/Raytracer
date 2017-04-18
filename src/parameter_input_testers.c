/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameter_input_testers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scebula <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 15:08:27 by scebula           #+#    #+#             */
/*   Updated: 2017/01/03 15:09:35 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		parsetest_vector(char *line, int linenbr, t_p_cache *cache)
{
	int		i;
	float	tmp;

	i = 0;
	while (line[i] != 0)
	{
		if (ft_isnumeric(line[i]) == 0)
			ft_parsing_error(linenbr,
					"found non numeric character where float was expected", FN);
		i++;
	}
	tmp = ft_atof(line);
	if (tmp > 100000 || tmp < -100000)
		ft_parsing_error(linenbr,
				"error parsing a float vector over 100000", FN);
	return (1);
}
