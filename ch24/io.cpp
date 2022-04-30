#include <iostream>
#include "Matrix.h"
#include <cmath>

/*
1
34
5
3.4
54.4
2.3
1.2
2.4
5.2
4.3
*/


void io_sqrt(int x)
{
  if (!sqrt(x))
    std::cout << "no square root" << std::endl;
  else
    std::cout << "   sqrt_of_" << x << "==" << sqrt(x) << std::endl;
}

int main()
{
  /*
  int a;
  while(std::cin>>a)
    io_sqrt(a);
  */


  Numeric_lib::Matrix<double> m(10);
  double d;
  for(int i = 0; i < 10; ++i)
  {
    std::cin>>d;
    m[i] = d;
  }
  for(int i = 0; i < 10; ++i)
    std::cout << m[i] << ' ';
  std::cout << std::endl;


  return 0;
}
