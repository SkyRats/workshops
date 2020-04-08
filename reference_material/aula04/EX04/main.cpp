#include <iostream>
#include "Aluno.h"

using namespace std;

int main () {
	Aluno *a = new Aluno;
	a->setNome("Joao");
	a->setNotas(9, 8, 8.5);

	cout << a->getNome() << ": " << a->getMedia();
	return 0;
}
