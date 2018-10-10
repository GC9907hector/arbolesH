//arbol binario
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Nodo{
    int dato;
    Nodo *sig;
    Nodo *ant;
};

//prototipos
Nodo *crearNodo(int);
Nodo *arbol=NULL;
void insertarNodo(Nodo *&,int);
void mostrarArbol(Nodo *,int);
void menu();

int main(){
    menu();

    getch();
    return 0;
}

//menu para mostrar opciones
void menu(){
    int dato,op,contador=0,num;
    do{
        system("cls");
        cout << "\tMENU: " << endl;
        cout << "1. Insertar nuevo nodo" << endl;
        cout << "2. Mostrar arbol" << endl;
        cout << "3. Salir" << endl;
        cout << "opcion: ";
        cin >> op;

        switch(op){
            case 1:
                cout << "¿cuantos valores insertaras?: ";
                cin >> num;
                cout << "\nDame los valores: " << endl;
                for(int i=0; i<num; i++){
                    cout << "\t\t";
                    cin >> dato;
                    insertarNodo(arbol,dato);
                }
                system("pause");
            break;
            case 2:
                cout << "\nMostrar el arbol:\n\n";
                mostrarArbol(arbol,contador);
                system("pause");
            break;
            case 3:
            break;
            default:
                cout << "opcion invalida, intente de nuevo" << endl;
        }
    }while(op!=3);
}

//funcion para crear un nuevo nodo
Nodo *crearNodo(int n){
    Nodo *nuevo_nodo= new Nodo();

    nuevo_nodo->dato=n;
    nuevo_nodo->sig=NULL;
    nuevo_nodo->ant=NULL;

    return nuevo_nodo;

}

//funcion para insertar elementos a un arbol
void insertarNodo(Nodo *&arbol, int n){
    if(arbol==NULL){//si el arbol esta vacio
        cout << " (se inserto el valor raiz) "<< endl;
        Nodo *nuevo_nodo=crearNodo(n);
        arbol=nuevo_nodo;
    }
    else{//si el arbol tiene nodos
        int valorRaiz= arbol->dato;
        if(n!=valorRaiz){
            if(n<valorRaiz){//si n es menor a la izquierda
                insertarNodo(arbol->ant,n);
            }
            else{//si n es mayor insertar a la derecho
                insertarNodo(arbol->sig,n);
            }
        }
    }
}

//funcion para mostrar arbol
void mostrarArbol(Nodo *arbol, int cont){
    if(arbol==NULL){
        return;
    }
    else{
        mostrarArbol(arbol->sig, cont+1);
        for(int i=0;i<cont;i++){
            cout << "\t";
        }
        cout << arbol->dato<< endl;
        mostrarArbol(arbol->ant, cont+1);
    }
}
