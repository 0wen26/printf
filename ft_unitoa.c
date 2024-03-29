/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rherraiz <rherraiz@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:14:53 by rherraiz          #+#    #+#             */
/*   Updated: 2024/02/23 03:29:37 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_string(char *str, unsigned int len, unsigned int n)
{
	while (n > 0)
	{
		str[len--] = '0' + (n % 10);
		n = n / 10;
	}
}

static int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_unitoa(unsigned int n)
{
	char			*str;
	unsigned int	number;
	unsigned int	len;

	len = ft_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	number = (unsigned int)n;
	ft_string(str, len -1, number);
	return (str);
}
