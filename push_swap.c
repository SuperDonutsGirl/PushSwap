/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 04:23:53 by pamartin          #+#    #+#             */
/*   Updated: 2022/02/04 04:24:01 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *s)
{
	int	i;

	printf("Stack A   |   Stack B         Sorted		chunck\n");
	printf("----------------------	    ----------        	-------\n");
	i = 0;
	while (i < s->argc - 1)
	{
		printf("   %d	  |	%d	  	%d		   %d\n", s->a[i], s->b[i], s->sort[i], s->chunck[i]);
		i++;
	}
}

int	s_init(t_stack *s, int argc)
{
	s->argc = argc;
	s->ac = 0;
	if (s->argc == 2)
	{
		s->argc = s->len_str + 1;
		s->ac = 2;
	}
	s->a = malloc(sizeof(int) * (s->argc - 1));
	if (!s->a)
		return (0);
	s->b = malloc(sizeof(int) * (s->argc - 1));
	if (!s->b)
		return (0);
	s->sort = malloc(sizeof(int) * (s->argc - 1));
	if (!s->sort)
		return (0);
	s->chunck = malloc(sizeof(int) * (s->argc - 1));
	if (!s->chunck)
		return (0);
	s->len = s->argc - 2;
	s->len_a = s->argc - 2;
	s->len_b = -1;
	return (1);
}

t_stack	*array_fill(t_stack *s, char **type)
{
	int	i;
	int	y;

	i = 0;
	y = 1;
	if (s->ac == 2)
		y = 0;
	while (i < s->argc - 1)
	{
		s->a[i] = ft_atoi(type[y]);
		s->sort[i] = ft_atoi(type[y]);
		s->b[i] = 0;
		s->chunck[i] = 8;
		i++;
		y++;
	}
	return (s);
}

void	sort(int argc, t_stack *s)
{
	if (s->argc == 3)
		sort_2(s);
	else if (s->argc == 4)
		sort_3(s);
	else if (s->argc == 5)
		sort_4(s);
	else if (s->argc == 6)
		sort_5(s);
	else if (s->argc <= 41)
		extraction_sort(s);
	else
		radix(s);
}

int	main(int argc, char **argv)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (0);
	if (!check_params(argc, argv, s))
		return (output_error(s));
	if (!s_init(s, argc))
		return (0);
	if (s->ac == 2)
		s = array_fill(s, s->av);
	else
		s = array_fill(s, argv);
	if (!check_duplicate(s))
		return (output_error(s));
	if (is_sorted(s))
	{
		free(s);
		return (0);
	}
	sort(argc, s);
	print_stack(s);
	free(s);
}
