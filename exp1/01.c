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