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

void working_with_statistics_in_many_proc(struct Employee *emp, int max_years, int n) {
    char **positions[POSITIONS][9];
    snprintf(positions[0], sizeof(positions[0]),  "%s", "novice");
    snprintf(positions[1], sizeof(positions[1]),  "%s", "junior");
    snprintf(positions[2], sizeof(positions[2]),  "%s", "middle");
    snprintf(positions[3], sizeof(positions[3]),  "%s", "senior");
    snprintf(positions[4], sizeof(positions[4]),  "%s", "teamlead");
    snprintf(positions[5], sizeof(positions[5]),  "%s", "boss");

    int pos = 0;
    while (pos < POSITIONS) {  // итератор идёт по всем позициям
        if (fork() == 0) {
            printf("forked\n");
            struct statistic *pos_stat = (struct statistic *) malloc(
                    sizeof(struct statistic) * (max_years+1));
            pos_stat = calc_stat(pos_stat, emp, pos, n, max_years);  // считает сатистику по годам
            puts(positions[pos]);  // position_name
            for (int i = 0; i <= max_years; ++i) {  // выводит статистику
                printf("years: %d   middle_salary: %d\n", i, pos_stat[i].sum_salary / pos_stat[i].size);
            }
            free(pos_stat);
            exit(0);
        }
        ++pos;
    }
    // free(emp);
}

void working_with_statistics_in_one_process(struct Employee *emp, int max_years, int n) {
    char **positions[POSITIONS][9];
    snprintf(positions[0], sizeof(positions[0]),  "%s", "novice");
    snprintf(positions[1], sizeof(positions[1]),  "%s", "junior");
    snprintf(positions[2], sizeof(positions[2]),  "%s", "middle");
    snprintf(positions[3], sizeof(positions[3]),  "%s", "senior");
    snprintf(positions[4], sizeof(positions[4]),  "%s", "teamlead");
    snprintf(positions[5], sizeof(positions[5]),  "%s", "boss");

    for (size_t pos = 0; pos < POSITIONS; ++pos) {
        struct statistic *pos_stat = (struct statistic *) malloc(
                sizeof(struct statistic) * max_years);
        pos_stat = calc_stat(pos_stat, emp, pos, n, max_years);
        puts(positions[pos]);  // position_name
        for (int i = 0; i <= max_years; ++i) {
            printf("years: %d   middle_salary: %d\n", i, pos_stat[i].sum_salary / pos_stat[i].size);
        }
        free(pos_stat);
    }
}
