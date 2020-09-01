#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b)
{
  if (a > b)
    return a;

  return b;
}

int kadanes_algo(vector<int> arr)
{
  int max_curr, max_global;
  max_curr = max_global = arr.at(0);

  for (int i = 1; i <= arr.size() - 1; i++)
  {
    max_curr = max(arr.at(i), max_curr + arr.at(i));

    if (max_curr > max_global)
      max_global = max_curr;
  }

  return max_global;
}

int main()
{
  vector<int> arr = {-2, 3, 2, -1};

  cout << kadanes_algo(arr) << endl;

  return 0;
}