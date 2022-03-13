/**
 * 计算矩阵相乘次数
 */
#include <iostream>
#include <stack>

using namespace std;

const int maxSize = 26;

// 矩阵结构体
struct Matrix
{
  int lineCnt, colCnt; // 行列数
  Matrix(int a = 0, int b = 0) : lineCnt(a), colCnt(b) {}
} matrixList[maxSize];

int main()
{
  int caseCnt;
  cin >> caseCnt;

  stack<Matrix> s;
  string exp; // 表达式
  char c;     // A 30 20 矩阵名称和维度

  while (caseCnt--)
  {
    cin >> c;
    int k = c - 'A'; // ABC转换为下标
    cin >> matrixList[k].lineCnt >> matrixList[k].colCnt;
  }

  while (cin >> exp)
  {
    bool isError = false;
    int len = exp.length();
    int ans = 0;

    // A(BC) 如果是矩阵就入栈，如果是 ( 什么都不做，如果是 ) 表示要优先运算栈顶
    for (int i = 0; i < len; i += 1)
    {
      // 字母则入栈
      if (isalpha(exp[i]))
      {
        s.push(matrixList[exp[i] - 'A']);
      }
      else if (exp[i] == ')')
      {
        // m1 x m2
        Matrix m2 = s.top();
        s.pop();
        Matrix m1 = s.top();
        s.pop();

        // 矩阵相乘规则
        if (m1.colCnt != m2.lineCnt)
        {
          isError = true;
          break;
        }

        ans += m1.lineCnt * m1.colCnt * m2.colCnt;
        s.push(Matrix(m1.lineCnt, m2.colCnt));
      }
    }

    if (isError) {
      cout << "error" << endl;
    } else {
      cout <<ans<<endl;
    }
  }

  return 0;
}
