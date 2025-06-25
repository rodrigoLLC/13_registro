#include<iostream>
using namespace std;

struct correo{
    string user;
    string domain;
};

struct contactoEmail{
    string nom;
    char sex;
    int edad;
    correo email;
};

void leerCorreo(correo &, string, string);
void leerContacto(contactoEmail &, string, char, int, correo);
void imprimeContacto(contactoEmail &);

int main(){
    int n, op;
    string nom, user, domain, nuevo_nombre;
    char sex;
    int edad;
    correo email;
    contactoEmail cont, lista[100];
    n = 0;
    do{
        system("cls");
        cout<<"-----Menu de opciones-----"<<endl;
        cout<<"1. Agregar contacto"<<endl;
        cout<<"2. Modificar contactos"<<endl;
        cout<<"3. Mostrar contactos"<<endl;
        cout<<"4. Eliminar un contacto"<<endl;
        cout<<"0. Salir"<<endl << endl;

        cout<<"Elige una opcion: "; cin>>op;

        switch(op){
            case 1:
                cout<<"Ingrese los datos de un usuario: "<<endl;
                cin.ignore();
                cout<<"Ingrese el nombre del contacto: "; getline(cin,nom);
                cout<<"Ingrese el sexo (M/F): "; cin>>sex;
                cout<<"Ingrese la edad: "; cin>>edad;
                cout<<"Ingrese el correo electronico (usuario@dominio): "<<endl;
                cout<<"\tIngrese el usuario: "; cin>>user;
                cout<<"\tIngrese el dominio: "; cin>>domain;
                
                leerCorreo(email,user,domain);
                leerContacto(cont,nom,sex,edad,email);
                //imprimeContacto(cont);

                lista[n] = cont;
                n++;
                system("pause");
                break;

            case 2:
                cin.ignore();
                cout << "Ingrese el nombre del contacto a modificar"<< endl;
                getline(cin, nuevo_nombre);
                if (nuevo_nombre == lista[n - 1].nom ) {

                    cout<<"-----Ingrese los datos del usuario----- "<<endl;
                    cin.ignore();
                    cout<<"Ingrese el nombre del contacto: "; getline(cin,nom);
                    cout<<"Ingrese el sexo (M/F): "; cin>>sex;
                    cout<<"Ingrese la edad: "; cin>>edad;
                    cout<<"Ingrese el correo electronico (usuario@dominio): "<<endl;
                    cout<<"\tIngrese el usuario: "; cin>>user;
                    cout<<"\tIngrese el dominio: "; cin>>domain;
                    
                    leerCorreo(email,user,domain);
                    leerContacto(cont,nom,sex,edad,email);

                    lista[n - 1] = cont;
                    system("pause");

                }
                break;

            case 3:
                for(int i = 0; i < n; i++){
                    cout<<"Contacto #"<<i<<endl;
                    imprimeContacto(lista[i]);
                    cout<<endl;
                }
                system("pause");
                break;

            case 4:
                cin.ignore();
                cout << "Ingrese el nombre del contacto a eliminar: ";
                getline(cin, nuevo_nombre);
                for (int i = 0; i < n; i++) {
                    if (lista[i].nom == nuevo_nombre) {
                        for (int p = i; p < n - 1; p++) {
                            lista[p] = lista[p + 1];
                        }
                        n--;
                        cout << "Contacto eliminado exitosamente." << endl;
                        break;
                    }
                }
                system("pause");
                break;

            case 0:
                char salir;
                cout<<"Esta seguro de salir? (S/N): ";
                cin>>salir;
                if (salir == 'S' || salir == 's') {
                    op = 0; 
                } else {
                    op = -1; 
                }
                break;
                
            default:
                cout<<"Opcion no valida!"<<endl;
                system("pause");
                break;
        }
    } while(op != 0);
    return 0;
}

void leerContacto(contactoEmail &c, string n, char s, int e, correo em){
    c.nom = n;
    c.sex = s;
    c.edad = e;
    c.email = em;
}

void leerCorreo(correo &c, string u, string d){
    c.user = u;
    c.domain = d;
}

void imprimeContacto(contactoEmail &c){
    cout<<"Nombre: "<<c.nom<<endl;
    cout<<"Sexo: "<<c.sex<<endl;
    cout<<"Edad: "<<c.edad<<endl;
    cout<<"Email: "<<c.email.user<<"@"<<c.email.domain<<endl;
}