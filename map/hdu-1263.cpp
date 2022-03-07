#include <iostream>
#include <map>

using namespace std;

typedef map<string, map<string, int> > TMap;

int main()
{
  int n, m, count;
  string name, addr;
  TMap mp;

  // n 组测试数据
  cin >> n;

  while (n--)
  {
    cin >> m; // m 组成功交易

    for (int i = 0; i < m; i += 1)
    {
      cin >> name >> addr >> count;

      mp[addr][name] += count;
    }

    TMap::iterator it1;
    map<string, int>::iterator it2;

    for (it1 = mp.begin(); it1 != mp.end(); it1++)
    {
      cout << it1->first << endl;

      for (it2 = it1->second.begin(); it2 != it1->second.end(); it2++)
      {
        cout << "  |----" << it2->first << "(" << it2->second << ")" << endl;
      }
    }

    if (n)
    {
      cout << endl;
    }
  }

  return 0;
}