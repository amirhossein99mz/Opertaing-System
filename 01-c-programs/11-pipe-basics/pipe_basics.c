#include <stdio.h> // input/output
#include <stdlib.h> // eixt(), rand()
#include <string.h> //
#include <unistd.h> // fork(), exec(), system()

#define N 256

int main(int argc, char *argv[]) {
    
    int fd[2];
    char line[N];    

    pipe(fd); // Pipe is created.

    if (fork()) {
        close(fd[0]); // Parent closes read end because it only writes.
        while (1) {
            scanf("%s", line);
            write(fd[1], line, strlen(line) + 1);
        }
    } else {
        close(fd[1]); // Child closes write end because it only reads.
        while (1) {
            read(fd[0], line, N);
            printf("%s", line);
        }
    }
}
