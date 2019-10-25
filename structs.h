#ifndef IZ2_STRUCTS_H
#define IZ2_STRUCTS_H

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

#endif //IZ2_STRUCTS_H
