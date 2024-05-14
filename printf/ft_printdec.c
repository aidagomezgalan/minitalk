/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidgomez <aidgomez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:48:49 by aidgomez          #+#    #+#             */
/*   Updated: 2023/03/10 14:48:49 by aidgomez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_length_nbr(long n)
{
	int	length;

	length = 0;
	if (n == 0)
		length = 1;
	else if (n < 0)
	{
		n *= -1;
		length++;
	}
	while (n > 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char		*str;
	long		nbr;
	int			length;

	length = ft_length_nbr(n);
	nbr = n;
	str = malloc (sizeof(char) * (length + 1));
	if (!str)
		return (NULL);
	str[length--] = '\0';
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	while (nbr > 0)
	{
		str[length--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}

int	ft_putnbr(int nb)
{
	char	*str;
	int		count;

	str = ft_itoa(nb);
	count = ft_printstr(str);
	free (str);
	return (count);
}

char	*ft_itoa2(unsigned int n)
{
	char		*str;
	long		nbr;
	int			length;

	length = ft_length_nbr(n);
	nbr = n;
	str = malloc (sizeof(char) * (length + 1));
	if (!str)
		return (NULL);
	str[length--] = '\0';
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	while (nbr > 0)
	{
		str[length--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}

int	ft_putnbr2(unsigned int nb)
{
	char	*str;
	int		count;

	str = ft_itoa2(nb);
	count = ft_printstr(str);
	free (str);
	return (count);
}
