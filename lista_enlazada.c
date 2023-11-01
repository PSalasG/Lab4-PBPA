#include <stdio.h>
#include <stdlib.h>

// Se crea la estructura para los datos de la lista, solamente de tipo int.
struct Nodo {
	int valor;
        struct Nodo* next;
};

// Se agrega el nodo al inicio, reemplazando al head.
void agregar_nodo_inicio (int valor, struct Nodo** head) {
	struct Nodo* nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));

	nuevo->valor = valor;
	nuevo->next = (*head);
	(*head) = nuevo;
}

// Se agrega el nodo al final de la lista.
void agregar_nodo_final (int valor, struct Nodo** nodo) {
	struct Nodo* nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
	
	nuevo->valor = valor;
	
	// El caso de que sea el primer nodo de la lista.
	if (*nodo == NULL) {
        	nuevo->next = (*nodo);
        	(*nodo) = nuevo;
		return;
	}

	struct Nodo* actual = *nodo;

	while (actual->next != NULL) {
		actual = actual->next;
	}

	nuevo->next = actual->next;
	actual->next = nuevo;
}

// Elimina el nodo correspondiente al valor deseado.
void eliminar_nodo (int valor, struct Nodo** nodo) {
	struct Nodo* actual = *nodo;
	struct Nodo* anterior = NULL;

	// El caso donde se desea eliminar el head.
	if (actual != NULL && actual->valor == valor) {
		*nodo = actual->next;
		free(actual);
		return;
	}

	while (actual != NULL && actual->valor != valor) {
		anterior = actual;
		actual = actual->next;
	}
	
	// Por si no existe el nodo con ese valor.
	if (actual == NULL) {
		printf("No se encontró el nodo.\n");
		return;
	}

	anterior->next = actual->next;
	free(actual);
}

// Busca un nodo que contenga el valor deseado.
void buscar_nodo (int valor, struct Nodo* nodo) {
	struct Nodo* actual = nodo;

	while (actual != NULL && actual->valor != valor) {
		actual = actual->next;
	}

	if (actual == NULL) {
		printf("No se encontró el nodo %d en la lista.\n", valor);
		return;
	}

	printf("El nodo %d si existe en la lista.\n", actual->valor);
}

// Imprime todos los valores de la lista en órden.
void imprimir_lista (struct Nodo* nodo) {
	while (nodo != NULL) {
		printf("%d -> ", nodo->valor);
		nodo = nodo->next;
	}
	printf("\n");
}

// Elimiación de la memoria ocupada por cada nodo al finalizar la ejecución.
void liberar_memoria (struct Nodo* head) {
	struct Nodo* actual = head;
	struct Nodo* next;

	while (actual != NULL) {
		next = actual->next;
		free(actual);
		actual = next;
	}
}

// Itera hasta el índice indicado y busca el nodo correspondiente a esa posición.
void obtener_nodo (int indice, struct Nodo* nodo) {
	for (int i = 0; i < indice; i++) {
		nodo = nodo->next;

		if (nodo == NULL) {
			printf("No existe un nodo en el índice %d.\n", indice);
			return;
		}
	}
	
	printf("El nodo correspondiente al índice %d tiene el valor: %d.\n", indice, nodo->valor);
}

int main () {
	struct Nodo* head = NULL;
	
	agregar_nodo_inicio(10, &head);
	imprimir_lista(head);
	printf("Se ingresa el primer valor de la lista.\n");
	agregar_nodo_inicio(18, &head);
	imprimir_lista(head);
	printf("Se agrega un nodo al inicio de la lista.\n");
	agregar_nodo_final(26, &head);
	imprimir_lista(head);
	printf("Se agrega un nodo al final de la lista.\n");
	buscar_nodo(18, head);
	printf("Se busca un nodo y se comprueba su existencia.\n");
	eliminar_nodo(18, &head);
	imprimir_lista(head);
	printf("Se elimina un nodo de la lista por su valor.\n");
	buscar_nodo(18, head);
	printf("Se busca un nodo y se comprueba que no existe.\n");
	obtener_nodo(0, head);
	printf("Se busca un nodo en la lista por su posición y se comprueba su existencia.\n");
	obtener_nodo(4, head);
        printf("Se busca un nodo en la lista por su posición y se comprueba que no existe.\n");
	liberar_memoria(head);
}
