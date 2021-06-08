#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int m;
int z1, z2, c;
vector < pair < int , pair < int , int > > > vertices;
int padres[100];

int buscarAncestro(int x){
	if(padres[x] == x){
		return x;
	}
	return buscarAncestro(padres[x]);
}

void unirArboles(int z1, int z2){
	int fz1 = buscarAncestro(z1);
	int fz2 = buscarAncestro(z2);
	padres[fz1] = fz2;
}

int main (){
	for(int i = 0; i < 100; i++){
		padres[i] = i;
	}
	/*Llamando al input*/
	cin>>n>>m;
	/*Escribiendo los vertices*/
	for(int i = 0; i < m; i++){
		cin>>z1>>z2>>c;
		vertices.push_back(make_pair(c,make_pair(z1,z2)));
	}
	cout<<endl;
	//KRUSKAL
	int mst_peso = 0;
	int mst_vertices = 0;
	int mst_ind_sig = 0;
	/*Paso 1: Se sortea la lista de vertices*/
	sort(vertices.begin(), vertices.end());
	/*Paso 2 y 3:*/
	while((mst_vertices < n-1) || (mst_ind_sig < m)){
		/*Separacion del vertice en los integers que lo describen */
		z1 = vertices[mst_ind_sig].second.first;
		z2 = vertices[mst_ind_sig].second.second;
		c = vertices[mst_ind_sig].first;
		/* Se checkea que el vertice no cree un ciclo (no este en el mismo arbol)*/
		if(buscarAncestro(z1) != buscarAncestro(z2)){
			/* Unimos los arboles*/
			unirArboles(z1,z2);
			/* Se suma el peso del vertice*/
			mst_peso += c;
			/* Printeamos el vertice y lo contamos */
			cout<<z1<<" "<<z2<<" "<<c<<endl;
			mst_vertices++;
		}
		/* Sumar al contador de indice siguiente del vertice */
		mst_ind_sig++;
	}
	/* Peso final */
	cout<<"\n Peso del Arbol Recubridor Minimo: "<<mst_peso<<endl;
}
