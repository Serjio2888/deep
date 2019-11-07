#include "header.h"


struct statistic* calc_stat(struct statistic *stat, struct Employee *emp, int pos_id, int n, int max_years) {
    for (size_t i = 0; i <= max_years; ++i) {
        stat[i].size = 0;
    }
    for (size_t i = 0; i < n; ++i) {
        if (emp[i].position_id == pos_id) {
            stat[emp[i].work_stage].sum_salary += emp[i].salary;
            stat[emp[i].work_stage].size += 1;
        }
    }
    return stat;
}

void working_with_statistics_in_many_proc(struct Employee *emp, int max_years, int n) {;
    int pos = 0;
    int pid, status;
    while (pos < POSITIONS) {  // итератор идёт по всем позициям
        pid = fork();
        if (pid == 0) {
            struct statistic *pos_stat = (struct statistic *) malloc(
                    sizeof(struct statistic) * (max_years+1));
            pos_stat = calc_stat(pos_stat, emp, pos, n, max_years);  // считает сатистику по годам
            print_employee_type(pos);
            for (int i = 0; i <= max_years; ++i) {  // выводит статистику
                printf("years: %d   middle_salary: %d\n", i, pos_stat[i].sum_salary / pos_stat[i].size);
            }
            free(pos_stat);
            exit(0);
        }
        ++pos;
    }
    waitpid(pid, &status, 0);
}

void working_with_statistics_in_one_process(struct Employee *emp, int max_years, int n) {
    for (size_t pos = 0; pos < POSITIONS; ++pos) {
        struct statistic *pos_stat = (struct statistic *) malloc(
                sizeof(struct statistic) * max_years);
        pos_stat = calc_stat(pos_stat, emp, pos, n, max_years);
        print_employee_type(pos);
        for (int i = 0; i <= max_years; ++i) {
            printf("years: %d   middle_salary: %d\n", i, pos_stat[i].sum_salary / pos_stat[i].size);
        }
        free(pos_stat);
    }
}

void print_employee_type(int pos) {
    switch (pos) {
        case 0:
            puts("novice");
            break;
        case 1:
            puts("junior");
            break;
        case 2:
            puts("middle");
            break;
        case 3:
            puts("senior");
            break;
        case 4:
            puts("teamlead");
            break;
        case 5:
            puts("boss");
            break;
    }
}
