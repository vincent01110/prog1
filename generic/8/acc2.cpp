#include <iostream>
#include <vector>

template<typename Iterator, typename T, typename BinOp>
T accumulate(Iterator first, Iterator last, T init, BinOp op)
{
  while (first != last){
    init = op(init, *first);
    ++first;
  }

  return init;
};

template<class T>
struct my_multiplies {
  T operator()(const T& a, const T& v) const { return a*v; }
};

double multiply(double a, double v)
{
  return a*v;
}

int main()
{
    std::vector<double> v {1.1, 2.2, 3.3, 4.4, 5.5};
    std::cout << accumulate(v.begin(), v.end(), 1.0,
                            multiply) << std::endl;
    std::cout << accumulate(v.begin(), v.end(), 1.0,
                            my_multiplies<double>()) << std::endl;
    
    return 0;
}
