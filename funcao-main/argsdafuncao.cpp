#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  cout << "Numero de argumentos: " << argc << endl;

  cout << "\nAgumentos" << endl;

  for (int i = 0; i < argc; i++)
  {
    cout << argv[i] << endl;
  }

  return 0;
}