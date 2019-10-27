#include <gtest/gtest.h>

extern "C" {
    #include "../header.h"
}

class TestStress : public ::testing::Test {
    protected:
        int n;
        struct Employee *empl;
        virtual void SetUp() override {
            /// do data
            n = 10000;
            empl = (struct Employee*)malloc(sizeof(struct Employee)*n);
            empl = random_emp(empl); // randomizing 10000 employees
        }
        void TearDown() override {
                ;
            }
};

TEST_F(TestStress, working_with_statistics_in_one_process) {
    /// do test
    clock_t begin = clock();
    for (size_t i = 0; i < 5; ++i){
        working_with_statistics_in_one_process(empl, 8, n);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC / 5; // average time
    ASSERT_GE(time_spent, 0.002);

}

TEST_F(TestStress, working_with_statistics_in_many_proc) {
    /// do test
    clock_t begin = clock();
    working_with_statistics_in_many_proc(empl, 8, n);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC; // average time
    printf("average %f\n", time_spent);
    ASSERT_GE(time_spent, 0.002);
    free(empl);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

    /// нагрузочное тестирование
/*   В обоих режимах по пять раз запустил программу и посчитал среднее арифметическое.
    Однопроцессная программа отрабатывала в среднем за 0,004228с, а 6 процессов - за 0,002318с
    То есть почти в два раза быстрее.
    Предполагаю, что если бы количество рассчетов сильно увеличилось, прирост был бы намного заметнее.
    Так как в нашем случае относительно много времени ушло на порождение дочерних процессов.
*/