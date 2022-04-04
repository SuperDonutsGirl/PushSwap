/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:49:16 by pamartin          #+#    #+#             */
/*   Updated: 2022/04/04 14:49:18 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	output_error(t_stack *s)
{
	free(s);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
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
		s->b[i] = 0;
		i++;
		y++;
	}
	return (s);
}

void	exec_cmd(t_stack *s, char *line)
{
	if (!ft_strncmp(line, "sa\n", 3))
		swap_a(s);
	else if (!ft_strncmp(line, "sb\n", 3))
		swap_b(s);
	else if (!ft_strncmp(line, "ss\n", 3))
		swap_ab(s);
	else if (!ft_strncmp(line, "pa\n", 3))
		push_a(s);
	else if (!ft_strncmp(line, "pb\n", 3))
		push_b(s);
	else if (!ft_strncmp(line, "ra\n", 3))
		rotate_a(s);
	else if (!ft_strncmp(line, "rb\n", 3))
		rotate_b(s);
	else if (!ft_strncmp(line, "rr\n", 3))
		rotate_ab(s);
	else if (!ft_strncmp(line, "rra\n", 4))
		reverse_a(s);
	else if (!ft_strncmp(line, "rrb\n", 4))
		reverse_b(s);
	else if (!ft_strncmp(line, "rrr\n", 4))
		reverse_ab(s);
	else
		output_error(s);
}

void	read_exec_cmd(t_stack *s)
{
	char *line;

	line = get_next_line(0);
	while (line)
	{
		exec_cmd(s, line);
		get_next_line(0);
	}
}

int	is_sorted(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->len_a)
	{
		if (s->a[i] > s->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_stack *s;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (0);
	if (!check_params(argc, argv, s))
		output_error(s);
	if (!s_init(s, argc))
		return (0);
	if (s->ac == 2)
		s = array_fill(s, argv);
	else
		s = array_fill(s, argv);
	if (!check_duplicate(s))
		output_error(s);
	read_exec_cmd(s);
	if (is_sorted(s) && s->len_b == -1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
