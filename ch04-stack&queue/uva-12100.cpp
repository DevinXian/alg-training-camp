#include <iostream>
#include <vector>
#include <queue>

using namespace std;

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
    vector<int> tasks;
    // 任务优先级队列降序排列
    vector<int> order;
    // 任务优先级下标队列
    deque<int> indexes;

    int x;
    int result = 0; // 执行分钟数

    for (int j = 0; j < taskCnt; j += 1)
    {
      cin >> x;
      tasks.push_back(x);
      order.push_back(x);
      indexes.push_back(j);
    }

    sort(order.begin(), order.end(), greater<int>());

    // 最大优先级所在 index
    int maxWeightIndex = 0;
    // 最大优先级
    int maxWeight = 0;

    while (!indexes.empty())
    {
      maxWeight = order[maxWeightIndex];

      int currentIndex = indexes.front();

      // 优先级低，往后排
      if (tasks[currentIndex] < maxWeight)
      {
        indexes.pop_front();
        indexes.push_back(currentIndex);
      }
      else
      {
        if (currentIndex == taskIndex)
        {
          // 结果已定
          cout << ++result << endl;
          break;
        }

        else
        {
          indexes.pop_front();
          result += 1;
          maxWeightIndex += 1;
        }
      }
    }

    // for (int i = taskIndex; i < taskCnt; i += 1)
    // {
    //   int maxWeight = order[maxWeightIndex];

    //   // 优先级低
    //   if (tasks[i] < maxWeight)
    //   {

    //   }
    // }
  }

  return 0;
}