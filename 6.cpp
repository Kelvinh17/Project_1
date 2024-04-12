#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct Carro{
    string id;
    string maker;
	string model;
	string year;
};

Carro carrosComprados[1001];
int totalCarrosComprados = 0;

// Funcion para eliminar datos de un carro o cliente
void eliminarDatosCarroCliente() {
    string model;
    cout<<"Ingrese el modelo del carro a eliminar: ";
    cin>>model;

    for (int i = 0; i < totalCarrosComprados; i++){
        if (carrosComprados[i].model == model){
            break;
        }
    }
}
