#include <stdio.h>
#include <math.h>
#include "structs.h"

void inputer(){
    printf("scanning triangle info...\nplease, input sides\n");
    scanf("%f", &tri.a_side);
    scanf("%f", &tri.b_side);
    scanf("%f", &tri.c_side);
}
int calculate(){
    float p = (tri.a_side + tri.b_side + tri.c_side)/2;//полупериметр для формулы Герона
    float S = sqrt(p*(p-tri.a_side)*(p-tri.b_side)*(p-tri.c_side));//формула Герона////////////////

    circ.radius = (tri.a_side*tri.b_side*tri.c_side)/(4*S);//радиус описанной окружности
    kv.side = circ.radius*2;//искомая сторона квадрата

    return 0;
}

