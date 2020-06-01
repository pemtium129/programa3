#include <stdbool.h>
#include "tabla_simbolos.h"

/*
 * Fecha: 30/05/2020
 * Autor: VMCR
 * Descripci�n: Funciones para las tablas y pilas de s�mbolos
 * Modificaci�n:
 * Modific�:
 */

void append_sym(SYMTAB *tablaSim, SYM *simbolo){ //FALTA ACTUALIZAR LA DIR DEL SIMBOLO
	if(tablaSim->head == NULL){ // Si la TS est� vac�a
		tablaSim->head = simbolo; // Todav�a no hay tail, el next de head sigue siendo nulo
		tablaSim->head->dir = 0;
		tablaSim->num++;
	}
	else{
		if(tablaSim->num == 1){ // Si hay un elemento en la tabla
			tablaSim->tail = simbolo; // El nuevo se convierte en tail
			tablaSim->head->next = tablaSim->tail; // El nuevo elemento es el siguiente del que hab�a
			tablaSim->tail->next = NULL;
			tablaSim->tail->dir = tablaSim->head->dir+1; //+ TT.getTam();
			tablaSim->num++;
		}
		else{
			SYM *current = tablaSim->head; // Si hay m�s de 1 elemento comienzo a recorrer la tabla
			while(current->next != tablaSim->tail){ // Cuando el siguiente del actual sea tail, me detengo
				current = current->next;
			}
			SYM *copy = tablaSim->tail; // Copio a tail
			current->next = copy; // El pen�ltimo ahora apunta a la copia de tail
			tablaSim->tail = simbolo; // Ahora el �ltimo ser� el s�mbolo nuevo
			tablaSim->tail->dir = copy->dir+1; //+TT.getTam();
			copy->next = tablaSim->tail; // El siguiente del que era tail es el valor nuevo
			tablaSim->num++;
		}
	}
} //Agrega al final de la tabla un nuevo s�mbolo


void clear_sym_tab(SYMTAB *tablaSim){
	if(tablaSim->head == NULL){ // Si head es nulo quiere decir que la tabla est� vac�a
    	printf("La tabla de s%cmbolos no tiene elementos\n",161);
    }
    else{				
    	SYM *current = tablaSim->head; //Obtengo a head
    	SYM *currNext = tablaSim->head->next; // Obtengo al siguiente de head
   		while (currNext != NULL) { // Voy un s�mbolo adelante para comprobar
        	if(current != tablaSim->head){
        		free(current); // Elimino el actual, mientras no sea head
        		current = currNext; // Ahora el actual se iguala con el s�mbolo adelantado
        		currNext = current->next; // El s�mbolo "adelantado" toma el valor siguiente del actual y comprobamos de nuevo	
        	}
   	 	}
   	 	printf("La tabla de s%cmbolos se ha vaciado correctamente",161);
	}
	tablaSim->head = NULL; // Se libera espacio para los nodos intermedios entre head y tail, nos quedamos s�lo con estos dos
	tablaSim->tail = NULL; // Faltaba poner a tail y head como nulos
	tablaSim->next = NULL; // No tiene siguiente
	tablaSim->num = 0; // Ya no tiene elementos
} // Deja vac�a la tabla


SYMTAB pop_st(SSTACK *stack){
	if(stack->tail == NULL){ // Si al fondo de la pila no hay nada, es que est� vac�a
		printf("La pila est� vac%ca",161);
		return *stack->tail;
	}
	else{
		SYMTAB *copia = stack->tail->next; /*Vamos a detenernos en el pen�ltimo elemento hacia arriba*/
		SYMTAB *copiaTop = stack->top; /*Obtenemos el valor de la cima de la pila actual*/
		while(copia->next != stack->top){ /*Mientras no lleguemos al pen�ltimo elemento, avanzamos*/
			copia = copia->next;
		}
		copia->next = NULL; /*Cuando estemos en el pen�ltimo, su siguiente ya no es nada por el pop*/
		stack->top = copia; /*En la cima ahora queda el pen�ltimo elemento*/
		return *copiaTop;
	} 
} // Ejecuta un pop sobre la pila de tablas de s�mbolos


void push_st(SSTACK *stack, SYMTAB *tablaSim){
	if(stack->tail == NULL){ // Si al fondo de la pila no hay nada, es que est� vac�a
		stack->tail = tablaSim; // Ingreso el primer elemento a la pila, no actualizo nada todav�a
		stack->top = stack->tail;
	}
	else{
		if(stack->top == stack->tail){ // Si s�lo hay un elemento en la pila, es el fondo y la cima 
			stack->top == tablaSim; // La cima ser� la nueva tabla
			stack->tail->next = tablaSim; // El siguiente del fondo es la cima, se ligan
		}
		else{ // Si hay m�s de un elemento en la pila
			SYMTAB *copia = stack->tail->next; /*Vamos a detenernos en el pen�ltimo elemento hacia arriba*/
			SYMTAB *copiaTop = stack->top; /*Obtenemos el valor de la cima de la pila actual*/
			while(copia->next != stack->top){ /*Mientras no lleguemos al pen�ltimo elemento, avanzamos*/
				copia = copia->next;
			}
			copia->next = copiaTop; /*Cuando estemos en el pen�ltimo, su siguiente es lo que sacamos de la cima*/
			copiaTop->next = tablaSim; /*El siguiente de lo que era la cima es el nuevo elemento*/
			stack->top = tablaSim; /*En la cima ahora queda el nuevo elemento*/
		}
	}
} // Ingresa una tabla a la pila de tablas de s�mbolos


SSTACK *init_sym_tab_stack(){
	SSTACK *pilaTS = (SSTACK*) malloc(sizeof(SSTACK));
	pilaTS->top = NULL;
	pilaTS->tail = NULL;
	return pilaTS;
} // Reserva memoria para la pila


SYMTAB *init_sym_tab(){
	SYMTAB *tablaSim = (SYMTAB*) malloc(sizeof(SYMTAB));
	tablaSim->head = NULL;
	tablaSim->tail = NULL;
	tablaSim->next = NULL;
	tablaSim->num = 0;
	return tablaSim;
} // Reserva memoria para una tabla de s�mbolos vac�a


SYM *init_sym(){
	SYM *simbolo = (SYM*) malloc(sizeof(SYM));
	simbolo->args = NULL;
	simbolo->next = NULL;
	simbolo->dir = 0;
	memset((void*)simbolo->id, '\0', sizeof(simbolo)); // Se inicializa el arreglo de caracteres al s�mbolo nulo
	simbolo->num = 0;
	simbolo->tipo = 0;
	simbolo->var = 0;
	return simbolo;
} // Reserva memoria para un s�mbolo vac�o


/*En las siguientes tres funciones se utiliza free() porque la memoria se reserv�(allocate) con malloc*/
void finish_sym_tab_stack(SSTACK *stackSim){
	free(stackSim);
} // Libera la memoria para la pila


void finish_sym_tab(SYMTAB *tablaSim){
	free(tablaSim);
} // Libera memoria para una tabla de simbolos


void finish_sym(SYM *simbolo){
	free(simbolo);
} // Libera memoria para un s�mbolo vac�o


void print_tab(SYMTAB *tablaSim){
	if(tablaSim->head == NULL){
    	printf("La tabla de s%cmbolos no tiene elementos\n\n",161);
    }
    else{
    	printf("%10s %10s %10s %10s %10s\n\n","Identificador","Direccion","Tipo","Var","Num Args");
    	SYM *actual = tablaSim->head;
   		while (actual->next != NULL) {	// Recorro la tabla hasta que se terminen los s�mbolos
        	printf("%10s %10d %10d %10d %10d\n\n", actual->id,actual->dir,actual->tipo,actual->var,actual->num);
        	actual = actual->next;
   	 	}
   	 	printf("%10s %10d %10d %10d %10d\n\n", actual->id,actual->dir,actual->tipo,actual->var,actual->num);
	}
} // Imprime en pantalla la tabla de s�mbolos
