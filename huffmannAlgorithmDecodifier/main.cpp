#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <stdio.h>

using namespace std;
const size_t MAX_TREE_HEIGHT = 1000;
string mensaje;
char c1;
char c2;

struct Nodo{  
	char letra;
	int freq;
	Nodo *arriba;
	Nodo *derecha;
	Nodo *izquierda;
    
}; 

void recorrerArbol(Nodo *aux){
	if(aux->letra != NULL){
		return;
	}
	cout<<aux->freq<<endl;
	recorrerArbol(aux->derecha);
	recorrerArbol(aux->izquierda);

}


int main(){
	
	Nodo lista[100];  
	cout<<"Inserte su mensaje a codificar\n";
	cin>>mensaje;
	int real_count = 0;
	cout<<"Simbolos presentes"<<endl;
	for(int i= 0;i<mensaje.length(); i++){
		int count = 0;
		bool flag = true;
		for (int x=0; x<=real_count; x++){
			if (lista[x].letra== mensaje[i] ){
				flag = false;
				break;
			}
		}
		if(flag){
			
			for(int b = i; b<=mensaje.length();b++){
				if(mensaje[i] == mensaje[b]){
					count++;
				}
			}
			printf("%c\n",mensaje[i]);
			lista[real_count].letra = mensaje[i];
			lista[real_count].freq = count;
			real_count++;
		}
	}
	
	for(int i = 0; i<=real_count-2; i++){

		for(int x = i+1; x<=real_count-1 ; x++){
			int a = lista[x].freq;
		    char b = lista[x].letra;
			if (lista[i].freq > lista[x].freq){
				lista[x].freq = lista[i].freq;
				lista[x].letra = lista[i].letra;
				lista[i].freq = a;
				lista[i].letra = b;

			}
		}
	}
	//ORDENADO//
	cout<<"Letras ordenadas crecientemente por frecuencias"<<endl;
	for (int i = 0; i <= real_count-1; i++){
		cout<<lista[i].letra<<" = "<<lista[i].freq<<endl;
	}
	int i = 0;
	while(i<=real_count -1){
		i++;
		if(i%2 == 0){
			Nodo *pareja = new Nodo();
			Nodo *D = new Nodo();
			Nodo *I = new Nodo();
			D->letra = lista[i-1].letra;
			I->letra = lista[i-2].letra ;
			pareja->freq = lista[i-2].freq + lista[i-1].freq;
			pareja->izquierda = I;
			pareja->derecha = D;		
			lista[i-2].arriba = pareja;
		    lista[i-1].arriba = pareja;
		}
		//if(%2 == 0) arreglar impares
	}


	i = 0;
	Nodo *aux;

	while(i<=real_count - 1){
		i++;
		if(i%2 ==0 and i%4 != 0 and i<6){
			Nodo *nodo = new Nodo();
			aux = lista[i-1].arriba;
			nodo->derecha = aux;
			aux = nodo;
			
		}
		if(i%4 == 0 and i%2 == 0 and i<6){
			
     		Nodo *nodo2 = new Nodo();
     		aux->freq = aux->derecha->freq + (lista[i-1].arriba)->freq;
     		aux->izquierda = lista[i-1].arriba;
     		aux->arriba = nodo2;
     		nodo2->derecha = aux;
     		aux = nodo2;

		}
		if(i%2 == 0 and i >= 6){
			
			Nodo *nodo3 = new Nodo();
     		aux->freq = aux->derecha->freq + (lista[i-1].arriba)->freq;
     		aux->izquierda = lista[i-1].arriba;
     		aux->arriba = nodo3;
     		nodo3->derecha = aux;
     		aux = nodo3;
		}
		if((real_count)%2 != 0 and i == real_count){
			
			Nodo *nodo2 = new Nodo();
     		aux->freq = aux->derecha->freq + lista[i-1].freq;
     		aux->izquierda = &lista[i-1];
     		aux->arriba = nodo2;
     		nodo2->derecha = aux;
     		aux = nodo2;
		}
	}
	cout<<"Arbol de frecuencias acumuladas (derecha a izquierda)"<<endl;
	recorrerArbol(aux->derecha);
	return 0;
}

