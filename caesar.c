#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

string only_digits(string k);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    int k;
    string plaintext;

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        string check = only_digits(argv[1]);

        if (strcmp(check, "false") == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        else
        {
            k = atoi(argv[1]);
            plaintext = get_string("plaintext: ");
            printf("ciphertext: ");
            for (int i = 0; i < strlen(plaintext); i++)
            {

                char c = plaintext[i];
                if (isalpha(c))
                {
                    char text = rotate(c, k);
                    printf("%c", text);
                    continue;
                }
                else
                {
                    printf("%c", c);
                }
            }
            printf("\n");
        }
    }
}

string only_digits(string k)
{
    string check;
    for (int i = 0; i < strlen(k); i++)
    {
        if (isdigit(k[i]))
        {
            check = "true";
        }
        else
        {
            check = "false";
        }
    }
    return check;
}

char rotate(char c, int n)
{
    char e = '\0';
    if (isupper(c))
    {
        int a = c;
        a = a - 65;
        int b = (a + n) % 26;
        int d = b + 65;
        e = d;
    }
    else if (islower(c))
    {
        int a = c;
        a = a - 97;
        int b = (a + n) % 26;
        int d = b + 97;
        e = d;
    }
    return e;
}