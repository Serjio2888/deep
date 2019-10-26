#ifndef HEADER_H_
#define HEADER_H_

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
#include <time.h>

#include "structs.h"

#define POSITIONS 6

struct Employee* random_emp(struct Employee *emp);
struct statistic* calc_stat(struct statistic *stat, struct Employee *emp, int pos_id, int n, int max_years);
void working_with_statistics_in_many_proc(struct Employee *emp, int max_years, int n);
void working_with_statistics(struct Employee *emp, int max_years, int n);
struct Employee* write_employees(int n, int max_years, struct Employee *emp);
int run_app();

#endif  // HEADER_H_
