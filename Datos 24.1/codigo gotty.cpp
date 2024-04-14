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

bool f_alfil(Pieza rey, int* p_alfil, Tablero table) {
    int d1, d2;
    d1 = abs(rey.x - p_alfil[0]);
    d2 = abs(rey.y - p_alfil[1]);
    if (d1 == d2) {
        int movx = (rey.x - p_alfil[0]) / d1;
        int movy = (rey.y - p_alfil[1]) / d2;
        int x = p_alfil[0] + movx;
        int y = p_alfil[1] + movy;
        while (x != rey.x && y != rey.y) {
            for (int i = 0; i < table.cantidad_piezas; i++) {
                if (table.piezas_tablero[i].x == x && table.piezas_tablero[i].y == y) {
                    cout << "Pieza en el camino" << endl;
                    return false;
                }
            }
            x += movx;
            y += movy;
        }
    } else {
        cout << "No hay amenaza por parte del alfil" << endl;
        return false;
    }
    cout << "JAQUE" << endl;
    return true;
}



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


int* f_rey_x;
int* f_rey_y;

bool f_rey(Pieza rey, Tablero &tablero) {

    for (int i = rey.x - 1; i <= rey.x + 1; i++) {
        for (int j = rey.y - 1; j <= rey.y + 1; j++) {

            if (i >= 0 && i < 8 && j >= 0 && j < 8 && (i != rey.x || j != rey.y)) {

                for (int k = 0; k < tablero.cantidad_piezas; ++k) {

                    if (tablero.piezas_tablero[k].x == i && tablero.piezas_tablero[k].y == j) {

                      f_rey_x=&i;
                      f_rey_y=&j;

                      return true; 
                    }
                }
            }
        }
    }
    return false; 
}

//Punteros
int* p_peon;
int* p_rey;
int* p_alfil;
int* p_torre;

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
    Pieza alfil;
    Pieza torre;
  

    p_peon = new int[2];
    p_rey = new int[2];
    p_alfil = new int[2];
    p_torre= new int[2];

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

            p_rey[0]=rey.x;
            p_rey[1]=rey.y; 

            if (f_rey(rey, table) == true){
                cout << "(" << *f_rey_x << ", " <<*f_rey_y << "): Hay una pieza" << endl;
            } 

            else {
                cout << "No hay pieza" << endl;
            }
        }

        if (no != '.' && no != 'X') {
                    cout << "la pieza " << cont << " es " << p.simbolo << " esta en las cordenadas " << p.x << "," << p.y << endl;
                    table.piezas_tablero[cont] = p;
                    cont++;
                }
                switch(no){
                  case 'P':
                     {
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
                    break;
                      }
                       
                  case 'A': {
                      alfil.simbolo=no;
                      alfil.x = x;
                      alfil.y = y;
                      p_alfil[0]=alfil.x;
                      p_alfil[1]=alfil.y;
                      f_alfil(rey, p_alfil, table);
                    break;
                    
                  case 'T':{
                      torre.simbolo=no;
                      torre.x = x;
                      torre.y = y;
                      p_torre[0]=alfil.x;
                      p_torre[1]=alfil.y;
                      //f_torre(rey, p_alfil);
                    break;
                    }
  
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
            delete[] p_alfil;
  
            file.close();
            return 0;
        }

//pe