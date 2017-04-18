/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrahy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 02:12:34 by ntrahy            #+#    #+#             */
/*   Updated: 2017/01/03 02:12:36 by ntrahy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREADS_H
# define THREADS_H
# include <pthread.h>

typedef	struct s_data	t_data;
typedef struct		s_thread
{
	int				num;
	pthread_t		t;
	t_data			*d;
	double			x;
	double			y;
}					t_thread;
#endif
