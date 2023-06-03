#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int lines;

    printf("** WELCOME TO MARIO ** \n");

    do
    {
        lines = get_int("Digite um número de 1 a 8: ");
    }
    while (lines <= 0 || lines > 8);

    switch (lines)
    {
        case 1:
            printf("#  #\n");
            break;

        case 2:
            printf(" #  #\n");
            printf("##  ##\n");
            break;

        case 3:
            printf("  #  #\n");
            printf(" ##  ##\n");
            printf("###  ###\n");
            break;

        case 4:
            printf("   #  #\n");
            printf("  ##  ##\n");
            printf(" ###  ###\n");
            printf("####  ####\n");
            break;

        case 5:
            printf("    #  #\n");
            printf("   ##  ##\n");
            printf("  ###  ###\n");
            printf(" ####  ####\n");
            printf("#####  #####\n");
            break;

        case 6:
            printf("     #  #\n");
            printf("    ##  ##\n");
            printf("   ###  ###\n");
            printf("  ####  ####\n");
            printf(" #####  #####\n");
            printf("######  ######\n");
            break;

        case 7:
            printf("      #  #\n");
            printf("     ##  ##\n");
            printf("    ###  ###\n");
            printf("   ####  ####\n");
            printf("  #####  #####\n");
            printf(" ######  ######\n");
            printf("#######  #######\n");
            break;

        case 8:
            printf("       #  #\n");
            printf("      ##  ##\n");
            printf("     ###  ###\n");
            printf("    ####  ####\n");
            printf("   #####  #####\n");
            printf("  ######  ######\n");
            printf(" #######  #######\n");
            printf("########  ########\n");
            break;
    }
}