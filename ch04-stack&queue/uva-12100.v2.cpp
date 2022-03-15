#include <iostream>
#include <queue>

using namespace std;

// 比原答案减少一个队列
int main()
{
  // 总case数量
  int caseCnt;
  cin >> caseCnt;

  while (caseCnt--)
  {
    // 任务数量，任务下标
    int taskCnt, taskIndex;

    cin >> taskCnt >> taskIndex;

    // 任务优先级队列
    deque<int> tasks;
    // 任务优先级队列降序排列
    deque<int> order;

    int x;
    int result = 0; // 执行分钟数

    for (int j = 0; j < taskCnt; j += 1)
    {
      cin >> x;
      tasks.push_back(x);
      order.push_back(x);
    }

    sort(order.begin(), order.end(), greater<int>());

    while (!tasks.empty())
    {
      int currentTask = tasks.front();

      // 优先级低，往后排
      if (currentTask < order.front())
      {
        tasks.pop_front();
        tasks.push_back(currentTask);

        // 如果是目标任务，放到最后
        if (taskIndex == 0)
        {
          taskIndex = tasks.size() - 1;
        }
        else
        {
          // 不是，则向前移动
          taskIndex -= 1;
        }
      }
      else
      {
        if (taskIndex == 0)
        {
          // 结果已定
          cout << ++result << endl;
          break;
        }
        else
        {
          // 优先级最高的pop掉
          order.pop_front();
          tasks.pop_front();
          result += 1;
          taskIndex -= 1;
        }
      }
    }
  }

  return 0;
}