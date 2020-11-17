#include "ft_printf.h"
#include <stdio.h>

#define PARAMS "[%*x]",-20,2147483647
int     main()
{
    ft_printf(PARAMS);
    printf(PARAMS);
}