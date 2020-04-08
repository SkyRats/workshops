#include <iostream>
using namespace std;

class Aluno {
private:
	string nome;
	int numeroUsp;
public:
	void setNome (string nome);
	string getNome();
	void setNumeroUsp(int numeroUsp);
	int getNumeroUsp();
};

void Aluno::setNome(string nome) {
	this->nome = nome;
}

string Aluno::getNome() {
	return nome;
}

void Aluno::setNumeroUsp(int numeroUsp) {
	this->numeroUsp = numeroUsp;
}

int Aluno::getNumeroUsp() {
	return numeroUsp;
}

int main() {
	Aluno *a = new Aluno;
	a->setNome("Ana");
	a->setNumeroUsp(987654321);
	cout << a->getNome() << endl;
	return 0;
}
