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
    Tablero table;
    fstream file;
    file.open("tablero.txt", ios::in);
    int num_piezas, x, y;
    y = 0;
    x = 0;
    file >> num_piezas;
    table.cantidad_piezas = num_piezas;
    cout << table.cantidad_piezas << endl;
    Pieza p;
    Pieza rey;
    char no;
    table.piezas_tablero = new Pieza[num_piezas];
    int cont = 1;
    for (int i = 0; i <= 63; i++) {
        file >> no;
        p.simbolo = no;
        p.x = x;
        p.y = y;
        if (no == 'X') {
            rey.simbolo = no;
            rey.x = x;
            rey.y = y;
            cout << rey.simbolo << rey.x << rey.y << endl;
        }
        if (no != '.' && no != 'X') {
            cout << "la pieza " << cont << " es " << p.simbolo << " esta en las cordenadas " << p.x << "," << p.y << endl;

            table.piezas_tablero[cont] = p;
            cont++;

            if (no == 'P') {
                // Código relacionado con la pieza 'P'
            }
        }

        x++;
        if (x == 8) {
            x = 0;
            y++;
        }
    }
    delete[] table.piezas_tablero;
    file.close();
    return 0;
}
