#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <sys/wait.h>

#define N 256

void P1(int *P){
    char s[N];

    close(P[0]);

    do {
        scanf("%255s", s);              
        write(P[1], s, strlen(s) + 1);  
    } while (strcmp(s, "STOP") != 0);

    close(P[1]);
}


void P2(int *P){
    
    char c;
    char string[N];
    char strings[N][N];
    int pos1 = 0, pos2 = 0;

    close(P[1]);                         // P2 only reads

    while (read(P[0], &c, sizeof(char))) {

        if (c == '\0') {                 // end of one received word
            string[pos1] = '\0';

            if (strcmp(string, "STOP") == 0)
                break;

            strcpy(strings[pos2++], string);
            printf("%s\n", string);

            pos1 = 0;
        }
        else {
            if (isalpha((unsigned char)c)) {
                if (islower((unsigned char)c))
                    c = toupper((unsigned char)c);
                else
                    c = tolower((unsigned char)c);
            }

            string[pos1++] = c;
        }
    }

    close(P[0]);
}


int main(void)
{
    int P[2];

    if (pipe(P) == -1)exit(-1);

    if (fork()) {
        P1(P);
        wait(NULL);
    }
    else {
        P2(P);
        exit(0);
    }

    return 0;
}
