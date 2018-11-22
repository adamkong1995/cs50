# include <stdio.h>
# include <cs50.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>

int main(int argc, string argv[])
{
    if (argc == 1)
    {
        return 1;
    }
    int key = atoi(argv[1]);

    string plainText = get_string("plaintext:  ");
    if (!plainText)
    {
        return 1;
    }

    for (int i = 0, n = strlen(plainText); i < n; i++)
    {
        if (isalpha(plainText[i]))
        {
            if (isupper(plainText[i]))
            {
                int num = (int)plainText[i] - 65;
                num = ((num + key) % 26) + 65;
                plainText[i] = num;
            }
            else
            {
                int num = (int)plainText[i] - 97;
                num = ((num + key) % 26) + 97;
                plainText[i] = num;
            }
        }
        else
        {
            int num = (int)plainText[i];
            plainText[i] = num;
        }
    }

    printf("ciphertext: %s\n", plainText);
}