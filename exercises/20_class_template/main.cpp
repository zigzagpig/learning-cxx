#include "../exercise.h"
#include <cstdio>
#include <cstring>// for std::memcpy
#include <ostream>



// READ: 类模板 <https://zh.cppreference.com/w/cpp/language/class_template>

template<class T>
struct Tensor4D {
    unsigned int shape[4];
    T *data;

    Tensor4D(unsigned int const shape_[4], T const *data_) {
        // 计算 Tensor 的大小
        unsigned int size = 1;
        for (int i = 0; i < 4; ++i) {
            shape[i] = shape_[i];// 直接将 shape_ 赋值给 shape
            size *= shape_[i];
            // std::printf("%d %d\n", shape[i], shape_[i]);
            std::cout << shape[i] << " " << shape_[i] << std::endl;
            // std::printf("%d\n", size);
            std::cout << size << std::endl;
        }
        data = new T[size];
        std::memcpy(data, data_, size * sizeof(T));
        for (unsigned int i = 0; i < shape[0] * shape[1] * shape[2] * shape[3]; ++i) {
            // data[i] += others.data[i];
            // std::printf("%d \n", data[i], data_[i]);
            std::cout << data[i] << " __LINE__ " << data_[i] << std::endl;
        }
        // for (unsigned int i = 0; i < shape[0] * shape[1] * shape[2] * shape[3]; ++i) {
        //     // data[i] += others.data[i];
        //     std::printf("%d \n", data_[i]);
        // }
        std::printf("-------------\n", size);
    }
    ~Tensor4D() {
        delete[] data;
    }

    // 为了保持简单，禁止复制和移动
    Tensor4D(Tensor4D const &) = delete;
    Tensor4D(Tensor4D &&) noexcept = delete;

    // 这个加法需要支持“单向广播”。
    // 具体来说，`others` 可以具有与 `this` 不同的形状，形状不同的维度长度必须为 1。
    // `others` 长度为 1 但 `this` 长度不为 1 的维度将发生广播计算。
    // 例如，`this` 形状为 `[1, 2, 3, 4]`，`others` 形状为 `[1, 2, 1, 4]`，
    // 则 `this` 与 `others` 相加时，3 个形状为 `[1, 2, 1, 4]` 的子张量各自与 `others` 对应项相加。
    Tensor4D &operator+=(Tensor4D const &others) {

        // #include <cstdlib>
        //         system("pause");
        //         std::printf("%d ", shape[0]);
        //         std::printf("%d ", shape[1]);
        //         std::printf("%d ", shape[2]);
        //         std::printf("%d \n", shape[3]);
        //         for (unsigned int i = 0; i < shape[0] * shape[1] * shape[2] * shape[3]; ++i) {
        //             // data[i] += others.data[i];
        //             // std::printf("%d \n", data[i]);
        //             std::cout << data[i] << " ";
        //         }
        //         std::cout << std::endl;
        //         // TODO: 实现单向广播的加法
        //         // 预先存储每个阶是否斋要广播
        //         bool broadcast[4];
        //         for (auto i = 0u; i < 4; ++i) {
        //             if ((broadcast[i] = shape[i] != others.shape[i]))// 如果形状不一致就需要广播
        //             {
        //                 // std::printf("%u,others.shape[i]=%u\n", i, others.shape[i]);

        //                 ASSERT(others.shape[i] == 1, "!");
        //             }
        //             std::cout << "broadcast " << i << "  " << shape[i] << " " << others.shape[i] << "bool" << broadcast[i] << std::endl;
        //         }
        //         // 单向广播，others 的对应长度必须为1
        //         std::cout << __LINE__ << std::endl;
        //         auto dst = data; // 要加到的元素地址
        //         auto src = others.data;// 要加上的元素地址
        //         T *marks[4]{src};      //4个阶的锚点
        //         for (auto i0 = 0u; i0 < shape[0]; ++i0) {
        //             // You，4分钟的*Uncammitted changes
        //             std::cout << __LINE__ << std::endl;
        //             if (broadcast[0]) src = marks[0];// 如果这个阶是广播的，回到锚点位置marks[1] = src;// 记录下一阶锚点
        //             for (auto i1 = 0u; i1 < shape[1]; ++i1) {
        //                 if (broadcast[1]) src = marks[1];
        //                 marks[2] = src;
        //                 std::cout << __LINE__ << std::endl;

        //                 for (auto i2 = 0u; i2 < shape[2]; ++i2) {
        //                     if (broadcast[2]) src = marks[2];
        //                     marks[3] = src;
        //                     std::cout << __LINE__ << std::endl;

        //                     for (auto i3 = 0u; i3 < shape[3]; ++i3) {
        //                         if (broadcast[3]) src = marks[3];
        //                         std::cout << __LINE__ << *dst << std::endl;
        //                         std::cout << __LINE__ << *src << std::endl;

        //                         *dst++ += *src++;
        //                         std::printf("run here ");
        //                     }
        //                 }
        //             }
        //         }


        // //TODO 实现单向广播算法 answer
        // bool broadcast[4];
        // for (auto i = 0u; i < 4; ++i)
        //     if ((broadcast[i] = shape[i] != others.shape[i]))// 如果形状不一致就需要广播
        //         ASSERT(others.shape[i] == 1, "!");           // 单向广播，others 的对应长度必须为 1

        // auto dst = data; // 要加到的元素地址
        // auto src = others.data;// 要加上的元素地址
        // T *marks[4]{src};      // 4 个阶的锚点
        // for (auto i0 = 0u; i0 < shape[0]; ++i0) {
        //     // You，4分钟的*Uncammitted changes
        //     std::cout << __LINE__ << std::endl;
        //     if (broadcast[0]) src = marks[0];// 如果这个阶是广播的，回到锚点位置
        //     marks[1] = src;                  // 记录下一阶锚点
        //     for (auto i1 = 0u; i1 < shape[1]; ++i1) {
        //         if (broadcast[1]) src = marks[1];
        //         marks[2] = src;
        //         std::cout << __LINE__ << std::endl;

        //         for (auto i2 = 0u; i2 < shape[2]; ++i2) {
        //             if (broadcast[2]) src = marks[2];
        //             marks[3] = src;
        //             std::cout << __LINE__ << std::endl;

        //             for (auto i3 = 0u; i3 < shape[3]; ++i3) {
        //                 if (broadcast[3]) src = marks[3];
        //                 std::cout << __LINE__ << *dst << std::endl;
        //                 std::cout << __LINE__ << *src << std::endl;

        //                 *dst++ += *src++;
        //                 std::printf("run here ");
        //             }
        //         }
        //     }
        // }
        // for (auto i0 = 0u; i0 < shape[0]; ++i0) {

        //     if (broadcast[0]) src = marks[0];// 如果这个阶是广播的，回到锚点位置
        //     marks[1] = src;                  // 记录下一阶锚点

        //     for (auto i1 = 0u; i1 < shape[1]; ++i1) {

        //         if (broadcast[1]) src = marks[1];
        //         marks[2] = src;

        //         for (auto i2 = 0u; i2 < shape[2]; ++i2) {

        //             if (broadcast[2]) src = marks[2];
        //             marks[3] = src;

        //             for (auto i3 = 0u; i3 < shape[3]; ++i3) {

        //                 if (broadcast[3]) src = marks[3];
        //                 *dst++ += *src++;
        //             }
        //         }
        //     }
        // }


        int base[] = {0, 0, 0, 0};

        // #include <cstdlib>
        //         system("pause");
        for (unsigned int i = 0; i < shape[0]; ++i) {
            if (others.shape[0] != 1) {
                base[0] = i;
            }
            std::printf("i=%d,base[0]=%d\n", i, base[0]);
            for (int j = 0; j < shape[1]; ++j) {
                if (others.shape[1] != 1) {
                    base[1] = j;
                }
                std::printf("j=%d,base[1]=%d\n", j, base[1]);
                for (int k = 0; k < shape[2]; ++k) {
                    if (others.shape[2] != 1) {
                        base[2] = k;
                    }
                    std::printf("k=%d,base[2]=%d\n", k, base[2]);
                    for (int l = 0; l < shape[3]; ++l) {
                        if (others.shape[3] != 1) {
                            base[3] = l;
                        }
                        // std::printf("l=%d,base[3]=%d\n", l, base[3]);

                        // std::printf("%d\n", i * shape[0] * shape[1] * shape[2] * shape[3] + j * shape[2] * shape[3] + k * shape[3] + l);
                        // std::printf("%d\n\n", base[0] * others.shape[0] * others.shape[1] * others.shape[2] * others.shape[3] + base[1] * others.shape[2] * others.shape[3] + base[2] * others.shape[3] + base[3]);

                        data[i * shape[1] * shape[2] * shape[3] + j * shape[2] * shape[3] + k * shape[3] + l] += others.data[base[0] * others.shape[1] * others.shape[2] * others.shape[3] + base[1] * others.shape[2] * others.shape[3] + base[2] * others.shape[3] + base[3]];
                        // std::printf("%d\n", data[i * shape[0] * shape[1] * shape[2] * shape[3] + j * shape[2] * shape[3] + k * shape[3] + l]);
                        // std::printf("\n");
                    }
                }
            }
        }
        // #include <cstdlib>
        // system("pause");
        std::printf("%d ", shape[0]);
        std::printf("%d ", shape[1]);
        std::printf("%d ", shape[2]);
        std::printf("%d ", shape[3]);
        for (unsigned int i = 0; i < shape[0] * shape[1] * shape[2] * shape[3]; ++i) {
            // data[i] += others.data[i];
            // std::printf("%d ", data[i]);
            std::cout << data[i] << " " << std::endl;
        }

        return *this;
    }
};

// ---- 不要修改以下代码 ----
int main(int argc, char **argv) {
    {
        unsigned int shape[]{1, 2, 3, 4};
        // clang-format off
        int data[]{
             1,  2,  3,  4,
             5,  6,  7,  8,
             9, 10, 11, 12,

            13, 14, 15, 16,
            17, 18, 19, 20,
            21, 22, 23, 24};
        // clang-format on
        auto t0 = Tensor4D(shape, data);
        auto t1 = Tensor4D(shape, data);
        t0 += t1;
        for (auto i = 0u; i < sizeof(data) / sizeof(*data); ++i) {
            ASSERT(t0.data[i] == data[i] * 2, "Tensor doubled by plus its self.");
        }
    }
    {
        unsigned int s0[]{1, 2, 3, 4};
        // clang-format off
        float d0[]{
            1, 1, 1, 1,
            2, 2, 2, 2,
            3, 3, 3, 3,

            4, 4, 4, 4,
            5, 5, 5, 5,
            6, 6, 6, 6};
        // clang-format on
        unsigned int s1[]{1, 2, 3, 1};
        // clang-format off
        float d1[]{
            6,
            5,
            4,

            3,
            2,
            1};
        // clang-format on

        auto t0 = Tensor4D(s0, d0);
        auto t1 = Tensor4D(s1, d1);
        t0 += t1;
        for (auto i = 0u; i < sizeof(d0) / sizeof(*d0); ++i) {
            ASSERT(t0.data[i] == 7.f, "Every element of t0 should be 7 after adding t1 to it.");
        }
    }
    {
        unsigned int s0[]{1, 2, 3, 4};
        // clang-format off
        double d0[]{
             1,  2,  3,  4,
             5,  6,  7,  8,
             9, 10, 11, 12,

            13, 14, 15, 16,
            17, 18, 19, 20,
            21, 22, 23, 24};
        // clang-format on
        unsigned int s1[]{1, 1, 1, 1};
        double d1[]{1};

        auto t0 = Tensor4D(s0, d0);
        auto t1 = Tensor4D(s1, d1);
        t0 += t1;
        for (auto i = 0u; i < sizeof(d0) / sizeof(*d0); ++i) {
            ASSERT(t0.data[i] == d0[i] + 1, "Every element of t0 should be incremented by 1 after adding t1 to it.");
        }
    }
    std::printf("All tests passed.\n");
}
