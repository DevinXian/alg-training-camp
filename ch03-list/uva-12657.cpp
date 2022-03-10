/**
 * @file uva-12657.cpp
 * 不使用 list 作为双向链表，使用数组来模拟静态双向链表实现
 * 原答案多一个头指针，本答案不需要
 */
#include <iostream>
using namespace std;

void print(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
    if (i == size - 1)
      cout << endl;
  }
}

// 数组名即 *int 指针
void init(int data[], int left[], int right[], int size)
{
  for (int i = 0; i < size; i += 1)
  {
    data[i] = i + 1; // data 填充
    left[i] = i - 1;
    right[i] = i + 1;
  }

  // 收尾相连
  left[0] = size - 1;
  right[size - 1] = 0;
}

/**
 * 操作： 1 x y： x移动到y左侧
 *       2 x y： x移动到y右侧
 *       3 x y： x y 交换
 *       4    ： 翻转
 */
int main()
{
  int size, cmdCount;
  bool isReverse = false; // 是否翻转
  int caseNum = 1;

  // 每次输入总长度和命令个数
  while (cin >> size >> cmdCount)
  {
    // data 及左右指针
    int data[size];
    int left[size];
    int right[size];

    // 初始化静态链表
    init(data, left, right, size);

    // 整个调整过程中，data不动，就动指针就对了; 最后根据 index + 1 == data[index] 找对应数据
    int cmd, x, y;

    while (cmdCount--)
    {
      cin >> cmd;

      if (cmd == 4)
      {
        isReverse = !isReverse;
        continue;
      }

      // 操作数
      cin >> x >> y;

      // 如果颠倒，则对称操作互换: 即1->2,2->1
      if (isReverse && cmd != 3)
      {
        cmd = 3 - cmd;
      }

      // 存两个变量抹平 index+1 = ele 这个关系
      int xIndex = x - 1;
      int yIndex = y - 1;

      switch (cmd)
      {
      case 1:
        // x 在 y 左边
        if (xIndex == left[yIndex])
        {
          continue;
        }

        // 1. 删除x(结合图形更好理解)
        // x.right.left = x.left
        // x.left.right = x.right
        left[right[xIndex]] = left[xIndex];
        right[left[xIndex]] = right[xIndex];

        // 2. x放入y左侧
        // y.left.right = x
        // x.left = y.left
        // y.left = x
        // x.right = y
        right[left[yIndex]] = xIndex;
        left[xIndex] = left[yIndex];
        left[yIndex] = xIndex;
        right[xIndex] = yIndex;
        break;
      case 2:
        // x 在 y 右边
        if (xIndex == right[yIndex])
        {
          continue;
        }

        // 1. 删除x
        left[right[xIndex]] = left[xIndex];
        right[left[xIndex]] = right[xIndex];

        // x放入y右侧
        left[right[yIndex]] = xIndex;
        right[xIndex] = right[yIndex];
        right[yIndex] = xIndex;
        left[xIndex] = yIndex;
        break;
      case 3:
        // x在y右边，换成x在y左边，统一处理
        if (right[yIndex] == xIndex)
        {
          swap(xIndex, yIndex);
        }

        // 相邻 - 3次连接
        // x 在 y 左边
        if (right[xIndex] == yIndex)
        {
          left[right[yIndex]] = xIndex;
          right[xIndex] = right[yIndex];

          right[yIndex] = xIndex;
          left[xIndex] = yIndex;

          right[left[xIndex]] = yIndex;
          left[yIndex] = left[xIndex];
        }

        // 不相邻 - 4次连接

        // y 放在x位置 part1
        // x.right.left = y
        // x.left.right = y;

        // x 放在y位置 part1
        // y.left.right = x;
        // y.right.left = x;

        // y 放在x位置 part2
        // y.right = x.right;
        // y.left = x.left;

        // x 放在y位置 part2
        // x.right = y.right;
        // x.left = y.left;
        left[right[xIndex]] = yIndex;
        right[left[xIndex]] = yIndex;
        left[right[yIndex]] = xIndex;
        right[left[yIndex]] = xIndex;

        right[yIndex] = right[xIndex];
        left[yIndex] = left[xIndex];
        right[xIndex] = right[yIndex];
        left[xIndex] = left[yIndex];
        break;

      default:
        break;
      }
    }

    int index = 0;
    long long sum = 0;

    for (int i = 0; i < size; i += 1)
    {
      index = right[index];

      // 奇数位
      if ((i + 1) % 2 == 1)
      {
        sum += index + 1; // index和元素关系
      }
    }

    if (isReverse && (size % 2 == 0))
    {
      sum = (long long)(size - 1) * size / 2 - sum;
    }

    cout << "Case " << caseNum++ << sum << endl;
  }

  return 0;
}