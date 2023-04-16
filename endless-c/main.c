#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_NAME_LENGTH 20
#define MAX_TYPE_LENGTH 7

struct Entity {
    char name[MAX_NAME_LENGTH];
    char type[MAX_TYPE_LENGTH];
    int health;
    int attackRange[2];
};



int getAttackValue(int range[2]) {
    return rand() % (range[1] + 1 - range[0]) + range[0];
};

int fight(struct Entity hero, struct Entity enemy) {
    while (hero.health > 0 && enemy.health > 0) {
        
        printf("\n[ Hero: %d HP | %s: %d HP ]\n", hero.health, enemy.type, enemy.health);
        
        // Player Turn
        
        printf("What would you like to do?\n");
        printf("[1] Attack\n");
        
        int action;
        scanf("%d", &action);
        
        if (action == 1) {
            const int damage = getAttackValue(hero.attackRange);
            printf("You swing at the %s for %d damage!\n", enemy.type, damage);
            enemy.health -= damage;
        }
        
        sleep(2);
        
        // Enemy Turn
        
        if (enemy.health > 0) {
            const int damage = getAttackValue(enemy.attackRange);
            printf("The %s takes a swing at you for %d damage!\n", enemy.type, damage);
            hero.health -= damage;
        } else {
            printf("%s: You...\n", enemy.type);
            sleep(1);
            printf("%s: Defeated...\n", enemy.type);
            sleep(1);
            printf("%s: The mighty %s!\n\n", enemy.type, enemy.name);
        }
        
        sleep(2);
    }
    
    if (hero.health > 0) {
        return 1;
    } else {
        return 0;
    }
};

void play(void) {
    struct Entity hero;
    
    strcpy(hero.type, "Human");
    
    hero.health = 20;
    hero.attackRange[0] = 1;
    hero.attackRange[1] = 8;
    
    printf("Welcome to Endless C, young hero! What is your name?\n");
    scanf("%s", hero.name);
    
    printf("\nWell, %s, you have a long journey ahead of you...\n", hero.name);
    sleep(2);
    
    struct Entity enemy;
    
    strcpy(enemy.name, "Jared");
    strcpy(enemy.type, "Goblin");
    enemy.health = 20;
    enemy.attackRange[0] = 1;
    enemy.attackRange[1] = 4;
    
    printf("\nIt looks like a %s is approaching!\n", enemy.type);
    sleep(2);
    
    printf("%s: \"Well...what do we have here! Name's %s, prepare to fight!\"\n", enemy.type, enemy.name);
    sleep(2);
    
    const int fightResult = fight(hero, enemy);
    
    if (fightResult == 1) {
        printf("You have reached the end of Endless C! Not very endless was it?\n");
    } else {
        printf("Your thoughts fade to black and you awake in the same forest from before...");
    }
    
    printf("\n");
}

int main(void) {
    play();
    return 0;
}
