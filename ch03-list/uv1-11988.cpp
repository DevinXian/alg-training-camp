/**
 * @file uv1-11988.cpp 悲剧文字
 */
#include <iostream>
#include <list>

using namespace std;

void solve(string *s)
{
  int len = s->length();

  // 双向链表存文本: 用户处理 [(Home) 和 ] (End)字符跳跃问题
  list<char> text;
  list<char>::iterator it = text.begin();
  string::iterator it2;

  // 字符串便利方式很多，此处随机选用迭代器
  for (it2 = s->begin(); it2 != s->end(); it2++)
  {
    if ((*it2) == '[') // char 单引号哦
    {
      it = text.begin();
    }
    else if ((*it2) == ']')
    {
      it = text.end();
    }
    else
    {
      it = text.insert(it, *it2);
      it++;
    }
  }

  for (it = text.begin(); it != text.end(); it++)
  {
    cout << *it;
  }

  s->clear();
  cout << endl;
}

int main()
{
  string s;

  cin >> s;

  solve(&s);

  return 0;
}