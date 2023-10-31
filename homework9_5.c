#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <ctype.h>

//#define MAXSTRING 1000
//#define CNT_NUMBERS 1000

// В файле .txt дана строка слов, разделенных пробелами. Найти самое длинное
// слово и вывести его в файл .txt. Случай, когда самых длинных слов может быть
// несколько, не обрабатывать.

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

void longWord(const char* words, char* longestWord) 
{
    char currentWord[1001]; 
    char tempLongestWord[1001];
    int longestWordLength = 0;
    int currentWordLength = 0;
    int wordStarted = 0;

    int len = strlen(words);
    for (int i = 0; i < len; i++) 
    {
        char currentChar = words[i];

        if (currentChar != ' ') 
        {
            if (!wordStarted) 
            {               
                wordStarted = 1;
                currentWordLength = 0;
                currentWord[currentWordLength] = currentChar;
                currentWordLength++;
            } 
            else 
            {              
                currentWord[currentWordLength] = currentChar;
                currentWordLength++;
            }
        } 
        else 
        {
            if (wordStarted) 
            {
                currentWord[currentWordLength] = '\0'; 
                if (currentWordLength > longestWordLength) 
                {
                    longestWordLength = currentWordLength;
                    strcpy(tempLongestWord, currentWord);
                }
                wordStarted = 0;
            }
        }
    }

    if (currentWordLength > longestWordLength) 
    {
        currentWord[currentWordLength] = '\0';
        strcpy(tempLongestWord, currentWord);
        longestWordLength = currentWordLength;
    }

    strcpy(longestWord, tempLongestWord);
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

    fgets(word, sizeof(word), f_in); // меняем на функцию fgets, есть мысли что не читается несколько слов с прошлым scanf
    fclose(f_in);

    char longword[1001]; // будущее слово

    longWord(word, longword);
        
    f_out = fopen("output.txt", "w"); // открываем exit file
    if (f_out == NULL) 
    {
      printf("error!");
      return 1;
    }
    fprintf(f_out, "%s", longword);          
    fclose(f_out);

    return 0;
}
