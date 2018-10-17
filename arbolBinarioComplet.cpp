//arbol binario
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Nodo{
    int dato;
    Nodo *der;
    Nodo *izq;
};

//prototipos
Nodo *crearNodo(int);
Nodo *arbol=NULL;
int lvl=0;
void insertarNodo(Nodo *&,int);
void mostrarArbol(Nodo *,int, int);
void mostrarArbolV(Nodo *,int);
void nivelmaximo(Nodo *,int);
void menu();

int main(){
    menu();

    getch();
    return 0;
}

//menu para mostrar opciones
void menu(){
    int dato,op,contador=1,num;
    int arreglo[]={8,14,10,12,17,16,18};
    //cout << sizeof arreglo/ sizeof *arreglo;//<----lo anteroir es para el tamaño del arreglo;
    //este for es para que se inserte el arreglo anterior aautomaticamente al correr el programa
    //(se tiene que modificar i<7 dependiendo del tamaños del arreglo
    for(int i=0; i<7; i++){
        dato=arreglo[i];
        insertarNodo(arbol,dato);
    }
    do{
        system("pause");
        system("cls");
        cout << "\tMENU: " << endl;
        cout << "1. Insertar nuevo nodo" << endl;
        cout << "2. Insertar 2 nodos o mas" << endl;
        cout << "3. Mostrar arbol vertical" << endl;
        cout << "4. Mostrar arbol horizontal" << endl;
        cout << "5. Mostrar el arreglo" << endl;
        cout << "6. Salir" << endl;
        cout << "opcion: ";
        cin >> op;

        switch(op){
            case 1:
                cout << "insertar dato: ";
                cin >> dato;
                insertarNodo(arbol,dato);
            break;
            case 2:
                cout << "¿cuantos valores insertaras?: ";
                cin >> num;
                cout << "\nDame los valores: " << endl;
                for(int i=0; i<num; i++){
                    cout << "\t\t";
                    cin >> dato;
                    insertarNodo(arbol,dato);
                }
            break;
            case 3:
                cout << "\nMostrar el arbol:\n\n";
                nivelmaximo(arbol,contador);
                cout << "\n------" << lvl << "-------" << endl;
                for(int i=1; i<lvl+1; i++)
                {
                    mostrarArbol(arbol,contador, i);
                    cout << endl;
                }
            break;
            case 4:
                cout << "\nMostrar el arbol:\n\n";
                //cout << "\n------" << lvl << "-------" << endl;
                mostrarArbolV(arbol,contador);
            break;
            case 5:
                cout << "\nEL ARREGLO ES: \n\n";
                for(int i=0; i<21; i++){
                        cout << arreglo[i];
                        if(i!=7-1){
                        cout <<  ",";
                        }
                }
                cout << "." << endl;
            break;
            case 6:
            break;
            default:
                cout << "opcion invalida, intente de nuevo" << endl;
        }
    }while(op!=6);
}

//funcion para crear un nuevo nodo
Nodo *crearNodo(int n){
    Nodo *nuevo_nodo= new Nodo();

    nuevo_nodo->dato=n;
    nuevo_nodo->der=NULL;
    nuevo_nodo->izq=NULL;

    return nuevo_nodo;

}

//funcion para insertar elementos a un arbol
void insertarNodo(Nodo *&arbol, int n){
    if(arbol==NULL){//si el arbol esta vacio
        Nodo *nuevo_nodo=crearNodo(n);
        arbol=nuevo_nodo;
        return;

    }
    else{//si el arbol tiene nodos
        int valorRaiz= arbol->dato;
        if(n!=valorRaiz){
            if(n<valorRaiz){//si n es menor a la izquierda
                insertarNodo(arbol->izq,n);
            }
            else{//si n es mayor insertar a la derecho
                insertarNodo(arbol->der,n);
            }
        }
    }

}

//funcion para mostrar arbol
void nivelmaximo(Nodo *arbol, int cont){
    if(arbol==NULL){
        return;
    }
    else{
        nivelmaximo(arbol->der, cont+1);
        if(lvl<cont){
            lvl=cont;
        }
        nivelmaximo(arbol->izq, cont+1);
    }
}

void mostrarArbol(Nodo *arbol, int cont, int lvlactual){
    if(arbol==NULL){
        return;
    }
    else{
        mostrarArbol(arbol->izq, cont+1, lvlactual);
        if(cont==lvlactual){
                if(arbol->dato < 10)
                {
                    cout << "0";
                }
            cout << arbol->dato;
        }
        else{
            cout << "..";
        }
        mostrarArbol(arbol->der, cont+1, lvlactual);
    }
}

void mostrarArbolV(Nodo *arbol, int cont){
    if(arbol==NULL){
        return;
    }
    else{
        mostrarArbolV(arbol->der, cont+1);
        for(int i=1; i<cont; i++)
        {
            cout << "-";
        }
        cout << arbol->dato << endl;
        mostrarArbolV(arbol->izq, cont+1);
    }
}
