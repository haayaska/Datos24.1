#include <iostream>
using namespace std;

int a[10];
int main()
{
    cout << "la direccion base del arreglo A es " <<a <<"\n";
for (int i = 0; i <10 ; i++){
    cout << "la direccion de a["<<i<<"] es "<<&a[i]<<"\n";
}

    return 0;
}