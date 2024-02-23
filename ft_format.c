#include "ft_printf.h"

//funcion para decidir los formatos que imprime los agurmentos
int	ft_format(va_list arguments, char format)
{
	int	counter;

	counter = 0;
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
		counter += ft_putnbrunsig(va_arg(arguments, unsigned int));
	//else if (format == 'x' || format == 'X' )
		//se imprime un numero hexadecimal en minusculas o mayusculas.
		//counter += ft_puthex(va_arg(arguments, unsigned int), format);
	else if (format == '%')
		//se imprime el %
		counter += ft_putchar('%');
	//se devuelve el numero de caracteres imprimidos.
	return (counter);
}
