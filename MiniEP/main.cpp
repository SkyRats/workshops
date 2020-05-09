#include <iostream>

#include "Modalidade.h"
#include "Competicao.h"
#include "CompeticaoMultimodalidades.h"
#include "CompeticaoSimples.h"
#include "Equipe.h"

using namespace std;

int main () {

    cout<< "Digite a quantidade de equipes: ";
    int qtd_Eq;
    cin >> qtd_Eq;
    Equipe** equipe_tot = new Equipe*[qtd_Eq];

    for (int i = 0; i < qtd_Eq; i++){ //Define as equipes totais
        cout<< "Digite o nome da equipe "<< i+1 << ": ";
        string nome_eq;
        cin >> nome_eq;
        equipe_tot[i] = new Equipe(nome_eq);
    }

    cout<< "Digite o nome da competicao: ";
    string nome_comp;
    cin >> nome_comp;
    cout<< "Competicao simples (s) ou multimodalidades (m): ";
    string tipo_Comp;
    cin >> tipo_Comp;

    if (tipo_Comp == "s"){
        cout<< "Informe o nome da modalidade: ";
        string nome_Mod_S;
        cin >> nome_Mod_S;

        Modalidade* m = new Modalidade (nome_Mod_S, equipe_tot, qtd_Eq);
        CompeticaoSimples* comp = new CompeticaoSimples(nome_comp, equipe_tot, qtd_Eq, m);
        cout << "" << endl;
        comp->imprimir();
    } else if (tipo_Comp == "m"){
        cout << "Digite o numero de modalidades: ";
        int num_mod;
        cin >> num_mod;
        CompeticaoMultimodalidades* compMult = new CompeticaoMultimodalidades(nome_comp,equipe_tot,qtd_Eq);
        for (int i = 0; i<num_mod; i++){
            cout<< "Digite o nome da modalidade " << i+1 << ":";
            string nome_mod;
            cin >> nome_mod;

            cout << "Digite o numero de equipes participantes desta modalidade: ";
            int num_eq_part;
            cin >> num_eq_part;

            Equipe** equipesDaModalidade = new Equipe*[num_eq_part];

            for (int j = 0; j<num_eq_part; j++){
                cout<< "Digite o nome da equipe "<< j+1 << ": ";
                string nome_eq;
                cin >> nome_eq;
                equipesDaModalidade[j] = new Equipe(nome_eq);
            }
            Modalidade* m = new Modalidade(nome_mod,equipesDaModalidade,num_eq_part);
            compMult->adicionar(m);

        }
        compMult->imprimir();

    }
    return 0;
}
