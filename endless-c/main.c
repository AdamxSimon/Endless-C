#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 5

struct Hero {
    char name[MAX_NAME_LENGTH];
};

int main(void) {
    struct Hero hero;
    
    printf("Welcome to Endless C, young hero! What is your name?\n");
    fgets(hero.name, MAX_NAME_LENGTH, stdin);
    
    printf("Well, %s, you have a long journey ahead of you...", hero.name);
    
    printf("\n");
    
    return 0;
}
