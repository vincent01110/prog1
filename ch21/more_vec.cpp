#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

template<typename Iterator, typename Dest, typename Pred>
Dest my_copy(Iterator first, Iterator last, Dest dest, Pred pred)
{
  while(first!=last)
  {
    if(pred(*first))
    {
      (*dest) = (*first);
      ++dest;
    }
    ++first;
  }
  return dest;
}

int main()
{
  vector<double> vd;
  string iname = "input2.txt";
  ifstream ist{iname};
  if (!ist) cout << "can't open input file==" << iname;
  for(double d; ist>>d;) {
    vd.push_back(d);
  }
  /*for(const auto& e : vd)
    cout << e << endl;*/

  vector<int> vi;
  for(const auto& e : vd)
    vi.push_back((int)e);
  for(int i = 0; i < vd.size(); ++i)
    cout << vd[i] << '\t' << vi[i] << endl;

  int sum_vd = 0, sum_vi = 0;
  for(int i = 0; i < vd.size(); ++i)
  {
    sum_vd += vd[i];
    sum_vi += vi[i];
  }
  cout << "\nsum of vd==" << sum_vd << endl;
  cout << "sum of vi==" << sum_vi << endl;
  double diff = abs(sum_vd - sum_vi);
  cout << "diff of sum_vd and sum_vi==" << diff << endl;

  cout << "\nReverse vd==" << endl;
  reverse(vd.begin(), vd.end());
  for(const auto& e : vd)
    cout << e << endl;

  double mean_value = (double)sum_vd/vd.size();
  cout << "\nmean value of vd==" << mean_value << endl;

  cout << "\nvd2==" << endl;
  vector<double> vd2(vd.size());
  my_copy(vd.begin(), vd.end(), vd2.begin(),
          [&](double x) -> bool { return x < mean_value; });
  for(const auto& e : vd2)
    if(e != 0) cout << '\t' << e << endl;

  cout << "\nAfter sort" << endl;
  sort(vd.begin(), vd.end());
  for(const auto& e : vd)
    cout << '\t' << e << endl;
}
