#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <ctype.h>

#define MAXSTRING 1000

// В файле .txt дана символьная строка не более 1000 символов. Необходимо
// заменить все буквы "а" на буквы "b" и наоборот, как заглавные, так и
// строчные. Результат записать в .txt.

int main (void) 
{ 
    FILE *f_in, *f_out;

    f_in = fopen("input.txt", "r"); //открываем файл
    if (f_in == NULL) 
    {
        printf("ERROR!");
        return 1;
    }

    char word1[1001];

    fscanf(f_in, "%s", word1);
    fclose(f_in);

    int len1 = strlen(word1);
    for (int i = 0; i < len1; i++) //А если цифра? Надо делать ещё 1 if на цифры?
    {
        if (islower(word1[i])) // если символ - строчная буква
        { 
            if (word1[i] == 'a')
                word1[i] = 'b';
            else if (word1[i] == 'b')
                word1[i] = 'a';
        } 
        else // если символ - заглавная буква
        { 
            if (word1[i] == 'A')
                word1[i] = 'B';
            else if (word1[i] == 'B')
                word1[i] = 'A';
        }
                
    }
    
    f_out = fopen("output.txt", "w");
    if (f_out == NULL) 
    {
      printf("error!");
      return 1;
    }

    fprintf(f_out, "%s", word1);

    fclose(f_out);


     return 0;
}
