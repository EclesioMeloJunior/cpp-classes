#include <iostream>
#include <string>

using namespace std;

int operation(string stmt)
{
  if (stmt.compare("++X") == 0)
    return 1;

  if (stmt.compare("X++") == 0)
    return 1;

  if (stmt.compare("--X") == 0)
    return -1;

  if (stmt.compare("X--") == 0)
    return -1;
}

int main()
{
  int x = 0, l;

  cin >> l;

  for (int i = 0; i < l; i++)
  {
    string stmt;
    cin >> stmt;

    x = x + operation(stmt);
  }

  cout << x << endl;
  return 0;
}