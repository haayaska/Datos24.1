#include <iostream>
#include <fstream>
using namespace std;

struct Pieza {
 char simbolo; // Define qué tipo de pieza es y su caracter
 int x, y; // Su posición dentro del tablero [0, 7] x [0, 7]
};

struct Tablero {
 Pieza* piezas_tablero; // Lista de piezas que tiene el tablero
};

bool tableroEnJaqueMate(Tablero &tablero);

int main(){
    fstream file;
    file.open("tablero.txt", ios::in);
    int si;
    file>> si ;
    cout << si << endl;
    char no;
    for(int cont = 0; cont<= 63 ;cont++){
         file>> no;
         cout << no << endl;
    }

//prueba
    file.close();
    return 0;

}