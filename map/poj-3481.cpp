#include <iostream>
#include <map>

using namespace std;

int main()
{
  // k 为标识，p 为优先级
  int n, k, p;

  map<int, int> mp;
  map<int, int>::iterator it;

  // 输入0退出
  while (cin >> n && n)
  {
    switch ((n))
    {
    case 1:
      cin >> k >> p;
      mp.insert(make_pair(p, k));
      break;
    case 2:
      if (mp.empty())
      {
        cout << 0 << endl;
        break;
      }

      it = --mp.end();
      cout << it->second << endl;
      mp.erase(it);
      break;
    case 3:
      if (mp.empty())
      {
        cout << 0 << endl;
        break;
      }
      it = mp.begin();
      cout << it->second << endl;
      mp.erase(it);
      break;

    default:
      break;
    }
  }

  return 0;
}