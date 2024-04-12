#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct Carro{
    string id;
    string maker;
	string model;
	string year;
	string sold_to;
	string bought_to;
	string sold_for;
	string bought_for;
	string comprador;
	int precioVenta;
	int precioCompra;
};

Carro carrosVendidos[1001]; 
int totalCarrosVendidos = 0;

// Funcion para mostrar p?rdidas o ganancias en la compra y venta de un carro
void mostrarPerdidasGanancias() {
    int perdidas = 0;
    int ganancias = 0;
    
    for (int i = 0; i < totalCarrosVendidos; i++){
        if (carrosVendidos[i].precioVenta < carrosVendidos[i].precioCompra){
            perdidas += (carrosVendidos[i].precioCompra - carrosVendidos[i].precioVenta);
        } else{
            ganancias += (carrosVendidos[i].precioVenta - carrosVendidos[i].precioCompra);
        }
    }

    cout<<"\n--- Informe Financiero ---"<<endl;
    cout<<"Perdidas totales: " << perdidas<<endl;
    cout<<"Ganancias totales: " << ganancias<<endl;
}

