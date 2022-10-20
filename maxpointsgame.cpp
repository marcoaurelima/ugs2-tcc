#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("UGS2 - Maximo de pontos possiveis em fase\n");
    printf("Path para arquivo de sequencia: ");
    char path[100];
    scanf(" %s", &path);

    FILE* file = fopen(path, "r");

    unsigned total = 0;

    float a = 0.0, b = 0.0, c = 0.0;
    while(fscanf(file, " %f %f %f", &a, &b, &c) != EOF)
    {
        if(c == 0.0)
        {
            total++;
        } else 
        {
            total = total + (c * 60);
        }
    }

    printf("Maximo de pontos possivel para esta fase e': %d\n....\n\n", total);


    fclose(file);


    return 0;
}
