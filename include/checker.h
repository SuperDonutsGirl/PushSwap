/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:55:44 by pamartin          #+#    #+#             */
/*   Updated: 2022/04/04 14:55:45 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include "../include/get_next_line.h"

typedef struct s_stack
{
	int		argc;
	char	**av;
	int		ac;
	int		len_str;
	int		*a;
	int		*b;
	int		len;
	int		len_a;
	int		len_b;
}	t_stack;

//Utils
int		ft_isdigit(char c);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
void	*free_split(char **split);
int		no_duplicate(t_stack *s, int nb, int i);
int		output_error(t_stack *s, int error);
//Check params
int		check_params(int argc, char **argv, t_stack *s);
int		check_duplicate(t_stack *s);
int		is_sorted(t_stack *s);
// Swap
void	swap_a(t_stack *s);
void	swap_b(t_stack *s);
void	swap_ab(t_stack *s);
// Push
void	push_a(t_stack *s);
void	push_b(t_stack *s);
// Rotate
void	rotate_a(t_stack *s);
void	rotate_b(t_stack *s);
void	rotate_ab(t_stack *s);
// Reverse
void	reverse_a(t_stack *s);
void	reverse_b(t_stack *s);
void	reverse_ab(t_stack *s);
//Get mvt
char	*get_next_line(int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
