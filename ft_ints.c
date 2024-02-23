#include "ft_printf.h"

//imprime el int
int	ft_putnbr(int nbr)
{
	int		counter;
	char	*number;

	//se usa itoa para pasar de int a str
	number = ft_itoa(nbr);
	counter = ft_putstr(number);
	//liberamos la memoria
	free(number);
	return (counter);
}

//imprime unsigned int
int	ft_putnbrunsig(unsigned int nbr)
{
	int		counter;
	char	*number;

	//se usa unitoa para pasar unsigned int a str
	number = ft_unitoa(nbr);
	counter = ft_putstr(number);
	// liberamos memoria
	free(number);
	return (counter);
}
