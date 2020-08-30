#include <iostream>
#include <string>

using namespace std;

void llps(char *s)
{
  int lim = 0, max = 0, til = 0;
  string str;

  for (int i = 0; i < 10; i++)
  {
    if (*(s + i) == '\0')
      break;

    lim++;
  }

  for (int i = 0; i < lim; i++)
  {
    for (int j = lim - 1; j > i; j--)
    {
      if (int(*(s + i)) < int(*(s + j)))
      {
        char tmp = *(s + i);
        *(s + i) = *(s + j);
        *(s + j) = tmp;
      }
    }
  }

  max = *(s + 0);

  for (int i = 1; i < lim; i++)
  {
    if (int(*(s + i) < max))
      break;

    til = i;
  }

  for (int i = 0; i <= til; i++)
  {
    cout << *(s + i);
  }
}

int main()
{
  char s[10];

  cin >> s;

  llps(s);

  return 0;
}