#include "ft_printf.h"

//longitud del numero
static int	ft_put_len(unsigned int nbr)
{
	int	counter;

	counter = 0;
	while (nbr != 0)
	{
		counter++;
		//se divide 16 porque es hexadecimal
		nbr = nbr / 16;
	}
	return (counter);
}

//funcion para imprimir numeros hexa
static void	ft_put_hex(unsigned int nbr, const char format)
{
	if (nbr >= 16)
	{
		ft_put_hex(nbr / 16, format);
		ft_put_hex(nbr % 16, format);
	}
	else
	{
		if (nbr <= 9)
		{
			//si es menor de 9 imprime num
			ft_putchar(nbr + '0');
		}
		else
			//decide la letra si mayuscula o minuscula
			if (format == 'x')
				ft_putchar(nbr -10 + 'a');
			if (format == 'X')
				ft_putchar(nbr -10 + 'A');
	}
}

int	ft_put_print_hex(unsigned int nbr, const char format)
{
	//si es 0 imprimimos 0
	if (nbr == 0)
		ft_putchar('0');
	else
		ft_put_hex(nbr, format);
	return (ft_put_len(nbr));
}
