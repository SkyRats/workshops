#ifndef LAMPADA_H
#define LAMPADA_H

class Lampada {
private:
	bool acesa;
public:
	void ligar();
	void desligar();
	void imprimir();
	void ligarSeNoite(bool ehNoite);
};

#endif // LAMPADA_H
