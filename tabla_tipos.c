#include <stdbool.h>
#include "tabla_tipos.h"

/*
 * Fecha: 30/05/2020
 * Autor: VMCR
 * Descripción: Funciones para las tablas y pilas de tipos
 * Modificación:
 * Modificó:
 */

void append_type(TYPTAB *tablaTipos, TYP *tipo){
	if(tablaTipos->head == NULL){ // Si la TT está vacía
		tablaTipos->head = tipo; // Todavía no hay tail, el next de head sigue siendo nulo
		tablaTipos->num++;
	}
	else{
		if(tablaTipos->num == 1){ // Si hay un elemento en la tabla
			tablaTipos->tail = tipo; // El nuevo se convierte en tail
			tablaTipos->head->next = tipo; // El nuevo elemento es el siguiente del que había
			tablaTipos->tail->next = NULL;
			tablaTipos->num++;
		}
		else{
			TYP *current = tablaTipos->head; // Si hay más de 1 elemento comienzo a recorrer la tabla
			while(current->next != tablaTipos->tail){ // Cuando el siguiente del actual sea tail, me detengo
				current = current->next;
			}	
			TYP *copy = tablaTipos->tail; // Copio a tail
			current->next = copy; // El penúltimo ahora apunta a la copia de tail
			tablaTipos->tail = tipo; // Ahora el último será el símbolo nuevo
			copy->next = tablaTipos->tail; // El siguiente del que era tail es el valor nuevo
		}
	}
} //Agrega al final de la tabla un nuevo tipo


void clear_type_tab(TYPTAB *tablaTipos){
	if(tablaTipos->head == NULL){ // Si head es nulo quiere decir que la tabla está vacía
    	printf("La tabla de tipos no tiene elementos\n");
    }
    else{				
    	TYP *current = tablaTipos->head; //Obtengo a head
    	TYP *currNext = tablaTipos->head->next; // Obtengo al siguiente de head
   		while (currNext != NULL) { // Voy un símbolo adelante para comprobar
        	if(current != tablaTipos->head){
        		free(current); // Elimino el actual, mientras no sea head
        		current = currNext; // Ahora el actual se iguala con el símbolo adelantado
        		currNext = current->next; // El símbolo "adelantado" toma el valor siguiente del actual y comprobamos de nuevo	
        	}
   	 	}
   	 	printf("La tabla de tipos se ha vaciado correctamente");
	}
	tablaTipos->head = NULL; // Se libera espacio para los nodos intermedios entre head y tail, nos quedamos sólo con estos dos
	tablaTipos->tail = NULL; // Faltaba poner a tail y head como nulos
	tablaTipos->next = NULL; // No tiene siguiente
	tablaTipos->num = 0; // Ya no tiene elementos
} // Deja vacia la tabla


TYPTAB pop_tt(TSTACK *stack){
	if(stack->tail == NULL){ // Si al fondo de la pila no hay nada, es que está vacía
		printf("La pila está vac%ca",161);
		return *stack->tail;
	}
	else{
		TYPTAB *copia = stack->tail->next; /*Vamos a detenernos en el penúltimo elemento hacia arriba*/
		TYPTAB *copiaTop = stack->top; /*Obtenemos el valor de la cima de la pila actual*/
		while(copia->next != stack->top){ /*Mientras no lleguemos al penúltimo elemento, avanzamos*/
			copia = copia->next;
		}
		copia->next = NULL; /*Cuando estemos en el penúltimo, su siguiente ya no es nada por el pop*/
		stack->top = copia; /*En la cima ahora queda el penúltimo elemento*/
		return *copiaTop;
	} 
} // Ejecuta un pop sobre la pila de tablas de tipos


void push_tt(TSTACK *stack, TYPTAB *tablaTipos){
	if(stack->tail == NULL){ // Si al fondo de la pila no hay nada, es que está vacía
		stack->tail = tablaTipos; // Ingreso el primer elemento a la pila, no actualizo nada todavía
		stack->top = stack->tail;
	}
	else{
		if(stack->top == stack->tail){ // Si sólo hay un elemento en la pila, es el fondo y la cima 
			stack->top == tablaTipos; // La cima será la nueva tabla
			stack->tail->next = tablaTipos; // El siguiente del fondo es la cima, se ligan
		}
		else{ // Si hay más de un elemento en la pila
			TYPTAB *copia = stack->tail->next; /*Vamos a detenernos en el penúltimo elemento hacia arriba*/
			TYPTAB *copiaTop = stack->top; /*Obtenemos el valor de la cima de la pila actual*/
			while(copia->next != stack->top){ /*Mientras no lleguemos al penúltimo elemento, avanzamos*/
				copia = copia->next;
			}
			copia->next = copiaTop; /*Cuando estemos en el penúltimo, su siguiente es lo que sacamos de la cima*/
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
	
	// Llenando los tipos básicos
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
	memset((void*)tipo->nombre, '\0', sizeof(tipo)); // Se inicializa el arreglo de caracteres al símbolo nulo
	tipo->tam = 0;
	tipo->next = NULL;
	return tipo;
} // Reserva memoria para un tipo


/*En las siguientes tres funciones se utiliza free() porque la memoria se reservó(allocate) con malloc*/
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
    	printf("%10s %10s %10s %10s %10s\n\n","Identificador","Nombre","Tamaño","Tipo Base");
    	TYP *actual = tablaTipos->head;
   		while (size > 0) {	// Recorro la tabla hasta que se terminen los tipos
        	printf("%10d %10s %10d %10d\n\n", actual->id,actual->nombre,
					actual->tam,actual->tb.is_est);
        	actual = actual->next;
        	size--;                           
   	 	}
	}
} // Imprime en pantalla la tabla de tipos
