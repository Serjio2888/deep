//#define NDEBUG
#include "proj.h"

// Условие ИЗ№1
// Создать структуры для хранения информации об окружности, треугольнике и
// квадрате. Составить с использованием этих структур программу нахождения
// квадрата, в который вписана окружность, описанная вокруг заданного
// треугольника.

int main(void) {
  test_logic();

  inputer();

  testing_triangle();
  printf("all input parametrs are correct\n");

  calculate();
  printf("result is %.8f\n", kv.side);
  return 0;
}
