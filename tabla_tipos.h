#ifndef TYPTAB_H
#define TYPTAB_H
#include "datos.h"

void append_type(TYPTAB *tablaTipos, TYP *tipo); //Agrega al final de la tabla un nuevo tipo

void clear_type_tab(TYPTAB *tablaTipos); // Deja vacía la tabla

TYPTAB pop_tt(TSTACK *stack); // Ejecuta un pop sobre la pila de tablas de tipos

void push_tt(TSTACK *stack, TYPTAB *tablaTipos); // Ingresa una tabla a la pila de tablas de tipos

TSTACK *init_type_tab_stack(); // Reserva memoria para la pila

TYPTAB *init_type_tab(); // Reserva memoria para una tabla de tipos e inserta los tipos nativos

TYP *init_type(); // Reserva memoria para un tipo

void finish_type_tab_stack(TSTACK *stack); // Libera la memoria para la pila

void finish_type_tab(TYPTAB *tablaTipos); // Libera memoria para una tabla de tipos

void finish_type(TYP *tipo); // Libera memoria para un tipo

void print_tab(TYPTAB *tablaTipos); // Imprime en pantalla la tabla de tipos

#endif
