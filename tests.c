//
// Created by sergey on 10.10.2019.
//
#include <math.h>
#include "structs.h"
#include <assert.h>
#include "calc.h"

int testing_triangle(){
    assert(tri.a_side > 0);
    assert(tri.b_side > 0);
    assert(tri.c_side > 0);
    assert((tri.a_side < (tri.b_side + tri.c_side)));
    assert((tri.b_side < (tri.a_side + tri.c_side)));
    assert((tri.c_side < (tri.b_side + tri.a_side)));//проверка треугольника по сторонам
    return 0;
}

int test_logic() {
    tri.a_side = 3;
    tri.b_side = 4;
    tri.c_side = 5;
    calculate();
    assert(kv.side == 5.0);
    tri.a_side = 7;
    tri.b_side = 8;
    tri.c_side = 9;
    calculate();
    assert(kv.side > 9.3 && kv.side < 9.4);
}