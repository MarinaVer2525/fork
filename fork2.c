#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    pid_t pid;
    int a = 0;

    pid = fork();

    if (pid == -1) {
        perror("fork failed");
        return -1;
    } else if (pid == 0) {
        a = 10;
        printf("Дочерний процесс: PID = %d, PPID = %d, a = %d\n", getpid(), getppid(), a);
    } else {
        a = 5;
        printf("Родительский процесс: PID = %d, PPID = %d, a = %d\n", getpid(), getppid(), a);
    }

    return 0;
}
