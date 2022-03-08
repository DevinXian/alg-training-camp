#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
  // priority_queue<int> q1; // 最大堆（默认）
  priority_queue<int, vector<int>, greater<int> > q1; // 最小堆（小顶堆）

  q1.push(3);
  q1.push(1);

  int x;

  while (q1.size())
  {
    cout << q1.top() << endl;
    q1.pop();
  }

  return 0;
}
