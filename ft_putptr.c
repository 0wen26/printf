#include "ft_printf.h"

//longitud del numero
int	ft_putlen(unsigned long long ptr)
{
	int	counter;

	counter = 0;
	while (ptr != 0)
	{
		counter++;
		//se divide 16 porque es hexadecimal
		ptr = ptr / 16;
	}
	return (counter);
}

//funcion para imprimir numeros hexa
void	ft_putp(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		ft_putp(ptr / 16);
		ft_putp(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
		{
			ft_putchar(ptr + '0');
		}
		else
			//se resta 10 y suma a (97) para conseguir la letra en hexa
			ft_putchar(ptr -10 + 'a');
	}
}

int	ft_putptr(unsigned long long ptr)
{
	int	counter;

	counter = 0;
	//imprimimos 0x hexadecimal
	counter += write(1, "0x", 2);
	if (ptr == 0)
		counter += write(1, "0", 1);
	else
	{
		//imprime caracteres hex
		ft_putp(ptr);
		//Contamos caracteres
		counter += ft_putlen(ptr);
	}
	return (counter);
}
