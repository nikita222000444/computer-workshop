#include <math.h>
#include <stdio.h>
#include "functions.h"
#include <stdlib.h>
#include <time.h>
double TaskOne()
{
   int a = 1;
   int x = 1;
   int c = 1;
   double L = (sqrt(exp(x) - pow(cos(pow(x, 2) * pow(a, 5)), 4)) + pow(atan(a - pow(x, 5)), 4)) / (exp(1) * sqrt(abs(a + x * pow(c, 4))));
   return L;
}

double TaskTwo(double t_)
{
   double V = 3 * t_ * t_ - 6 * t_;
   return V;
}

double TaskThree(double a_,double b_, double c_)
{
   double x = 0;
   double x1 = 0;
   double x2 = 0;
   double D = b_ * b_ - 4 * a_ * c_;
   if (D < 0)
   {
      printf("No real solutions");
   }if (D == 0)
   {
      x = (-b_) / (2 * a_);
      return x;
   }
   
   if (D > 0)
   {
      x1 = ((-b_) - sqrt(D)) / (2 * a_);
      x2 = ((-b_) + sqrt(D)) / (2 * a_);
      return x1, x2;
   }
}

double TaskFour(int x_,double sec_) //хначение времени вводим в секундах
{
   switch (x_)
   {
   case 48:
      return 15 * (sec_ / 60); break;
   case 44:
      return 18 * (sec_ / 60); break;
   case 46:
      return 13 * (sec_ / 60); break;
   case 45:
      return 11 * (sec_ / 60); break;
   }
}

int TaskFive()
{
   for (int i = 1000; i < 10000; ++i)
   {
      int num = i;
      int x4 = num % 10;
      num = num / 10;
      
      int x3 = num % 10;
      num = num / 10; 
      
      int x2 = num % 10;
      num = num / 10;
      
      int x1 = num % 10;
      
      if (x1 * x1 * x1 * x1 + x2 * x2 * x2 * x2 + x3 * x3 * x3 * x3 + x4 * x4 * x4 * x4 == i)
         return i;
   }
}

int TaskSix(x_)
{
   int* arr;
   int c = 0;
   int y = x_;
   while (y > 0)
   {
      ++c;
      y /= 10;
   }
   arr = malloc(c * sizeof(int));
   for (int i = c - 1; i >= 0; --i)
   {
      arr[i] = x_ % 10;
      x_ /= 10;
   }
   int num = 0;
   for (int i = 0; i < c; ++i)
   {
      num += pow(2, i) * arr[c - 1 - i];
   }
   return num;
}

int TaskSeven(int n_, int m_)
{
   srand(time(NULL));
   int** L = (int**)malloc(n_ * sizeof(int*));
   for (int i = 0; i < n_; i++)
   {
      L[i] = (int*)malloc(m_ * sizeof(int));
   }
   for (int i = 0; i < n_; ++i)
   {
      for (int j = 0; j < m_; ++j)
      {
         L[i][j] = (rand() % 21) - 10;
         L[i][j] *= (-3);
         printf("%d ", L[i][j]);
      }
      printf("\n");
   }
}