/*
 * Fecha: 30/05/2020
 * Autor: VMCR
 * Descripción: Declaración de las estructuras para las tablas y pilas
 * Modificación:
 * Modificó:
 */

typedef struct arg ARG;

struct arg{
    int arg;
    ARG *next;
};

typedef struct args ARGS;

typedef struct args{
    ARG *head;
    ARG *tail;
    int num; // Número de elementos en la lista
};

typedef struct sym SYM;

struct sym{
    int dir; // Dirección para la variable
    int tipo; // Tipo como índice a la tabla de tipos
    char id[33]; // Identificador
    ARGS *args ; // Lista de argumentos
    int num; // Número de argumentos
    int var; // Tipo de variable
    SYM *next; // Apuntador al siguiente símbolo
};

typedef struct sym_tab SYMTAB;

struct sym_tab{
    SYM *head;
    SYM *tail;
    int num; //Número de elementos en la tabla
    SYMTAB *next; //Apuntador a la tabla siguiente
};

typedef struct sym_stack{
    SYMTAB *top;
    SYMTAB *tail;
} SSTACK;

typedef struct tipobase{
    int is_est; // 1:si es estructura  0:si es tipo simple  1:si no tiene tipo base
    union{
    SYMTAB *est;
    int tipo;
    } tipo;
} TB;

typedef struct type TYP;

struct type{
    int id;
    char nombre [12];
    TB tb;
    int tam;
    TYP *next; //Apuntador al siguiente tipo en la tabla de tipos
};

typedef struct type_tab TYPTAB;

struct type_tab{
    TYP *head;
    TYP *tail;
    int num; //Contador de elementos en la tabla
    TYPTAB *next; //Apuntador a la tabla siguiente
};

typedef struct typ_stack{
    TYPTAB *top;
    TYPTAB *tail;
} TSTACK;
