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
    int* data_a = (int*) aligned_alloc(32, 8 * sizeof(int));
    int* data_b = (int*) aligned_alloc(32, 8 * sizeof(int));
    int* data_sum = (int*) aligned_alloc(32, 8 * sizeof(int));

    fillVector(data_a, 8, 10);
    fillVector(data_b, 8, 20);

    __m256i vec_a, vec_b, vec_sum;

    printf("AAAA\n");

    vec_a = _mm256_load_si256((__m256i *)data_a);
    vec_b = _mm256_load_si256((__m256i *)data_b);

    vec_sum = _mm256_add_epi32(vec_a, vec_b);
    
    _mm256_store_si256((__m256i *) data_sum, vec_sum);

    imprime(data_sum, 8);
}