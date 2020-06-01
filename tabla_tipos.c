#include <stdbool.h>
#include "tabla_tipos.h"

/*
 * Fecha: 30/05/2020
 * Autor: VMCR
 * Descripci�n: Funciones para las tablas y pilas de tipos
 * Modificaci�n:
 * Modific�:
 */

void append_type(TYPTAB *tablaTipos, TYP *tipo){
	if(tablaTipos->head == NULL){ // Si la TT est� vac�a
		tablaTipos->head = tipo; // Todav�a no hay tail, el next de head sigue siendo nulo
		tablaTipos->num++;
	}
	else{
		if(tablaTipos->num == 1){ // Si hay un elemento en la tabla
			tablaTipos->tail = tipo; // El nuevo se convierte en tail
			tablaTipos->head->next = tipo; // El nuevo elemento es el siguiente del que hab�a
			tablaTipos->tail->next = NULL;
			tablaTipos->num++;
		}
		else{
			TYP *current = tablaTipos->head; // Si hay m�s de 1 elemento comienzo a recorrer la tabla
			while(current->next != tablaTipos->tail){ // Cuando el siguiente del actual sea tail, me detengo
				current = current->next;
			}	
			TYP *copy = tablaTipos->tail; // Copio a tail
			current->next = copy; // El pen�ltimo ahora apunta a la copia de tail
			tablaTipos->tail = tipo; // Ahora el �ltimo ser� el s�mbolo nuevo
			copy->next = tablaTipos->tail; // El siguiente del que era tail es el valor nuevo
		}
	}
} //Agrega al final de la tabla un nuevo tipo


void clear_type_tab(TYPTAB *tablaTipos){
	if(tablaTipos->head == NULL){ // Si head es nulo quiere decir que la tabla est� vac�a
    	printf("La tabla de tipos no tiene elementos\n");
    }
    else{				
    	TYP *current = tablaTipos->head; //Obtengo a head
    	TYP *currNext = tablaTipos->head->next; // Obtengo al siguiente de head
   		while (currNext != NULL) { // Voy un s�mbolo adelante para comprobar
        	if(current != tablaTipos->head){
        		free(current); // Elimino el actual, mientras no sea head
        		current = currNext; // Ahora el actual se iguala con el s�mbolo adelantado
        		currNext = current->next; // El s�mbolo "adelantado" toma el valor siguiente del actual y comprobamos de nuevo	
        	}
   	 	}
   	 	printf("La tabla de tipos se ha vaciado correctamente");
	}
	tablaTipos->head = NULL; // Se libera espacio para los nodos intermedios entre head y tail, nos quedamos s�lo con estos dos
	tablaTipos->tail = NULL; // Faltaba poner a tail y head como nulos
	tablaTipos->next = NULL; // No tiene siguiente
	tablaTipos->num = 0; // Ya no tiene elementos
} // Deja vacia la tabla


TYPTAB pop_tt(TSTACK *stack){
	if(stack->tail == NULL){ // Si al fondo de la pila no hay nada, es que est� vac�a
		printf("La pila est� vac%ca",161);
		return *stack->tail;
	}
	else{
		TYPTAB *copia = stack->tail->next; /*Vamos a detenernos en el pen�ltimo elemento hacia arriba*/
		TYPTAB *copiaTop = stack->top; /*Obtenemos el valor de la cima de la pila actual*/
		while(copia->next != stack->top){ /*Mientras no lleguemos al pen�ltimo elemento, avanzamos*/
			copia = copia->next;
		}
		copia->next = NULL; /*Cuando estemos en el pen�ltimo, su siguiente ya no es nada por el pop*/
		stack->top = copia; /*En la cima ahora queda el pen�ltimo elemento*/
		return *copiaTop;
	} 
} // Ejecuta un pop sobre la pila de tablas de tipos


void push_tt(TSTACK *stack, TYPTAB *tablaTipos){
	if(stack->tail == NULL){ // Si al fondo de la pila no hay nada, es que est� vac�a
		stack->tail = tablaTipos; // Ingreso el primer elemento a la pila, no actualizo nada todav�a
		stack->top = stack->tail;
	}
	else{
		if(stack->top == stack->tail){ // Si s�lo hay un elemento en la pila, es el fondo y la cima 
			stack->top == tablaTipos; // La cima ser� la nueva tabla
			stack->tail->next = tablaTipos; // El siguiente del fondo es la cima, se ligan
		}
		else{ // Si hay m�s de un elemento en la pila
			TYPTAB *copia = stack->tail->next; /*Vamos a detenernos en el pen�ltimo elemento hacia arriba*/
			TYPTAB *copiaTop = stack->top; /*Obtenemos el valor de la cima de la pila actual*/
			while(copia->next != stack->top){ /*Mientras no lleguemos al pen�ltimo elemento, avanzamos*/
				copia = copia->next;
			}
			copia->next = copiaTop; /*Cuando estemos en el pen�ltimo, su siguiente es lo que sacamos de la cima*/
			copiaTop->next = tablaTipos; /*El siguiente de lo que era la cima es el nuevo elemento*/
			stack->top = tablaTipos; /*En la cima ahora queda el nuevo elemento*/
		}
	}
} // Ingresa una tabla a la pila de tablas de tipos


TSTACK *init_type_tab_stack(){
	TSTACK *pilaTT = (TSTACK*) malloc(sizeof(TSTACK));
	pilaTT->top = NULL;
	pilaTT->tail = NULL;
	return pilaTT;
} // Reserva memoria para la pila


TYPTAB *init_type_tab(){
	TYPTAB *tablaTipos = (TYPTAB*) malloc(sizeof(TYPTAB));
	tablaTipos->head = NULL;
	tablaTipos->tail = NULL;
	tablaTipos->next = NULL;
	tablaTipos->num = 0;
	TYP *entero = init_type();
	TYP *real = init_type();
	TYP *doble_real = init_type();
	TYP *caracter = init_type();
	
	// Llenando los tipos b�sicos
	entero->id = 0;
	strcpy(entero->nombre,"int");;
	entero->tb.is_est = 1;
	entero->tam = 4;
	
	real->id = 1;
	strcpy(real->nombre,"float");;
	real->tb.is_est = 1;
	real->tam = 4;
	
	doble_real->id = 2;
	strcpy(doble_real->nombre,"double");
	doble_real->tb.is_est = 1;
	doble_real->tam = 8;
	
	caracter->id = 3;
	strcpy(caracter->nombre,"char");
	caracter->tb.is_est = 1;
	caracter->tam = 1;
	
	append_type(tablaTipos, entero);
	append_type(tablaTipos, real);
	append_type(tablaTipos, doble_real);
	append_type(tablaTipos, caracter);
	
	return tablaTipos;
} // Reserva memoria para una tabla de tipos e inserta los tipos nativos


TYP *init_type(){
	TYP *tipo = (TYP*) malloc(sizeof(TYP));
	tipo->id = 0;
	memset((void*)tipo->nombre, '\0', sizeof(tipo)); // Se inicializa el arreglo de caracteres al s�mbolo nulo
	tipo->tam = 0;
	tipo->next = NULL;
	return tipo;
} // Reserva memoria para un tipo


/*En las siguientes tres funciones se utiliza free() porque la memoria se reserv�(allocate) con malloc*/
void finish_type_tab_stack(TSTACK *stackTyp){
	free(stackTyp);
} // Libera la memoria para la pila


void finish_type_tab(TYPTAB *tablaTipos){
	free(tablaTipos);
} // Libera memoria para una tabla de tipos


void finish_type(TYP *tipo){
	free(tipo);
} // libera memoria para un tipo


void print_tab(TYPTAB *tablaTipos){
	if(tablaTipos->head == NULL){
    	printf("La tabla de tipos no tiene elementos\n\n");
    }
    else{
    	int size = tablaTipos->num;				
    	printf("%10s %10s %10s %10s %10s\n\n","Identificador","Nombre","Tama�o","Tipo Base");
    	TYP *actual = tablaTipos->head;
   		while (size > 0) {	// Recorro la tabla hasta que se terminen los tipos
        	printf("%10d %10s %10d %10d\n\n", actual->id,actual->nombre,
					actual->tam,actual->tb.is_est);
        	actual = actual->next;
        	size--;                           
   	 	}
	}
} // Imprime en pantalla la tabla de tipos
