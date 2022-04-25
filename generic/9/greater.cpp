#include <list>
#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
  int m = 20;
  std::ostream& os = std::cout;
  std::vector<int> v = {10, 20, 30, 40, 50};
  std::list<double> l = {10, 200, 31, 20, 560};

  auto Greater_print = [&os, m]<typename K>(K x) {if(x>m) os<<'\t'<<x<<'\n'; };

  std::cout << "v > m:" << std::endl;
  std::for_each(v.begin(), v.end(), Greater_print);

  std::cout << "l > m:" << std::endl;
  std::for_each(l.begin(), l.end(), Greater_print);




  return 0;
}
