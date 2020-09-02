#include <iostream>
#include <string>

using namespace std;

int main()
{
  int n;
  string word, abr;

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> word;

    if (word.size() > 10)
    {
      int btw = word.size() - 2;
      abr = word.at(0) + to_string(btw) + word.at(word.size() - 1);
    }
    else
      abr = word;

    cout << abr << endl;
  }

  return 0;
}