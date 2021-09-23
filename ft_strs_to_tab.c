#include <stdlib.h>
#include "ft_stock_str.h"

int ft_strlen2(char *str);
char *ft_strdup(char *src);

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
   int i;
   t_stock_str *result;

   i = 0;
   result = malloc(sizeof(t_stock_str) * (ac + 1));
   if(result == NULL)
       return NULL;
   while(i < ac)
   {
       result[i].size = ft_strlen2(av[i]);
       result[i].str = av[i];
       result[i].copy = ft_strdup(av[i]);
       i++;
   }
   result[i].str = 0;
   return (result);
}

int ft_strlen2(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
        i++;
    return (i);
}

char *ft_strdup(char *src)
{
    int i;
    char *dst;

    i = 0;
    dst = (char *)malloc(ft_strlen2(src) + 1);
    if(dst == NULL)
        return NULL;
    while(src[i] != '\0')
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (dst);
}
