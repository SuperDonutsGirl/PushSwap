/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvt_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:50:30 by pamartin          #+#    #+#             */
/*   Updated: 2022/02/08 09:50:33 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_a(t_stack *s)
{
    int 	tmp;
	size_t	ia;
	size_t	ib;
  
	ib = s->len - s->len_b;
	if (s->len_a < 0)
		ia = s->len;
	else 
		ia = s->size_diff - 1;
    if (s->len_b >= 0)
    {
        tmp = s->b[ib];
        s->b[ib] = s->a[ia];
        s->a[ia] = tmp;
		s->len_b--;
		s->len_a++;
    }
	s->size_diff = s->len - s->len_a;
	write(1, "pa\n", 3);
}

void    push_b(t_stack *s)
{
    int tmp;
    size_t  ia;
	size_t	ib;

	//printf("yoooooo\n");
	ia = s->size_diff;
	if (s->len_b < 0)
		ib = s->len;
	else 
		ib = s->len - s->len_b - 1;
    if (s->len_a >= 0)
    {
        tmp = s->a[ia];
        s->a[ia] = s->b[ib];
        s->b[ib] = tmp;
		s->len_a--;
		s->len_b++;
    }
	s->size_diff = s->len - s->len_a;
	write(1, "pb\n", 3);
}
