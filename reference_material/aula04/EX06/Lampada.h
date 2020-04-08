#ifndef LAMPADA_H
#define LAMPADA_H

#include "Relogio.h"

class Lampada {
private:
	bool acesa;
public:
	void ligar();
	void desligar();
	void imprimir();
	void ligarSeNoite(Relogio *horaAtual);
};

#endif // LAMPADA_H
