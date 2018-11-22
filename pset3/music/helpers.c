// Helper functions for music

#include <cs50.h>
# include "helpers.h"
# include <string.h>
# include <stdio.h>
# include <math.h>

//int main(void)
//{
//    bool y = is_rest(""); // 131
//}

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int numerator = 0;
    int denominator = 0;

    numerator = (int)fraction[0] - 48;
    denominator = (int)fraction[2] - 48;
    return numerator * (8 / denominator);
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    double hz = 0;
    double notes = 0;

    hz = 27.5 * pow(2, ((int)note[strlen(note) - 1] - 48));
    if ((int)note[0] == 66) //B
    {
        double temp = (float)2 / 12;
        hz = hz * pow(2, temp);
    }
    else if ((int)note[0] == 67) //C
    {
        double temp = (float)9 / 12;
        hz =  hz / pow(2, temp);
    }
    else if ((int)note[0] == 68) //D
    {
        double temp = (float)7 / 12;
        hz =  hz / pow(2, temp);
    }
    else if ((int)note[0] == 69) //E
    {
        double temp = (float)5 / 12;
        hz =  hz / pow(2, temp);
    }
    else if ((int)note[0] == 70) //F
    {
        double temp = (float)4 / 12;
        hz =  hz / pow(2, temp);
    }
    else if ((int)note[0] == 71) //G
    {
        double temp = (float)2 / 12;
        hz =  hz / pow(2, temp);
    }

    if (strlen(note) == 3)
    {
        if ((int)note[1] == 35)
        {
            hz = hz * pow(2, (0.083333));
        }
        else if ((int)note[1] == 98)
        {
            hz = hz / pow(2, (0.083333));
        }
    }
    return round(hz);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    int len = strlen(s);
    printf("%i\n", len);
    if (len == 6)
    {
        if ((int)s[0] <= 65 || (int)s[0] >= 90)
        {
            return false;
        }
        if ((int)s[2] <= 48 || (int)s[1] >= 57)
        {
            return false;
        }
        if ((int)s[2] != 64)
        {
            return false;
        }
        if ((int)s[3] <= 48 || (int)s[3] >= 57)
        {
            return false;
        }
        if ((int)s[4] != 47)
        {
            return false;
        }
        if ((int)s[5] <= 48 || (int)s[5] >= 57)
        {
            return false;
        }
        return true;
    }
    else if (len == 7)
    {
        if ((int)s[0] <= 65 || (int)s[0] >= 90)
        {
            return false;
        }
        if ((int)s[1] != 35 && (int)s[1] != 98)
        {
            return false;
        }
        if ((int)s[2] <= 48 || (int)s[2] >= 57)
        {
            return false;
        }
        if ((int)s[3] != 64)
        {
            return false;
        }
        if ((int)s[4] <= 48 || (int)s[4] >= 57)
        {
            return false;
        }
        if ((int)s[5] != 47)
        {
            return false;
        }
        if ((int)s[6] <= 48 || (int)s[6] >= 57)
        {
            return false;
        }
        return true;
    }
    else if (strcmp(s, "") == 0)
    {
        return 1;
    }
    return false;
}
