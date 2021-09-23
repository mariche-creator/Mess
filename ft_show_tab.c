#include <unistd.h>
#include "ft_stock_str.h"

void ft_putstr(char *str);
void ft_putnbr(int nbr);

void ft_show_tab(struct s_stock_str *par)
{
    int i;

    i = 1;
    while (par[i].str != 0)
    { 
        ft_putstr(par[i].str);
        write(1, "\n", 1);
        ft_putnbr(par[i].size);
        write(1, "\n", 1);
        ft_putstr(par[i].copy);
        write(1, "\n", 1);
        i++;
    }
}

void ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
}

void ft_putnbr(int nbr)
{
    char temp;
    
    if(nbr == -2147483648)
    {
        write(1, "-2147483648", 11);
        return;
    }
    if (nbr < 0)
    {
        write(1, "-", 1);
        nbr *= -1;
    }   
    if (nbr >= 10)
    {
        temp = nbr % 10 + '0';
        ft_putnbr(nbr / 10);
        write(1, &temp, 1);
    }
    if (nbr < 10)
    {
        temp = nbr % 10 + '0';
        write(1, &temp, 1);
    }
}
