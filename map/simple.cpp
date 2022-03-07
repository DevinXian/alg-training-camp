#include <iostream>
#include <map>
using namespace std;

int main()
{
  multimap<string, int> mp;
  string s1("X"), s2("Y");

  mp.insert(make_pair(s1, 10));
  mp.insert(make_pair(s1, 20));
  mp.insert(make_pair(s2, 3));
  mp.insert(make_pair(s2, 4));

  multimap<string, int>::iterator it;
  it = mp.find(s1);

  // 不能使用 it += 1 代替 it++ 的原因
  // Iterator for std::map is defined by standard as Bidirectional Iterator.
  // This type of iterators can be incremented(operator ++) and decremented (operator --),
  // but you can't perform mathematical operations on them (mostly because it would take O(n) time rather than O(1))
  for (int k = 0; k < mp.count(s1); k += 1, it++)
  {
    cout << it->first << ":" << it->second << endl;
  }

  return 0;
}