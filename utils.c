#include "utils.h"
#include <stdio.h>
int strLen(char* src) {
/*
Requiere: src es un puntero a un arreglo de caracteres terminado en '\0'.
Devuelve: la cantidad de caracteres en src sin contar el '\0'.
Esta función cuenta la cantidad de caracteres en src sin contar el '\0'.
*/
    int i = 0;
    while(src[i] != '\0') {
        i++;
    }
    return i;
}

char* strDup(char* src) {
    /*
    Requiere: src es un puntero a un arreglo de caracteres terminado en '\0'.
    Devuelve: un puntero a un arreglo de caracteres con el mismo contenido que src.
    Esta función copia el contenido de src en un nuevo arreglo de caracteres.
    */
    int i = 0;
    char* aux = (char*)malloc(sizeof(char) * (strLen(src)+1)); 
    while(src[i] != '\0') {
        aux[i] = src[i];
        i++;
    }
    aux[i] = '\0';
    return aux;
}

struct littleEnigma* littleEnigmaNew(char** alphabetPermutation, int count){
/*
Requiere: alphabetPermutation es un puntero a un arreglo de punteros a arreglos de caracteres
terminados en '\0'. count es la cantidad de permutaciones en alphabetPermutation.
Devuelve: un puntero a una estructura littleEnigma que contiene count ruedas, cada una con
la permutación de letras correspondiente.
Crea una estructura littleEnigma a partir de un arreglo de permutaciones de letras.
*/
    struct littleEnigma* le = (struct littleEnigma*)malloc(sizeof(struct littleEnigma)); 
    le->wheels = (struct wheel**)malloc(sizeof(struct wheel*) * count); 
    le->wheelsCount = count; 
    for(int i=0; i<count; i++) { 
        le->wheels[i] = makeWheelFromString(alphabetPermutation[i]); 
    }
    return le; 
}

void littleEnigmaSet(struct littleEnigma* le, int* positions) {
    /*
    Requiere: positions es un puntero a un arreglo de enteros de tamaño igual a la cantidad de ruedas
    Devuelve: nada.
    Setea la posición de cada rueda de la máquina.
    */
    for(int i=0; i<le->wheelsCount; i++) { 
        setWheel(le->wheels[i], positions[i]);
    }
}

char* littleEnigmaEncrypt(struct littleEnigma* le, char* text){
    /*
   Requiere: text es un puntero a un arreglo de caracteres terminado en '\0'.
   Devuelve: un puntero a un arreglo de caracteres con el texto codificado.
   Genera una nueva string, resultado de la codificación de la string pasada por parámetro. Esta
    */
    char* aux = (char*)malloc(sizeof(char) * (strLen(text)+1)); 
    for(int i=0; i<strLen(text); i++) { 
        aux[i] = encryptOneLetter(le, text[i]); 
    }
    aux[strLen(text)] = '\0';
    return aux; 
}

char* littleEnigmaDecrypt(struct littleEnigma* le, char* code) {
    /*
    Requiere: code es un puntero a un arreglo de caracteres terminado en '\0'.
    Devuelve: un puntero a un arreglo de caracteres con el texto decodificado.
    Genera una nueva string, resultado de la decodificación de la string pasada por parámetro. Esta
    última no debe ser modificada. Aplica a cada caracter de la función decryptOneLetter.
    */
    char*aux=(char*)malloc(sizeof(char) * strLen(code)+1);
    for(int i=0; i<strLen(code); i++){
        aux[i]= decryptOneLetter(le, code[i]);
    }
    aux[strLen(code)]='\0';
    return aux;
}

void littleEnigmaDelete(struct littleEnigma* le) {
    /*
    Requiere: le es un puntero a una estructura littleEnigma inicializada.
    Devuelve: nada.
    Borra la estructura littleEnigma y todas las estructuras apuntadas. Para esto se debe utilizar
    la función wheelDelete
    */
        for (int i = 0; i < le->wheelsCount; i++) {
        wheelDelete(le->wheels[i]); // Liberar memoria de las ruedas
    }
    free(le->wheels); // Liberar memoria del arreglo de ruedas
    free(le); // Liberar memoria de la estructura littleEnigma
}

void littleEnigmaPrint(struct littleEnigma* le) {
    for(int i=0; i<le->wheelsCount; i++) {
        wheelPrint(le->wheels[i]);
        printf("\n");
    }
}

struct wheel* makeWheelFromString(char* alphabetPermutation) {
   /*
    Requiere: alphabetPermutation es un puntero a un arreglo de caracteres terminado en '\0'.
    Devuelve: un puntero a una estructura wheel que contiene la permutación de letras.
    Crea una estructura wheel a partir de una permutación de letras.
   */
    struct wheel* w = (struct wheel*)malloc(sizeof(struct wheel)); 
    w->alphabet = strDup(alphabetPermutation); 
    w->count = strLen(alphabetPermutation); 
    struct letter* current = (struct letter*)malloc(sizeof(struct letter)); 
    current->letter = alphabetPermutation[0]; 
    current->position = 0; 
    current->next = current; 
    w->first = current;
    for(int i=1; i<w->count; i++) { // i=1 porque ya se agregó la primera letra
        struct letter* next = (struct letter*)malloc(sizeof(struct letter)); // Crear un nuevo nodo
        next->letter = alphabetPermutation[i];  // Asignarle la letra correspondiente
        next->position = i; 
        next->next = current->next; // El siguiente del nuevo nodo es el siguiente del nodo actual
        current->next = next;  // El siguiente del nodo actual es el nuevo nodo
        current = next; // El nodo actual es el nuevo nodo
    }
    return w;
}

void setWheel(struct wheel* w, int position) {
    struct letter* current = w->first;
    while(current->position != position) { // Mientras no se haya llegado a la posición indicada
        current = current->next; // Avanzar al siguiente nodo
    }
    w->first = current;   
}

void rotateWheel(struct wheel* w, int steps) {
    /*
    Requiere: w es un puntero a una estructura wheel inicializada. steps es un entero positivo.
    Devuelve: nada.
    Mueve el puntero first de la lista la cantidad de steps pasados por parámetro. No retorna
    ningún valor, ya que modifica la estructura w.
    */
    for(int i=0; i<steps; i++) {
        w->first = w->first->next;  
    }
}

void rotateWheels(struct wheel** wheels, int wheelsCount) {
    /*
    Requiere: wheels es un puntero a un arreglo de punteros a estructuras wheel inicializadas.
    Devuelve: nada.
    Mueve el puntero first de cada estructura wheel la cantidad de veces indicada por el índice de
    */
	int i = 0;
	int seguir = 1;
	struct wheel* curr_wheel;
	while (i < wheelsCount && seguir){ // Mientras no se haya llegado al final del arreglo y no se haya llegado a la primera posición de la rueda
		curr_wheel = wheels[i]; // Se obtiene la rueda actual
		rotateWheel(curr_wheel, 1); // Se rota la rueda actual en una posición
		if ((curr_wheel->first)->position != 0){ 
			seguir = 0; 
		}
		i++;
	}
	
	return;
}

void wheelDelete(struct wheel* w) {
    /*
    Requiere: un struct wheel
    Devuelve: nada
    Libera la memoria de la estructura wheel y de todos los letter que contiene.
    */   
    struct letter* current = w->first; 
    struct letter* next = current->next; 
    while (next != w->first) { 
        struct letter* temp = current; 
        current = next;
        next = current->next; 
        free(temp);
    }
    free(current);
    free(w->alphabet);
    free(w); 
}

void wheelPrint(struct wheel* w) {
    printf("%s", w->alphabet);
    struct letter* current = w->first;
    int i = 0;
    while(i<w->count) {
        printf("(%c-%i)", current->letter, current->position);
        current = current->next;
        i++;
    }
}

int letterToIndex(char letter) {
    if('A' <= letter && letter <= 'Z') return letter-'A';
    return 0;
}

char indexToletter(int index) {
    if(0 <= index && index <= 25) return index+'A';
    return 0;
}

char encryptWheel(struct wheel* w, char letter) {
    int index =  letterToIndex(letter);
    struct letter* current = w->first;
    int i = 0;
    while(i<index) {
        current = current->next;
        i++;
    }
    return current->letter;
}

char decryptWheel(struct wheel* w, char letter) {
    struct letter* current = w->first;
    int i = 0;
    while(current->letter != letter) {
        current = current->next;
        i++;
    }
    return indexToletter(i);
}

char encryptOneLetter(struct littleEnigma* le, char letter) {
    for(int i=0; i<le->wheelsCount; i++) { 
        struct wheel* current = le->wheels[i]; 
        letter = encryptWheel(current, letter); 
    }
    rotateWheels(le->wheels, le->wheelsCount);
    return letter;
}

char decryptOneLetter(struct littleEnigma* le, char letter) {
    for(int i=le->wheelsCount-1; i>=0; i--) { 
        struct wheel* current = le->wheels[i]; 
        letter = decryptWheel(current, letter);  
    }
    rotateWheels(le->wheels, le->wheelsCount); 
    return letter;
}