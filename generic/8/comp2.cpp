/*
Béla Budapest
Tamás Halásztelek
Zsófi Alsóbivalybasznád
Erzsébet Gyál
q q
*/


#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

struct Record {
  std::string name;
  std::string address;
};


int main()
{
  std::vector<Record> vr;

  for(std::string a, b; std::cin>>a>>b && (a != "q" || b != "q");)
  {
    Record first;
    first.name = a;
    first.address = b;
    vr.push_back(first);
  }

  std::cout << "Before sort:\n";
  for(const auto& record : vr)
    std::cout << '\t' << record.name <<  ' ' << record.address << std::endl;

  std::sort(vr.begin(), vr.end(),
      [](const Record& a, const Record& b) { return a.name < b.name; });
  std::cout << "After sort by name:\n";
  for(const auto& record : vr)
    std::cout << '\t' << record.name <<  ' ' << record.address << std::endl;

  std::sort(vr.begin(), vr.end(),
      [](const Record& a, const Record& b) { return a.address < b.address; });
  std::cout << "After sort by address:\n";
  for(const auto& record : vr)
    std::cout << '\t' << record.name <<  ' ' << record.address << std::endl;

  return 0;
}
