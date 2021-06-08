#include <iostream>
#include "Makefile.h"
#define N 10
using namespace std;

/*Global statements*/
int cell_matrix[N][N];
int replace[N][N];
int alive_cells = 0;
int w;
int n;

void fill(int M[N][N], int w){
	/*fill 0s*/
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++) M[i][j] = 0;
	}
	if (w == 0){/*3 row & col*/
		M[2][2] = 1;
		M[2][3] = 1;
		M[2][4] = 1;
		M[6][6] = 1;
		M[7][6] = 1;
		M[8][6] = 1;
	}
	if (w == 1){/*glider*/
		M[1][2] = 1;
		M[2][3] = 1;
		M[3][3] = 1;
		M[3][2] = 1;
		M[3][1] = 1;
	}
	if (w == 2){/*tumbler*/
		M[3][3] = 1;
		M[4][2] = 1;
		M[4][3] = 1;
		M[5][2] = 1;
		M[5][4] = 1;
		M[6][4] = 1;
		M[7][3] = 1;
		M[7][4] = 1;
		M[8][3] = 1;
		M[3][7] = 1;
		M[4][7] = 1;
		M[4][8] = 1;
		M[5][6] = 1;
		M[5][8] = 1;
		M[6][6] = 1;
		M[7][7] = 1;
		M[7][6] = 1;
		M[8][7] = 1;
		
	}
}

void iteration(int cell[N][N]){
	int i,j;
	for(int i = 0; i < N; i++){
        	for(int j = 0; j < N; j++){
        		if (cell[i+1][j] == 1){
				alive_cells++;
			}
        		if (cell[i][j+1] == 1){
				alive_cells++;
			}	
        		if (cell[i-1][j] == 1){
				alive_cells++;
			}
        		if (cell[i][j-1] == 1){
				alive_cells++;
			}
        		if (cell[i-1][j-1] == 1){
				alive_cells++;
			}
        		if (cell[i+1][j+1] == 1){
				alive_cells++;
			}
        		if (cell[i-1][j+1] == 1){
				alive_cells++;
			}	
        		if (cell[i+1][j-1] == 1){
				alive_cells++;
    		}
    		if (cell[i][j]==1){
    			if ((alive_cells==2) || (alive_cells==3)){
    				replace[i][j]=1;
    			}
    			else{
    				replace[i][j]=0;
    			}	
    		}
    		else if(cell[i][j]==0){
    			if (alive_cells==3){
    				replace[i][j]=1;
    			}
    			else{
    				replace[i][j]=0;
    			}
    		}
    		else{
    			replace[i][j]=0;
    		}
    		alive_cells = 0;
    	}
    }
}


int main (){
	/*Input*/
	cin >> w >> n ;
	/*Using fill function*/
	fill(cell_matrix,w);
	/*Original matrix print*/
	for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << cell_matrix[i][j];
        }
    cout << endl;
	}
	cout << endl;
    /*Iteration cycle*/
    while (n > 0){
    	iteration(cell_matrix);	
    	for (int x = 0; x < N; x++){
			for (int y = 0; y < N; y++){
				cell_matrix[x][y] = replace[x][y];
			}
		}
		n--;
	}		
	/*Iterated matrix print*/
	for(int a = 0; a < N; a++){
        for(int b = 0; b < N; b++){
            cout << cell_matrix[a][b];
        }
    cout << endl;
	}
	return 0;
}


