/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsidqi <nsidqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:10:37 by nsidqi            #+#    #+#             */
/*   Updated: 2024/01/31 15:14:16 by nsidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	ft_s(char (*t)[4])
{
	int	s;

	s = 8;
	if ((*t)[0] == '1' && (*t)[1] == '1' && (*t)[2] == '1' && (*t)[3] == '1')
		s = 32;
	else if ((*t)[0] == '1' && (*t)[1] == '1'
			&& (*t)[2] == '1' && (*t)[3] == '0')
		s = 24;
	else if ((*t)[0] == '1' && (*t)[1] == '1'
			&& (*t)[2] == '0' && (*t)[3] == '0')
		s = 16;
	else
		s = 8;
	return (s);
}

void	less(int num, char chara, int i, char (*t)[4])
{
	if (num == 32 || num == 24 || num == 16)
	{
		if (i == 8)
			(*t)[0] = chara;
		else if (i == 16 && (num == 32 || num == 24 || num == 16))
			(*t)[1] = chara;
		else if (i == 24 && (num == 32 || num == 24))
			(*t)[2] = chara;
		else if (i == 32 && num == 32)
			(*t)[3] = chara;
	}
}

int	ft_helper(int sig, char *chara, int pid, char (*tab)[4])
{
	static int	pid_old;
	static int	i = 0;
	static int	num = -1;

	if (pid_old != pid)
	{
		clear(&i, &num, *tab, *chara);
		pid_old = pid;
	}
	*chara = (*chara << 1) | (sig - SIGUSR1);
	i++;
	if (i == 4)
		num = ft_s(tab);
	less(num, *chara, i, tab);
	if (i == 8 && num == 8)
	{
		end_1(*chara, pid);
		clear(&i, &num, *tab, *chara);
	}
	else if (i == num)
	{
		end_2(*chara, pid, *tab);
		clear(&i, &num, *tab, *chara);
	}
	return (i);
}

void	ft_get(int sig, siginfo_t *info, void *content)
{
	static char	chara;
	static char	tab[4];
	static int	i;

	(void)content;
	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		if (sig == SIGUSR1 || i > 4)
			tab[i] = '0';
		else if (sig == SIGUSR2 || i > 4)
			tab[i] = '1';
		i++;
		i = ft_helper(sig, &chara, info->si_pid, &tab);
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	sa.sa_sigaction = ft_get;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		pause();
	return (0);
}
