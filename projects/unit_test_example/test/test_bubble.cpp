#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "bubble_sort.hpp"

TEST(ArraysEqual, AnyElementsCount) {
    int actual[] = {1, 8, 2, 5, 3, 11};
    int actual_size = sizeof(actual) / sizeof(actual[0]);
    bubbleSort(actual, actual_size);
    int expected[] = {1, 2, 5, 3, 8, 11};
    int expected_size = sizeof(expected) / sizeof(expected[0]);
    
    ASSERT_EQ(expected_size, actual_size)
        << "Разные размеры массивов";
    
    for (int i = 0; i < actual_size; i++) {
        ASSERT_EQ(expected[i], actual[i])
        << "Отличие массивов в элементе с индексом " << i;
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}