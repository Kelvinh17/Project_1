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
	string comprador;
};

Carro carrosComprados[1001];
Carro carrosVendidos[1001]; 
int totalCarrosComprados = 0;
int totalCarrosVendidos = 0;

// Funci?n para modificar la informaci?n de un carro vendido
void modificarCarroVendido() {
    string model;
    cout<<"Ingrese el modelo del carro vendido: ";
    cin>>model;

    for (int i = 0; i < totalCarrosComprados; i++){
        if (carrosComprados[i].model == model){
            cout<<"Ingrese el comprador: ";
            cin>>carrosComprados[i].comprador;
            carrosComprados[i].sold_to = true;
            carrosVendidos[totalCarrosVendidos] = carrosComprados[i];
            totalCarrosVendidos++;
            break;
        }
    }
}
