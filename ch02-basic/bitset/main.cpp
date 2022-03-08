#include <iostream>
using namespace std;

const int maxn = 1000;
bitset<100> s[maxn];

int main()
{
  int N, Q, num, x, y;

  cin >> N;

  // i 表示第几个集合
  for (int i = 1; i <= N; i += 1)
  {
    cin >> num;

    while (num--)
    {
      cin >> x;
      // 每个数在第几个集合，对应位 set 1
      s[x][i] = 1;
    }
  }

  cin >> Q;

  while (Q--)
  {
    cin >> x >> y;

    if ((s[x] & s[y]).count()) // 位与，个数不为0，表示共有
    {
      cout << "Yes" << endl;
    }
    else
    {
      cout << "No" << endl;
    }
  }
  return 0;
}