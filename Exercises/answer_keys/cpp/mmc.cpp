#include <iostream>

using namespace std;

int mmc(int a, int b){
    int maior, menor = 0;
    
    if(a > b){
        maior = a;
        menor = b;
    }else{
        maior = b;
        menor = a;
    }

    while(maior%menor != 0){
        maior += maior;
    }

    return maior;
}

int main(){
    int a, b = 0;

    cout << "Input 2 numbers (separated by 'Enter'): " << endl;
    cin >> a; 
    cin >> b;

    cout << "The MMC between " << a << " and " << b << " is " << mmc(a, b) << endl;

    return 0;
}