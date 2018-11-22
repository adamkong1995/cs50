# include <stdio.h>
# include <cs50.h>

int main(void)
{
    int x = 0;
    bool isEven;
    long long temp;
    int checkSum;
    int sum = 0;
    int header;
    long long creditCard = get_long_long("Number: ");

    // Number of byte of the long long
    temp = creditCard;
    while (temp != 0)
    {
        temp = temp / 10;
        x++;
    }

    // Check even or odd
    if (x % 2 == 0)
    {
        isEven = true;
    }
    else
    {
        isEven = false;
    }

    for (int i = 0; i < x; i++)
    {
        temp = creditCard;
        creditCard = creditCard / 10;
        temp = temp % 10;

        if (i == x - 1)
        {
            header = header + temp * 10;
        }
        else if (i == (x - 2))
        {
            header = header + temp;
        }

        if (isEven)
        {
            //i == 0 | i % 2 == 0
            if (i % 2 != 0)
            {
                //printf("even: %lli\n", temp);
                temp = temp * 2;
                while (temp != 0)
                {
                    checkSum = checkSum + (temp % 10);
                    temp = temp / 10;
                }
            }
            else
            {
                //printf("no: %lli\n", temp);
                sum = sum + temp;
            }
        }
        else
        {
            if (i % 2 != 0)
            {
                //printf("odd: %lli\n", temp);
                temp = temp * 2;
                while (temp != 0)
                {
                    checkSum = checkSum + (temp % 10);
                    temp = temp / 10;
                }
            }
            else
            {
                //printf("no: %lli\n", temp);
                sum = sum + temp;
            }
        }
    }

    checkSum = checkSum + sum;
    checkSum = checkSum % 10;
    if (checkSum  == 0 && x >= 13 && x <= 16)
    {
        if (header == 34 || header == 37)
        {
            printf("AMEX\n");
        }
        else if (header >= 51 && header <= 55)
        {
            printf("MASTERCARD\n");
        }
        else if (header >= 40 && header <= 49)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

