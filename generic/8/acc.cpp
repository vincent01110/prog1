#include <iostream>
#include <vector>

template<typename Iterator, typename T>
T accumulate(Iterator first, Iterator last, T init)
{
  while (first != last){
    init = init + *first;
    ++first;
  }

  return init;
};

int main()
{
    std::vector<double> v {1.1, 2.2, 3.3, 4.4, 5.5};
    std::cout << accumulate(v.begin(), v.end(), 0.0) << std::endl;

    return 0;
}
