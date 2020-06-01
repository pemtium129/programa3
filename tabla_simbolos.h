# ifndef SYMTAB_H
#define SYMTAB_H
#include <stdbool.h>
#include "datos.h"

/*
 * Fecha: 30/05/2020
 * Autor: VMCR
 * Descripci�n: Prototipos de funciones para las tablas y pilas de s�mbolos
 * Modificaci�n:
 * Modific�:
 */

void append_sym(SYMTAB *t , SYM *s) ; //Agrega al final de la tabla un nuevo s�mbolo

void clear_sym_tab (SYMTAB *tablaSim) ; // Deja vac�a la tabla

SYMTAB pop_st(SSTACK *stack) ; // Ejecuta un pop sobre la pila de tablas de s�mbolos

void push_st(SSTACK *stack, SYMTAB *tablaSim) ; // Ingresa una tabla a la pila de tablas de s�mbolos

SSTACK *init_sym_tab_stack(); // Reserva memoria para la pila

SYMTAB *init_sym_tab(); // Reserva memoria para una tabla de s�mbolos vac�a

SYM *init_sym(); // Reserva memoria para un s�mbolo vac�o

void finish_sym_tab_stack(SSTACK *stackSim); // Libera la memoria para la pila

void finish_sym_tab(SYMTAB *tablaSim); // Libera memoria para una tabla de s�mbolos

void finish_sym(SYM *simbolo); // Libera memoria para un s�mbolo vac�o

void print_tab(SYMTAB *tablaSim); // Imprime en pantalla la tabla de s�mbolos
#endif
