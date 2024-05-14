/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:47:10 by aidgomez          #+#    #+#             */
/*   Updated: 2023/02/15 21:47:10 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Acceso a los args de una función cuando tiene un nº variable de args:
va_arg(va_list arg_ptr, type): Devuelve el arg actual.
	arg_ptr: Puntero a la lista de args. Debe tener el tipo va_list.
	type: Tipo de arg que se va a recuperar.
va_start(va_list arg_ptr, prev_param): Establece arg_ptr en el 1º arg opcional.
	prev_param: Parámetro que precede al primer arg opcional.
va_end(va_list arg_ptr): Restablece el puntero a NULL.
	Hay que llamarlo en cada lista de args que se inicialice con va_start o va_copy 
	antes de que la función devuelva su resultado.
*/

#include "ft_printf.h"

int	ft_argindex(va_list arg_ptr, char str, int i)
{
	if (str == 'c')
		i += ft_printchar(va_arg(arg_ptr, int));
	else if (str == 's')
		i += ft_printstr(va_arg(arg_ptr, char *));
	else if (str == 'p')
		i += ft_printptr(va_arg(arg_ptr, unsigned long));
	else if (str == 'd' || str == 'i')
		i += ft_putnbr(va_arg(arg_ptr, int));
	else if (str == 'u')
		i += ft_putnbr2(va_arg(arg_ptr, unsigned int));
	else if (str == 'x')
		i += ft_printhex(va_arg(arg_ptr, unsigned int), 0);
	else if (str == 'X')
		i += ft_printhex(va_arg(arg_ptr, unsigned int), 1);
	else if (str == '%')
		i += ft_printchar('%');
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg_ptr;
	int		i;
	int		unit;
	int		count;

	va_start (arg_ptr, str);
	i = 0;
	unit = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			unit += ft_argindex(arg_ptr, str[i + 1], count);
			i++;
		}
		else
			unit += ft_printchar(str[i]);
		i++;
	}
	va_end(arg_ptr);
	return (unit);
}
