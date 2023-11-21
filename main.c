#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "visualiser.h"
#include "langton.h"

int main(int argc, char *argv[]) {
    struct ant ant1;
    start_visualisation(&ant1);

    // argc == 1 means no parameters given
    // so run standard version of ant
    if ( argc == 1 ) {
        while (not_quit()) {
            visualise_and_advance(&ant1);
        }
        end_visualisation();
    // argc == 2 means one parameter was passed in
    } else if ( argc == 2 ) {
        // if given parameter is "i"
        // do infinite anting
        if (argv[1][0] == 'i' && strlen(argv[1]) == 1) {
            while (true) {
                visualise_and_advance(&ant1);
            }
        }
        // Check if input is in valid format for an ant rule
        for (int i = 0; i < strlen(argv[1]); i++) {
            if (!(argv[1][i] == 'L' || argv[1][i] == 'R')) {
                end_visualisation();
                printf("invalid character inrule\n");
                return 0;
            }
        }
        // Input is valid. Store as a rule
        struct rule advanvcedRule;
        advanvcedRule.rules = malloc( sizeof(char) * ( strlen(argv[1]) + 1 ) );
        advanvcedRule.rules = argv[1];

        // Start generalised anting
        while (not_quit()) {
            visualise_and_advance_general(&ant1, &advanvcedRule);
        }
        end_visualisation();
    // argc == 3 means two parameters are passed in
    } else if ( argc == 3 ) {
        // Check if first parameter is a valid rule
        for (int i = 0; i < strlen(argv[1]); i++) {
            if (!(argv[1][i] == 'L' || argv[1][i] == 'R')) {
                end_visualisation();
                printf("invalid character in rule\n");
                return 0;
            }
        }
        // first input is valid so store as a rule
        struct rule advanvcedRule;
        advanvcedRule.rules = malloc( sizeof(char) * ( strlen(argv[1]) + 1 ) );
        advanvcedRule.rules = argv[1];
        // if second parameter is 'i'
        // start infinite generalised anting with given rule
        if (argv[2][0] == 'i' && strlen(argv[2]) == 1) {
            while (true) {
                visualise_and_advance_general(&ant1, &advanvcedRule);
            }
        } else {
            end_visualisation();
            printf("invalid input\n");
            return 0;
        }
        end_visualisation();
    } else if (argc > 3) {
        end_visualisation();
        printf("too many arguments\n");
    }
    return 0;
}
