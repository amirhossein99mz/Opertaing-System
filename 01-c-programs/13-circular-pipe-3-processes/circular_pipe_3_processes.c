#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

static void p1(int pr, int pw) {
    int n = 0;

    while (1) {
        fprintf(stdout, "P1 waiting %d\n", n);
        sleep(n);

        fprintf(stdout, "P1 writing: ");
        fflush(stdout);
        scanf("%d", &n);

        write(pw, &n, sizeof(int));
        read(pr, &n, sizeof(int));
    }
}

static void p2(int pr, int pw) {
    int n;

    while (1) {
        read(pr, &n, sizeof(int));

        fprintf(stdout, "P2 waiting %d\n", n);
        sleep(n);

        fprintf(stdout, "P2 writing: ");
        fflush(stdout);
        scanf("%d", &n);

        write(pw, &n, sizeof(int));
    }
}

static void p3(int pr, int pw) {
    int n;

    while (1) {
        read(pr, &n, sizeof(int));

        fprintf(stdout, "P3 waiting %d\n", n);
        sleep(n);

        fprintf(stdout, "P3 writing: ");
        fflush(stdout);
        scanf("%d", &n);

        write(pw, &n, sizeof(int));
    }
}

int main(int argc, char *argv[]) {

    int p12[2], p23[2], p31[2];

    if (pipe(p12) == -1 || pipe(p23) == -1 || pipe(p31) == -1)
        exit(-1);

    if (fork()) {                     // P1
        close(p12[0]);
        close(p23[0]);
        close(p23[1]);
        close(p31[1]);

        p1(p31[0], p12[1]);           // read P3->P1, write P1->P2
    }
    else {
        if (fork()) {                 // P2
            close(p12[1]);
            close(p23[0]);
            close(p31[0]);
            close(p31[1]);

            p2(p12[0], p23[1]);       // read P1->P2, write P2->P3
        }
        else {                        // P3
            close(p12[0]);
            close(p12[1]);
            close(p23[1]);
            close(p31[0]);

            p3(p23[0], p31[1]);       // read P2->P3, write P3->P1
        }
    }

    return 0;
}
