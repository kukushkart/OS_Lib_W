#include "VectorLibrary.h"
#include <windows.h>

Vector::Vector(const Number& x_val, const Number& y_val) : x(x_val), y(y_val) {}
Vector::Vector(const Vector& other) : x(other.x), y(other.y) {}

Number Vector::getX() const { return x; }
Number Vector::getY() const { return y; }

Number Vector::getRadius() const {
    Number x_squared = x * x;
    Number y_squared = y * y;
    Number sum = x_squared + y_squared;
    return Number::sqrt(sum);
}

Number Vector::getTheta() const {
    return Number::arctg(x, y);
}

Vector Vector::add(const Vector& other) const {
    return Vector(x + other.x, y + other.y);
}

Vector Vector::subtract(const Vector& other) const {
    return Vector(x - other.x, y - other.y);
}

Vector* VECTOR_ZERO = nullptr;
Vector* VECTOR_ONE_ONE = nullptr;

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
        VECTOR_ZERO = new Vector(create_number(0.0), create_number(0.0));
        VECTOR_ONE_ONE = new Vector(create_number(1.0), create_number(1.0));
        break;
    case DLL_PROCESS_DETACH:
        delete VECTOR_ZERO;
        delete VECTOR_ONE_ONE;
        break;
    }
    return TRUE;
}

Vector* vector_create(double x, double y) {
    return new Vector(create_number(x), create_number(y));
}

void vector_delete(Vector* vector) {
    delete vector;
}

double vector_get_x(Vector* vector) {
    return vector->getX().getValue();
}

double vector_get_y(Vector* vector) {
    return vector->getY().getValue();
}

double vector_get_radius(Vector* vector) {
    return vector->getRadius().getValue();
}

double vector_get_theta(Vector* vector) {
    return vector->getTheta().getValue();
}

Vector* vector_add(Vector* vector1, Vector* vector2) {
    Vector result = vector1->add(*vector2);
    return new Vector(result.getX(), result.getY());
}

Vector* vector_subtract(Vector* vector1, Vector* vector2) {
    Vector result = vector1->subtract(*vector2);
    return new Vector(result.getX(), result.getY());
}