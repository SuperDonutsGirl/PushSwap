/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:02:18 by pamartin          #+#    #+#             */
/*   Updated: 2022/02/09 13:02:31 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_tab(t_stack *s)
{
	int	i;
	int	j;

	i = 0;
	while (i <= s->len)
	{
		j = 0;
		s->num = s->a[i];
		while (s->sort[j] != s->num)
			j++;
		s->index[i] = j;
		s->target_a[i] = j;
		i++;
	}
}

void	index_binary(t_stack *s)
{
	int	i;

	i = 0;
	while (i <= s->len)
	{
		s->target_a[i] = binary_convert(s->target_a[i]);
		i++;
	}
}

int	only_one(t_stack *s)
{
	int	i;

	i = s->size_diff;
	while (i <= s->len)
	{
		//printf("a la position %d, il y a %d\n", i, s->chunck[i]);
		if (s->chunck[i] == 0)
			return (0);
		i++;
	}
	return (1);
}

int	only_zero(t_stack *s)
{
	int	i;

	i = s->size_diff;
	while (i <= s->len)
	{
		if (s->chunck[i] == 1)
			return (0);
		i++;
	}
	return (1);
}

int	found_zero(t_stack *s)
{
	int	i;

	i = s->size_diff;
	while (i <= s->len)
	{
		if (s->chunck[i] == 0)
			return (i);
		i++;
	}
	// return -1 si jamais il y a une 0 ?
	return (i);
}

void	fill_target(t_stack *s, int i)
{
	int	j;
	int	nb;
	int	x;

	j = s->size_diff;
	nb = 0;
	while (j <= s->len)
	{
		nb = s->target_a[j];
		s->chunck[j] = nb % (10 * i) / i;
		j++;
	}
	//print_stack(s);
}

void	sort_target(t_stack *s, int i)
{
	int	z;

	z = 0;
	fill_target(s, i);
	//print_stack(s);
	if (!only_zero(s))
	{
		printf("AVANT EXTRACTION, POSITION : %d\n", i);
		print_stack(s);
		//printf("only 1 = %d\n", only_one(s));
		while (!only_one(s))
		{
			
			z = found_zero(s);
			//printf("zero a la position : %d\n", z);
			if (z - s->size_diff < (s->len_a / 2 + 1))
			{
				//printf("la\n");
				while (z > s->size_diff)
				{
					//printf("ici\n");
					rotate_a_target(s);
					rotate_a(s);
					z--;
				}
			}
			else
			{
				while (z <= s->len)
				{
					//printf("bonjour\n");
					reverse_a_target(s);
					reverse_a(s);
					
					z++;
				}

			}
			////Condition pour verifier si on est rendu au plus grand bit
			push_b_target(s);
			push_b(s);
			//printf("only 1 = %d\n", only_one(s));
			//printf("APRES EXTRACTION, POSITION : %d\n", i);
			//print_stack(s);
			//fill_target(s, i);
		}
		printf("APRES EXTRACTION, POSITION : %d\n", i);
		print_stack(s);
	}
	//printf("hello\n");
	while (s->len_b != -1)
	{
		push_a_target(s);
		push_a(s);
		
	}
	printf("APRES AVOIR TOUT REMIS, POSITION : %d\n", i);
	print_stack(s);


		
}

int	radix(t_stack *s)
{
	int	i;
	int	target;

	i = 1;
	target = 0;
	quick_sort(s->sort, 0, s->len);
	//print_stack(s);
	index_tab(s);
	//print_stack(s);
	index_binary(s);
	while (target != 9)
	{
		target++;
		sort_target(s, i);
		i *= 10;
	}
	//print_stack(s);
	//if (!is_sorted(s))
	//	radix(s);
	return (1);
}


1 2 3 4 5 6   AU DEBUT 

6 1 2 3 4 5	 6 reverse

6 1 2 3 4 5 	1 ROTATE