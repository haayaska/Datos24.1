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
  Pieza rey;
  char no;
  tabler.piezas_tablero = new Pieza[npiezas];
  int cont = 1; 
  for(int i = 0; i<= 63 ;i++){
      file >> no;
      p.simbolo = no;
      p.x = x;
      p.y = y;
      if(no=='X'){
        rey.simbolo= no;
        rey.x=x;
        rey.y=y;
        cout<< rey.simbolo<<rey.x<<rey.y<<endl;
      }
      if(no != '.'&& no!='X'){
        cout<<"la pieza "<<cont<<" es "<<p.simbolo<<" esta en las cordenadas "<< p.x <<","<< p.y << endl;
        
        tabler.piezas_tablero[cont] = p;
        cont++;

        if(no=='P'){

          
            
    }
        
    x++;
    if(x==8){
      x=0;
      y++;
    
    }
  }
  delete[] tabler.piezas_tablero;
  file.close();
  return 0 ;
}


//Pancho NO TOCAR

int peon(tabler.piezas_tablero){

  tabler.piezas_tablero[i]=pos_peon;

  p.x=pos_x;
  p.y=pos_y;

  p.y + 1;
  p.x + 1;

  p.y + 1;
  p.x - 1;

  

  

  
}

  

  

  

  

  

} 