#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    string number = get_string("Número: ");
    int size = strlen(number);
    long produto[size];
    long somaDigitos = 0;

    long *n = malloc(size * sizeof(long));

    if (n == NULL)
    {
        printf("Erro na alocação de memória.\n");
    }

    for (int i = 0; i < size; i++)
    {
        n[i] = number[i] - '0';
    }

    //printf("Number: \n");

    //for (int i = 0; i < size; i++)
    //{
       // printf("%ld ", n[i]);
    //}

    //printf("\n");

    for (int i = size - 2; i >= 0; i -= 2)
    {
        produto[i] = n[i] * 2;
    }

    for (int i = 0; i < sizeof(produto) / sizeof(produto[0]); i++)
    {
        int numero = produto[i];
        while (numero != 0)
        {
            int digito = numero % 10;
            somaDigitos += digito;
            numero /= 10;
        }
    }

    for (int i = 1; i < size; i += 2)
    {
        somaDigitos += n[i];
    }

    int ultimoDigito = somaDigitos % 10;

    if (ultimoDigito > 0)
    {
        printf("Número Inválido");
        printf("\n");
    }
    else if ((size == 13 || size == 16) && n[0] == 4)
    {
        printf("VISA\n");
    }
    else if (size == 15 && n[0] == 3 && (n[1] == 4 || n[1] == 7))
    {
        printf("AMEX\n");
    }
    else if (size == 16 && n[0] == 5 && (n[1] >= 1 && n[1] <= 5))
    {
        printf("MASTERCARD\n");
    }



    free(n);

    return 0;
}
