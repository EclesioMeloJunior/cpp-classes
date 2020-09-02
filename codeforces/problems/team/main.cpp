#include <iostream>

using namespace std;

int main()
{
  int l, c = 0;
  cin >> l;

  for (int i = 0; i < l; i++)
  {
    int p, v, t;

    cin >> p >> v >> t;

    if (
        (p == 1 && v == 1) ||
        (p == 1 && t == 1) ||
        (v == 1 && t == 1))
    {
      c++;
    }
  }

  cout << c << endl;

  return 0;
}