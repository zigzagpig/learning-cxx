﻿#include "../exercise.h"
//math
#include <cmath>
#include <cstdlib>

// READ: 函数模板 <https://zh.cppreference.com/w/cpp/language/function_template>
// TODO: 将这个函数模板化
template<class T>
T plus(T a, T b) {
    return a + b;
}

int main(int argc, char **argv) {
    ASSERT(plus(1, 2) == 3, "Plus two int");
    ASSERT(plus(1u, 2u) == 3u, "Plus two unsigned int");

    const double eps = 1e-6;
    // THINK: 浮点数何时可以判断 ==？何时必须判断差值？
    std::cout << std::fabs(plus(1.25f, 2.5f) - 3.75f) << std::endl;
    ASSERT(std::fabs(plus(1.25f, 2.5f) - 3.75f) < eps, "Plus two float");
    ASSERT(std::abs(plus(1.25, 2.5) - 3.75) < eps, "Plus two double");
    // TODO: 修改判断条件使测试通过
    ASSERT(std::abs(plus(0.1, 0.2) - 0.3) < eps, "How to make this pass?");

    return 0;
}
