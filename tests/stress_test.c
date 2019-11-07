#include "../header.h"

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
