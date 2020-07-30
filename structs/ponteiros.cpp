#include <iostream>

using namespace std;

typedef struct carro
{
  int ano;
} t_carro;

int main(int argc, char *argv[])
{
  t_carro gol;
  gol.ano = 2000;

  cout << "Ano do carro: " << gol.ano << endl;

  t_carro *outrogol;
  outrogol = &gol;

  outrogol->ano = 4000;

  cout << "Ano ponteiro para carro: " << gol.ano << endl;

  return 0;
}