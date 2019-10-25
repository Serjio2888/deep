#include "header.h"


struct statistic* calc_stat(struct statistic *stat, struct Employee *emp, int pos_id, int n, int max_years) {
    for (size_t i = 0; i <= max_years; ++i) {
        stat[i].size = 0;
    }
    for (size_t i = 0; i < n; ++i) {
        if (emp[i].position_id == pos_id) {
            stat[emp[i].work_stage].sum_salary += emp[i].salary;
            stat[emp[i].work_stage].size += 1;
        };
    }
    return stat;
}

void working_with_statistics_in_many_proc(struct Employee *emp, int max_years, int n) {
    char **positions[POSITIONS][9];
    strcpy(positions[0], "novice");
    strcpy(positions[1], "junior");
    strcpy(positions[2], "middle");
    strcpy(positions[3], "senior");
    strcpy(positions[4], "teamlead");
    strcpy(positions[5], "boss");

    int pos = 0;
    int dog = 0;
    while (pos < POSITIONS) {// итератор идёт по всем позициям
        if (fork() == 0) {
            struct statistic *pos_stat = (struct statistic *) malloc(
                    sizeof(struct statistic) * (max_years+1));
            pos_stat = calc_stat(pos_stat, emp, pos, n, max_years);// считает сатистику по годам для этой позиции
            puts(positions[pos]);// position_name
            for (int i = 0; i <= max_years; ++i) {// выводит статистику
                printf("years: %d   middle_salary: %d\n", i, pos_stat[i].sum_salary / pos_stat[i].size);
            }
            free(pos_stat);
            exit(0);
            dog+= 15;
        }
        ++pos;
    }
}

void working_with_statistics_in_one_process(struct Employee *emp, int max_years, int n) {
    char **positions[POSITIONS][9];
    strcpy(positions[0], "novice");
    strcpy(positions[1], "junior");
    strcpy(positions[2], "middle");
    strcpy(positions[3], "senior");
    strcpy(positions[4], "teamlead");
    strcpy(positions[5], "boss");

    for (size_t pos = 0; pos < POSITIONS; ++pos) {
        struct statistic *pos_stat = (struct statistic *) malloc(
                sizeof(struct statistic) * max_years);// 9 лет существует компания
        pos_stat = calc_stat(pos_stat, emp, pos, n, max_years);
        puts(positions[pos]);// position_name
        for (int i = 0; i <= max_years; ++i) {
            printf("years: %d   middle_salary: %d\n", i, pos_stat[i].sum_salary / pos_stat[i].size);
        }
        free(pos_stat);
    }
}

