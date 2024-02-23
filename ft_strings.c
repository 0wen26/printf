#include "ft_printf.h"
//funcion imprime char
int	ft_putchar(int c)
{
	//imprimir caracter por caracter
	write(1, &c, 1);
	//se devuelve 1 porque suma 1 caracter
	return (1);
}

// funcion imprime string
int	ft_putstr(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter])
	{
		ft_putchar(str[counter]);
		counter++;
	}
	//devolvemos el numero de caracteres que hemos imprimido
	return (counter);
}
