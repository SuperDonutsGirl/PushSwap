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


#define EXIT_SUCCES 0 
typedef struct s_stack
{
	int	argc;
	int	*a;
	int	*b;
	int	*sort;
	int	*chunck; 
	int	*chunck_b; 
	int	shift;
	int	len;
	int	len_a;
	int	len_b;
	int	num;

}	t_stack;

// Utils check
int		ft_isdigit(char c);
int		ft_atoi(const char *str);
int		ft_strlen(const char *s);
int 	output_error(t_stack *s);
int 	no_duplicate(t_stack *s, int nb, int i);
int		is_sorted(t_stack *s);
// Found utils
int		found_min(int len_s, int *stack);
// Swap
void    swap_a(t_stack *s); 		//sa
void    swap_b(t_stack *s);			//sb
void    swap_ab(t_stack *s);		//ss
// Push
void    push_a(t_stack *s);		//pa
void    push_b(t_stack *s);		//pb
// Rotate
void    rotate_a(t_stack *s);		//ra   vers le haut
void    rotate_b(t_stack *s);		//rb
void    rotate_ab(t_stack *s);		//rr
// Reverse
void    reverse_a(t_stack *s);		//rra	vers le bas
void    reverse_b(t_stack *s);		//rrb
void    reverse_ab(t_stack *s);	//rrr
// Sort
void	sort_2(t_stack *s);
void	sort_3(t_stack *s);
void	sort_4(t_stack *s);
void	sort_5(t_stack *s);
void	extraction_sort(t_stack *s);
void	radix(t_stack *s);
// Utils sort 4
void    min_start(t_stack *s);
void	max_start(t_stack *s);
void	min_end(t_stack *s);
void	max_min_middle(t_stack *s);
void	min_max_end(t_stack *s);
// Quick
void	quick_sort(int  *tab, int start, int end);
int		partition(int *tab, int start, int end);
int    	quick(t_stack *s);
void    ft_swap(int *tab, int i, int x);
// Radix mvt
void    rotate_a_target(t_stack *s,  int *stack_a);
void    reverse_a_target(t_stack *s,  int *stack_a);
void    push_b_target(t_stack *s, int *stack_a, int *stack_b);
void    push_a_target(t_stack *s, int *stack_a, int *stack_b);
// Radix found
int		only_one(t_stack *s);//
int		only_zero(t_stack *s);//
int		found_zero(t_stack *s);//
int	found_last_zero(t_stack *s);
// Radix tab
void	chunck_tab(t_stack *s);


// Print stack
void	print_stack(t_stack *s);



#endif