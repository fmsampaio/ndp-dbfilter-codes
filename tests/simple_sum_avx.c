#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <immintrin.h>

void imprime(int *vector, int size) {
    for (int i = 0; i < size; i++) {
        printf("%u ", vector[i]);
    }
}

void fillVector(int *vector, int size, int value) {
    for (int i = 0; i < size; i++) {
        vector[i] = value;
    }
}


int main(int argc, char const *argv[]) {
    int* data_a = (int*) aligned_alloc(32, 2048 * sizeof(int));
    int* data_b = (int*) aligned_alloc(32, 2048 * sizeof(int));
    int* data_sum = (int*) aligned_alloc(32, 2048 * sizeof(int));

    //int numSteps = 2048 / 8;
    fillVector(data_a, 2048, 10);
    fillVector(data_b, 2048, 20);

    for (int i = 0; i < 2048; i+=8) {
        int* pointer_a = data_a + i;
        int* pointer_b = data_b + i;
        int* pointer_sum = data_sum + i;

        __m256i vec_a, vec_b, vec_sum;

        vec_a = _mm256_load_si256((__m256i *)pointer_a);
        vec_b = _mm256_load_si256((__m256i *)pointer_b);

        vec_sum = _mm256_add_epi32(vec_a, vec_b);
        
        _mm256_store_si256((__m256i *) pointer_sum, vec_sum);
    }

    imprime(data_sum, 2048);
}