/* Programa que realiza una BFS en un grafo no dirigido (https://www.quora.com/What-is-an-undirected-graph). */

#include <iostream>
#include <vector>
#include <queue> // Estructura de datos preferida para hacer una BFS

using namespace std;

// Variables minimas necesarias para poder construir un grafo con vector de adyacencias y recorrerlo con una BFS
int numeroNodos, numeroConexiones;
vector<vector<int>> grafo;
vector<bool> visitados;


// Funcion recursiva BFS (Breadth First Search) su complejidad es O(V + E) donde V representa el numero de vertices (nodos) en el grafo
// y E el numero de edges(conexiones) del mismo
void BFS(int primerNodo){
	queue<int> camino;

	// Añadimos nuestro vertice inicial
	camino.push(primerNodo);

	while(!camino.empty()){	
		int nodoActual = camino.front();

		if(!visitados[nodoActual]){
			// Hacemos algo con el nodo actual, en este caso lo imprimimos
			cout << "Visitando el nodo: " << nodoActual << endl;

			// Marcamos el nodo actual como visitado (para no volver a visitarlo despues)
			visitados[nodoActual] = true;

			// Corremos la BFS en los nodos vecinos de nuestro nodo actual
			for(int i = 0; i < grafo[nodoActual].size(); i++){
				int nodoVecino = grafo[nodoActual][i];
				// Si nuestro nodo vecino no ha sido visitado aun : lo añadimos al camino
				if(!visitados[nodoVecino]) camino.push(nodoVecino);
			}
		}
		// Quitar del camino el nodo que estás visitando
		camino.pop();
	}
}


// Funcion para leer input (esta NO es la parte importante del programa)
void leerDatos(){
	cin >> numeroNodos >> numeroConexiones;
	grafo.resize(numeroNodos, vector<int>());
	visitados.resize(numeroNodos, false);
	int nodoA, nodoB;
	for(int i = 0; i < numeroNodos; i++){
		cin >> nodoA >> nodoB;
		grafo[nodoA].push_back(nodoB);
		grafo[nodoB].push_back(nodoA);
	}
}

// Ejemplo de input (el primer numero representa el numero de nodos
// y el segundo el numero de adyacencias, el resto son pares de adyacencias
// de tipo "a b" donde a tiene una conexion con b)

/*
	5 5
	0 1
	1 2
	2 3
	0 3
	2 4
*/

int main(){
	// Leemos los datos del problema
	leerDatos();
	// Llamamos la BFS con nuestro nodo inicial
	BFS(0);
	return 0;
}