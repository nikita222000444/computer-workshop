#include <math.h>
#include <stdio.h>
#include "functions.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>
//1

char* Replace(char* str_)
{
   char strfail[] = "Fail";

   int n = 0;
   int m = 0;
   for (int i = 0; str_[i] != '\0' && str_[i] != ' '; i++)
      n++;

   for (int i = strlen(str_) - 1; i >= 0 && str_[i] != ' '; i--)
      m++;

   int a = n + 1;
   int b = m + 1;
   char* strf = malloc(a * sizeof(char));

   char* strl = malloc(b * sizeof(char));

   if (strf && strl)
   {
      for (int i = 0; i < n; i++)
         strf[i] = str_[i];
      
      int  ki = 0;
      for (int i = strlen(str_) - m; i < strlen(str_); i++)
      {
         strl[ki] = str_[i];
         ki++;
      }
      
      if (n == m)
      {
         for (int i = 0; i < n; i++)
            str_[i] = strl[i];

         ki = 0;
         for (int i = strlen(str_) - m; i < strlen(str_); i++)
         {
            str_[i] = strf[ki];
            ki++;
         }

      }

      if (n > m)
      {   
         for (int i = n + 1; i < (strlen(str_) - m); i++)   
            str_[i - (n - m)] = str_[i];
        
         for (int i = 0; i < m; i++)
            str_[i] = strl[i];
         str_[m] = ' ';

         ki = 0;
         for (int i = strlen(str_) - n; i < strlen(str_); i++)
         {
            str_[i] = strf[ki];
            ki++;
         }
      }

      if (m > n)
      {
         for (int i = strlen(str_) - m - 2; i > n; i--)
            str_[i + (m - n)] = str_[i];

         for (int i = 0; i < m; i++)
            str_[i] = strl[i];
         str_[m] = ' ';

         str_[strlen(str_) - n - 1] = ' ';
         
         ki = 0;
         for (int i = strlen(str_) - n; i < strlen(str_); i++)
         {
            str_[i] = strf[ki];
            ki++;
         }
      }
      return str_;
   }
   else
      return strfail;
}

//2

struct Engineers
   {
      char Surname[50];
      char Name[50];
      char Patronymic[50];
      
      char Gender[2];
      char Position[50];
      int DateOfBirth[3];
   };

void Print(struct Engineers *arr)
{
   printf("\n");
   puts(arr->Surname);
   puts(arr->Name);
   puts(arr->Patronymic);
   puts(arr->Gender);
   puts(arr->Position);
   printf("%d.%d.%d", arr->DateOfBirth[0], arr->DateOfBirth[1], arr->DateOfBirth[2]);
}


void Old(struct Engineers **arr, int n)
{
   //today's date 19.12.2021
   for (int i = 0; i < n; i++)
   {
      if (arr[i]->Position == "Engineer")
      {
         if (arr[i]->Gender == 'm' || arr[i]->Gender == 'M')
            if (arr[i]->DateOfBirth[2] < 1956)
               Print(&arr[i]);
            else
               if (arr[i]->DateOfBirth[2] = 1956 && arr[i]->DateOfBirth[1] < 12)
                  Print(&arr[i]);
               else
                  if (arr[i]->DateOfBirth[1] = 12 && arr[i]->DateOfBirth[0] <= 19)
                     Print(&arr[i]);
         
         if (arr[i]->Gender == 'f' || arr[i]->Gender == 'F')
            if (arr[i]->DateOfBirth[2] < 1961)
               Print(&arr[i]);
            else
               if (arr[i]->DateOfBirth[2] = 1961 && arr[i]->DateOfBirth[1] < 12)
                  Print(&arr[i]);
               else
                  if (arr[i]->DateOfBirth[1] = 12 && arr[i]->DateOfBirth[0] <= 19)
                     Print(&arr[i]);
      }
   }

}

//3

void f_to_g(FILE *f, FILE *g)
{
   

   char* str = malloc(2048 * sizeof(char));
   int n = 0;

   fgets(str, 2048, f);

   for (int i = 0; i < 2048; i++)
   {
      while (str[i] != "\0")
      {
         if (str[i] == ' ')
            n++;

         if (n == 4)
         {
            n = 0;
            while (str[i] != ' ')
               continue;
         }

         if (str[i] != 'ï')
         {
            while (str[i] != ' ')
               fprintf(g, "%c", str[i]);
         }
         else
         {
            while (str[i] != ' ')
               continue;
         }
      }
   }
   fclose(f);
   fclose(g);

   return 0;
}

int main()
{
   setlocale(LC_ALL, "Russian");

   char str[] = "wwaw kuw tot etot ukudfe";
   char* FinStr = Replace(str);
   for (int i = 0; i < strlen(str); i++)
      printf("%c",FinStr[i]);
   
   int n;
   scanf_s("%d", &n);

   struct Engineers* arr =(struct Engineers*) malloc(n * sizeof(struct Engineers));
   if (arr)
   {
      for (int i = 0; i < n; i++)
      {
         printf("Engineer %d\n", i);
         printf("Surname: ");
         fscanf_s(stdin, "%s", arr[i].Surname, 50);
         printf("Name: ");
         fscanf_s(stdin, "%s", arr[i].Name, 50);
         printf("Patronymic: ");
         fscanf_s(stdin, "%s", arr[i].Patronymic, 50);
         printf("Gender: ");
         fscanf_s(stdin, "%s", arr[i].Gender, 2);
         printf("Position: ");
         fscanf_s(stdin, "%s", arr[i].Position, 50);

         for (int j = 0; j < 3; j++)
         {
            if (j == 0)
               printf("Day: ");
            if (j == 1)
               printf("Month: ");
            if (j == 2)
               printf("Year: ");

            scanf_s("%d", &arr[i].DateOfBirth[j]);
         }
         printf("\n");
      }
      Old(arr, n);
   }

   FILE* f = NULL;
   FILE* g = NULL;

   fopen_s(&f, "Text.txt", "r");
   if (!f)
   {
      printf("File not opened\n");
      return 1;
   }

   fopen_s(&g, "Text1.txt", "w");
   if (!g)
   {
      printf("File not opened\n");
      return 2;
   }
   f_to_g(f, g);
   return 0;
}

