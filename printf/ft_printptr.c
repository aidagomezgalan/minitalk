/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:32:46 by aidgomez          #+#    #+#             */
/*   Updated: 2023/03/10 14:39:33 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr(unsigned long ptr)
{
	int	i;

	i = 2;
	write (1, "0x", 2);
		i += ft_printhex(ptr, 0);
	return (i);
}
