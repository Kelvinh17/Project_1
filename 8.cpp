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

// Funcion para mostrar el men?
void mostrarMenu() {
    cout<<"\n--- Menu ---"<<endl;
    cout<<"1. Mostrar carros comprados"<<endl;
    cout<<"2. Mostrar carros vendidos"<<endl;
    cout<<"3. Mostrar carros comprados/vendidos a un cliente"<<endl;
    cout<<"4. Agregar informacion de un carro comprado"<<endl;
    cout<<"5. Modificar informacion de un carro vendido"<<endl;
    cout<<"6. Eliminar datos de un carro o cliente"<<endl;
    cout<<"7. Mostrar perdidas o ganancias en la compra y venta de un carro"<<endl;
    cout<<"8. Salir"<<endl;
}
