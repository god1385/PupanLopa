#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void ft_char(t_print *tab, char f)
{
    char  c;

  if (f == '%')
    tab->tl += write(1, "%", 1);
  if (f == 'c')
  {
    c = va_arg(tab->args, int);
    while (tab->wdt-- > 1 && tab->dash == 0)
        tab->tl += write(1, " ", 1);
    tab->tl += write(1, &c, 1);
    while (tab->wdt-- > 0 && tab->dash == 1)
        tab->tl += write(1, " ", 1);
  }

}

void ft_string(t_print *tab)
{
    char *string;
    int i;
        
    i = 0;
    string = va_arg(tab->args, char *);
    if (!string)
     string = "(null)";
    while (tab->wdt-- > ft_strlen(string) && !tab->dash)
        tab->tl += write(1, " ", 1);
     while (string[i])
        tab->tl += write(1, &string[i++], 1);
    while (tab->wdt-- > ft_strlen(string)  && tab->dash)
        tab->tl += write(1, " ", 1);
}

void    ft_pointer(t_print *tab)
{
    unsigned long n;

    n = (unsigned long)va_arg(tab->args, void *);
    while (tab->wdt-- > 11 && !tab->dash)
        tab->tl += write(1, " ", 1);
    tab->tl += write(1, "0x", 2);
    tab->tl += ft_putnbr_base(n, "0123456789abcdef");
     while (tab->wdt-- > 11 && tab->dash)
        tab->tl += write(1, " ", 1);
}