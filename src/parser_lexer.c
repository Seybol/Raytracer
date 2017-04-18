/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_lexer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrahy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 04:56:50 by ntrahy            #+#    #+#             */
/*   Updated: 2017/01/08 14:58:12 by scebula          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	free_prec_split(t_p_cache *cache)
{
	void *back;

	back = PARAMS;
	if (PARAM_NAME != NULL)
	{
		free(PARAM_NAME);
		PARAM_NAME = NULL;
	}
	if (PARAMS != NULL)
	{
		while (*PARAMS != NULL)
		{
			free(*PARAMS);
			*PARAMS = NULL;
			PARAMS++;
		}
		free(back);
		PARAMS = NULL;
	}
}

char	isempty(char *str)
{
	if (str == NULL)
		return (1);
	while (*str != 0)
	{
		if (*str != 9 && *str != 32)
			return (0);
		str++;
	}
	return (1);
}

int		check_line(t_p_cache *cache)
{
	char	lineid;

	lineid = line_identifier(cache);
	if (lineid == CONTEXT_OPENER)
		cache->scope++;
	else if (lineid == CONTEXT_CLOSER)
		cache->scope--;
	if ((cache->prec == DECLARATOR && lineid == CONTEXT_OPENER)
			|| (lineid == CONTEXT_CLOSER && cache->scope >= 0)
			|| lineid == PARAMETER || lineid == DECLARATOR || lineid == 0)
	{
		cache->prec = lineid;
		return (1);
	}
	return (0);
}

void	lexer(int fd, char *filename)
{
	t_p_cache cache;

	cache_init(&cache, filename);
	while ((cache.linelen = get_next_line(fd, &cache.line)) > 0)
	{
		if (check_line(&cache) != 1)
			ft_parsing_error(cache.pos, "lexical inconsistency detected",
			cache.filename);
		cache.pos++;
		free(cache.line);
	}
}
