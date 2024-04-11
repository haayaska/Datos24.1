

// int main() {
//     fstream file;
//     file.open("tablero.txt", ios::in);
//     int npiezas;
//     file >> npiezas;
//     char array[npiezas];
//     cout << npiezas << endl;

//     char no;
//     for (int cont = 0; cont < npiezas; cont++) {
//         file >> no;
//         cout << no;

//         if (no != '.') {
//             array[cont] = no;
//         }

//         if ((cont + 1) % 8 == 0) {
//             cout << "\n";
//         }
//     }

//     file.close();

//     for (int i = 0; i < npiezas-1; i++) {
//         cout << array[i] << endl;
//     }

//     return 0;
// }

/* int main(){

    Tablero table;
    fstream file;
    file.open("tablero.txt",ios::in);

    int cantpiezas;

    if (!file.is_open()) {

        cout << "Error al abrir el archivo" << endl;
    }

    file >> cantpiezas;

    arr_piezas = new Pieza[cantpiezas];

    Pieza p;
    char lugar;       INTENTO MALO MIO 
 */

#include <iostream>
#include <fstream>
using namespace std;

struct Pieza {
 char simbolo; // Define qué tipo de pieza es y su caracter
 int x, y; // Su posicin dentro del tablero [0, 7] x [0, 7]
};

struct Tablero {
  int cantidad_piezas;
  Pieza *piezas_tablero;
};

bool tableroEnJaqueMate(Tablero &tablero);

int main(){
  Tablero tabler;
  fstream file;
    file.open("tablero.txt", ios::in);
    int npiezas,x,y;
    y = 0;
    x = 0;
    file>> npiezas ;
    tabler.cantidad_piezas= npiezas;
    cout<< tabler.cantidad_piezas << endl;
    Pieza p;
    char no;
    tabler.piezas_tablero = new Pieza[npiezas];
    int cont = 1; 
    for(int i = 0; i<= 63 ;i++){
       file >> no;
       p.simbolo = no;
       p.x = x;
       p.y = y;
       if(no != '.'){
         cout<<"la pieza "<<cont<<" es "<<p.simbolo<<" esta en las cordenadas "<< p.x <<","<< p.y << endl;
         tabler.piezas_tablero[cont] = p;
         cont++;
      }
      x++;
      if(x==8){
        x=0;
        y++;
      }
    }
    file.close();
    return 0 ;
}























    file.close()










}

