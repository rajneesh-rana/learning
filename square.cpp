#include<stdio.h>

unsigned int squareRoot(int n)
{
  int x = n;
  int y = 1;
  while(x > y)
  {
    x = (x + y)/2;
    y = n/x;
  }
  return x;
}
 
/* Driver program to test above function*/
int main()
{
  int n = 48;
  printf (" root of %d is %d", n, squareRoot(n));
  getchar();
}
