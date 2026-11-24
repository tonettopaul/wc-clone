#include <stdio.h> 
#include <stdlib.h>
#include <wctype.h>
#include <string.h>

int wc(void) {
    int count_words = 0; 
    int count_lines = 0;
    int count_bytes = 0;
    char buf[2] = " ";
    char tmp[2] = " ";

    while(1) {
        if(fgets(buf, sizeof(buf), stdin) == NULL) {
            if(feof(stdin)) {
                if(!iswspace(buf[0])) {
                    count_words++;
                }
                break;
            } else {
                perror("Error: fgets failed in some kind of way. Aborting. \n");
                exit(EXIT_FAILURE);
            }
        }
        for(size_t i = 0; i < sizeof(buf); i++) {
            if(iswspace(buf[i]) && !iswspace(tmp[i])) {
                count_words++;
            }
            if(buf[i] == '\n') {
                count_lines++;
            }
            strcpy(tmp, buf);
        }
        count_bytes++;
    }

    printf("lines: %d; words: %d; bytes: %d\n", count_lines, count_words, count_bytes);

    return count_words;
}

int main(void) {
    wc();
    return 1;
}
