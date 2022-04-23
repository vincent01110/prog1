#include <vector>
#include <iostream>
#include <memory>

std::vector<int>* suspicious()
{
  //std::vector<int>* si = new vector<int>;
  //std::unique_ptr<std::vector<int>> v {new std::vector<int>};
  std::unique_ptr<std::vector<int>> v =
        std::make_unique<std::vector<int>>();
  //nincs new, nem akkora a különbség de jobb

  for(int i; std::cin>>i;)
  {
    if(i) v->push_back(i);
    else throw std::exception();
  }
  return v.release(); //a unique_ptr-től elvesszük a "tulajdonjogot"
}

int main()
try {
  std::vector<int>* vi = suspicious();

  for(int i = 0; i < vi->size(); ++i)
      std::cout << vi->at(i) << std::endl;

  delete vi;
  return 0;
}
catch(std::exception& e) {
  std::cerr << "Error" << std::endl;
  return 1;
}
