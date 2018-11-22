# include <stdio.h>
# include <cs50.h>

int main(void)
{
    bool isValid = false;
    int x = 0;

    while (!isValid)
    {
        x = get_int("Height: ");
        if (x >= 0 & x < 24)
        {
            isValid = true;
        }
    }

    for (int i = 1; i <= x; i++)
    {
        for (int j = 1; j <= x - i; j++)
        {
            printf(" ");
        }

        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }

        printf("  ");

        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }

        printf("\n");
    }



}