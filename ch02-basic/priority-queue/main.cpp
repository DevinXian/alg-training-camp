/**
 * POJ1442 输出黑盒子第 i 小元素
 * @author tmax
 * @date 2022-02-28
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 最大值优先队列
priority_queue<int> q1;
// 最小值优先队列
priority_queue<int, vector<int>, greater<int> > q2;

// <1...,i-1, i....M>
//   其中 [1, i-1] 放在 q1，表示最小的前 i-1 个数字，其中 i-1为最大，即 q1.top()
//   其中 [i, M] 放在 q2，表示较大的 M-(i-1)个数字，其中 q2.top() 为最小，即整个盒子的第 i 小元素，即是目标值

int main(int argc, char *argv[])
{
  int m, n, x;

  // 读入元素个数和第N次操作时包含元素个数
  scanf("%d%d", &m, &n);

  int a[m + 1];

  for (int i = 1; i <= m; i += 1)
  {
    // 读取元素列表
    scanf("%d", &a[i]);
  }

  // 盒子中的元素个数
  int cnt = 0;

  // 执行 N 次事务
  for (int i = 1; i <= n; i += 1)
  {
    // 当前x值代表：获取第i小元素时盒子里元素个数
    scanf("%d", &x);

    // 元素个数达到 x 个
    while (cnt <= x)
    {
      if (!q1.empty() && a[cnt] < q1.top())
      {
        // 更小元素进来了，则要将最大值 q1.top() 移动到 q2
        q2.push(q1.top());
        q1.pop();
        q1.push(a[cnt]);
      }
      // q1 空，则第1小元素肯定在q2；a[cnt] >= q1.top() 说明非前 i-1 小里面，放入q2
      else
      {
        q2.push(a[cnt]);
      }

      cnt++;
    }

    // q2.top() 就是第 i 小的元素
    cout << "result:" << q2.top() << endl;

    // 下一次，增加 q1 大小，i => i + 1
    q1.push(q2.top());
    q2.pop();
  }

  return 0;
}