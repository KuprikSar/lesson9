#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <ctype.h>

#define MAXSTRING 100


// В файле .txt даны два слова не более 100 символов каждое, разделенные
// одним пробелом. Найдите только те символы слов, которые встречаются в
// обоих словах только один раз. Напечатайте их через пробел в файл .txt в
// лексикографическом порядке.


int main (void) 
{ 
    FILE *f_in, *f_out;

    f_in = fopen("input.txt", "r"); //открываем файл
    if (f_in == NULL) 
    {
        printf("ERROR!");
        return 1;
    }

    char word1[101];
    char word2[101];

    fscanf(f_in, "%s %s", word1, word2);
    fclose(f_in);

    int count [26] = {0}; //26 символов считаем в алфавите

    int len1 = strlen(word1);
    int len2 = strlen(word2);

    for (size_t i = 0; i < len1; i++) //считаем частоту симоволов в первом слове
    {
        count[word1[i] - 'a']++;
    }

    for (size_t i = 0; i < len2; i++) //считаем частоту симоволов во втором слове
    {
        count[word2[i] - 'a']++;
    }
    
    f_out = fopen("output.txt", "w");
    if (f_out == NULL) 
    {
      printf("error!");
      return 1;
    }

    for (int i = 0; i < 26; i++) {
        if (count[i] == 1) {
            fprintf(f_out, "%c ", i + 'a');
        }
    }
    fclose(f_out);

    return 0;
}
