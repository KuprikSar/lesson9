#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <ctype.h>

#define MAXSTRING 100
//#define CNT_NUMBERS 1000

// В файле .txt строка из маленьких и больших английских букв, знаков
// препинания и пробелов. Требуется удалить из нее повторяющиеся символы и
// все пробелы. Результат записать в файл .txt.



// void sortingupper(int* numbers, int count) 
// {
//     for (int i = 0; i < count - 1; i++) 
//     {
//         for (int j = 0; j < count - i - 1; j++) 
//         {
//             if (numbers[j] > numbers[j + 1]) 
//             {
//                 int temp = numbers[j];
//                 numbers[j] = numbers[j + 1];
//                 numbers[j + 1] = temp;
//             }
//         }
//     }
// }


int main (void) 
{ 
    FILE *f_in, *f_out;

    f_in = fopen("input.txt", "r"); //открываем файл
    if (f_in == NULL) 
    {
        printf("ERROR!");
        return 1;
    }

    char word[101];

    fscanf(f_in, "%s", word);
    fclose(f_in);

    int len = strlen(word);
    int count = 0;

    for (int i = 0; i < len; i++) 
    {
        char currentChar = word[i];

        if (currentChar != ' ' && !isalpha(currentChar))  // проверяем ещё и цифры
        {
            continue; // пропустить пробелы
        }
     
        int doublechar = 0; // если дубли будут

        for (int j = 0; j < count; j++) 
        {
            if (tolower(word[j]) == tolower(currentChar)) 
            {
                doublechar = 1;
                break;
            }
        }

        if (!doublechar) {
            word[count] = currentChar;
            count++;
        }
    }

    word[count] = '\0'; // закончить нулём
    
    f_out = fopen("output.txt", "w"); // открываем exit file
    if (f_out == NULL) 
    {
      printf("error!");
      return 1;
    }  

    fprintf(f_out, "%s", word);      
    fclose(f_out);

    return 0;
}
