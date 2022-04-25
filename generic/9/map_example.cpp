#include <map>
#include <iostream>

int main()
{
  std::map<std::string, double> dow_price = {
    {"MMM", 81.86},
    {"AA", 34.69},
    {"MO", 54.45}
  };
  std::map<std::string, double> dow_weight = {
    {"MMM", 5.8549},
    {"AA", 2.4808},
    {"MO", 3.894}
  };
  std::map<std::string, std::string> dow_name = {
    {"MMM", "3M Co."},
    {"AA", "Alcoa. Inc."},
    {"MO", "Altria Group Inc."}
  };

  double alcoa_price = dow_price["AA"];
  std::cout << dow_name["AA"] << ' ' << alcoa_price << std::endl;

  return 0;
}
