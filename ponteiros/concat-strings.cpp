#include <iostream>

using namespace std;

int length(char *str)
{
  int tam = 0;

  while (*str != '\0')
  {
    str++;
    tam++;
  }

  return tam;
}

char *concat(char *str_one, char *str_two)
{
  char *resultado = new char[length(str_one) + length(str_two)];

  int endof_strone = length(str_one);
  int endof_strtwo = endof_strone + length(str_two);

  for (int i = 0, j = endof_strone; i < endof_strone || j < endof_strtwo; i++, j++)
  {
    if (i < endof_strone)
    {
      *(resultado + i) = *(str_one++);
    }

    if (j < endof_strtwo)
    {
      *(resultado + j) = *(str_two++);
    }
  }

  return resultado;
}

int main(int argc, char *argv[])
{
  char *myname = new char[100];
  char *mylastname = new char[100];

  cout << "Digite seu primeiro: ";
  cin >> myname;

  cout << "Digite seu último nome: ";
  cin >> mylastname;

  cout << concat(myname, mylastname) << endl;

  return 0;
}