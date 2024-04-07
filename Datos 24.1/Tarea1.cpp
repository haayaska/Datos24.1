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

int main(){
    char tablerito[64];
    fstream file;
    file.open("tablero.txt", ios::in);
    int npiezas;
    file>> npiezas ;
    cout << npiezas << endl;
    char no;
    for(int cont = 0; cont<= 63 ;cont++){
      file >> no;
      cout << no;
      if((cont+1)%8==0){
        cout<<"\n";
      }
    }
    file.close();
    return 0;

}