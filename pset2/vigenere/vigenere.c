# include <stdio.h>
# include <cs50.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>

int main(int argc, string argv[])
{
    int count = 0;
    int keyNum = 0;

    if (argc != 2)
    {
        return 1;
    }

    string key = argv[1];

    int lenght = strlen(key);

    for (int a = 0; a < lenght; a++)
    {
        if (isalpha(key[a]) == false)
        {
            return 1;
        }
    }

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
                if (count >= lenght)
                {
                    count = 0;
                }

                if (isupper(key[count]))
                {
                    keyNum = (int)key[count] - 65;
                }
                else
                {
                    keyNum = (int)key[count] - 97;
                }

                num = ((num + keyNum) % 26) + 65;
                plainText[i] = num;
                count++;
            }
            else
            {
                int num = (int)plainText[i] - 97;
                if (count >= lenght)
                {
                    count = 0;
                }

                if (isupper(key[count]))
                {
                    keyNum = (int)key[count] - 65;
                }
                else
                {
                    keyNum = (int)key[count] - 97;
                }

                num = ((num + keyNum) % 26) + 97;
                plainText[i] = num;
                count++;
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