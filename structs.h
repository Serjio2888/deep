#ifndef STRUCTS_H_
#define STRUCTS_H_

struct Employee {
    int salary;
    int position_id;
    int work_stage;
    int age;
    char *name[16];
    char *surname[15];
    int sex;
};

struct statistic {
    int position_id;
    int work_stage;
    int sum_salary;
    int size;  // how many people are with the same position and work stage
};

#endif  // STRUCTS_H_
