/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybachaki <ybachaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 19:15:18 by ybachaki          #+#    #+#             */
/*   Updated: 2022/04/04 02:57:21 by ybachaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

int		ft_atoi(const char *str);
void	ft_putchar(char c);
void	ft_putnbr(int n);
int		ft_isdigit(int c);
#endif
