#include <stdio.h>
#include <stdlib.h>
#include "maze.h"
#include <time.h>

typedef struct {
    int size;
    int capacity;
    int *data;
}ArrayList;

ArrayList* createArrayList(int initialCapacity) {
    ArrayList *list = (ArrayList*)malloc(sizeof(ArrayList));

    list->data = (int*)malloc(initialCapacity * sizeof(int));
    
    list->size = 0;
    list->capacity = initialCapacity;

    return list;

}

void addElement(ArrayList* list, int value) {
    if (list->size == list->capacity) {
        int newCapacity = list->capacity +=10;
        int *newData = list->data = (int *)realloc(list->data, list->capacity * sizeof(int));
    

        if (newData == NULL){
            return;
        }
        list->data = newData;
        list->capacity = newCapacity;
    }
    list->data[list->size] = value;
    list->size++;
}


void removeLastElement(ArrayList* list) {
    if (list->size > 0) {
        int newCapacity;
        int *newData;

        list->size--;

        if (list->size < list->capacity / 4 && list->capacity / 2 >= 2) {
            newCapacity = list->capacity / 2;
            newData = (int *)realloc(list->data, newCapacity * sizeof(int));

        }
        if (newData != NULL) {
            list->data = newData;
            list->capacity = newCapacity;
        }
    }

}

int getElement(ArrayList* list, int index){
    if (index < 0 || index >= list->size) {
        
        printf("Error: Index out of bounds\n");
        return -1;
    }

    return list->data[index];
}

void freeArrayList(ArrayList* list){
    free(list->data);
    free(list);
}

void randomSearch(ArrayList *listOfMovements) {
    srand(time(NULL));
    while (!is_solved()) {
        int randomNum = rand() % 4;
        if (randomNum == 0) {
            move(UP);
            addElement(listOfMovements,0);
        }
        else if (randomNum == 1) {
            move(DOWN);
            addElement(listOfMovements,1);
        }
        else if (randomNum == 2) {
            move(LEFT);
            addElement(listOfMovements,2);
        }
        else if(randomNum == 3) {
            move(RIGHT);
            addElement(listOfMovements,3);
        }
    }
}
void printDirections(ArrayList *listOfMovements) {
    printf("\n");
    for (int i = 0; i < listOfMovements->size; i++) {

        if (i > 0) {
            printf(", ");
        }

        if (listOfMovements->data[i] == 0) {
            printf("U");
        } else if (listOfMovements->data[i] == 1) {
            printf("D");
        } else if (listOfMovements->data[i] == 2) {
            printf("L");
        } else if (listOfMovements->data[i] == 3) {
            printf("R");
        } else {
            break;
        }
    }
}


int main()
{
    ArrayList listOfMovements[100000];
    initialize_maze("mazefile.dat");
    randomSearch(listOfMovements);
    printDirections(listOfMovements);
    

    

    return 0;
}
