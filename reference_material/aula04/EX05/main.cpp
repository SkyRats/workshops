#include <iostream>
#include "Aluno.h"
#include "Avaliacao.h"

using namespace std;

int main() {
	Aluno *a = new Aluno;
	a->setNome("Joao");

	Avaliacao *doJoao = new Avaliacao;
	doJoao->setNotas(9, 8, 8.5);

	// A avaliacao eh de um aluno em uma disciplina
	// Entao faltam outras classes!

	cout << a->getNome() << ": " << doJoao->getMedia();
	return 0;
}
