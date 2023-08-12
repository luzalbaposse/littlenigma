#include "utils.h"
#include <stdio.h>

int strLen(char* src) {
/*
Requiere: src es un puntero a un arreglo de caracteres terminado en '\0'.
Devuelve: la cantidad de caracteres en src sin contar el '\0'.
*/
    int i;
    while(src[i] != '\0'){
        i++;
    }
    return i;
}

char* strDup(char* src) {
    /*
    Requiere: src es un puntero a un arreglo de caracteres terminado en '\0'.
    Devuelve: un puntero a un arreglo de caracteres con el mismo contenido que src.
    */
    int i = 0;
    char* aux = (char*)malloc(sizeof(char) * (strLen(src)+1)); 
    while (src[i] != '\0'){        
        aux[i] = src[i];
        i++;
    }
    // le agrego el caracter nulo
    aux[i] = '\0';
    return aux;
}

struct littleEnigma* littleEnigmaNew(char** alphabetPermutation, int count){
/*
Requiere: alphabetPermutation es un puntero a un arreglo de punteros a arreglos de caracteres
terminados en '\0'. count es la cantidad de permutaciones en alphabetPermutation.
Devuelve: un puntero a una estructura littleEnigma que contiene count ruedas, cada una con
la permutación de letras correspondiente.
*/
    struct littleEnigma* le = (struct littleEnigma*)malloc(sizeof(struct littleEnigma)); // Pido memoria para littleEnigma
    le->wheels = (struct wheel**)malloc(sizeof(struct wheel*) * count); // Pido memoria para el arreglo de ruedas
    le->wheelsCount = count; // Asigno la cantidad de ruedas
    for(int i=0; i<count; i++) { // Recorro el arreglo de permutaciones
        le->wheels[i] = makeWheelFromString(alphabetPermutation[i]); // Creo la rueda a partir de la permutación
    }
    return le; // Retorno la estructura littleEnigma creada
}

void littleEnigmaSet(struct littleEnigma* le, int* password) {

    /*
    Requiere:  password es un puntero a un arreglo de enteros de tamaño igual a la cantidad de
ruedas en le.
    Devuelve: nada.
    Efecua: configura las ruedas de le de acuerdo a password. Cada entero en password indica
    */
    for(int i=0; i<le->wheelsCount; i++) { // Recorro el arreglo de ruedas
        setWheel(le->wheels[i], password[i]); // Configuro la rueda actual
    }
    return;
}

char* littleEnigmaEncrypt(struct littleEnigma* le, char* text){

    /*
   Requiere: text es un puntero a un arreglo de caracteres terminado en '\0'.
   Devuelve: un puntero a un arreglo de caracteres con el texto codificado.
    */
    char* aux = (char*)malloc(sizeof(char) * (strLen(text)+1)); // Pido memoria para la nueva string
    for(int i=0; i<strLen(text); i++) { // Recorro la string
        aux[i] = encryptOneLetter(le, text[i]); // Codifico el caracter actual
    }
    aux[strLen(text)] = '\0'; // Le agrego el caracter nulo
    return aux; // Retorno la nueva string
}

char* littleEnigmaDecrypt(struct littleEnigma* le, char* code) {

    /*
    Genera una nueva string, resultado de la decodificación de la string pasada por parámetro. Esta 
    última no debe ser modificada. Aplica a cada caracter de la función decryptOneLetter.
    */

    return 0;
}

void littleEnigmaDelete(struct littleEnigma* le) {

    /*
    Borra la estructura littleEnigma y todas las estructuras apuntadas. Para esto se debe utilizar
    la función wheelDelete
    */

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
   */
    struct wheel* w = (struct wheel*)malloc(sizeof(struct wheel)); // Pido memoria para wheel
    w->alphabet = strDup(alphabetPermutation); // Copio el alfabeto
    w->count = strLen(alphabetPermutation); // Cuento la cantidad de letras
    struct letter* current = (struct letter*)malloc(sizeof(struct letter)); // Pido memoria para letter
    current->letter = alphabetPermutation[0]; // Asigno la primera letra
    current->position = 0; // Asigno la primera posición
    current->next = current; // Asigno el siguiente como el mismo
    w->first = current; // Asigno el primer letter
    for(int i=1; i<w->count; i++) { // Recorro el resto si es que hay, y los enlazo
        struct letter* next = (struct letter*)malloc(sizeof(struct letter)); // Pido memoria para el siguiente letter
        next->letter = alphabetPermutation[i]; // Asigno la letra
        next->position = i; // Asigno la posición
        next->next = current->next;
        current->next = next; 
        current = next;
    }
    return w; // Retorno la estructura wheel creada a partir de la permutación
}

void setWheel(struct wheel* w, int position) {
    struct letter* current = w->first;
    while(current->position != position) {
        current = current->next;
    }
    w->first = current;   
}

void rotateWheel(struct wheel* w, int steps) {

    /*
    Mueve el puntero first de la lista la cantidad de steps pasados por parámetro. No retorna
ningún valor, ya que modifica la estructura w.
    */
    for(int i=0; i<steps; i++) {
        w->first = w->first->next;
        
    }


}

void rotateWheels(struct wheel** wheels, int wheelsCount) {
    /*
    Recorre el arreglo de ruedas y rota cada una de ellas una posición. Si la rueda llega al final
    */
    for(int i=0; i<wheelsCount; i++) { // recorro las ruedas
        struct wheel* current = wheels[i];  // me paro en la rueda actual
        rotateWheel(current, 1); // roto la rueda actual
        if(current->first->position == 0) { // si la rueda actual llego al final
            rotateWheel(current, 1); // roto la rueda actual
        }
    }
    

}

void wheelDelete(struct wheel* w) {
    /*
    Libera la memoria de la estructura wheel y de todos los letter que contiene.
    */   
    struct letter* current = w->first; // Me paro en el primer nodo
    struct letter* next = current->next; // me paro en el segundo
    while (next != w->first) { // mientras el siguiente, no sea el primero
        struct letter* temp = current; // me creo un nodo temporal para guardar el actual
        current = next; // designo como actual al siguiente 
        next = current->next; // designo como siguiente al siguiente del actual
        free(temp); // libero el que quería liberar 
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
/*
Requiere: le es un puntero a una estructura littleEnigma inicializada.
Devuelve: la letra codificada por la m´aquina.
    */
    for(int i=0; i<le->wheelsCount; i++) { // recorro las ruedas
        struct wheel* current = le->wheels[i];  // me paro en la rueda actual
        letter = encryptWheel(current, letter); // codifico la letra
    }
    rotateWheels(le->wheels, le->wheelsCount); // roto las ruedas
    return letter;



}

char decryptOneLetter(struct littleEnigma* le, char letter) {

    /*
    Requiere:  le es un puntero a una estructura littleEnigma inicializada.
    Devuelve: la letra decodificada por la m´aquina.

    */
    for(int i=le->wheelsCount-1; i>=0; i--) { // recorro las ruedas
        struct wheel* current = le->wheels[i];  // me paro en la rueda actual
        letter = decryptWheel(current, letter); // decodifico la letra
    }
    rotateWheels(le->wheels, le->wheelsCount); // roto las ruedas
    return letter;
}