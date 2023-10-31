#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <ctype.h>

#define MAXSTRING 1000
#define CNT_NUMBERS 1000

// В файле .txt дана строка, не более 1000 символов, содержащая буквы, целые
// числа и иные символы. Требуется все числа, которые встречаются в строке,
// поместить в отдельный целочисленный массив. Например, если дана строка
// "data 48 call 9 read13 blank0a", то в массиве числа 48, 9, 13 и 0. Вывести
// массив по возрастанию в файл .txt.


void sortingupper(int* numbers, int count) 
{
    for (int i = 0; i < count - 1; i++) 
    {
        for (int j = 0; j < count - i - 1; j++) 
        {
            if (numbers[j] > numbers[j + 1]) 
            {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
}

int main (void) 
{ 
    FILE *f_in, *f_out;

    f_in = fopen("input.txt", "r"); //открываем файл
    if (f_in == NULL) 
    {
        printf("ERROR!");
        return 1;
    }

    char word[1001];

    fscanf(f_in, "%s", word);
    fclose(f_in);

    int count = 0;
    int numbers[CNT_NUMBERS];
    int len = strlen(word);
    char numbersec[101]; //3х значное число
    int cntNumber = 0;
    for (int i = 0; i < len; i++) 
    {
        if (isdigit(word[i])) // символ цифра ?
        { 
            numbersec[cntNumber] = word[i];
            cntNumber++;
        }
        else 
        {
            if (cntNumber > 0) // конец числа?
            { 
                numbers[cntNumber] = '\0'; // надо добавить ноль
                numbers[count] = atoi(numbersec); // преобразуем строку в число и сохраняем
                count++;
                cntNumber = 0;
            }
        }
    }

    if (cntNumber > 0) // Число после цикла?
    {
        numbers[cntNumber] = '\0'; // надо добавить ноль
        numbers[count] = atoi(numbersec);
        count++;
    }

    sortingupper(numbers, count);
    
    f_out = fopen("output.txt", "w"); // открываем exit file
    if (f_out == NULL) 
    {
      printf("error!");
      return 1;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(f_out, "%d", numbers[i]); 
    }
     
    fclose(f_out);

    return 0;
}
