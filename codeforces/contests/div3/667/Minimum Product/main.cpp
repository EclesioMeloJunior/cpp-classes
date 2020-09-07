#include <iostream>

using namespace std;

int minproduct(int a, int b, int x, int y, int n)
{
  if (a == x && b == y)
    return 0;

  for (int i = 0; i < n; i++)
  {
    int diffB = b - y;
    int diffA = a - x;

    if (diffB == 0 && diffA == 0)
      break;

    if (diffB == 0 && diffA > 0)
    {
      a--;
      continue;
    }

    if (diffA == 0 && diffB > 0)
    {
      b--;
      continue;
    }

    if (diffB > diffA)
    {
      a--;
    }
    else if (diffB < diffA)
    {
      b--;
    }
  }

  return a * b;
}

int main()
{
  int t;

  cin >> t;

  for (int i = 0; i < t; i++)
  {
    long int a = 0, b = 0, x = 0, y = 0, n = 0;

    cin >> a >> b >> x >> y >> n;

    cout << minproduct(a, b, x, y, n) << endl;
  }

  return 0;
}