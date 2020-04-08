#ifndef RELOGIO_H
#define RELOGIO_H

class Relogio {
private:
	int hora = 0;
	int minuto = 0;
public:
	void inicializar (int hora, int minuto);
	int getHora();
	int getMinuto();
	void imprimir();
};

#endif // RELOGIO_H
