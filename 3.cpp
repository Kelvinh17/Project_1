#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct Carro{
    string id;
    string maker;
	string model;
	string year;
	string comprador;
};

Carro carrosComprados[1001];
Carro carrosVendidos[1001]; 
int totalCarrosComprados = 0;
int totalCarrosVendidos = 0;

// Funcion para mostrar los carros comprados o vendidos a un cliente
void mostrarCarrosCliente(){
    string cliente;
    cout<<"Ingrese el nombre del cliente: ";
    cin>>cliente;

    cout<<"\n--- Carros Comprados por "<<cliente<<" ---"<<endl;
    for (int i = 0; i < totalCarrosComprados; i++){
        if (carrosComprados[i].comprador == cliente){
            cout<<"ID: "<<carrosComprados[i].id<<", Maker: "<<carrosComprados[i].maker<<", Model: "<<carrosComprados[i].model<<", Year: "<<carrosComprados[i].year<<endl;
        }
    }

    cout<<"\n--- Carros Vendidos a "<<cliente<<" ---"<<endl;
    for (int i = 0; i < totalCarrosVendidos; i++){
        if (carrosVendidos[i].comprador == cliente){
            cout<<"ID: "<<carrosVendidos[i].id<<", Maker: "<<carrosVendidos[i].maker<<", Model: "<<carrosVendidos[i].model<<", Year: "<<carrosVendidos[i].year<<endl;
        }
    }
}
