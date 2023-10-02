#include <iostream>
#define T 20 // Librería para darle un tope al tamaño del arreglo
using namespace std;

void quick(int[], int, int);
void mostrar(int[], int);

int main() {
    int numero, a[T]; // Dos variables
    cout << "Cuantos elementos va ingresar?" << endl;
    cin >> numero;
    cout << "Ingrese elementos:" << endl;

    // Un for para que ingrese datos hasta que cumpla con los elementos que quiere ingresar
    for (int i = 0; i < numero; i++) {
        cout << "Arreglo [" << i << "] = ";
        cin >> a[i]; // Para que guarde los números ingresados en el arreglo
    }

    // Otro for para mostrar los elementos ingresados en el arreglo
    cout << "~ Elementos ingresados ~" << endl;
    for (int i = 0; i < numero; i++) {
        cout << a[i] << " - ";
    }

    quick(a, 0, numero - 1); // Llamar función con la posición en 0 y el último
    mostrar(a, numero);

    return 0;
}

void mostrar(int a[], int numero) {
    cout << "\n~ Elementos ordenados ~" << endl;
    for (int i = 0; i < numero; i++) {
        cout << a[i] << " - ";
    }
    cout << endl;
}

void quick(int a[], int primero, int ultimo) {
    int mitad, p, u, pivote;
    mitad = (primero + ultimo) / 2; // Divide y vencerás
    p = primero;
    u = ultimo;
    pivote = a[primero];
    do {
        while (a[p] < pivote) p++; // Separar valores menores
        while (a[u] > pivote) u--; // Separar valores mayores
        // If para hacer el intercambio
        if (p <= u) {
            int temp = a[p]; // Variable para hacer el intercambio de posiciones
            a[p] = a[u];
            a[u] = temp;
            p++;
            u--;
        }
    } while (p <= u); // Va dejar de recorrer el arreglo cuando primero sea menor que o igual a ultimo
    if (primero < u)
        quick(a, primero, u);
    if (p < ultimo)
        quick(a, p, ultimo);
}

