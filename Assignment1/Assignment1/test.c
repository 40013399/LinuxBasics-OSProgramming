#include<stdio.h>
#include "fun.h"
int main() 
{
  int a, b, c, d,e;
  a = 10;
  b = 20;
  c=4;
  d = sum(a,b);
  e = square(c);
  printf("sum is %d\n",d);
  printf("square is %d\n",e);
  return 0;
}
