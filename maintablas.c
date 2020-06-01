#include <stdio.h>
#include <string.h>
#include "tabla_simbolos.c"

/*
 * Fecha: 30/05/2020
 * Autor: VMCR
 * Descripción: Pruebas para TS y pilas de TS
 * Modificación:
 * Modificó:
 */

int main(void){
    printf("Pruebas para la tabla de s%cmbolos\n",161);
    SYMTAB *cola = init_sym_tab();
    printf("Cola: %d\n\n",cola->num);
    printf("Cola: %s\n\n",cola->head);
    printf("Tamaño: %d",sizeof(cola));
    print_tab(cola);
    return 0;
}
