#include <stdio.h> 
#include <stdlib.h>

int wc() {
    int count = 1; 
    char buf[32]; 
    fgets(buf, sizeof(buf), stdin);
    for(int i = 0; i < sizeof(buf); i++) {
        if(buf[i] == ' ') {
            count++;
        }
    }

    while(1) {
        printf("%s", buf);

        if(fgets(buf, sizeof(buf), stdin) == NULL) {
            if(feof(stdin)) {
                printf("breaks at feof\n");
                break;
            } else {
                perror("Error: fgets failed in some kind of way. Aborting. \n");
                exit(EXIT_FAILURE);
            }
        }
        for(int i = 0; i < sizeof(buf); i++) {
                if(buf[i] == ' ' || buf[i] == '\n') {
                count++;
            }
        }
    }
    
    printf("%d\n", count);

    return count;
}

int main() {
    wc();
    return 1;
}
