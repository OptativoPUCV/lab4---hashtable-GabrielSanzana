#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "hashmap.h"


typedef struct HashMap HashMap;
int enlarge_called=0;

struct HashMap {
    Pair ** buckets;
    long size; //cantidad de datos/pairs en la tabla
    long capacity; //capacidad de la tabla
    long current; //indice del ultimo dato accedido
};

Pair * createPair( char * key,  void * value) {
    Pair * new = (Pair *)malloc(sizeof(Pair));
    new->key = key;
    new->value = value;
    return new;
}

long hash( char * key, long capacity) {
    unsigned long hash = 0;
     char * ptr;
    for (ptr = key; *ptr != '\0'; ptr++) {
        hash += hash*32 + tolower(*ptr);
    }
    return hash%capacity;
}

int is_equal(void* key1, void* key2){
    if(key1==NULL || key2==NULL) return 0;
    if(strcmp((char*)key1,(char*)key2) == 0) return 1;
    return 0;
}


void insertMap(HashMap * map, char * key, void * value) {
  if(key == NULL)
    return;

  size_t index = hash(key, map->capacity); // Aplicar la función hash a la clave

  while(map->buckets[index] != NULL && map->buckets[index]->key != NULL) {
    // Avanzar a la siguiente casilla disponible (nula o con par inválido)
    index = (index + 1) % map->capacity;
  }

  map->buckets[index] = createPair(key, value); // Insertar el nuevo par en la casilla encontrada
  map->size++; // Incrementar el tamaño del mapa
  map->current = index; // Actualizar el índice current a la nueva posición
}

void enlarge(HashMap * map) {
    enlarge_called = 1; //no borrar (testing purposes)


}


HashMap * createMap(long capacity) {
    HashMap *mapaLocal = malloc(sizeof(HashMap));
    mapaLocal->buckets = (Pair **) calloc(sizeof(Pair*),capacity);
    mapaLocal->size=0;
    mapaLocal->capacity = capacity;
    mapaLocal->current = -1;
    return mapaLocal;
}

void eraseMap(HashMap * map,  char * key) {    


}

Pair * searchMap(HashMap * map,  char * key) {   


    return NULL;
}

Pair * firstMap(HashMap * map) {

    return NULL;
}

Pair * nextMap(HashMap * map) {

    return NULL;
}
