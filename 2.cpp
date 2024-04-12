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
};

Carro carrosVendidos[1001]; 
int totalCarrosVendidos = 0;

// Funcion para mostrar los carros vendidos
void mostrarCarrosVendidos(){
    cout<<"\n--- Carros Vendidos ---"<<endl;
    for (int i = 0; i < totalCarrosVendidos; i++) {
        cout<<"ID: "<<carrosVendidos[i].id<<", Maker: "<<carrosVendidos[i].maker<<", Model: "<<carrosVendidos[i].model<<", Year: "<<carrosVendidos[i].year<<", Sold to: "<<carrosVendidos[i].sold_to<<", Bought to: "<<carrosVendidos[i].bought_to<<endl;
    }
}
