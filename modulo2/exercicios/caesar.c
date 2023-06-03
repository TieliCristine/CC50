#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    char *arg = argv[1];

    for (int i = 0; arg[i] != '\0'; i++)
    {
        if (isalpha(arg[i]) || !isdigit(arg[i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int shift = atoi(argv[1]);

    if (shift < 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string text = get_string("plaintext: ");

    int length = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        length++;
    }

    char *ciphertext = malloc((length + 1) * sizeof(char));

    for (int i = 0; i < length; i++)
    {
        if (isalpha(text[i]))
        {
            char base = islower(text[i]) ? 'a' : 'A';
            ciphertext[i] = (text[i] - base + shift) % 26 + base;
        }
        else
        {
            ciphertext[i] = text[i];
        }
    }

    ciphertext[length] = '\0';

    printf("ciphertext: %s\n", ciphertext);

    free(ciphertext);

    return 0;
}
