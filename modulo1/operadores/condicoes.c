#include <cs50.h>
#include <stdio.h>

int main (void)
{
    long x = get_long("x: ");

    long y = get_long("y: ");

    if (x < y)
    {
        printf("%ld é menor que %ld\n", x, y);
    }
    else
    {
        printf("%ld é menor que %ld\n", y, x);
    }
}
