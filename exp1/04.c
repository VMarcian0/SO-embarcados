#include <stdio.h>
#define MAX 20

int read_array(float array[]){
    int size, i;
    printf("Inset the amount of elements and witch one of then separated by empty space:\n");
    scanf("%d", &size);
    for(i = 0; i < size; i++){
        scanf("%f", array + i);
    }
    return size; 
}

void print_array(float array[], int size){
    for(int i = 0; i < size; i++){
        printf("%f ", array[i]);
    }
}

int main(){
    float array[MAX];
    int size = read_array(array);
    print_array(array, size);
    return size;
}