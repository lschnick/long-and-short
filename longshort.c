#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void input(char *enter, char *str);
void trim (char *input, int length);
void getln(FILE *file, char *x);
void printlns(char *str, char *w1, char *w2, int size);

int main ()
{
    char namer[20];
    char namew1[20];
    char namew2[20];
    char ln[255];
    int count1, count2, length;
    count1 = 0;
    count2 = 0;
    length = 0;

    input("File to read from: ", namer);

    input("First file to write to: ", namew1);
    input("Second file to write to: ", namew2);

    FILE *filer = fopen(namer, "r");

    if (filer == NULL)
    {
        printf("File failed to open");
    }
    while (fgets(ln, 255, filer) != NULL)
    {
    {
        length = strlen(ln);
        trim(ln, length);
        length = strlen(ln);
        printlns(ln, namew1, namew2, length);
        if (length < 20)
        {
            count1++;
        }
        else
        {
            count2++;
        }
    }
    }
    fclose(filer);
    printf("Printed %d lines to %s.\n", count1, namew1);
    printf("Printed %d lines to %s.\n", count2, namew2);
}

void input(char *enter, char *str)
{
    int length = 0;
    fputs(enter, stdout);
    fgets(str, 255, stdin);
    length = strlen(str);
    trim(str, length);
}

void trim (char *input, int length)
{
    int i = length - 1;
    if ( input[i] == '\n')
    {
        input[i] = '\0';
    }
}

void printlns(char *str, char *w1, char *w2, int size)
{
    int i = 0;
    if (size < 20)
    {
        FILE *filew1 = fopen(w1, "a");
        if (filew1 == NULL)
    {
        printf("File failed to open");
    }
       for (i = 0; i < size; i++)
    {
        int ch = str[i];
        if ( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
        {
        ch = toupper(ch);
        }
        str[i] = ch;
    }
        fputs(str, filew1);
        fprintf(filew1, "\n");
        fclose(filew1);
    }
    else
    {
        FILE *filew2 = fopen(w2, "a");
        if (filew2 == NULL)
    {
        printf("File failed to open");
    }
    for (i = 0; i < size; i++)
    {
         int ch = str[i];
        if ( (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
        {
        ch = tolower(ch);
        }
        str[i] = ch;
    }
        fputs(str, filew2);
        fprintf(filew2, "\n");
        fclose(filew2);
    }
}