/**
 * @file uva-12657.cpp
 * 不使用 list 作为双向链表，使用数组来模拟静态双向链表实现
 */
#include <iostream>
using namespace std;

int leftPointers[100005], rightPointers[100005];

void print(int arr[], int size)
{
  for (int i = 0; i < size + 1; i++)
  {
    cout << arr[i] << " ";
    if (i == size)
      cout << endl;
  }
}

void init(int size)
{
  for (int i = 0; i < size; i += 1)
  {
    leftPointers[i + 1] = i;
    rightPointers[i + 1] = (i + 2) % (size + 1); // 循环: 头指针 + size
  }

  // 收尾相连
  leftPointers[0] = size;
  rightPointers[0] = 1;
}

void link(int l, int r)
{
  rightPointers[l] = r;
  leftPointers[r] = l;
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
  int caseNum = 1;

  // 每次输入总长度和命令个数
  while (cin >> size >> cmdCount)
  {
    bool isReverse = false; // 是否翻转
    // 初始化静态链表
    init(size);

    cout << "leftPointers:" << endl;
    print(leftPointers, size);
    cout << "rightPointers:" << endl;
    print(rightPointers, size);

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

      // x 已经在 y 左边
      if (cmd == 1 && x == leftPointers[y])
      {
        continue;
      }
      // x 已经在 y 右边
      if (cmd == 2 && x == rightPointers[y])
      {
        continue;
      }
      // x y 相邻且 x 在 y 右边, 则换到左边
      if (cmd == 3 && rightPointers[y] == x)
      {
        swap(x, y); // 一定要在前面
      }

      // 预定义 x 和 y 左右位置
      int yLeft = leftPointers[y];
      int xLeft = leftPointers[x];
      int yRight = rightPointers[y];
      int xRight = rightPointers[x];

      if (cmd == 1)
      {

        // 1. 删除x(结合图形更好理解)
        link(xLeft, xRight);
        // 2. x放入y左侧
        link(yLeft, x);
        link(x, y);
      }

      if (cmd == 2)
      {
        // 1. 删除x
        link(xLeft, xRight);
        // x放入y右侧
        link(y, x);
        link(x, yRight);
      }

      if (cmd == 3)
      {
        // 相邻 - 3次连接
        // x 在 y 左边
        if (rightPointers[x] == y)
        {
          // notice：如果不使用临时变量，需要注意调用顺序!!!
          link(xLeft, y);
          link(y, x);
          link(x, yRight);
        }
        else
        {
          // 不相邻 - 4次连接
          link(xLeft, y);
          link(y, xRight);
          link(yLeft, x);
          link(x, yRight);
        }
      }

      cout << "left:" << endl;
      print(leftPointers, size);
      cout << "right:" << endl;
      print(rightPointers, size);
    }

    cout << "left:" << endl;
    print(leftPointers, size);
    cout << "right:" << endl;
    print(rightPointers, size);

    int next = 0; // 头指针
    long long sum = 0;

    for (int i = 0; i < size; i += 1)
    {
      next = rightPointers[next];

      cout << "i: " << i + 1 << ", ele: " << next << endl;
      // 链表奇数位相加
      if ((i + 1) % 2 == 1)
      {
        // cout << "i:" << i << ", ele:" << ele << endl;
        sum += next;
      }
    }

    cout << "before sum revered:" << sum << endl;

    if (isReverse && (size % 2 == 0))
    {
      cout << "total: " << (long long)(size + 1) * size / 2 << endl;
      sum = (long long)(size + 1) * size / 2 - sum;
      cout << "after reversed, sum: " << sum << endl;
    }

    cout << "Case " << caseNum++ << ": " << sum << endl;
  }

  return 0;
}