#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
void ft_putchar(char c)
{
	//imprimir caracter por caracter
	write(1, &c, 1);
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
			
		
		ft_putchar(str[i]);
		i++;
	}
	va_end(arguments);
	
	return (0);
}

int main()
{
	ft_printf("Hola que %s tal","laura");
	return (0);
}
