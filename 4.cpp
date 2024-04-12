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

// Funcion para agregar informaci?n de un carro comprado
void agregarCarroComprado(){
    cout<<"\n--- Agregar Carro Comprado ---"<<endl;
    Carro nuevoCarro;
    cout<<"ID: ";
    cin>>nuevoCarro.id;
    cout<<"Maker: ";
    cin>>nuevoCarro.maker;
    cout<<"Model: ";
    cin>>nuevoCarro.model;
    cout<<"Year: ";
    cin>>nuevoCarro.year;
    carrosComprados[totalCarrosComprados] = nuevoCarro;
    totalCarrosComprados++;
}
