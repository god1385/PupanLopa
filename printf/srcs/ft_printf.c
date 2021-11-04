#include "../includes/ft_printf.h"
#include "../libft/libft.h"

t_print *ft_initialise_tab(t_print *tab)                       
{
      tab->wdt = 0;
      tab->tl = 0;
      tab->dash = 0;
      return (tab);
}

int ft_printf(const char *format, ...)
{
   int i;
   int ret;
   t_print *tab;
                       
   tab = (t_print *)malloc(sizeof(t_print));                        
   if (!tab)                         
       return (-1);
   ft_initialise_tab(tab);
   va_start(tab->args, format);
   i = -1;
   ret = 0;
   if (!format[0])
    return (0);
   while (format[++i])
   { 
      if (format[i] == '%')
         i = ft_format(tab, format, i + 1);
      else
         ret += write(1, &format[i], 1);
    }
    ret += tab->tl;
    va_end(tab->args);
    free (tab);
    return (ret);
}