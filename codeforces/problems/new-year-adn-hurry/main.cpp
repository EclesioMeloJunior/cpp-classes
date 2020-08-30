#include <iostream>

using namespace std;

int main()
{
  int n, k, acc = 0, total = 0, min = 240;

  cin >> n >> k;

  for (int i = 0; i < n; i++)
  {
    int spend = 5 * (i + 1);
    acc += spend;

    if ((acc + k) > min)
    {
      break;
    }

    total++;
  }

  cout << total;

  return 0;
}