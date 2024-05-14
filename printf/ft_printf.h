/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 12:07:07 by aidgomez          #+#    #+#             */
/*   Updated: 2023/03/10 15:24:29 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

//Constantes para ft_printhex
# define HEX_LOWERCASE "0123456789abcdef"
# define HEX_UPPERCASE "0123456789ABCDEF"

//%c imprime carácter
int		ft_printchar(int c);

//%s imprime string
int		ft_printstr(char *str);

//%d %i imprime decimal o entero
int		ft_putnbr(int nb);

//%u imprime decimal (base 16)
int		ft_putnbr2(unsigned int nb);

//%p imprime puntero (hexadecimal lowercase)
int		ft_printptr(unsigned long ptr);

//%x %X imprime hexadecimal (base 16)
int		ft_printhex(unsigned long long n, int base);

//Función printf()
int		ft_printf(const char *str, ...);

#endif