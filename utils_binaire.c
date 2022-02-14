/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_binaire.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:23:51 by pamartin          #+#    #+#             */
/*   Updated: 2022/02/09 20:25:19 by pamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    div_2(int nb)
{
    int i;

    i = 1;

    while (nb / 2 > 0)
    {
        i *= 2;
        nb = nb / 2;
    }
    return (i);
}

int binary_convert(int nb)
{
    int binary;
    int n;
    int i;

    i = div_2(nb);
    n = 0;
    binary = 0;
    while (i != 0)
    {
        n = nb / i;
        nb = nb % i;
        i = i / 2;
        binary *= 10;
        binary += n;
    }
    return (binary);
}

/*
int main(int argc, char **argv)
{
    int binary;

    binary = binary_convert(atoi(argv[1]));

    printf("nb base 10 = %d\n", atoi(argv[1]));
    printf("nb base 2  = %d\n", binary);
    
}*/
