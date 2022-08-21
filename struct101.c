// Ex. 1
/*
#include <stdio.h>

struct struct101
{
    float weight;
    float height;
    int age;
};

int main(){
    struct struct101 foo;
    printf("Insert in order weight, height and age");
    scanf("%f %f %i", &foo.weight, &foo.height, &foo.age);
    printf("age: %i|height: %f| weight: %f", foo.age, foo.height, foo.weight);
    return 0;
}

*/

// Ex. 2
/*
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
    struct person persons[amount];
    for(int i=0; i<amount; i++){
        createPerson(&persons[i]);
    }
    for(int i=0; i<amount; i++){
        printPerson(&persons[i]);
    }
    return 0;
}

void createPerson(struct person *p){
    printf("Insert in order weight, height and age\n");
    scanf("%f %f %i", &p->weight, &p->height, &p->age);
}

void printPerson(struct person *p){
    printf("age: %i|height: %f| weight: %f\n", p->age, p->height, p->weight);
}
*/


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