#include <iostream>
#include <set>
using namespace std;

bool vis[10005]; // 删除标记列表
multiset<int> s; // 默认为升序
int k;

void del(int p)
{
  if (s.empty())
  {
    cout << -1 << endl;
    return;
  }

  if (p == 1)
  {
    if (vis[k++]) // 如果打标记了，则删除最小成本的 p==1
    {
      cout << *s.begin() << endl;
    }
    s.erase(*s.begin());
  }
  else
  {
    if (vis[k++]) // 如果打标记了，则删除最大成本的
    {
      cout << *s.rbegin() << endl;
    }
    s.erase(*s.rbegin());
  }
}

int main()
{
  char c;
  int m, n, x, p;


  while (~scanf("%d%d", &m, &n))
  {
    memset(vis, false, sizeof(vis));
    s.clear();

    for (int i = 0; i < n; i += 1)
    {
      cin >> x;
      vis[x] = true; // 删除哪些位置，打标记
    }

    p = 1;
    k = 1;

    while (cin >> c)
    {
      if (c == 'e')
        break;
      if (c == 'a')
      {
        cin >> x;
        s.insert(x);
      }
      else if (c == 'p')
      {
        cin >> x;
        p = x;
      }
      else if (c == 'r')
      {
        del(p);
      }

      cout << endl;
    }
  }

  return 0;
}
