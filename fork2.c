#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid;
    int a = 0;

    pid = fork();

    if (pid == -1) {
        // Обработка ошибки
        perror("fork failed");
        return -1;
    } else if (pid == 0) {
        // Код для дочернего процесса
        a = 10; // Изменяем значение переменной в дочернем процессе
        printf("Дочерний процесс: PID = %d, PPID = %d, a = %d\n", getpid(), getppid(), a);
    } else {
        // Код для родительского процесса
        a = 5; // Изменяем значение переменной в родительском процессе
        printf("Родительский процесс: PID = %d, PPID = %d, a = %d\n", getpid(), getppid(), a);
    }

    return 0;
}
