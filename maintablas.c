#include <stdio.h>
#include <string.h>
#include "tabla_simbolos.c"

/*
 * Fecha: 30/05/2020
 * Autor: VMCR
 * Descripci�n: Pruebas para TS y pilas de TS
 * Modificaci�n:
 * Modific�:
 */

int main(void){
    printf("Pruebas para la tabla de s%cmbolos\n",161);
    SYMTAB *cola = init_sym_tab();
    printf("Cola: %d\n\n",cola->num);
    printf("Cola: %s\n\n",cola->head);
    printf("Tama�o: %d",sizeof(cola));
    print_tab(cola);
    return 0;
}
