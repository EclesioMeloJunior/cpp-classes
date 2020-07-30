#include <iostream>
#include <string.h>

using namespace std;

typedef struct pessoa
{
  char nome[100];
  int ano_nascimento;
  float nota;

} t_pessoa;

int main(int argc, char *argv[])
{
  t_pessoa eclesio;

  eclesio.nota = 10;
  eclesio.ano_nascimento = 2000;
  strcpy(eclesio.nome, "eclesio");

  t_pessoa flavia;

  flavia.nota = 10;
  flavia.ano_nascimento = 2000;
  strcpy(flavia.nome, "flávia");

  t_pessoa *alunos = new t_pessoa[2];

  alunos[0] = eclesio;
  alunos[1] = flavia;

  for (int i = 0; i < 2; i++)
  {
    t_pessoa aluno = alunos[i];
    cout << aluno.nome << ": " << aluno.nota << endl;
  }

  return 0;
}