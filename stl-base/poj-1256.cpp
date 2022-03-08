#include <iostream>
#include <algorithm>
using namespace std;

// A, a, B, b
int cmp(char a, char b)
{
  // 不同字母，比较前后顺序
  if (tolower(a) != towlower(b))
  {
    return tolower(a) < towlower(b);
  }
  return a < b;
}

int main()
{
  char ch[20];
  int n;

  cin >> n;

  while (n--)
  {
    cin >> ch;
    sort(ch, ch + strlen(ch), cmp); // 全排列从升序开始

    do
    {
      cout << ch << endl;
    } while (next_permutation(ch, ch + strlen(ch), cmp));
  }

  return 0;
}