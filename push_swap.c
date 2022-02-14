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
#include <stdio.h>

void	print_stack(t_stack *s)
{
	int i;
	int x;
	int	j;
	int	y;

	printf("Stack A   |   Stack B	      Index   	     Target A   |   Target B   	      cA | cB\n");
	printf("----------------------	    --------        ---------------------------       --------\n");
	i = 0;
	x = 0;
	j = 0;
	y = 0;
	while (i < s->argc - 1 && x < s->argc - 1)
	{
		printf("   %d	  |	%d		%d		%d	|	%d		%d | %d\n", s->a[i], s->b[x], s->index[y], s->target_a[i], s->target_b[i], s->chunck[i], s->chunck_b[i]);
		i++;
		x++;
		j++;
		y++;
	}
}

int	check_params(int argc, char **argv)
{
	size_t	i;
	size_t	x;

	if (argc <= 2)
		return (0);
	i = 1;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) >= 10 && (ft_atoi(argv[i]) == 0
			|| ft_atoi(argv[i]) == -1))
			return (0);
		if (argv[i][0] == 45)
			x = 1;
		else
			x = 0;
		while (argv[i][x])
		{
			if (!ft_isdigit(argv[i][x]))
				return (0);
			x++;
		}
		i++;
	}
	return (1);
}

int	s_init(t_stack *s, int argc)
{
	s->argc = argc;
	s->a = malloc(sizeof(int) * (argc - 1));
	if (!s->a)
		return (0);
	s->b = malloc(sizeof(int) * (argc - 1));
	if (!s->b)
		return (0);
	s->sort = malloc(sizeof(int) * (argc - 1));
	if (!s->sort)
		return (0);
	s->index = malloc(sizeof(int) * (argc - 1));
	if (!s->index)
		return (0);
	s->target_a = malloc(sizeof(int) * (argc - 1));
	if (!s->target_a)
		return (0);
	s->target_b = malloc(sizeof(int) * (argc - 1));
	if (!s->target_b)
		return (0);
	s->chunck= malloc(sizeof(int) * (argc - 1));
	if (!s->chunck)
		return (0);
	s->chunck_b= malloc(sizeof(int) * (argc - 1));
	if (!s->chunck_b)
		return (0);
	s->len = argc - 2;
	s->len_a = argc - 2;
	s->len_b = -1;
	s->len_ta = argc - 2;
	s->len_tb = -1;
	s->size_diff = 0;
	return (1);
}

void	array_fill(t_stack *s, char **argv)
{
	size_t	i;
	size_t	z;

	i = 0;
	while (i < s->argc - 1)
	{
		s->a[i] = ft_atoi(argv[i + 1]);
		s->sort[i] = ft_atoi(argv[i + 1]);
		s->index[i] = i;
		s->b[i] = 0;
		s->target_a[i] = 0;
		s->target_b[i] = 8;
		s->chunck[i] = 8;
		s->chunck_b[i] = 8;
		i++;
	}
	

}

int	check_duplicate(t_stack *s)
{
	size_t	i;
	int	nb;

	i = 0;
	while (i < s->len)
	{
		nb = s->a[i];
		if (!no_duplicate(s, nb, i + 1))
			return (0);
		i++;
	}
	return (1);
} 

int	is_sorted(t_stack *s)
{
	size_t	i;

	i = 0 + s->size_diff;
	//printf("le debut est a l'indice : %zu\n", i);
	while (i < s->len)
	{
		//printf("ecart entre les deux : %d\n", s->a[i] - s->a[i+1]);
		if (s->a[i] > s->a[i + 1])
			return(0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (write(1, "KO\n", 3));
	if (!check_params(argc, argv))
		return (output_error(s));
	s_init(s, argc);
	if (!s_init(s, argc))
		return (0);
	array_fill(s, argv);
	//if (!check_duplicate(s))
	//	return (output_error(s));
	if (is_sorted(s))
	{
		free(s);
		return (0);
	}

	//quick(s);
	
	//////// SORT 
	printf("DEBUT\n");
    print_stack(s);

	/*if (argc == 3)
		sort_2(s); 
	else if (argc == 4)
		sort_3(s);
	else if (argc == 5)
		sort_4(s);
	else if (argc == 6)
		sort_5(s);
	else
		extraction_sort(s);  //// Attention len
*/
	radix(s);
	//print_stack(s);

	

	free(s);
}


