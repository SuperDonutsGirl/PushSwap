/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 03:08:07 by pamartin          #+#    #+#             */
/*   Updated: 2022/02/05 03:08:12 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int		argc;
	char	**av;
	int		ac;
	int		len_str;
	int		*a;
	int		*b;
	int		*sort;
	int		*chunck;
	int		shift;
	int		len;
	int		len_a;
	int		len_b;
	int		num;
}	t_stack;

// Utils 
int		ft_isdigit(char c);
int		ft_atoi(const char *str);
int		ft_strlen(const char *s);
int		output_error(t_stack *s);
int		no_duplicate(t_stack *s, int nb, int i);
// Utils Check
int		check_params(int argc, char **argv, t_stack *s);
int		check_duplicate(t_stack *s);
int		is_sorted(t_stack *s);
char	**ft_split(char const *s, char c);
int		check_split_argv(char **argv, t_stack *s);
int		check_is_valid(char **arg);
// Utils Found
int		found_min(int len_s, int *stack);
int		found_last_zero(t_stack *s);
// Swap
void	swap_a(t_stack *s);			//sa
void	swap_b(t_stack *s);			//sb
void	swap_ab(t_stack *s);		//ss
// Push
void	push_a(t_stack *s);			//pa
void	push_b(t_stack *s);			//pb
// Rotate
void	rotate_a(t_stack *s);		//ra   vers le haut
void	rotate_b(t_stack *s);		//rb
void	rotate_ab(t_stack *s);		//rr
// Reverse
void	reverse_a(t_stack *s);		//rra	vers le bas
void	reverse_b(t_stack *s);		//rrb
void	reverse_ab(t_stack *s);		//rrr
// Sort Litlle
void	sort_2(t_stack *s);
void	sort_3(t_stack *s);
void	sort_4(t_stack *s);
void	sort_5(t_stack *s);
// Sort Extraction
void	extraction_sort(t_stack *s);
// Sort Radix
void	radix(t_stack *s);
void	quick_sort(int *tab, int start, int end);
// Print stack
void	print_stack(t_stack *s);

#endif