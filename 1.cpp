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
};

Carro carrosComprados[1001];
int totalCarrosComprados = 0;

// Funcion para mostrar los carros comprados
void mostrarCarrosComprados(){
    cout<<"\n--- Carros Comprados ---"<<endl;
    for (int i = 0; i < totalCarrosComprados; i++){
        cout<<"ID: "<<carrosComprados[i].id<<", Maker: "<<carrosComprados[i].maker<<", Model: "<<carrosComprados[i].model<<", Year: "<<carrosComprados[i].year<<", Sold for: "<<carrosComprados[i].sold_for<<", Bought for: "<<carrosComprados[i].bought_for<<endl;
    }
}
