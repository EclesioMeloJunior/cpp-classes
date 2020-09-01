#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b)
{
  if (a > b)
    return a;

  return b;
}

int kadanes(int arr[], int n)
{
  int max_curr, max_global;
  max_curr = max_global = arr[0];

  for (int i = 1; i < n; i++)
  {
    max_curr = max(arr[i], max_curr + arr[i]);
    max_global = max(max_curr, max_global);
  }

  return max_global;
}

int main()
{
  int l, n;

  cin >> l;

  for (int i = 0; i < l; i++)
  {
    cin >> n;
    int arr[n];

    for (int j = 0; j < n; j++)
    {
      cin >> arr[j];
    }

    cout << kadanes(arr, n) << endl;
  }

  return 0;
}