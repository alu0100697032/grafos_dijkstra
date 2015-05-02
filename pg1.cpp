/*
 * pg1.cpp
 *
 *  Created on: 19/03/2015
 *      Author: Victor
 */

#include "grafo.h"

int main() {
	char fichero[40];
	cout << "Introduzca el nombre del fichero a procesar >> " << endl;
	cin >> fichero;
	GRAFO grafo(fichero);
	char opcion;
	bool parar = false;
	while (parar == false) {
		if (grafo.Es_dirigido() == 1) {
			cout << endl;
			cout << "MENU DE OPCIONES:" << endl;
			cout << "------------------------------------------------" << endl;
			cout << "| [c] Cargar un nuevo grafo:                   |" << endl;
			cout << "| [i] Mostrar la informacion basica del grafo: |" << endl;
			cout << "| [s] Mostrar la lista de sucesores            |" << endl;
			cout << "| [p] Mostrar la lista de predecesores         |" << endl;
			cout << "| [q] Salir del programa                       |" << endl;
			cout << "------------------------------------------------" << endl;
			cout << endl;
			cin >> opcion;
			switch (opcion) {
			case 'c': {
				cout << "Introduzca el nombre del fichero a procesar >> "
						<< endl;
				cin >> fichero;
				grafo.actualizar(fichero);
			}
				break;
			case 'i': {
				grafo.Info_Grafo();
			}
				break;
			case 's': {
				grafo.Mostrar_Lista_Sucesores();
			}
				break;
			case 'p': {
				grafo.Mostrar_Lista_Predecesores();
			}
				break;
			case 'q': {
				cout << endl;
				cout << "Programa cerrado" << endl;
				parar = true;
			}
				break;
			default: {
				cout << endl;
				cout << "¡Seleccione una de las opciones especificadas!"
						<< endl;
			}
				break;
			} //END SWITCH
		} else {
			cout << endl;
			cout << "MENU DE OPCIONES:" << endl;
			cout << "------------------------------------------------" << endl;
			cout << "| [c] Cargar un nuevo grafo:                   |" << endl;
			cout << "| [i] Mostrar la informacion basica del grafo: |" << endl;
			cout << "| [a] Mostrar la lista de adyacentes           |" << endl;
			cout << "| [d] DFS                                      |" << endl;
			cout << "| [q] Salir del programa                       |" << endl;
			cout << "------------------------------------------------" << endl;
			cout << endl;
			cin >> opcion;
			switch (opcion) {
			case 'c': {
				cout << "Introduzca el nombre del fichero a procesar >> "
						<< endl;
				cin >> fichero;
				grafo.actualizar(fichero);
			}
				break;
			case 'i': {
				grafo.Info_Grafo();
			}
				break;
			case 'a': {
				grafo.Mostrar_Lista_Sucesores();
			}
				break;
			case 'd': {
				grafo.ComponentesConexas();
			}
				break;
			case 'q': {
				cout << endl;
				cout << "Programa cerrado" << endl;
				parar = true;
			}
				break;
			default: {
				cout << endl;
				cout << "¡Seleccione una de las opciones especificadas!"
						<< endl;
			}
				break;
			} //END SWITCH
		}
	} //END WHILE
	return 0;
}
