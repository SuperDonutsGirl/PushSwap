/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mvt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 00:50:55 by pamartin          #+#    #+#             */
/*   Updated: 2022/02/10 00:50:58 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_a_target(t_stack *s)
{
    int 	tmp;
	size_t	ia;
	size_t	ib;
  
	ib = s->len - s->len_tb;
	if (s->len_ta < 0)
		ia = s->len;
	else 
		ia = s->size_diff - 1;
    if (s->len_tb >= 0)
    {
        tmp = s->target_b[ib];
        s->target_b[ib] = s->target_a[ia];
        s->target_a[ia] = tmp;
		tmp = s->chunck_b[ib];
        s->chunck_b[ib] = s->chunck[ia];
        s->chunck[ia] = tmp;
		s->len_tb--;
		s->len_ta++;
    }
}

void    push_b_target(t_stack *s)
{
    int tmp;
    size_t  ia;
	size_t	ib;

	ia = s->size_diff;
	if (s->len_tb < 0)
		ib = s->len;
	else 
		ib = s->len - s->len_tb - 1;
    if (s->len_ta >= 0)
    {
        tmp = s->target_a[ia];
        s->target_a[ia] = s->target_b[ib];
        s->target_b[ib] = tmp;
		
		
		tmp = s->chunck[ia];
        s->chunck[ia] = s->chunck_b[ib];
        s->chunck_b[ib] = tmp;
		s->len_ta--;
		s->len_tb++;
    }
}

void    reverse_a_target(t_stack *s)
{
    int     tmp;
	int		tmp_chunck;
	size_t  i;
    
    i = s->len;
    tmp = s->target_a[i];
	tmp_chunck = s->chunck[i];
    while (i > s->size_diff)
    {
        s->target_a[i] = s->target_a[i - 1];
		s->chunck[i] = s->chunck[i - 1];
        i--;
    }
    s->target_a[i] = tmp;
	s->chunck[i] = tmp_chunck;
}

void    rotate_a_target(t_stack *s)
{
    int     tmp;
	int		tmp_chunck;
    size_t  i;

	i = s->size_diff;
    tmp = s->target_a[i];
	tmp_chunck = s->chunck[i];
    while (i < s->len)
    {
        s->target_a[i] = s->target_a[i + 1];
		s->chunck[i] = s->chunck[i + 1];
        i++;
    }
    s->target_a[i] = tmp;
	s->chunck[i] = tmp_chunck;
}
