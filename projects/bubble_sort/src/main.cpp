#include <iostream>
#include "bubble_sort.hpp"

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int size = 6;
    
    std::cout << "Исходный массив: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    bubbleSort(arr, size);
    
    std::cout << "Отсортированный массив: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}