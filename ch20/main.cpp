#include "std_lib_facilities.h"
#include <iterator>

void print_all(int* a, vector<int> v, list<int> l)
{
  for(int i = 0; i < 10; ++i)
    cout << a[i] << ' ';
  cout << endl <<"------------------------------" << endl;

  for(int i = 0; i < 10; ++i)
    cout << v[i] << ' ';
  cout << endl << "------------------------------" << endl;

  for(const auto& e : l)
    cout << e << ' ';
  cout << endl << "------------------------------" << endl;
}

template<typename Iter1, typename Iter2>
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
  while (f1!=e1) {
      *f2 = *f1;
      ++f1;
      ++f2;
  }
  return f2;
}



int main()
{
  int* arr = new int[10]{0,1,2,3,4,5,6,7,8,9};
  vector<int> vec {0,1,2,3,4,5,6,7,8,9};
  list<int> ls {0,1,2,3,4,5,6,7,8,9};
  print_all(arr, vec, ls);

  for(int i = 0; i < 10; ++i)
    arr[i] += 2;
  for(vector<int>::iterator p = vec.begin(); p!=vec.end(); ++p)
    *p += 3;

  for(list<int>::iterator p = ls.begin(); p!=ls.end(); ++p)
    *p += 5;
  print_all(arr, vec, ls);

  int* arr2 = arr;
  vector<int> vec2 = vec;
  list<int> ls2 = ls;
  print_all(arr2, vec2, ls2);

  my_copy(arr, &arr[9], vec.begin());
  my_copy(ls.begin(), ls.end(), arr);
  cout << "after copy" << endl;
  print_all(arr, vec, ls);


  auto p = find(vec.begin(), vec.end(), 3);
  if(p == vec.end())
    cout << "Vec does not contain 3" << endl;
  else
    cout << "'3' in vec at==" << distance(vec.begin(), p) << endl;

  p = find(vec.begin(), vec.end(), 27);
  if(p == vec.end())
    cout << "Vec does not contain 27" << endl;
  else
    cout << "'27' in vec at==" << distance(vec.begin(), p) << endl;
}
