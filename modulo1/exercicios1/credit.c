#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isValidChecksum(const char* number) {
    int len = strlen(number);
    int sum = 0;
    bool doubleDigit = false;

    for (int i = len - 1; i >= 0; i--) {
        int digit = number[i] - '0';
        if (doubleDigit) {
            digit *= 2;
            if (digit > 9) {
                digit = (digit % 10) + 1;
            }
        }
        sum += digit;
        doubleDigit = !doubleDigit;
    }

    return (sum % 10) == 0;
}

const char* getCardType(const char* number) {
    int len = strlen(number);

    if ((len == 13 || len == 16) && number[0] == '4') {
        return "VISA";
    } else if (len == 15 && number[0] == '3' && (number[1] == '4' || number[1] == '7')) {
        return "AMEX";
    } else if (len == 16 && number[0] == '5' && number[1] >= '1' && number[1] <= '5') {
        return "MASTERCARD";
    }

    return "INVALID";
}

int main(void) {
    char number[17];
    printf("Number: ");
    scanf("%16s", number);

    if (!isValidChecksum(number)) {
        printf("INVALID\n");
        return 0;
    }

    const char* cardType = getCardType(number);
    printf("%s\n", cardType);

    return 0;
}
