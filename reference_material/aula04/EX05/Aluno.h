#ifndef ALUNO_H
#define ALUNO_H

#include <string>
using namespace std;

class Aluno {
private:
	string nome;

public:
	void setNome(string nome);
	string getNome();
};

#endif // ALUNO_H
