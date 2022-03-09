#include "minitalk.h"
#include <stdio.h>

int	ft_atoi(const char *str)
{
	long int	num;
	int			i;
	long int	minus;

	minus = 1;
	i = 0;
	num = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (num * minus > 2147483647)
			return (-1);
		if (num * minus < -2147483648)
			return (0);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(minus * num));
}

void	send_signal(int bit, int pid)
{
	if (bit == 0)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			write(1, "Problem sending the signal!\n", 29);
			exit(1);
		}
		usleep(150);
	}
	if (bit == 1)
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			write(1, "Problem sending the signal!\n", 29);
			exit(1);
		}
		usleep(150);
	}
}

void	convert(int c, int pid)
{
	t_byte_struct	byte_char;

	*(unsigned char *)&byte_char = (unsigned char)c;
	printf("the address is: %d\n",byte_char.b8);
	send_signal(byte_char.b1, pid);
	send_signal(byte_char.b2, pid);
	send_signal(byte_char.b3, pid);
	send_signal(byte_char.b4, pid);
	send_signal(byte_char.b5, pid);
	send_signal(byte_char.b6, pid);
	send_signal(byte_char.b7, pid);
	send_signal(byte_char.b8, pid);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{ 
		pid = ft_atoi((const char *)argv[1]);
		if (pid == 0 || pid < 0)
		{
			write(1, "Invalid PID!\n", 13);
			return (0);
		}
		while (argv[2][i])
		{
			convert((int)argv[2][i], pid);
			i++;
		}
	}
	else
		write(1, "Usage: ./client [PID] [STRING_TO_PASS]\n", 40);
	return (0);
}