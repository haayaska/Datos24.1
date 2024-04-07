#include <iostream>
#include <fstream>
using namespace std;

struct Pieza {
    char simbolo; // Define qué tipo de pieza es y su caracter
    int x, y; // Su posición dentro del tablero [0, 7] x [0, 7]
};

struct Tablero {
    int cantidad_piezas;
    Pieza *piezas_tablero;
};

bool tableroEnJaqueMate(Tablero &tablero);

int main() {
    fstream file;
    file.open("tablero.txt", ios::in);
    int npiezas;
    file >> npiezas;
    char array[npiezas];
    cout << npiezas << endl;

    char no;
    for (int cont = 0; cont < npiezas; cont++) {
        file >> no;
        cout << no;

        if (no != '.') {
            array[cont] = no;
        }

        if ((cont + 1) % 8 == 0) {
            cout << "\n";
        }
    }

    file.close();

    for (int i = 0; i < npiezas-1; i++) {
        cout << array[i] << endl;
    }

    return 0;
}
