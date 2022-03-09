#include <iostream>
#include <vector>

using namespace std;

// 理应放局部变量- -
int n;
vector<int> block[30];

void init(int n, vector<int> *vec)
{

  for (int i = 0; i < n; i += 1)
  {
    vec[i].push_back(i); // 向结尾push初始元素
  }
}

// 找位置，将引用传递进来
void loc(int x, int &p, int &h)
{
  for (int i = 0; i < n; i += 1)
  {
    for (int j = 0; j < block[i].size(); j += 1)
    {
      if (block[i][j] == x)
      {
        p = i;
        h = j;
      }
    }
  }
}

/**
 * 将p块高于h的块还原
 * @param p 第几块
 * @param h 高度h(索引)
 */
void goBack(int p, int h)
{
  // h+1 是排除自身
  for (int i = h + 1; i < block[p].size(); i += 1)
  {
    // 第几块
    int k = block[p][i];
    // 放回
    block[k].push_back(k);
  }

  block[p].resize(h + 1); // 本身还在, 0~h 下标都在，其中h放本身
}

/**
 * 将p块高度 >=h 的块移动到q块上方
 * @param p 源块
 * @param h 高度
 * @param q 目标块
 */
void moveAll(int p, int h, int q)
{
  for (int i = h; i < block[p].size(); i += 1)
  {
    block[q].push_back(block[p][i]);
  }

  // 注意长度和索引的差别，小标为h的已经被移走，剩下0~h-1共h个
  block[p].resize(h);
}

void solve()
{
  int a, b;      // 两个目标块
  string s1, s2; // 动作

  while (cin >> s1)
  {
    if (s1 == "quit")
    {
      break;
    }

    cin >> a >> s2 >> b;

    int ap = 0, ah = 0, bp = 0, bh = 0;

    // 找出a的位置（所在块和所在高度）
    loc(a, ap, ah);
    // 找出b的位置
    loc(b, bp, bh);

    // 在相同块，跳过
    if (ap == bp)
    {
      continue;
    }

    // s1 归位
    if (s1 == "move")
    {
      goBack(ap, ah);
    }
    // s2 归位
    if (s2 == "onto")
    {
      goBack(bp, bh);
    }

    // a及上面的块移动到b块上
    moveAll(ap, ah, bp);

    print();
  }
}

void print()
{
  for (int i = 0; i < n; i += 1)
  {
    cout << i << ": ";
    for (int j = 0; j < block[i].size(); j += 1)
    {
      cout << " " << block[i][j];
    }
    cout << endl;
  }
}

int main()
{
  cin >> n;

  init(n, block);
  print();
  solve();
  print();

  return 0;
}