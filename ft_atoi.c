/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenkrar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:59:57 by abenkrar          #+#    #+#             */
/*   Updated: 2024/11/24 00:15:02 by abenkrar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(char **str)
{
	int	resultat;

	resultat = 0;
	while (**str >= '0' && **str <= '9')
	{
		resultat = resultat * 10;
		resultat = resultat + **str - '0';
		(*str)++;
	}
	return (resultat);
}
