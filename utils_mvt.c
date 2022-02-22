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

void    push_a_target(t_stack *s, int *stack_a, int *stack_b)
{
    int 	tmp;
	int	ia;
	int	ib;
  
	ib = 0;
	ia = s->len;
	if (s->len_b != -1)
	{
		tmp = stack_b[0];
		while (ib < s->len_b)
		{
			stack_b[ib] = stack_b[ib + 1];
			ib++;
		}
		if (s->len_a != -1)
		{
			while (ia > 0)
			{
				stack_a[ia] = stack_a[ia - 1];
				ia--;
			}
		}
		stack_a[0] = tmp;
		stack_b[s->len_b] = 8;
    }
}

void    push_b_target(t_stack *s, int *stack_a, int *stack_b)
{
    int tmp;
    int  ia;
	int	ib;

	
	ia = 0;
	ib = s->len;
	if (s->len_a != -1)
	{
		//printf("yooooo\n");
		tmp = stack_a[0];
		while (ia < s->len_a)
		{
			//printf("yooooo\n");
			stack_a[ia] = stack_a[ia + 1];
			ia++;
		}
		if (s->len_b != -1)
		{
			//printf("yooooo\n");
			while (ib > 0)
			{
				stack_b[ib] = stack_b[ib - 1];
				ib--;
			}
		}
		stack_b[0] = tmp;
		stack_a[s->len_a] = 8;
		//printf("push_b\n");
	}
}

void    reverse_a_target(t_stack *s,  int *stack_a)
{
    int     tmp;
	int  i;
    
	//printf("LEN  = %d\n", s->len);
	//printf("LEN DE A = %d\n", s->len_a);
    i = s->len_a;
    tmp = stack_a[i];
    while (i > 0)
    {
        stack_a[i] = stack_a[i - 1];
        i--;
    }
    stack_a[i] = tmp;
	// printf("APRES LE ROTATE\n");
	// print_stack(s);
}

void    rotate_a_target(t_stack *s,  int *stack_a)
{
    int     tmp;
    int  i;

	//printf("LEN  = %d\n", s->len);
	//printf("LEN DE A = %d\n", s->len_a);
	i = 0;
    tmp = stack_a[0];
    while (i < s->len_a)
    {
        stack_a[i] = stack_a[i + 1];
        i++;
    }
    stack_a[i] = tmp;
	// printf("APRES LE ROTATE\n");
	// print_stack(s);
}
