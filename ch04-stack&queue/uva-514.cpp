/**
 * UVA-514 人字轨车厢进出
 * @copyright Copyright (c) 2022
 */
#include <iostream>
#include <stack>

using namespace std;

int main()
{
  int n;

  while (cin >> n && n)
  {
    cout << "n:" << n << endl;
    while (true)
    {
      int i = 0, j = 0;
      int out[n];

      cin >> out[0];

      // 为 0 则跳过
      if (!out[0])
        break;

      // 驶出顺序
      for (int k = 1; k < n; k += 1)
      {
        cin >> out[k];
      }

      for(int m = 0; m < n; m++) {
        cout << " " << out[m] << endl;
      }

      // 中间栈
      stack<int> s;

      // 1 2 3... 顺序驶入
      while (i < n)
      {
        // 相等则表示out前面部分可以直接出
        if (out[j] == i + 1)
        {
          i += 1;
          j += 1;
        }
        // 不相等则压入栈
        else
        {
          s.push(i + 1);
          i += 1;
        }

        // 栈非空，则从栈顶判断
        while (!s.empty() && out[j] == s.top())
        {
          // out 向后移动
          j += 1;
          s.pop();
        }
      }

      cout << "j = " << j << endl;
      // 判断是不是队列完备了
      if (j == n)
      {
        cout << "Yes" << endl;
      }
      else
      {
        cout << "No" << endl;
      }
    }
    cout << endl;
  }

  return 0;
}