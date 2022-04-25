#include <map>
#include <iostream>
#include <numeric>

double weighted_value(
  const std::pair<std::string, double>& a,
  const std::pair<std::string, double>& b)
{
  return a.second * b.second;
}

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


  if(dow_price.find("INTC") != dow_price.end())
    std::cout << "Intel is in DOW" << std::endl;
  else
    std::cout << "Intel is NOT in DOW" << std::endl;

  double dji_index = std::inner_product(dow_price.begin(), dow_price.end(),
                                        dow_weight.begin(), 0.0,
                                        std::plus<double>(), weighted_value);

  std::cout << "DJI index: " << dji_index << std::endl;
  return 0;
}
