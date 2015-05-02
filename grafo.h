/*
 *  GRAFO.h - definicion de la clase GRAFO
 *
 *  Created on: 19/03/2015
 *  Author: Victor
 */

#ifndef _GRAPH_H
#define _GRAPH_H

#include <vector>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

const unsigned UERROR = 65000;
const int maxint = 1000000;

// definicion de un elemento de la lista de adyacencia

typedef struct {
	unsigned nodo; // nodo
	int coste; // atributo para expresar el peso, la longitud, el coste, la inversin, etc...
} ElementoLista;

// definicion del tipo de una lista de adyacencia de un nodo

typedef vector<ElementoLista> LA_nodo;

class GRAFO {

	unsigned numero_nodos;         // numero de NODOS //
	unsigned numero_arcos;         // numero de ARCOS //
	unsigned dirigido;  //0 si el grafo es no dirigido y 1 si es dirigido
	vector<LA_nodo> LSucesores; // Lista de adyacencia de los sucesores: es una matriz donde cada fila posiblemente es posiblemente de distinto tamaño//
	vector<LA_nodo> LPredecesores; // Lista de adyacencia de los predecesores: es una matriz donde cada fila posiblemente es posiblemente de distinto tamaño//
	map<unsigned, unsigned> pendientes;
public:
	GRAFO(char nombrefichero[]);
	~GRAFO();
	void actualizar(char nombrefichero[]);
	unsigned Es_dirigido(); //devuelve 0 si el grafo es no dirigido y 1 si es dirigido
	void Info_Grafo();
	//void Mostrar_Listas(int l);
	void Mostrar_Lista_Sucesores();
	void Mostrar_Lista_Predecesores();
	void ListaPredecesores();
	void dfs(unsigned i, vector<bool> &visitado);
	void ComponentesConexas();

};

#endif
