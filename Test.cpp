#include <iostream>
#include "VectorLibrary.h"


int main() {
    std::cout << "Testing Math System" << std::endl;

    // 1. Создание векторов через библиотеку
    Vector* vec1 = vector_create(5.0, 4.0);
    Vector* vec2 = vector_create(1.0, 2.0);

    std::cout << "Vector 1: (" << vector_get_x(vec1) << ", " << vector_get_y(vec1) << ")" << std::endl;
    std::cout << "Vector 2: (" << vector_get_x(vec2) << ", " << vector_get_y(vec2) << ")" << std::endl;

    // 2. Операции
    Vector* sum = vector_add(vec1, vec2);
    Vector* diff = vector_subtract(vec1, vec2);

    std::cout << "\nOperations:" << std::endl;
    std::cout << "Sum: (" << vector_get_x(sum) << ", " << vector_get_y(sum) << ")" << std::endl;
    std::cout << "Diff: (" << vector_get_x(diff) << ", " << vector_get_y(diff) << ")" << std::endl;

    // 3. Полярные координаты
    std::cout << "\nPolar Coordinates (Vec1):" << std::endl;
    std::cout << "Radius: " << vector_get_radius(vec1) << std::endl;
    std::cout << "Theta: " << vector_get_theta(vec1) << std::endl;

    // 4. Проверка констант из DLL
    if (VECTOR_ZERO) {
        std::cout << "\nConstant ZERO Vector: (" << vector_get_x(VECTOR_ZERO)
            << ", " << vector_get_y(VECTOR_ZERO) << ")" << std::endl;
    }
    else {
        std::cout << "\nError: VECTOR_ZERO is null!" << std::endl;
    }

    if (VECTOR_ONE_ONE) {
        std::cout << "Constant ONE_ONE Vector: (" << vector_get_x(VECTOR_ONE_ONE)
            << ", " << vector_get_y(VECTOR_ONE_ONE) << ")" << std::endl;
    }

    vector_delete(vec1);
    vector_delete(vec2);
    vector_delete(sum);
    vector_delete(diff);


    std::cin.get();
    return 0;
}