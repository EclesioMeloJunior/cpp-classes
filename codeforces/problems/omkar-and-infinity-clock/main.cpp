#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int t;

  cin >> t;

  while (t--)
  {
    int n;
    long long k;

    cin >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
      cin >> a[i];

    if (k > 1)
    {
      k = 2 + k % 2;
    }

    while (k--)
    {
      int max_global = a[0];

      for (int i = 1; i < n; i++)
        max_global = max(max_global, a[i]);

      for (int i = 0; i < n; i++)
        a[i] = max_global - a[i];
    }

    for (int i = 0; i < n; i++)
      cout << a[i] << (i + 1 == n ? '\n' : ' ');
  }

  return 0;
}