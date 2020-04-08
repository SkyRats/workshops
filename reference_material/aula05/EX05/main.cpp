#include <iostream>

#include "Sensor.h"
#include "Residencia.h"

using namespace std;

void processar(const Sensor *s) {
    //s->setNumero(4);
}

const int* criarVetor() {
    return new int[3];
}

int main(int argc, char** argv) {
    const int x = 0; // x nao pode ser alterado
    const Sensor *s = new Sensor(1, new Residencia()); // s nao pode ser alterado

    //x = 3;
    //s->setNumero(4);

    Sensor *s2 = new Sensor(1, new Residencia);
    processar(s2);

    cout << s2->getNumero() << endl;
    cout << x << endl;

    //const int* vetor = criarVetor();
    //vetor[0] = 3;

    return 0;

}
