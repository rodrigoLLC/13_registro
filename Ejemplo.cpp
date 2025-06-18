#include <iostream>
using namespace std;

struct EMP {
    int numero;
    string nombre;
    float venta[12], salario;
};

int main () {
    EMP EMPLEADOS[100];
    int numero;
    cout << "Ingrese el numero de empleados del registro: ";
    cin >> numero;

    for ( int i = 0; i < numero; i++ ) {

        cout << "Ingrese el numero del empleado: ";
        cin >> EMPLEADOS[i].numero;
        cin.ignore();
        cout << "Ingresar el nombre del empleado: ";
        getline(cin, EMPLEADOS[i].nombre);

        cout << "Ingresar las ventas" << endl;

        for (int j = 0; j < 12; j++ ){

            cin >> EMPLEADOS[i].venta[j];
            
        }
    cout << "Ingresar su salario: ";
    cin >> EMPLEADOS[i].salario;
    }
    for (int i = 0; i < numero ; i++) {
        cout << "Empleado: " << i + 1 << endl;
        cout << "Numero de empleado: " << EMPLEADOS[i].numero<< endl;
        cout << "Nombre: " << EMPLEADOS[i].nombre << endl;
        cout << "Ventas: ";

        for (int j = 0; j < 12; j++) {
            cout << EMPLEADOS[i].venta[j] << " ";
            
        }
        cout << endl;
        cout << "Salario: " << EMPLEADOS[i].salario << endl;
        
    }
}
