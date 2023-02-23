#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Ingrese el tamaño de la lista: ";
    cin >> n;
    int lista[n];
    for (int i = 0; i < n; i++) {
        cout << "Ingrese el numero " << i+1 << ": ";
        cin >> lista[i];
    }
    int* max = &lista[0]; // inicializar el apuntador a la primera posición de la lista
    int* min = &lista[0];
    for (int i = 1; i < n; i++) { // comenzar en la posición 1 de la lista
        if (lista[i] > *max) { // comparar los valores apuntados, no los apuntadores
            max = &lista[i]; // actualizar el apuntador al valor máximo
        }
        if (lista[i] < *min) {
            min = &lista[i]; // actualizar el apuntador al valor mínimo
        }
    }
    int &Valor_Max=*max;
    int &Valor_Min=*min;

    int x;
    cout << "El numero mas grande de la lista es: " << Valor_Max << endl; // desreferenciar los apuntadores para obtener los valores
    cout << "El numero mas pequeño de la lista es: " << Valor_Min << endl;
    cout <<"Ingresa un numero que este en el rango"<<endl;
    cin>>x;
     if (x<Valor_Max & x>Valor_Min){
        cout<<"El numero esta en el rango del valor max y el valor min"<<endl;
     }else{
        cout<<"El numero no se encuentra en el rango del valor max y el valor min";
     }
    return 0;
}