#include <iostream>

using namespace std;

/**
 * Calcula o valor total da compra, considerando o frete.
 *
 * Se a soma dos precos dos produtos for maior que "limite" reais,
 * o frete nao deve ser cobrado.
 */
double totalDaCompra (double produtos[], int quantidade,
                      double frete, double limite) {
  double total = 0;
  for (int i = 0; i < quantidade; i++)
    total = total + produtos[i];
  if (total > limite)
    total = total + frete;
  return total;
}

int main() {
  double produtos[] = {5, 10, 5, 10};
  double total = totalDaCompra (produtos, 4, 5.5, 25);

  if (total != 30) cout << "Erro: " << total << endl;
  return 0;
}
