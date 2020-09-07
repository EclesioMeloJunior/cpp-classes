#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    int n;

    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
      cin >> a[i];

    std::sort(a.begin(), a.end());

    if (a.front() == a.back())
      cout << n << endl;
    else
      cout << 1 << endl;
  }

  return 0;
}