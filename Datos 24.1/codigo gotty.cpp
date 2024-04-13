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

bool f_peon(Pieza rey,int* p_peon){

  int a1x,a1y,a2x,a2y;
  a1x=p_peon[0]+1;
  a1y=p_peon[1]-1;

  a2x = p_peon[0]-1;
  a2y = p_peon[1]-1;

  if((rey.x==a1x && rey.y==a1y)||(rey.x==a2x && rey.y==a2y)){

    //llamado a función rey

    return true;}

  else{
    return false;
  }
}


//Punteros
int* p_peon;

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
    Pieza peon;

    p_peon = new int[2];

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
            //cout << rey.simbolo << rey.x << rey.y << endl;
        }
        if (no != '.' && no != 'X') {
            cout << "la pieza " << cont << " es " << p.simbolo << " esta en las cordenadas " << p.x << "," << p.y << endl;

            table.piezas_tablero[cont] = p;
            cont++;

            if (no == 'P') {

              peon.simbolo=no;
              peon.x=x;
              peon.y=y;

              p_peon[0]=peon.x;
              p_peon[1]=peon.y; 

              if (f_peon(rey, p_peon) == true) {
                  //cout << "El rey esta en jaque" << endl;
              }
              else {
                  //cout << "El rey se salva" << endl;
              }

              //cout<<"Valor del puntero"<<p_peon[0]<<p_peon[1]<<endl;
                
            }
          
        }

        x++;
        if (x == 8) {
            x = 0;
            y++;
        }
    }
    delete[] table.piezas_tablero;
    delete[] p_peon;

    file.close();
    return 0;
}

//p

