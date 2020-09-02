#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int n, k, t, app = 0;
  vector<int> participants;

  cin >> n >> k;

  for (int i = 0; i < n; i++)
  {
    int c;
    cin >> c;
    participants.push_back(c);
  }

  t = participants.at(k - 1);

  for (int i = 0; i < n; i++)
  {
    if (participants.at(i) > 0 && participants.at(i) >= t)
      app++;
  }

  cout << app << endl;

  return 0;
}