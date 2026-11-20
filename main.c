#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 

int wc() {
    int count_words = 1; 
    int count_lines = 0;
    int count_bytes = 8;
    char buf[2]; 

    while(1) {
        if(fgets(buf, sizeof(buf), stdin) == NULL) {
            if(feof(stdin)) {
                break;
            } else {
                perror("Error: fgets failed in some kind of way. Aborting. \n");
                exit(EXIT_FAILURE);
            }
        }
        for(int i = 0; i < sizeof(buf); i++) {
            if(buf[i] == '\n') {
                count_lines++;
            }
        }
    }
    
    printf("lines: %d; words: %d; bytes: %d\n", count_lines, count_words, count_bytes);

    return count_words;
}

int main() {
    wc();
    return 1;
}
