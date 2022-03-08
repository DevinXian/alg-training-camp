// 差值中位数（个数）
#include <iostream>
#include <algorithm>
using namespace std;

// 关键逻辑
bool check(int mid, int n, int total, int arr[])
{
  int cnt = 0;

  for (int i = 0; i < n; i += 1)
  {
    // 寻找第1个大于等于 mid 值的元素
    int *k = lower_bound(arr, arr + n, arr[i] + mid);
    // k-arr 返回小于 *k 的个数，然后累加
    cnt += n - (k - arr);
  }

  return cnt > total;
}

int main()
{
  int n;
  int ans;

  // 输入 0 结束
  while ((cin >> n) && n)
  {
    int arr[n];
    int N = n;

    // 读入元素
    while (n--)
    {
      cin >> arr[N - n - 1];
    }

    // 真是麻烦的 C++
    sort(arr, arr + sizeof(arr) / sizeof(arr[0]));

    int l = 0, r = arr[N - 1] - arr[0]; // r 为元素最大差
    int total = N * (N - 1) / 4;        // 两两差值 N * (N - 1) / 2, 然后取一半

    // 以“差值”作为范围进行二分查找
    while (l <= r)
    {
      int mid = (l + r) >> 1;

      // 比差值中间值大的多于 total， 说明较大数占多数，向右查看
      if (check(mid, N, total, arr))
      {
        // 中位差值可能存在此范围
        ans = mid;
        l = mid + 1;
      }
      else
      {
        r = mid - 1;
      }
    }

    cout << "result:" << ans << endl;
  }

  return 0;
}
