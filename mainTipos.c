#include <stdio.h>
#include <string.h>
#include "tabla_tipos.c"

/*
 * Fecha: 30/05/2020
 * Autor: VMCR
 * Descripción: Pruebas para TT y pilas de TT
 * Modificación:
 * Modificó:
 */

int main(void){
    printf("Pruebas para la tabla de tipos\n\n");
    
	printf("Creando la pila de tablas de tipos\n\n");
    TSTACK *pilaTT = init_type_tab_stack();
    
	printf("Creando dos tablas de tipos\n\n");
    TYPTAB *prueba1 = init_type_tab();
    TYPTAB *prueba2 = init_type_tab();
    
	printf("Creando tres tipos\n\n");
    TYP *tipo1 = init_type();
    TYP *tipo2 = init_type();
    TYP *tipo3 = init_type();
    
	printf("Llenando los tipos\n\n");
    tipo1->id = 0;
    strcpy(tipo1->nombre,"entero");
    tipo1->tb.is_est = 1;
    tipo1->tam = 4;
    
    tipo2->id = 1;
    strcpy(tipo1->nombre,"flotante");
    tipo2->tb.is_est = 1;
    tipo2->tam = 4;
    
    tipo3->id = 2;
    strcpy(tipo1->nombre,"doble");
    tipo3->tb.is_est = 1;
    tipo3->tam = 8;
	
    printf("Insertando dos tablas en la pila\n\n");
    push_tt(pilaTT, prueba1);
    push_tt(pilaTT, prueba2);
    
	printf("Llenando la tabla de la cima con 3 elementos\n\n");
    append_type(pilaTT->top, tipo1);
    append_type(pilaTT->top, tipo2);
    append_type(pilaTT->top, tipo3);
    
	printf("Imprimiendo la tabla de la cima\n\n");
    print_tab(pilaTT->top);
    
	printf("Sacando las tablas de la pila\n\n");
	TYPTAB *prueba1pop = init_type_tab();
    TYPTAB *prueba2pop = init_type_tab();
    
    printf("Liberando memoria\n\n");
    free(tipo1);
    free(tipo2);
    free(tipo3);
    free(prueba1pop);
    free(prueba2pop);
    free(prueba1);
    free(prueba2);
    free(pilaTT);
    
    return 0;
}
