#include <iostream>
#include <math.h>

using namespace std;

int findmin(long int a, long int b)
{
  if (a == b)
    return 0;

  if (a > b)
    return (a / 10) - (b / 10);

  if (b > a)
    return (b / 10) - (a / 10);
}

int main()
{
  int t;

  cin >> t;

  for (int i = 0; i < t; i++)
  {
    long int a = 0, b = 0;

    cin >> a >> b;

    cout << findmin(a, b) << endl;
  }

  return 0;
}