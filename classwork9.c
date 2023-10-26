#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <ctype.h>



// Чтение и запись в файл — это буферизированный ввод и вывод. Функция fflush –
// проталкивание данных.
/*
int main(void)
{
    FILE *f;
    f = fopen("in.txt","w"); // открытие файла in.txt на запись
    fclose(f); //Закрытие файла. После окончания работы с файлом необходимо убедиться, что все записанные данные попали на диск, и освободить все ресурсы, связанные с ним.
    return 0;
}
*/

//---------------------------------------------------------------------------

//Дан текстовый файл in.txt, содержащий целые числа. Посчитать сумму чисел.
/*
int main(void)
{
    FILE *f;
    int sum = 0, n;
    f = fopen("in.txt", "r");
    while (fscanf (f, "%d", &n) == 1)
    sum += n;
    fclose (f);
    printf ("%d\n", sum);
}
*/

//---------------------------------------------------------------------------

// Дан текстовый файл in.txt. Необходимо посчитать количество цифр в файле и
// записать это число в конец данного файла.
/*
int main(void)
{
    FILE *f;
    int sum = 0;
    signed char c;// обязательно signed! иначе зациклится
    f = fopen("in.txt", "r+"); // режим чтение и дозапись
    while ( (c=fgetc(f))!=EOF ) 
    {
        if(c>='0' && c<='9') 
        {
            sum += c-'0';
        }
    }
    fprintf (f, " %d", sum);
    printf (" %d", sum);
    fclose (f);
}
*/

//---------------------------------------------------------------------------

// Ввести имя файла и напечатать его размер. Функция ftell возвращает значение
// указателя текущего положения потока.
/*
int main(void)
{
    FILE *f;
    static char filename[100]={0};
    size_t size;
    printf("Input file name: ");
    scanf("%s",filename);
    f = fopen (filename, "r");
    if (f != NULL) 
    {
        fseek (f, 0, SEEK_END);
        size = ftell (f);
        fclose (f);
        printf ("File size of '%s' - %u bytes.\n",filename, size);
    } 
    else 
    {
        printf ("Can't open file %s\n", filename);
    }
}
*/

//---------------------------------------------------------------------------

// В файле in.txt дана строка. Вывести ее в файл output.txt три раза через запятую и показать
// количество символов в ней
/*
const int line_width = 256;
int main(void)
{
    char * input_fn = "in.txt";
    char * output_fn = "output.txt";
    char line[line_width];
    char c;
    FILE *fp;
    //
    if((fp = fopen(input_fn, "r")) == NULL)
    {
        perror("Error occured while opening input file!");
        return 1;
    }
    int count = 0;
    while(((c = getc(fp)) != EOF) && (c != '\n'))
    line[count++] = c;
    line[count] = '\0';
    fclose(fp);
    if((fp = fopen(output_fn, "w")) == NULL) {
    perror("Error occured while opening output file!");
    return 1;
    }
        for (int i = 0; i < 3; i++) {
        if (i)
        fprintf(fp, ", ");
        fprintf(fp, "%s", line);
    }
    fprintf(fp, " %d", count);
    printf ( " %d", count);
    fclose(fp);
    return 0;
}
*/

//---------------------------------------------------------------------------
// В файле .txt дана строка из 1000 символов. Показать номера символов, совпадающих с
// последним символом строки. Результат записать в файл .txt 
/*
#define MAXSTRING 1000

int main (void) 
{       
    FILE *f_in, *f_out;
    char line[1001]; //потомучто ноль в коце
    
    f_in = fopen("input.txt", "r"); //открываем файл
    if (f_in == NULL) 
    {
        printf("ERROR!");
        return 1;
    }

    if (fgets(line, sizeof(line), f_in) == NULL) //читаем строку
    {
      printf("error read!");
      fclose(f_in);
      return 1;
    }

    fclose(f_in);
   
    int lineLength = strlen(line)-1; //определяем длину стандартной функцией

    f_out = fopen("output.txt", "w");
    if (f_out == NULL) {
        printf("error open!");
        return 1;
    }

    printf("%d\n", line[lineLength - 1]);
    printf("%d\n", lineLength);

    for (int i = 0; i < lineLength; i++) 
    {
      if (line[i] == line[lineLength - 1]) 
      {         
        //printf("%d ", i);
        fprintf(f_out, "%d\n", i); // записываем iй номер
      }
      
   }
    
    fclose(f_out);
*/

    /*
    char name_in[] = "input.txt";
    char name_out[] = "output.txt";
    f_in = fopen(name_in, "r");
    f_out = fopen(name_out, "w");

    while (fscanf(f_in, "%[\n]", str) == 1)
    {
        
    }
    
    char str[n + 2];
    char c = 'A';
    char c_num = '2';

    for (i = 0; i < n; ++i)
    {
        if (i%2==0)
        str[i] = c++;
        else
        {
            str[i] = c_num;
            if (c_num == '8')
            c_num = '2';
            else
            c_num += 2;
        }
    }
    str[i] = '\0';
    fprintf(f_out, "%s", str);
    fclose(f_in);
    fclose(f_out);
*/



//---------------------------------------------------------------------------
// В файле .txt считать символьную строку, не более 10 000 символов. Посчитать
// количество строчных (маленьких) и прописных (больших) букв в введенной строке.
// Учитывать только английские буквы. Результат записать в файл .txt.

/*
#define MAXSTRING 1000

int main (void) 
{       
    int cntlow = 0;
    int cntbig = 0;

    FILE *f_in, *f_out;
    char line[1001]; //потомучто ноль в коце
    
    f_in = fopen("input.txt", "r"); //открываем файл
    if (f_in == NULL) 
    {
        printf("ERROR!");
        return 1;
    }

    if (fgets(line, sizeof(line), f_in) == NULL) //читаем строку
    {
      printf("error read!");
      fclose(f_in);
      return 1;
    }

    fclose(f_in);
    int len = strlen(line);
    
    for (int i = 0; i < len; i++) 
    {
      if (islower(line[i])) 
      {
         cntlow++;
      } 
      else if (isupper(line[i])) 
      {
         cntbig++;
      }
   }

   f_out = fopen("output.txt", "w");
   if (f_out == NULL) 
   {
      printf("error!");
      return 1;
   }

    fprintf(f_out, "low: %d\n", cntlow);
    fprintf(f_out, "BIG: %d\n", cntbig);

    fclose(f_out);
}
*/

//---------------------------------------------------------------------------
// В файле .txt в одной строке фамилию, имя и отчество. Сформировать файл приветствие
// .txt, где останутся имя и фамилия

#define MAXSTRING 100

int main (void) 
{ 
    FILE *f_in, *f_out;
    char name[101] = {0};
    char family[101] = {0};
    char HELLO[101] = "HELLO, ";
        
    f_in = fopen("input.txt", "r"); //открываем файл
    if (f_in == NULL) 
    {
        printf("ERROR!");
        return 1;
    }

    if (fscanf(f_in, "%s %s", name, family) != 2) 
    {
        printf("error read!");
        fclose(f_in);
        return 1;
   }

    fclose(f_in);
    int len = strlen(name);
    
    strcat(HELLO, name);
    strcat(HELLO, " ");
    strcat(HELLO, family);
    strcat(HELLO, "!");

   f_out = fopen("output.txt", "w");
   if (f_out == NULL) 
   {
      printf("error!");
      return 1;
   }

    fprintf(f_out, "%s\n", HELLO);
    
    fclose(f_out);

    return 0;
}