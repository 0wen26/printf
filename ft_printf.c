#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "libft.h"
//funcion imprime char
int ft_putchar(int c)
{
	//imprimir caracter por caracter
	write(1, &c, 1);
	//se devuelve 1 porque suma 1 caracter
	return (1);
}

// funcion imprime string
int ft_putstr(char *str)
{
	int counter;
	counter = 0;

	while (str[counter])
	{
		ft_putchar(str[counter]);
		counter++;
	}
	//devolvemos el numero de caracteres que hemos imprimido
	return (counter);
}

//imprime el int
int ft_putnbr(int nbr)
{
	int counter;
	char *number;
	
	//se usa itoa para pasar de int a str
	number = ft_itoa(nbr);
	counter = ft_putstr(number);
	//liberamos la memoria
	free(number);
	return (counter);
}

//imprime unsigned int
int ft_putnbrunsig(unsigned int nbr)
{
	int counter;
	char *number;

	//se usa unitoa para pasar unsigned int a str
	number = ft_unitoa(nbr);
	counter = ft_putstr(number);
	// liberamos memoria
	free(number);
	return (counter);
}

//funcion para decidir los formatos que imprime los agurmentos
int ft_format(va_list arguments, char format)
{
	int counter = 0;

	//definimos las condiciones
	if (format == 'c')
		//imprimimos caracter
		counter += ft_putchar(va_arg(arguments, int));
	else if (format == 's')
		//imprimimos string
		counter += ft_putstr(va_arg(arguments, char *));
//	else if (format == 'p')
		//se imrpime puntero void en hexadecimal( ni idea aun )
//		counter += ft_putptr(va_arg(arguments, unsigned long long));
	else if (format == 'd' || format == 'i')
		//se imprime un numero decimal (base 10)
		counter += ft_putnbr(va_arg(arguments, int));
	else if (format == 'u')
		//se imprime un numero decimal unsigned (base 10)
		counter += ft_putnbrunsig(va_arg(arguments,unsigned int));
	//else if (format == 'x' || format == 'X' )
		//se imprime un numero hexadecimal en minusculas o mayusculas.
		//counter += ft_puthex(va_arg(arguments, unsigned int), format);
	else if (format == '%')
		//se imprime el %
		counter += ft_putchar('%');
	//se devuelve el numero de caracteres imprimidos.
	return (counter);
}

int ft_printf(char const *str, ...)
{
	//variables
	int	i;
	int size;
	va_list arguments;

	// inicializar variables
	i = 0;
	size = 0;
	va_start(arguments, str);
	//bucle recorriendo argumentos
	while (str[i])
	{
		
		//si encontramos % miramos la siguiente posicion para decidir que hacer
		if (str[i] == '%')
		{
			// enviamos el siguiente caracter a % y los argumentos
			size += ft_format(arguments, str[i + 1]);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			size ++;
		}
		i++;
	}
	va_end(arguments);
	
	return (size);
}

int main()
{
	int size;
	size = ft_printf("Hola que %s tal %u","Hola", 55 );
	printf("\n%d",size);
	return (0);
}
