#include <iostream>
using namespace std;
int n;

void Quicksort(int* arr, int izq, int der)
{
	int i = izq, j = der, tmp;
	int p = arr[(izq + der)/2];
while (i <= j){
		while (arr[i] < p) i++;
		while (arr[j] > p) j--;
		if (i <= j){
			tmp = arr[i];
			arr [i] = arr [j];
			arr [j] = tmp;
			i++; j--;
		}
	}
	if (izq < j)
		Quicksort (arr, izq, j);
		if (i < der)
				Quicksort (arr, i, der);
}

int main(){
	cout << "Ingrese el numero de elementos a ordenar" << endl;
	cin >> n;
	int lista [n];
	cout << "Ingrese los elementos a ordenar" << endl;
	int contador = 0;
	while (contador != n){
		cin >> lista [contador];
		contador++;
	}
	
	Quicksort(lista, 0, n-1);
	for (int i = 0; i < n; i++){
		cout << lista[i] << " ";
	}
	cout << endl;
	return 0;	
}
