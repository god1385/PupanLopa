#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h> // Библиотека для макросов

void	function(int a, int b, int c)
{
	printf("%d %d %d\n", &a, &b, &c);  	// Вызываем адрес ячейки памяти.
	int *ptr = &a - 1;					// Объявляем переиенную и придаем ей значение переменной значение соседней ячейки
	printf("%d\n", *(ptr--));
	printf("%d\n", *(ptr--));
}

double summa(int count, ...)			// Первый вариант //
{
	double	res = 0;
	double	*ptr = &count + 1;			// Переменной ptr приравнивается значение из след. ячейки памяти после count
	while (count-- > 0)
		res += *(ptr++);				// Двигаемся по значениям ячеек памяти пока наш счетчик не будет равен 0
	return (res);
}

double va_summa(int count, ...)			// Второй вариант //
{
	double	res = 0;
	va_list	ptr;						// Тип данных для указателя(?)
	va_start(ptr, count);				// Инициализирует наш указатель, 2ой аргумент указывает откуда начинает
	while (count-- > 0)
		res += va_arg(ptr, double);		// Возвращает текущее значение данного типа и длает шаг в след переменную 
	va_end(ptr);						// Нужен для корректного завершения макроса 
	return (res);
}

void mega_printf(char *params, ...)
{
	va_list	ptr;
	va_start(ptr, params);
	while (*params)										// "Пока указатель на строке"
	{
		if (*params == 'i')								// Если указатель равен первому символу
			printf("--%d--\n", va_arg(ptr, int));		// Написать значение указанного типа и сделать шаг
		else if (*params == 'd')
			printf("--%f--\n", va_arg(ptr, double));	// Написать значение указанного типа и сделать шаг
		else if (*params == 'c')
			printf("--%c--\n", va_arg(ptr, int));		// Написать значение указанного типа и сделать шаг
		else if (*params == 's')
			printf("--%s--\n", va_arg(ptr, char*));		// Написать значение указанного типа и сделать шаг
		printf("--%s--\n", params);
		params++;										// сдигаем массив
	}
	va_end(ptr);			// Все гуд, но есть одно НО!, если переменные стоят в другом порядке от порядка 
}							// букв в переменной "isdc", то ничего не работает

int	main()
{
	mega_printf("isdc", 111, "Huitu ya napisal", 22.3, 's');
	return (0);
}
