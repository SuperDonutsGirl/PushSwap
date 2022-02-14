/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvt_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:51:47 by pamartin          #+#    #+#             */
/*   Updated: 2022/02/08 09:51:49 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotate_a(t_stack *s)
{
    int     tmp;
    size_t  i;

	i = s->size_diff;
    tmp = s->a[i];
    while (i < s->len)
    {
        s->a[i] = s->a[i + 1];
        i++;
    }
    s->a[i] = tmp;
    write(1, "ra\n", 3);
}

void    rotate_b(t_stack *s)
{
    int     tmp;
    size_t  i;
  
	i = s->len - s->len_b;
    tmp = s->b[i];
    while (i < s->len)
    {
        s->b[i] = s->b[i + 1];
        i++;
    }
    s->b[i] = tmp;
    write(1, "rb\n", 3);
}

void    rotate_ab(t_stack *s)
{
    int     tmp;
    size_t  i;
   
	i = s->size_diff;
    tmp = s->a[i];
    while (i < s->len)
    {
        s->a[i] = s->a[i + 1];
        i++;
    }
    s->a[i] = tmp;
	i = s->len - s->len_b;
    tmp = s->b[i];
    while (i <= s->len_b)
    {
        s->b[i] = s->b[i + 1];
        i++;
    }
    s->b[i] = tmp;
    write(1, "rr\n", 3);
}

