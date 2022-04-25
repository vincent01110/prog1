#include <map>
#include <iostream>

int main()
{
  std::map<std::string, int> words;

  for(std::string s; std::cin>>s;)
    ++words[s];

  for(const auto& e : words)
    std::cout << e.first << ": " << e.second << std::endl;

  std::cout << words["the"] << std::endl;
  return 0;
}
