#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int check_type(char c, va_list ap);
int c_type(va_list ap);
int	s_type(va_list ap);
int	p_type(va_list ap);
int d_type(va_list ap);
int u_type(va_list ap);

size_t	ft_strlen(const char *s)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (*(s + i))
	{
		len++;
		i++;
	}
	return (len);
}

int	find_len(int n)
{
	int	len;

	len = 1;
	if (n < 0)
		len++;
	while (n / 10 != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	a;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n >= 0)
	{
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		a = n % 10 + '0';
		write(fd, &a, 1);
	}
}

void	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	char	a;

	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	a = n % 10 + '0';
	write(fd, &a, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	s_len;

	if (s == 0)
		return ;
	s_len = ft_strlen(s);
	if (s_len <= 2147483647)
		write(fd, s, s_len);
	while (s_len > 2147483647)
	{
		write(fd, s, 2147483647);
		s_len -= 2147483647;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		cnt;

	cnt = 0;
	va_start(ap, format);
	while (*format != 0)
	{
		if (*format == '%')
		{
			format++;
			cnt += check_type(*format, ap);
			if (*format == '%')
				format++;
		}
		else
		{
			write(1, format, 1);
			cnt++;
		}
		format++;
	}
	va_end(ap);
	return (cnt);
}

int percent_type(void)
{
	write(1, "%", 1);
	return (1);
}

int d_type(va_list ap)
{
	int d;

	d = va_arg(ap, int);
	ft_putnbr_fd(d, 1);
	return (find_len(d));
}

int u_type(va_list ap)
{
	unsigned int u;

	u = va_arg(ap, unsigned int);
	ft_putnbr_unsigned_fd(u, 1);
	return (find_len(u));
}


int	check_type(char c, va_list ap)
{
	if (c == 'c')
		return (c_type(ap));
	if (c == 's')
		return (s_type(ap));
	if (c == 'p')
		return (p_type(ap));
	if (c == 'd' || c == 'i')
		return (d_type(ap));
	if (c == 'u')
		return (u_type(ap));
	if (c == '%')
		return (percent_type());
	return (0);
}

int	c_type(va_list ap)
{
	char c;

	c = va_arg(ap, int);
	write(1, &c, 1);
	return (1);
}

int	s_type(va_list ap)
{
	char *s;

	s = va_arg(ap, char *);
	ft_putstr_fd(s, 1);
	return (ft_strlen(s));

}

int p_type(va_list ap)
{
	void *p;

	p = va_arg(ap, void *);
	if (p == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	// write(1, "0x0", 3);
	return (0);
}

int main()
{ 
	int a;
	a = ft_printf("%%");
	printf("\n%d", a);
	return (0);
}