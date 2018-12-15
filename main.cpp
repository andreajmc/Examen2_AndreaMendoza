#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ifstream;

#include <string>
#include <fstream>

#include <vector>
using std::vector;

#include <string>
using std::string;

#include "LinkedList.h"

void recorrerLista(LinkedList*, User*);


int main() {
    int resp = 0;
    string un;
    string pw;
    // ofstream alumnosW("Users.pndr", std::ios::binary);
    LinkedList* list = new LinkedList();
    while (resp != 3) {
        cout<<endl<<endl<<" ________________________________________" <<endl
        <<"|                                        |"<<endl
        <<"|          ¡Bienvenido a Pinder!         |" <<endl
        <<"|                                        |" <<endl
        <<"| [1] Ingresar al programa.              |" <<endl
        <<"| [2] Crear un nuevo usuario.            |" <<endl
        <<"| [3] Salir.                             |" <<endl
        <<"|                                        |" <<endl
        <<"|________________________________________|" <<endl
        <<endl<<"Por favor, ingrese el número correspondiente la opción que desea acceder: ";
        cin>>resp;

        if (resp == 1) {
            bool access = false;
            cout<<endl<<endl<<"Ingrese su nombre de usuario: ";
            cin>>un;
            cout<<endl<<"Ingrese su contraseña: ";
            cin>>pw; // error segfault
            User* currentUser = 0;
            Node* target;

            if (list->getInicio() == 0) {
                cout<<endl<<"No hay usuarios creados. ¡Crea una cuenta ahora!"<<endl<<endl;
            } else {
                cout<<list->getInicio()->getData()->toString();
                if (list->getInicio()->getData()->getUsername() == un && list->getInicio()->getData()->getPw() == pw) {
                    currentUser = list->getInicio()->getData();
                    access = true;
                } else {
                    target = list->getInicio()->getNext();
                    while (target != 0) {
                        if(target->getData()->getUsername() == un && target->getData()->getPw() == pw) {
                            currentUser = target->getData();
                            access = true;
                            break;
                        } else {
                            access = false;
                            target = target->getNext();
                        }
                    }
                }
            }

            if (access) {
                int resp2;
                while (resp2 != 6) {
                    cout << endl << endl << " ________________________________________" << endl
                         << "|                                        |" << endl
                         << "|          ¡Bienvenido a Pinder!         |" << endl
                         << "|                                        |" << endl
                         << "| [1] Agregar un Amigo.                  |" << endl
                         << "| [2] Eliminar un Amigo.                 |" << endl
                         << "| [3] Ver Sugerencias de Amigos.         |" << endl
                         << "| [4] Ver Lista de Usuarios General.     |" << endl
                         << "| [5] Ver Lista de Amigos.               |" << endl
                         << "|                                        |" << endl
                         << "| [6] Cerrar sesión.                     |" << endl
                         << "|                                        |" << endl
                         << "|________________________________________|" << endl
                         << endl << "Por favor, ingrese el número correspondiente la opción que desea acceder: ";
                    cin >> resp2;
                    if (resp2 == 1) {
                        Node* test = list->getInicio();
                        User* amigo = nullptr;
                        string user;
                        cout<<endl<<endl<<"-- USUARIOS DISPONIBLES --"<<endl<<endl;
                        if (list->getInicio() == nullptr) {
                            cout<<endl<<"No hay usuarios disponibles."<<endl<<endl;
                        } else {
                            bool amiguis = true;
                            while (test != nullptr) {
                                for (int i = 0; i < currentUser->getContacts().size(); ++i) {
                                    if (test->getData()->getUsername() == currentUser->getContacts().at(i)->getUsername()) {
                                        amiguis = true;
                                        break;
                                    } else {
                                        amiguis = false;
                                    }
                                }
                                if (!amiguis){
                                    cout<<"-; "<<test->getData()->toString()<<endl;
                                }
                                test = test->getNext();
                            }
                            cout<<endl<<endl<<"Ingrese el username de la persona que desea agregar: ";
                            cin>>user;
                            if (list->getInicio()->getData()->getUsername() == user) {
                                currentUser->addFriend(list->getInicio()->getData());
                                list->getInicio()->getData()->addFriend(currentUser);
                                cout<<endl<<endl<<"¡Amigo agregado exitósamente!";
                            } else if (list->getInicio()->getNext() != nullptr) {
                                target = list->getInicio()->getNext();
                                while (target != nullptr) {
                                    if(target->getData()->getUsername() == un) {
                                        currentUser->addFriend(target->getData());
                                        target->getData()->addFriend(currentUser);
                                        cout<<endl<<endl<<"¡Amigo agregado exitósamente!";
                                        break;
                                    } else {
                                        target = target->getNext();
                                    }
                                }
                            } else {
                                cout<<endl<<"Ha ingresado un username erróneo."<<endl;
                            }
                        }
                    } else if (resp2 == 2) {
                        Node* test = list->getInicio();
                        User* amigo = nullptr;
                        string user;
                        cout<<endl<<endl<<"-- SUS AMIGOS --"<<endl<<endl;
                        for (auto item : currentUser->getContacts()) {
                            cout<<item->toString()<<endl;
                        }

                        cout<<endl<<endl<<"Ingrese el username de la persona a la que desea eliminar: ";
                        cin>>user;
                        if (list->getInicio()->getData()->getUsername() == user) {
                            currentUser->unFriended(list->getInicio()->getData());
                            list->getInicio()->getData()->unFriended(currentUser);
                            cout<<endl<<endl<<"¡Amigo eliminado exitósamente! :(";
                        } else if (list->getInicio()->getNext() != nullptr) {
                            target = list->getInicio()->getNext();
                            while (target != nullptr) {
                                if(target->getData()->getUsername() == user) {
                                    currentUser->unFriended(target->getData());
                                    target->getData()->unFriended(currentUser);
                                    cout<<endl<<endl<<"¡Amigo eliminado exitósamente! :(";
                                    break;
                                } else {
                                    target = target->getNext();
                                }
                            }
                        } else {
                            cout<<endl<<"Ha ingresado un username erróneo."<<endl;
                        }
                    } else if (resp2 == 3) { // Sugerencias
                        cout<<"-- AMIGOS SUGERIDOS --"<<endl<<endl;
                        target = list->getInicio();
                        while (target != nullptr) {
                            vector<string> common;
                            bool commonint = false;
                            bool friends = false;
                            for (int i = 0; i < target->getData()->getInterests().size(); ++i) {
                                for (int j = 0; j < currentUser->getInterests().size(); ++j) {
                                    if (target->getData()->getInterests().at(i) == currentUser->getInterests().at(j)) {
                                        common.push_back(currentUser->getInterests().at(j));
                                        commonint = true;
                                        for (int k = 0; k < target->getData()->getContacts().size(); ++k) {
                                            if (target->getData()->getContacts().at(k)->getUsername() == currentUser->getUsername()) {
                                                friends = true;
                                                break;
                                            }
                                        }
                                    }
                                }
                            }
                            if (commonint && !friends) {
                                cout<<"-; "<<target->getData()->toString()<<endl;
                            }

                            target = target->getNext();
                        }
                    } else if (resp2 == 4) { // General
                        cout<<"-- LISTA GENERAL DE USUARIOS --"<<endl<<endl;
                        target = list->getInicio();
                        while(target != nullptr) {
                            cout<<target->getData()->toString();
                            target = target->getNext();
                        }
                    } else if (resp2 == 5) { // ver amigos
                        cout<<"-- SUS AMIGOS --"<<endl<<endl;
                        for (auto item : currentUser->getContacts()) {
                            cout<<item->toString()<<endl;
                        }
                    }
                } // fin while menu2
// fin de if de access
            } else {
                cout<<endl<<endl<<"Nombre de usuario o contraseña incorrecto.";
            }
        } else if (resp == 2) {
            string name, username, passw, gender;
            int age;
            cout<<endl<<"Ingrese su nombre completo: ";
            cin>>name;
            cout<<endl<<"Ingrese su edad: ";
            cin>>age;
            cout<<endl<<"Ingrese su username: ";
            cin>>username;
            cout<<endl<<"Ingrese su contraseña: ";
            cin>>passw;
            cout<<endl<<"Ingrese su género (F/M): ";
            cin>>gender;
            gender = gender.at(0);
            if (list->getInicio() == nullptr) {
                list->setInicio(new Node(new User(name,username,passw,age,gender)));
            } else {
                list->push(new User(name, username,passw,age,gender));
            }
            cout<<endl<<"¡Usuario creado exitósamente!"<<endl;
        }
    }
}