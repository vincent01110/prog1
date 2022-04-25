#include <map>
#include <iostream>

using namespace std;

int main()
{
  map<string, int> msi {
    {"ab", 1},
    {"cd", 2},
    {"ef", 3},
    {"gh", 4},
    {"ij", 5},
    {"kl", 6},
    {"mn", 7},
    {"op", 8},
    {"qr", 9},
    {"st", 10}
  };

  for(const auto& e : msi)
    cout << '\t' << e.first << ' ' << e.second << endl;

  msi.erase(msi.begin(), msi.end());
  cout << "Erase check" << endl;
  for(const auto& e : msi)
    cout << '\t' << e.first << ' ' << e.second << endl;

  cout << "user input map" << endl;
  string l;
  int v;
  while(cin>>l>>v)
  {
    msi[l] = v;
    if(msi.size() == 10) break;
  }
  for(const auto& e : msi)
    cout << '\t' << e.first << ' ' << e.second << endl;

  int sum = 0;
  for(const auto& e : msi)
    sum += e.second;
  cout << "sum of values==" << sum << endl;

  map<int, string> mis;
  for(const auto& e : msi)
    mis[e.second] = e.first;
  cout << "mis:" << endl;
  for(const auto& e : mis)
    cout << '\t' << e.first << ' ' << e.second << endl;


}
