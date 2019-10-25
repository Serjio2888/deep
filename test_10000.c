#include "header.h"

struct Employee* random_emp(struct Employee *emp) {
    int forks = 0;
    while (forks < 10) {
        int pid = fork();
        int status;
        ++forks;
        if (pid != 0) {
            int part_of_array = forks * 1000;
            for (int i = part_of_array - 1000; i < part_of_array; ++i) {
                emp[i].salary = 10000+part_of_array+i;
            }
            for (int i = part_of_array - 1000; i < part_of_array; ++i) {
                emp[i].position_id = pid%POSITIONS;
            }
            for (int i = part_of_array - 1000; i < part_of_array; ++i) {
                emp[i].work_stage = (pid+i)%9;
            }
            for (int i = part_of_array - 1000; i < part_of_array; ++i) {
                emp[i].age = (pid)%30+18;
            }
            for (int i = part_of_array - 1000; i < part_of_array; ++i) {
                snprintf(emp[i].name, sizeof(emp[i].name), "%s", "John");
            }
            for (int i = part_of_array - 1000; i < part_of_array; ++i) {
                snprintf(emp[i].surname, sizeof(emp[i].surname), "%s", "Constantine");
            }
        }
        if (pid == 0) {
            sleep(0.1);
            exit(1);
        }
        waitpid(pid, &status, 0);
    }
    return emp;
}

int ten_thousand_test(bool many_processes) {
    int n = 10000;
    struct Employee *emp = (struct Employee*)malloc(sizeof(struct Employee)*n);
    emp = random_emp(emp);

    clock_t begin = clock();
    if (many_processes) {
        working_with_statistics_in_many_proc(emp, 8, n);
    } else {
        working_with_statistics_in_one_process(emp, 8, n);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("%f", time_spent);
    // free(emp);

    return 0;
}

void main() {
    ten_thousand_test(true);  // много процессов
    ten_thousand_test(false);  // один процесс
}
/*   В обоих режимах по пять раз запустил программу и посчитал среднее арифметическое.
    Однопроцессная программа отрабатывала в среднем за 0,004228с, а 6 процессов - за 0,002318с
    То есть почти в два раза быстрее.
    Предполагаю, что если бы количество рассчетов сильно увеличилось, прирост был бы намного заметнее.
    Так как в нашем случае относительно много времени ушло на порождение дочерних процессов */
