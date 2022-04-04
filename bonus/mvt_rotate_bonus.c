/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvt_rotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:40:00 by pamartin          #+#    #+#             */
/*   Updated: 2022/04/04 15:40:02 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	rotate_a(t_stack *s)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = s->a[0];
	while (i < s->len_a)
	{
		s->a[i] = s->a[i + 1];
		i++;
	}
	s->a[i] = tmp;
}

void	rotate_b(t_stack *s)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = s->b[0];
	while (i < s->len_b)
	{
		s->b[i] = s->b[i + 1];
		i++;
	}
	s->b[i] = tmp;
}

void	rotate_ab(t_stack *s)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = s->a[0];
	while (i < s->len_a)
	{
		s->a[i] = s->a[i + 1];
		i++;
	}
	s->a[i] = tmp;
	i = 0;
	tmp = s->b[0];
	while (i < s->len_b)
	{
		s->b[i] = s->b[i + 1];
		i++;
	}
	s->b[i] = tmp;
}
