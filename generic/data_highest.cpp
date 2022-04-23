#include <iostream>
#include <vector>

double* get_from_jack(int* count)
{
  double* jack_array = new double[6];

  for(int i = 0; i < 6; ++i)
      jack_array[i] = i*3;
  jack_array[1] = 81;
  *count = 6;

  return jack_array;
}

std::vector<double>* get_from_jill()
{
  std::vector<double>* jill_vector = new std::vector<double>;
  *jill_vector = {100, 500, 300, 400};
  return jill_vector;
}

/*
double* high(double* first, double* last)
{
  double h = -1;
  double* high;
  for(double* p = first; p != last; ++p)
      if(h < *p) { high = p; h = *p; }
  return high;
}*/

template<typename Iterator>
Iterator high(Iterator first, Iterator last)
{
  Iterator high = first;
  for(Iterator p = first; p != last; ++p)
      if(*high < *p) high = p;
  return high;
}

int main()
{
  int jack_count = 0;
  double* jack_data = get_from_jack(&jack_count);

  std::cout << "Jack_data: " << std::endl;
  for(int i = 0; i < jack_count; ++i)
      std::cout << jack_data[i] << ' ';
  std::cout << std::endl;

  std::vector<double>* jill_data = get_from_jill();
  std::cout << "Jill_data: " << std::endl;
  for(auto i : *jill_data)
      std::cout << i << ' ';
  std::cout << std::endl;

  double h = -1;

  double* jack_high;
  double* jill_high;

  for(int i = 0; i < jack_count; ++i)
  {
      if(h < jack_data[i])
      {
        jack_high = &jack_data[i];
        h = jack_data[i];
      }
  }

  h = -1;

  for(int i = 0; i < jill_data->size(); ++i)
  {
    if(h < (*jill_data)[i])
    {
      jill_high = &(*jill_data)[i];
      h = (*jill_data)[i];
    }
  }

  std::cout << "Jill_high: " << *jill_high
            << " Jack_high: " << *jack_high << std::endl;


  std::vector<double>& jill_vector_ref = *jill_data;
  h = -1;
  for(int i = 0; i < jill_vector_ref.size(); ++i)
      if(h<jill_vector_ref[i])
      {
        jill_high = &jill_vector_ref[i];
        h = jill_vector_ref[i];
      }


  jack_high = high(jack_data, jack_data+jack_count);
  jill_high = high(&jill_vector_ref[0],
        &jill_vector_ref[0]+jill_vector_ref.size());

  std::cout << "Jill_high: " << *jill_high
            << " Jack_high: " << *jack_high << std::endl;

  double* jack_middle = jack_data + jack_count/2;
  double* jack_first_half = high(jack_data, jack_middle);
  double* jack_second_half = high(jack_middle, jack_data+jack_count);

  std::cout << "Jack_first_half: " << *jack_first_half
            << " Jack_second_half: " << *jack_second_half << std::endl;

  delete[] jack_data;
  delete jill_data;
  return 0;
}
