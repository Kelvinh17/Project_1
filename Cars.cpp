#include <iostream>
#include <fstream>
#include <string>

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

Carro carrosComprados[1001]; //Cantidad de carros 
Carro carrosVendidos[1001]; 
int totalCarrosComprados = 0;
int totalCarrosVendidos = 0;

// Función para mostrar los carros comprados
void mostrarCarrosComprados(){
    cout<<"\n--- Carros Comprados ---"<<endl;
    for (int i = 0; i < totalCarrosComprados; i++){
        cout<<"ID: "<<carrosComprados[i].id<<", Maker: "<<carrosComprados[i].maker<<", Model: "<<carrosComprados[i].model<<", Year: "<<carrosComprados[i].year<<", Sold for: "<<carrosComprados[i].sold_for<<", Bought for: "<<carrosComprados[i].bought_for<<endl;
    }
}

// Función para mostrar los carros vendidos
void mostrarCarrosVendidos(){
    cout<<"\n--- Carros Vendidos ---"<<endl;
    for (int i = 0; i < totalCarrosVendidos; i++) {
        cout<<"ID: "<<carrosVendidos[i].id<<", Maker: "<<carrosVendidos[i].maker<<", Model: "<<carrosVendidos[i].model<<", Year: "<<carrosVendidos[i].year<<", Sold to: "<<carrosVendidos[i].sold_to<<", Bought to: "<<carrosVendidos[i].bought_to<<endl;
    }
}

// Función para mostrar los carros comprados o vendidos a un cliente
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

// Función para agregar información de un carro comprado
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

// Función para modificar la información de un carro vendido
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

// Función para eliminar datos de un carro o cliente
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

// Función para mostrar pérdidas o ganancias en la compra y venta de un carro
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

// Función para mostrar el menú
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

int main(){
	ifstream file1("cars_data.csv");
    ifstream file2("clients.csv");
    
    if (!file1.is_open()||!file2.is_open()){
        cout<<"No se pudieron abrir los archivos"<<endl;
        return 1;
    }

    string line;
    int opcion;
    
do {
        mostrarMenu();
        cout << "\nIngrese una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                mostrarCarrosComprados();
                break;

            case 2:
                mostrarCarrosVendidos();
                break;

            case 3:
                mostrarCarrosCliente();
                break;

            case 4:
                agregarCarroComprado();
                break;

            case 5:
                modificarCarroVendido();
                break;

            case 6:
                eliminarDatosCarroCliente();
                break;

            case 7:
                mostrarPerdidasGanancias();
                break;

            case 8:
                cout<<"Saliendo del programa."<<endl;
                break;

            default:
                cout<<"Opción no valida. Por favor, ingrese una opción valida."<<endl;
                break;
        }

    } while (opcion != 8);

    return 0;

    file1.close();
    file2.close();

    return 0;
}

