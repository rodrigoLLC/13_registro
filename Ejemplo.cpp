#include <iostream>

using namespace std;

struct EMP {
    int numero;
    string nombre;
    float venta[12], salario, ventaTotal;
};

int main () {

    float Ventamayor;

    EMP EMPLEADOS[100];
    int numero;
    cout << "Ingrese el numero de empleados del registro: ";
    cin >> numero;

    for ( int i = 0; i < numero; i++ ) {

        cout << "datos del empleado #" << i + 1 << endl;

        cout << "Ingrese el numero del empleado: ";
        cin >> EMPLEADOS[i].numero;
        cin.ignore();

        cout << "Ingresar el nombre del empleado: ";
        getline(cin, EMPLEADOS[i].nombre);

        EMPLEADOS[i].ventaTotal = 0;

        cout << "Ingresar las ventas de los meses" << endl;
        for (int j = 0; j < 12; j++ ){
        
            cout << "Mes " << j + 1 << " : "; 
            cin >> EMPLEADOS[i].venta[j];
            EMPLEADOS[i].ventaTotal += EMPLEADOS[i].venta[j];
        }

    cout << "Ingresar su salario: ";
    cin >> EMPLEADOS[i].salario;
    }

    Ventamayor = EMPLEADOS[0].ventaTotal; 

    for (int i = 0; i < numero ; i++) {

        if ( EMPLEADOS[i].ventaTotal > Ventamayor ) {
            Ventamayor = EMPLEADOS[i].ventaTotal;
        }

        cout << "Empleado: " << i + 1 << endl;
        cout << "Numero de empleado: " << EMPLEADOS[i].numero<< endl;
        cout << "Nombre: " << EMPLEADOS[i].nombre << endl;
        cout << "Ventas: ";

        for (int j = 0; j < 12; j++) {
            cout << EMPLEADOS[i].venta[j] << " ";
            
        }
        cout << "Total de venta: " << EMPLEADOS[i].ventaTotal << endl;
        cout << endl;
        cout << "Salario: " << EMPLEADOS[i].salario << endl;
    }
    for (int i = 0; i < numero; i++) {
        if (Ventamayor == EMPLEADOS[i].ventaTotal) {

            cout << "Empleado con mayor venta anual:" << endl;
            cout << "Numero de empleado: " << EMPLEADOS[i].numero << endl;
            cout << "Nombre del empleado: " << EMPLEADOS[i].nombre << endl;
            cout << "Venta total: " << EMPLEADOS[i].ventaTotal << endl;
        }
    }
    
    return 0;
}
