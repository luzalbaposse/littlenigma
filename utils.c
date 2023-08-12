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

    return 0;
}

void littleEnigmaSet(struct littleEnigma* le, int* password) {

    // COMPLETAR
}

char* littleEnigmaEncrypt(struct littleEnigma* le, char* text){

    // COMPLETAR

    return 0;
}

char* littleEnigmaDecrypt(struct littleEnigma* le, char* code) {

    // COMPLETAR

    return 0;
}

void littleEnigmaDelete(struct littleEnigma* le) {

    // COMPLETAR

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

    // COMPLETAR

    return 0;
}

char decryptOneLetter(struct littleEnigma* le, char letter) {

    // COMPLETAR

    return 0;
}


// Pruebo makeWheelFromString
int main () {
    char* alphabet = "ABC";
    struct wheel* w = makeWheelFromString(alphabet);
    wheelPrint(w);
    printf("\n");

    printf("\n");
    // Ahora pruebo rotateWheel, si le paso ABC, devuelve BCA
    printf("Ahora pruebo rotateWheel, deberia devolver BCA: \n");
    rotateWheel(w, 1);
    wheelPrint(w);
    // ahora pruebo rotateWheels con un alphabeto mas largo, voy a usar "ABCD" y deberia devolver "BCDA"
    printf("\n");
    printf("Ahora pruebo rotateWheels, deberia devolver BCDA: \n");
    char* alphabet2 = "ABCD";
    struct wheel* w2 = makeWheelFromString(alphabet2);
    struct wheel* wheels[1];
    wheels[0] = w2;
    rotateWheels(wheels, 1);
    wheelPrint(w2);
    printf("\n");
    // Pruebo de nuevo rotateWheels
    printf("Ahora pruebo rotateWheels, deberia devolver CDAB: \n");
    rotateWheels(wheels, 1);
    wheelPrint(w2);
    printf("\n");
    // pruebo wheelDelete
    printf("Ahora pruebo wheelDelete, deberia devolver nada: \n");
    wheelDelete(w2);
    printf("\n");
    wheelPrint(w2);

}