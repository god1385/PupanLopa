#include "minitalk.h"
#include "stdio.h"

void	ft_putnbr(int n)
{
	char	c;

	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
	}
}

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

void	convert(int c, int pid)
{
	int	i;
	//int	mass[8];

	// i = 0;
	// while (c > 0)
	// {
	// 	if (c % 2 == 1)
	// 		mass[7 - i] = 1;
	// 	else
	// 		mass[7 - i] = 0;
	// 	c /= 2;
	// 	i++;
	// }
	i = 8;
	while (--i >= 0)
	{
		if (c >> i & 1)
		{
			kill(pid, SIGUSR1);
			usleep (5000);
		}
		else
		{
			// printf("s\n", c);
			// printf("0");
			kill(pid, SIGUSR2);
			usleep (5000);
		}
	}
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	handler(int sig, siginfo_t *info, void *context)
{
	static int	counter = 0;

	(void)context;
	(void)info;
	if (sig == SIGUSR1)
	{
		counter++;
		//printf("%d\n", counter);
	}
	else if (sig == SIGUSR2)
	{
		counter++;
		//printf("1");
		write(1, "Letters received : ", ft_strlen("Letters received : "));
		ft_putnbr(counter);
		write(1, "\n", 1);
		exit(0);
	}
	usleep(5000);
}

int	main(int argc, char **argv)
{
	struct sigaction	a;
	int					pid;
	int					i;

	a.sa_flags = SA_SIGINFO;
	a.sa_sigaction = handler;
	sigaction(SIGUSR1, &a, 0);
	sigaction(SIGUSR2, &a, 0);
	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
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
		convert(0, pid);
		while (1)
			pause();
	}
	else
		write(1, "Usage: ./client [PID] [STRING_TO_PASS]\n", 40);
	return (0);
}