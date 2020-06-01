# ifndef SYMTAB_H
#define SYMTAB_H
#include <stdbool.h>
#include "datos.h"

/*
 * Fecha: 30/05/2020
 * Autor: VMCR
 * Descripción: Prototipos de funciones para las tablas y pilas de símbolos
 * Modificación:
 * Modificó:
 */

void append_sym(SYMTAB *t , SYM *s) ; //Agrega al final de la tabla un nuevo símbolo

void clear_sym_tab (SYMTAB *tablaSim) ; // Deja vacía la tabla

SYMTAB pop_st(SSTACK *stack) ; // Ejecuta un pop sobre la pila de tablas de símbolos

void push_st(SSTACK *stack, SYMTAB *tablaSim) ; // Ingresa una tabla a la pila de tablas de símbolos

SSTACK *init_sym_tab_stack(); // Reserva memoria para la pila

SYMTAB *init_sym_tab(); // Reserva memoria para una tabla de símbolos vacía

SYM *init_sym(); // Reserva memoria para un símbolo vacío

void finish_sym_tab_stack(SSTACK *stackSim); // Libera la memoria para la pila

void finish_sym_tab(SYMTAB *tablaSim); // Libera memoria para una tabla de símbolos

void finish_sym(SYM *simbolo); // Libera memoria para un símbolo vacío

void print_tab(SYMTAB *tablaSim); // Imprime en pantalla la tabla de símbolos
#endif
