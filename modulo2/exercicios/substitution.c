#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Uso: ./ chave de substituição\n");
        return 1;
    }

    char *arg = argv[1];

    int chave_length = strlen(argv[1]);

    if (chave_length != 26)
    {
        printf("A chave deve conter 26 caracteres.\n");
    }

    for (int i = 0; i < chave_length; i++)
    {
        if (!isalpha(arg[i]) || isdigit(arg[i]))
        {
            printf("Uso: ./ chave de substituição\n");
            return 1;
        }
        for (int j = i + 1; j < 26; j++)
        {
            if (tolower(arg[i]) == tolower(arg[j]))
            {
                printf("A chave não pode conter letras repetidas.\n");
                return 1;
            }
        }
    }

    string plain_text = get_string("Texto simples: ");

    int text_length = strlen(plain_text);

    for (int i = 0; i < text_length; i++)
    {
        if (isalpha(plain_text[i]))
        {
            char base = islower(plain_text[i]) ? 'a' : 'A';
            int index = tolower(plain_text[i]) - 'a';
            plain_text[i] = islower(plain_text[i]) ? tolower(argv[1][index]) : toupper(argv[1][index]);
        }
    }

    printf("ciphertext: %s\n", plain_text);

    return 0;
}