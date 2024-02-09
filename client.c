/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsidqi <nsidqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:24:42 by nsidqi            #+#    #+#             */
/*   Updated: 2024/01/19 14:46:37 by nsidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	*ft_change(int *j, char av, int *res)
{
	int	h;

	h = 7;
	while (h >= 0)
	{
		res[*j] = (av >> h) & 1;
		(*j)++;
		h--;
	}
	return (res);
}

void	ft_send(int *res, int j, char *av)
{
	int	h;

	h = 0;
	while (h < j)
	{
		if (res[h] == 0)
		{
			if (kill(ft_atoi(av), SIGUSR1) < 0)
				exit(1);
		}
		else
		{
			if (kill(ft_atoi(av), SIGUSR2) < 0)
				exit(1);
		}
		usleep(500);
		h++;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	*res;
	int	j;

	if (ac == 1 || ft_atoi(av[1]) == 0 || ac > 3)
		write(1, "Wrong arguments, try again!\n", 29);
	else if (ac == 3 && av[2] != NULL)
	{
		res = malloc((ft_strlen(av[2]) * 8) * sizeof(int));
		if (res == NULL)
			exit(EXIT_FAILURE);
		i = 0;
		j = 0;
		while (av[2][i] != '\0')
		{
			res = ft_change(&j, av[2][i], res);
			i++;
		}
		ft_send(res, j, av[1]);
		free (res);
	}
	return (0);
}
