/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:28:19 by pamartin          #+#    #+#             */
/*   Updated: 2022/02/08 09:28:21 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_start(t_stack *s)
{
	push_b(s);
	sort_3(s);
	push_a(s);
}

void	max_start(t_stack *s)
{
	push_b(s);
	sort_3(s);
	push_a(s);
	rotate_a(s);
}

void	min_end(t_stack *s)
{
	reverse_a(s);
	push_b(s);
	sort_3(s);
	push_a(s);
}

void	max_min_middle(t_stack *s)
{
	rotate_a(s);
	max_start(s);
}

void	min_max_end(t_stack *s)
{
	reverse_a(s);
	max_start(s);
}
