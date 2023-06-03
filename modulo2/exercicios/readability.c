#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    int letters = 0;
    int words = 1;
    int sentences = 0;
    float total_letters;
    float total_sentences;
    float indice;
    int grade;

    string text = get_string("Text: ");
    printf("%s", text);
    printf("\n");

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
        else if (text[i] == ' ' && text[i + 1] != ' ')
        {
            words++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    printf("Letras: %d\n", letters);
    printf("Palavras: %d\n", words);
    printf("Sentenças: %d\n", sentences);

    total_letters = ((float)letters / words) * 100;
    total_sentences = ((float)sentences / words) * 100;
    indice = (0.0588 * total_letters) - (0.296 * total_sentences) - 15.8;
    grade = round(indice);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 12)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }
}