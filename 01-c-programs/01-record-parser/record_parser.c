#define N 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct record_s {
    int i;
    char s[N];
    float f;
} record_t;


int main(int argc, char *argv[]) {

    int fd = open(argv[1], O_RDONLY);

    if (fd == -1)exit(-1);

    record_t records[N];   

    int n = 0;

    char line[N];
    char c;
    int position = 0;

    while (read(fd, &c, sizeof(char)) > 0) {

        line[position++] = c;

        if (c == '\n') {

            line[position] = '\0';

            sscanf(line, "%d %s %f",&records[n].i,records[n].s,&records[n].f);

            n++;
            position = 0;
        }
    }

    close(fd);

    return 0;
}
