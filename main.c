#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num,count=0;
    char ch;
    FILE *f, *g, *res;
    f=fopen("f.dat","wb");
    printf("Input file f (int): ");
    scanf("%d", &num);
    fwrite(&num, sizeof(int), 1, f);

    fclose(f);

    if((f=fopen("f.dat","rb"))==NULL)
    {
        perror("Can’t open file for reading. ");
        exit(1);
    }
    if((g=fopen("g.txt","r"))==NULL)
    {
        perror("Can’t open file for reading. ");
        exit(2);
    }
    if((res=fopen("res.txt","w"))==NULL)
    {
        perror("Can’t open file for reading. ");
        exit(3);
    }

    char word[100];
    while (fscanf(f, "%d", &num) != EOF && fscanf(g, "%s", word) != EOF) {
        if (num == 1) {
            fprintf(res, "%s ", word);
        } else {
            count++;
        }
    }
    fprintf(res, "\n%d", count);

    fclose(res);
    fclose(f);
    fclose(g);
    return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num=0,count=0;
    char ch;
    FILE *f, *g, *res;
    f=fopen("f.dat","wb");

    printf("Input file f (int): ");
    scanf("%d", &num);
    fwrite(&num, sizeof(int), 1, f);

    fclose(f);

    f = fopen("f.txt", "rt");
    g = fopen("g.txt", "rt+");
    res = fopen("res.txt", "wt");

    char txt[1000];
    int i;
    int j = 0;
    int k = 0;
    char g1;
    int c;

    while ((c = fgetc(g)) != EOF) {
        if (c == ' ') {
            fseek(g, -2, SEEK_CUR);
            fputc('\n', g);
            fflush(g);
        }
    }

    fseek(g, 0, SEEK_SET);
    while (fgets(txt, sizeof(txt), g)) {
        k++;
    }
    fseek(g, 0, SEEK_SET);

    while (fgets(txt, sizeof(txt), g)) {
        fscanf(f, "%d", &i);

        if (1 == i) {
            fputs(txt, res);
            j++;
        }
    }

    fseek(g, 0, SEEK_SET);
    fseek(f, 0, SEEK_SET);
    while ((c = fgetc(g)) != EOF) {
        if (c == '\n') {
            fprintf(res, "%s\n", txt);
        }
    }

    fclose(f);
    fclose(g);
    fclose(res);

    return 0;
}
*/

/*
int main()
{
    int num,count=0;
    char ch;
    FILE *f, *g, *res;
    f=fopen("f.dat","wb");

    printf("Input file f (int): ");
    scanf("%d", &num);
    fwrite(&num, sizeof(int), 1, f);

    fclose(f);

    if((f=fopen("f.dat","rb"))==NULL)
    {
        perror("Can’t open file for reading. ");
        exit(1);
    }
    if((g=fopen("g.txt","r"))==NULL)
    {
        perror("Can’t open file for reading. ");
        exit(2);
    }
    if((res=fopen("res.txt","w"))==NULL)
    {
        perror("Can’t open file for reading. ");
        exit(3);
    }

    char word[100];
    int index = 0,c;


    do
    {
        while ((c = fgetc(g)) != EOF)
        {
            if (c == ' ' || c == '\n' || c == '\t')
            {
                if (index > 0)
                {
                    word[index] = '\0';
                    fprintf(res, "%s\n", word);
                    index = 0;
                }
            }
            else
            {
                word[index++] = c;
            }
        }

        if (num == 1)
        {
            fprintf(res, "%s\n", word);
        }
        else
        {
            count++;
        }
    }
    while (fscanf(f, "%d", &num) == 1 && fscanf(g, "%s", word) == 1);

    fprintf(res, "%d", count);

    fclose(res);
    fclose(f);
    fclose(g);
    return 0;
}
*/
