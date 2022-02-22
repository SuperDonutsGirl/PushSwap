/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_quick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:46:10 by pamartin          #+#    #+#             */
/*   Updated: 2022/02/08 21:46:15 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *tab, int i, int x)
{
	int	tmp;

	tmp = tab[i];
	tab[i] = tab[x];
	tab[x] = tmp;
}

int	partition(int *tab, int start, int end)
{
	int	pivot;
	int	top;
	int	down;

	pivot = tab[start];
	top = start + 1;
	down = end;
	while (1)
	{
		while (top <= down && tab[down] >= pivot)
			down--;
		while (top <= down && tab[top] <= pivot)
			top++;
		if (top <= down)
			ft_swap(tab, top, down);
		else
			break ;
	}
	ft_swap(tab, start, down);
	return (down);
}

void	quick_sort(int *tab, int start, int end)
{
	int	p;

	if (start >= end)
		return ;
	p = partition(tab, start, end);
	quick_sort(tab, start, p - 1);
	quick_sort(tab, p + 1, end);
}
