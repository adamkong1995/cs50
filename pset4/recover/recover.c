#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{

    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: copy infile outfile\n");
        return 1;
    }

    FILE *raw = fopen(argv[1], "r");

    //ensure file opened
    if (raw == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 2;
    }

    unsigned char byte[512];
    bool isJpg = false;
    int numOfFound = 0;
    char name[8];
    FILE *image = NULL;

    while (fread(byte, 512, 1, raw) == 1)
    {
        if (byte[0] == 0xff && byte[1] == 0xd8 && byte[2] == 0xff && (byte[3] & 0xf0) == 0xe0)
        {
            if (isJpg == true)
            {
                fclose(image);
            }
            else
            {
                isJpg = true;
            }

            sprintf(name, "%03i.jpg", numOfFound);
            image = fopen(name, "w");
            numOfFound++;
        }

        if (isJpg)
        {
            fwrite(&byte, 512, 1, image);
        }
    }

    fclose(image);
    fclose(raw);
    return 0;
}