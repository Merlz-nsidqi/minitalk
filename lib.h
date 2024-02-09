/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsidqi <nsidqi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:15:50 by nsidqi            #+#    #+#             */
/*   Updated: 2024/01/31 15:15:09 by nsidqi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_atoi(char *str);
int		ft_strlen(char *str);
void	ft_putnbr(int nb);
void	end_1(char chara, int pid);
void	end_2(char chara, int pid, char *tab);
void	clear(int *i, int *num, char *tab, char chara);

#endif
