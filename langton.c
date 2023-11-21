#include <ncurses.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include "langton.h"

// Implement the functions turn_left and turn_right.
// Take (ant) as input and modify direction to turn left or right (8 marks).
void turn_left(struct ant *ant) {
    switch ( ant -> direction ) {
        case UP:
            ant->direction = LEFT;
            break;
        case LEFT:
            ant->direction = DOWN;
            break;
        case DOWN:
            ant->direction = RIGHT;
            break;
        case RIGHT:
            ant->direction = UP;
            break;
    }
}

void turn_right(struct ant *ant) {
    switch ( ant -> direction ) {
        case UP:
            ant->direction = RIGHT;
            break;
        case LEFT:
            ant->direction = UP;
            break;
        case DOWN:
            ant->direction = LEFT;
            break;
        case RIGHT:
            ant->direction = DOWN;
            break;
    }
}

// Implement move_forward
// move the ant forward one step (5 marks).
void move_forward(struct ant *ant) {
    switch ( ant -> direction ) {
        case UP:
            ant->y--;
            break;
        case LEFT:
            ant->x--;
            break;
        case DOWN:
            ant->y++;
            break;
        case RIGHT:
            ant->x++;
            break;
    }
}

// The function apply_rule
// change the colour of square
// For the basic variant this means
// at a white square turn left and change the colour of the square to black
// at a black square turn right and change the colour of the square to white
// (7 marks)
void apply_rule(enum colour * colour, struct ant *ant) {
    if (*colour == 1) {
        turn_left(ant);
    } else if (*colour == 0) {
        turn_right(ant);
    }
    *colour = ++*colour % 2;
}

// Generalised version of apply_rule.
void apply_rule_general(enum colour * colour,
                        struct ant *ant,
                        struct rule *rule) {
    // enum colour used to index through char string rule
    if (rule->rules[*colour] == 'L') {
        turn_left(ant);
    } else {
        turn_right(ant);
    }
    *colour = ++*colour % strlen(rule->rules);
}
