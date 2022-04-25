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

struct Compare_by_name {
  bool operator()(const Record& a, const Record& b) const
  { return a.name < b.name; }
};

struct Compare_by_address {
  bool operator()(const Record& a, const Record& b) const
  { return a.address < b.address; }
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

  std::sort(vr.begin(), vr.end(), Compare_by_name());
  std::cout << "After sort by name:\n";
  for(const auto& record : vr)
    std::cout << '\t' << record.name <<  ' ' << record.address << std::endl;

  std::sort(vr.begin(), vr.end(), Compare_by_address());
  std::cout << "After sort by address:\n";
  for(const auto& record : vr)
    std::cout << '\t' << record.name <<  ' ' << record.address << std::endl;

  return 0;
}
