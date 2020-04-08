#ifndef ALUNO_H
#define ALUNO_H

#include <string>
using namespace std;

class Aluno {
private:
	string nome;
	double p1, p2, p3;

public:
	void setNome(string nome);
	string getNome();
	void setNotas(double p1, double p2, double p3);
	double getMedia();
};
#endif // ALUNO_H
