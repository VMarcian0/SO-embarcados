#include <stdio.h>

struct person
{
    float weight;
    float height;
    int age;
};

void createPerson(struct person *p);
void printPerson(struct person *p);

int main(){
    int amount = 2;
    struct person foo;
    struct person *bar;
    createPerson(&foo);
    // precisa alocar
    return 0;
}

void createPerson(struct person *p){
    printf("Insert in order weight, height and age\n");
    scanf("%f %f %i", &p->weight, &p->height, &p->age);
}

void printPerson(struct person *p){
    printf("age: %i|height: %f| weight: %f\n", p->age, p->height, p->weight);
}