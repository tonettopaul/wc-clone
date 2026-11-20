#include <stdio.h> 
#include <stdlib.h>

int wc() {
    int count = 0; 
    char buf[32]; 
    fgets(buf, sizeof(buf), stdin);
    for(int i = 0; i < sizeof(buf); i++) {
        if(buf[i] == ' ') {
            count++;
        }
    }
    
    printf("%d\n", count);

    return count;
}

int main() {
    wc();
    return 1;
}
