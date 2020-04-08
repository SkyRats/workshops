#include <iostream>
using namespace std;

class Relogio {
private:
	int hora = 0;
	int minuto = 0;
public:
	void inicializar(int hora, int minuto);
	void imprimir();
};

void Relogio::inicializar(int hora, int minuto) {
	if (hora < 0 || hora > 23) this->hora = 0;
	else this->hora = hora;

	if (minuto < 0 || minuto > 59) this->minuto = 0;
	else this->minuto = minuto;
}

void Relogio::imprimir() {
	cout << hora << ":" << minuto << endl;
}

int main() {
	Relogio *r = new Relogio;
	r->inicializar(10, 5);
	r->imprimir();

	return 0;
}
