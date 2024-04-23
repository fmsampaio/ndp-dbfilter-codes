#include "../../intrinsics/vima/vima.hpp"

void imprime(__v32u *vector) {
    for (size_t i = 0; i < 64; i++) {
        printf("%u ", vector[i]);
    }
}


__v32s main(__v32s argc, char const *argv[]) {
    __v32u *vector_a = (__v32u *) calloc (64, sizeof(__v32u));
    __v32u *vector_b = (__v32u *) calloc (64, sizeof(__v32u));
    __v32u *vector_sum = (__v32u *) calloc (64, sizeof(__v32u));

    _vim64_imovu(10, vector_a);
    _vim64_imovu(5, vector_b);

    __v32u *coeff2 = (__v32u *) calloc (64, sizeof(__v32u));
    __v32u *coeff3 = (__v32u *) calloc (64, sizeof(__v32u));
    __v32u *coeff4 = (__v32u *) calloc (64, sizeof(__v32u));

    _vim64_imovu(2, coeff2);
    _vim64_imovu(3, coeff3);
    _vim64_imovu(4, coeff4);

    /*
    // Frame region alloc
    __v32u *frame = (__v32u *) calloc (2048 * 8, sizeof(__v32u));

    // Frame line pointers calculation
    __v32u *p3 = frame;
    __v32u *p2 = frame + (1 * 2048);
    __v32u *p1 = frame + (2 * 2048);
    __v32u *p0 = frame + (3 * 2048);
    */

    _vim64_iaddu(vector_a, vector_b, vector_sum);
    _vim64_imulu(vector_sum, coeff2, vector_sum);

    imprime(vector_sum);
}
