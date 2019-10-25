/*
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <malloc.h>

#define POSITIONS 6


typedef struct Employee {
    int salary;
    int position_id;
    int work_stage;
    int age;
    char *name[16];
    char *surname[15];
    int sex;
};

typedef struct statistic {
    int position_id;
    int work_stage;
    int sum_salary;
    int size; //how many people are with the same position and work stage
};

struct Employee* random_emp(struct Employee *emp){
//    printf("memory %d\n", sizeof(emp));
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
                strcpy(emp[i].name, "John");
            }
            for (int i = part_of_array - 1000; i < part_of_array; ++i) {
                strcpy(emp[i].surname, "Constantine");
            }
            //printf("fork number %d\n", pid);
        }
        printf("status:%d\n", status);
        if (pid == 0) {
            sleep(0.2);
            exit(1);
        }
        waitpid(pid, &status, 0);
    }
    return emp;
}

struct statistic* calc_stat(struct statistic *stat, struct Employee *emp, int pos_id){
    for (size_t i = 0; i < 9; ++i) {
        stat[i].size = 0;
    }
    for (size_t i = 0; i < 10000; ++i) {
        if (emp[i].position_id == pos_id) {
            stat[emp[i].work_stage].sum_salary += emp[i].salary;
            stat[emp[i].work_stage].size += 1;
        };
    }
    return stat;
}

int main() {
    int n = 10000;
    struct Employee *emp = (struct Employee*)malloc(sizeof(struct Employee)*n);
    emp = random_emp(emp);

    char positions[POSITIONS][9];
    strcpy(positions[0], "novice");
    strcpy(positions[1], "junior");
    strcpy(positions[2], "middle");
    strcpy(positions[3], "senior");
    strcpy(positions[4], "teamlead");
    strcpy(positions[5], "boss");

    printf("size: %d \n", sizeof(emp[0]));

    for (size_t pos = 0; pos < POSITIONS; ++pos) {
        struct statistic *pos_stat = (struct statistic *) malloc(
                sizeof(struct statistic) * 9);// 9 лет существует компания
        pos_stat = calc_stat(pos_stat, emp, pos);
        puts(positions[pos]);// position_name
        for (int i = 0; i < 9; ++i) {
            printf("years: %d   middle_salary: %d\n", i, pos_stat[i].sum_salary / pos_stat[i].size);
        }
        free(pos_stat);
    }
    free(emp);
    return 0;
}


//for (size_t i = 0; i < 10; ++i){
//    char *positions = (char*)malloc(sizeof(char*)*POSITIONS);
//}
//*positions
//char **positions = (char**)malloc(sizeof(char*)*POSITIONS);
//printf("%d\n", sizeof(**positions));
//for (size_t i = 0; i < positions; ++i) {
//    for (size_t j = 0; j < 10; ++j){
//        positions[i] = "k";
//    }
//}*/

#include "header.h"



/*int main() {
    int n = 10000;
    struct Employee *emp = (struct Employee*)malloc(sizeof(struct Employee)*n);
    emp = random_emp(emp);

    clock_t begin = clock();
    bool many_processes = true;
    if (many_processes) {
        working_with_statistics_in_many_proc(emp);
    } else {
        working_with_statistics_in_one_process(emp);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("%f", time_spent);
*//*    В обоих режимах по пять раз запустил программу и посчитал среднее арифметическое.
    Однопроцессная программа отрабатывала в среднем за 0,004228с, а 6 процессов - за 0,002418с
    То есть почти в два раза быстрее.
    Предполагаю, что если бы количество рассчетов сильно увеличилось, прирост был бы намного заметнее.
    Так как в нашем случае относительно много времени ушло на порождение дочерних процессов*//*
    return 0;
}*/

/*

//
// Created by sergey on 23.10.2019.
//
#include "header.h"

struct Employee* random_emp(struct Employee *emp){
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
                strcpy(emp[i].name, "John");
            }
            for (int i = part_of_array - 1000; i < part_of_array; ++i) {
                strcpy(emp[i].surname, "Constantine");
            }
        }
//        printf("status:%d\n", status);
        if (pid == 0) {
            sleep(0.1);
            exit(1);
        }
        waitpid(pid, &status, 0);
    }
    return emp;
}

struct statistic* calc_stat(struct statistic *stat, struct Employee *emp, int pos_id){
    for (size_t i = 0; i < 9; ++i) {
        stat[i].size = 0;
    }
    for (size_t i = 0; i < 10000; ++i) {
        if (emp[i].position_id == pos_id) {
            stat[emp[i].work_stage].sum_salary += emp[i].salary;
            stat[emp[i].work_stage].size += 1;
        };
    }
    return stat;
}

void working_with_statistics_in_one_process(struct Employee *emp){
    char **positions[POSITIONS][9];
    strcpy(positions[0], "novice");
    strcpy(positions[1], "junior");
    strcpy(positions[2], "middle");
    strcpy(positions[3], "senior");
    strcpy(positions[4], "teamlead");
    strcpy(positions[5], "boss");

    for (size_t pos = 0; pos < POSITIONS; ++pos) {
        struct statistic *pos_stat = (struct statistic *) malloc(
                sizeof(struct statistic) * 9);// 9 лет существует компания
        pos_stat = calc_stat(pos_stat, emp, pos);
        puts(positions[pos]);// position_name
        for (int i = 0; i < 9; ++i) {
            printf("years: %d   middle_salary: %d\n", i, pos_stat[i].sum_salary / pos_stat[i].size);
        }
        free(pos_stat);
    }
    free(emp);
}*/
