// 差值中位数（个数）
#include <iostream>
#include <algorithm>
using namespace std;

bool check(int val, int n, int total, int arr[])
{
  int cnt = 0;

  for (int i = 0; i < n; i += 1)
  {
    cnt += n - (lower_bound(arr, arr + n, arr[i] + val) - arr);
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

    while (n--)
    {
      cin >> arr[N - n - 1];
    }

    // 真是麻烦的 C++
    sort(arr, arr + sizeof(arr) / sizeof(arr[0]));

    int l = 0, r = arr[N - 1] - arr[0];
    int total = N * (N - 1) / 4; // 两两差值 N * (N - 1) / 2, 然后取一半

    while (l <= r)
    {
      int mid = (l + r) >> 1;

      // 比中间
      if (check(mid, N, total, arr))
      {
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
