#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"
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
	else if (format == 'p')
		//se imrpime puntero void en hexadecimal( ni idea aun )
		counter += ft_putptr(va_arg(arguments, unsigned long long));
	else if (format == 'd' || format == 'i')
		//se imprime un numero decimal (base 10)
		counter += ft_putnbr(va_arg(arguments, int));
	else if (format == 'u')
		//se imprime un numero decimal unsigned (base 10)
		counter += ft_putnbrunsig(va_arg(arguments,unsigned int));
	else if (format == 'x' || format == 'X' )
		//se imprime un numero hexadecimal en minusculas o mayusculas.
		counter += ft_put_print_hex(va_arg(arguments, unsigned int), format);
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
/*
int main()
{
    
    //tests mios
    ft_printf("\n NULL %s NULL ", NULL);
    ft_printf("\n2 %p %p ", 0, 0);
    ft_printf("\n 1 %u ", -1);
    ft_printf("\n 2 %u ", -9);
    ft_printf("\n 3 %u ", -10);
    ft_printf("\n 4 %u ", -11);
    ft_printf("\n 5 %u ", -14);
    ft_printf("\n 6 %u ", -15);
    ft_printf("\n 7 %u ", -16);
    ft_printf("\n 8 %u ", -99);
    ft_printf("\n 9 %u ", -100);
    ft_printf("\n 10 %u ", -101);
    ft_printf("\n 11 %u ", INT_MIN);
    ft_printf("\n 12 %u ", LONG_MAX);
    ft_printf("\n 13 %u ", UINT_MAX);
    ft_printf("\n 14 %u ", ULONG_MAX);
    ft_printf("\n 15 %u ", 9223372036854775807LL);
    ft_printf("\n %u ", 0);
    ft_printf("\n %u ", LONG_MIN);
    ft_printf("\n %u %u %u %u %u %u %u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    printf("\n news");
    ft_printf("\n %x ", 0);
    ft_printf("\n %x ", LONG_MIN);
    int caca = ft_printf("\n %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    printf("\n%i", caca);
    //tests buenos
    printf("\n NULL %s NULL ", NULL);
    printf("\n2 %p %p ", 0, 0);
    printf("\n3 %u ", -1);
    printf("\n4 %u ", -9);
    printf("\n5 %u ", -10);
    printf("\n6 %u ", -11);
    printf("\n7 %u ", -14);
    printf("\n8 %u ", -15);
    printf("\n9 %u ", -16);
    printf("\n10 %u ", -99);
    printf("\n11 %u ", -100);
    printf("\n12 %u ", -101);
    printf("\n13 %u ", INT_MIN);
    printf("\n14 %u ", LONG_MAX);
    printf("\n15 %u ", UINT_MAX);
    printf("\n16 %u ", ULONG_MAX);
    printf("\n17 %u ", 9223372036854775807LL);
    printf("\n %U ", 0);
    printf("\n %u ", LONG_MIN);
    printf("\n %u %u %u %u %u %u %u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    printf("\n news");
    printf("\n %x ", 0);
    printf("\n %x ", LONG_MIN);
    int size = printf("\n %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    printf("\n %i", size);
    return (0);
    
}
*/


