/*
Author: Luiz Filipi de Sousa Moura, March 19 2022

Paradigm: Dynamic programming

Complexity: Ο(log n).

Description: z^n, where z is an integer (..., -2, 0, +2, ...) and n is a natural (0, 1, 2, ...).
*/
#include <iostream>
using namespace std;
long long z, n, r=1;

int main() {
    scanf("%lld%lld", &z, &n);
    while(n) {
        if(n & 1) r *= z;
        z *= z;
        n >>= 1;
    }
    printf("%lld\n", r);
    return 0;
}
