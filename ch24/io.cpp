#include <iostream>
#include "Matrix.h"
#include <cmath>
#include <complex>

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

void f4()
{
  int a;
  while(std::cin>>a)
    io_sqrt(a);
}

void f5()
{
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
}

void f6()
{
  int n;
  int m;
  std::cout << "Enter n==";
  std::cin>>n;
  std::cout << std::endl;
  std::cout << "Enter m==";
  std::cin>>m;
  Numeric_lib::Matrix<int, 2> mult(n,m);
  for(int i = 0; i < mult.dim1(); ++i)
  {
    for(int j = 0; j < mult.dim2(); ++j)
    {
      mult[i][j] = (i+1)*(j+1);
      std::cout << mult[i][j] << '\t';
    }
    std::cout << std::endl;
  }
}

void f7()
{
  std::complex<double> s;
  Numeric_lib::Matrix<std::complex<double>> mc(10);
  for(int i = 0; i < 10; ++i)
  {
    std::cin>>s;
    mc[i] = s;
  }
  std::complex<double> sum;
  for(int i = 0; i < mc.dim1(); ++i)
    sum+=mc[i];
  std::cout << "sum_of_complex==" << sum << std::endl;
}

void f8()
{
  Numeric_lib::Matrix<int, 2> m(2,3);
  for(int i = 0; i < m.dim1(); ++i)
  {
    for(int j = 0; j < m.dim2(); ++j)
    {
      std::cin>>m[i][j];
    }
  }

  for(int i = 0; i < m.dim1(); ++i)
  {
    for(int j = 0; j < m.dim2(); ++j)
    {
      std::cout << m[i][j] << '\t';
    }
    std::cout << std::endl;
  }
}

int main()
{
  f5();
  f4();
  f6();
  f7();
  f8();

  return 0;
}
