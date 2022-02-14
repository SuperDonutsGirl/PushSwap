/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvt_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:49:47 by pamartin          #+#    #+#             */
/*   Updated: 2022/02/08 09:49:56 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap_a(t_stack *s)
{
    int 	tmp;
    size_t  i;
   
	i = s->size_diff;
	if (s->len_a > 0)
	{
		tmp = s->a[i];
    	s->a[i] = s->a[i + 1];
    	s->a[i + 1] = tmp;
	}
	write(1, "sa\n", 3);

}

void    swap_b(t_stack *s)
{
    int 	tmp;
    size_t  i;
    
	i = s->len - s->len_b;
	if (s->len_b > 0)
	{
		tmp = s->b[i];
    	s->b[i] = s->b[i + 1];
    	s->b[i + 1] = tmp;
	}
	write(1, "sb\n", 3);
}

void    swap_ab(t_stack *s)
{
    int 	tmp;
    size_t  i;
  
	i = s->size_diff;
	if (s->len_a > 0)
	{
		tmp = s->a[i];
    	s->a[i] = s->a[i + 1];
    	s->a[i + 1] = tmp;
	}
    i = s->len - s->len_b;
	if (s->len_b > 0)
	{
		tmp = s->b[i];
    	s->b[i] = s->b[i + 1];
    	s->b[i + 1] = tmp;
	}
    write(1, "ss\n", 3);
}
