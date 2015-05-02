/*
 *  GRAFO.CPP - Implementación de la clase GRAFOS
 *
 *
 *  Created on: 19/03/2015
 *  Author: Victor
 */

#include "grafo.h"

//CONSTRUCTOR
GRAFO::GRAFO(char nombrefichero[85]) {
	ElementoLista dummy;
	ifstream textfile;
	textfile.open(nombrefichero);
	if (textfile.is_open()) {
		unsigned i, j, k;
		int c;//coste
		// leemos por conversion implicita el numero de nodos, arcos y el atributo dirigido
		textfile >> (unsigned &) numero_nodos >> (unsigned &) numero_arcos
				>> (unsigned &) dirigido;
		// los nodos internamente se numeran desde 0 a n-1
		// creamos las n listas de sucesores
		LSucesores.resize(numero_nodos);
		// leemos los m arcos y cramos las listas de sucesores LS
		for (k = 0; k < numero_arcos; k++) {
			textfile >> i;
			textfile >> j;
			textfile >> c;
			dummy.nodo = j - 1;
			dummy.coste = c;
			LSucesores[i - 1].push_back(dummy);
		}
		textfile.close();
		if (Es_dirigido() == 1) { //Si es dirigido creamos la lista de predecesores
			ListaPredecesores();
		} else { // si no, recorremos la lista de sucesores para unir bien los nodos
			vector<LA_nodo> aux = LSucesores;
			for (i = 0; i < aux.size(); i++) {
				for (j = 0; j < aux[i].size(); j++) {
					dummy.nodo = i;
					LSucesores[LSucesores[i][j].nodo].push_back(dummy);
				}
			}
		}
		cout << "¡Fichero cargado correctamente!" << endl;
	} else {
		cout << "¡Error en la apertura del fichero!" << endl;
		exit(0);
	}

}
//DESTRUCTOR
GRAFO::~GRAFO() {
	LPredecesores.clear();
	LSucesores.clear();
	pendientes.clear();
}
/*
 * CARGA UN NUEVO GRAFO
 */
void GRAFO::actualizar(char nombrefichero[85]) {
	//borramos la informacion de los vectores
	LPredecesores.clear();
	LSucesores.clear();
	pendientes.clear();
	ElementoLista dummy;
	ifstream textfile;
	textfile.open(nombrefichero);
	if (textfile.is_open()) {
		unsigned i, j, k;
		int c; //coste
		// leemos por conversion implicita el numero de nodos, arcos y el atributo dirigido
		textfile >> (unsigned &) numero_nodos >> (unsigned &) numero_arcos
				>> (unsigned &) dirigido;
		// los nodos internamente se numeran desde 0 a n-1
		// creamos las n listas de sucesores
		LSucesores.resize(numero_nodos);
		// leemos los m arcos y cramos las listas de sucesores LS
		for (k = 0; k < numero_arcos; k++) {
			textfile >> i;
			textfile >> j;
			textfile >> c;
			dummy.nodo = j - 1;
			dummy.coste = c;
			LSucesores[i - 1].push_back(dummy);
		}
		textfile.close();
		if (Es_dirigido() == 1) {//si es dirigido construir lista de predecesores
			ListaPredecesores();
		} else {// si no, recorremos la lista de sucesores para unir bien los nodos
			vector<LA_nodo> aux = LSucesores;
			for (i = 0; i < aux.size(); i++) {
				for (j = 0; j < aux[i].size(); j++) {
					dummy.nodo = i;
					LSucesores[LSucesores[i][j].nodo].push_back(dummy);
				}
			}
		}
		cout << "¡Grafo actualizado correctamente!" << endl;
	} else {
		cout << "¡Error en la apertura del fichero!" << endl;
		exit(0);
	}
}
/*
 * CONSTRUYE LA LISTA DE PREDECESORES
 */
void GRAFO::ListaPredecesores() {
	unsigned j, k;
	ElementoLista dummy;
	LPredecesores.resize(numero_nodos);
	for (j = 0; j < LPredecesores.size(); j++) {
		for (k = 0; k < LSucesores[j].size(); k++) {
			dummy.nodo = j;
			LPredecesores[LSucesores[j][k].nodo].push_back(dummy);
		}
	}
}
/*
 * MUESTRA LA INFORMACION DEL GRAFO
 */
void GRAFO::Info_Grafo() {
	cout << "Informacion del grafo:" << endl;
	cout << "Numero de nodos: " << numero_nodos << endl;
	cout << "Numero de arcos:" << numero_arcos << endl;
	if (Es_dirigido() == 1)
		cout << "Grafo dirigido" << endl;
	else
		cout << "Grafo no dirigido" << endl;
}

unsigned GRAFO::Es_dirigido() {
	return dirigido;
}
/*
 * MUESTRA LAS LISTAS FORMATEADAS
 */
void GRAFO::Mostrar_Lista_Sucesores() {
	unsigned i, j;
	for (i = 0; i < LSucesores.size(); i++) {
		cout << "[" << i + 1 << "] :";
		if (LSucesores[i].empty())
			cout << " | Null" << endl;
		else {
			for (j = 0; j < LSucesores[i].size(); j++) {
				cout << " | " << LSucesores[i][j].nodo + 1;
			}
			cout << endl;
		}
	}
}

void GRAFO::Mostrar_Lista_Predecesores() {
	unsigned i, j;
	for (i = 0; i < LPredecesores.size(); i++) {
		cout << "[" << i + 1 << "] :";
		if (LPredecesores[i].empty())
			cout << " | Null" << endl;
		else {
			for (j = 0; j < LPredecesores[i].size(); j++) {
				cout << " | " << LPredecesores[i][j].nodo + 1;
			}
			cout << endl;
		}
	}
}

/*
 * PRACTICA 3: RECORRIDO DE UN GRAFO, DFS Y COMPONENTES CONEXAS
 */

void GRAFO::dfs(unsigned i, vector<bool> &visitado) {
	visitado[i] = true;
	cout << i + 1 << " ";
	pendientes.erase(i);
	for (unsigned j = 0; j < LSucesores[i].size(); j++){
		if (visitado[LSucesores[i][j].nodo] == false){
			dfs(LSucesores[i][j].nodo, visitado);
		}
	}
}

void GRAFO::ComponentesConexas() {
	vector<bool> visitado;
	for(unsigned i = 0; i < numero_nodos; i++){
		visitado.push_back(false);
		pendientes[i] = i;
	}
	int x =1;
	while (pendientes.size() > 0) {
		cout << "Componente conexa " << x << ": { ";
		dfs(pendientes.begin()->first, visitado);
		cout << "}" << endl;
		x++;
	}
}

/*void GRAFO::Mostrar_Listas(int l) {
 if (l == 0) {
 Mostrar_Lista_Sucesores();
 } else {
 Mostrar_Lista_Sucesores();
 Mostrar_Lista_Predecesores();
 }
 }*/

