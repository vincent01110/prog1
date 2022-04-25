#include <iostream>
#include <vector>
#include <list>
#include <fstream>

using Line = std::vector<char>;

class Text_iterator {
  std::list<Line>::iterator ln;
  Line::iterator pos;
public:
  Text_iterator(std::list<Line>::iterator ll, Line::iterator pp):
                  ln(ll), pos(pp) {}
  std::list<Line>::iterator get_line() const { return ln; }
  Line::iterator get_pos() const { return pos; }

  char& operator*() { return *pos; }
  Text_iterator& operator++();
  bool operator==(const Text_iterator& other)
                const { return ln == other.ln && pos == other.pos; }
  bool operator!=(const Text_iterator& other)
                const { return !(*this==other); }
};

Text_iterator& Text_iterator::operator++()
{
  ++pos;
  if(pos == (*ln).end())
  {
    ++ln;
    pos = (*ln).begin();
  }
  return *this;
}

struct Document {
  std::list<Line> line;
  Document() { line.push_back(Line{}); }

  Text_iterator begin()
  {
    return Text_iterator(line.begin(), (*line.begin()).begin());
  }
  Text_iterator end()
  {
    auto last = line.end();
    --last;
    return Text_iterator(last, (*last).end());
  }
};

std::istream& operator>>(std::istream& is, Document& d)
{
  for(char ch; is.get(ch);)
  {
    d.line.back().push_back(ch);
    if(ch=='\n')
      d.line.push_back(Line{});
  }
  if(d.line.back().size())
    d.line.push_back(Line{});

  return is;
}

void print(Document& d)
{
  for(const auto& e : d)
    std::cout << e;
  std::cout << std::endl;
}

int main(int argc, char** argv)
{
  std::fstream ifs (argv[1]);

  if(!ifs)
  {
    std::cout << "File not found\n";
    return 1;
  }

  Document d;
  ifs >> d;

  print(d);

  return 0;
}
