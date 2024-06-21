#include "command.h"

int main(int argc, char** argv) {
    
    if (strcmp(argv[1], "-a") == 0) { //command 1,2,3
        if (argc == 5) {
            if (isNum(argv[3]) == 0) { //command 1
                string agro = argv[2];
                if (agro == "selection-sort");
                if (agro == "insertion-sort");
                if (agro == "shell-sort");
                if (agro == "bubble-sort");
                if (agro == "heap-sort");
                if (agro == "merge-sort");
                if (agro == "quick-sort");
                if (agro == "radix-sort");
                if (agro == "counting-sort");
                if (agro == "shaker-sort");
                if (agro == "flash-sort");
            } else { //command 3

            }
        } else { //command 2

        }
        
    } else if (strcmp(argv[1], "-c") == 0) {

    } else {

    }

    return 0;
}