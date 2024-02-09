/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsidqi <nsidqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:12:41 by nsidqi            #+#    #+#             */
/*   Updated: 2024/01/31 15:17:19 by nsidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	clear(int *i, int *num, char *tab, char chara)
{
	int	j;

	j = 0;
	while (tab[j])
		tab[j++] = 0;
	*i = 0;
	chara = 0;
	*num = -1;
}

void	end_1(char chara, int pid)
{
	write(1, &chara, 1);
	if (chara == '\0')
	{
		if (kill(pid, SIGUSR1) < 0)
			exit(1);
	}
}

void	end_2(char chara, int pid, char *tab)
{
	write(1, tab, 4);
	if (chara == '\0')
	{
		if (kill(pid, SIGUSR1) < 0)
			exit(1);
	}
}
