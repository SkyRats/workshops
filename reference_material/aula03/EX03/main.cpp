#include <iostream>
using namespace std;

class Relogio {
public:
	int hora = 0;
	int minuto = 0;
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

class Lampada {
public:
	Relogio *horaDeLigar;
	bool acesa = false;
	void ligar();
	void desligar();
	void imprimir();
	void atualizar(int horaAtual);
};

void Lampada::ligar() {
	this->acesa = true;
}

void Lampada::desligar() {
	this->acesa = false;
}

void Lampada::atualizar(int horaAtual) {
	if (horaAtual >= horaDeLigar->hora) {
		ligar();
		cout << "Ligado as ";
		horaDeLigar->imprimir();
	}
}

void Lampada::imprimir() {
	cout << this->acesa << endl;
}

int main() {
	Lampada *sala = new Lampada;
	Relogio *r = new Relogio;
	r->inicializar(10, 5);
	sala->horaDeLigar = r;

	sala->atualizar (9);
	sala->imprimir();

	sala->atualizar (10);
	sala->imprimir();
	return 0;
}
