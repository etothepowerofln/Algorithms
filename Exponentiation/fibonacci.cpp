/*
Author: Luiz Filipi de Sousa Moura

Paradigm: Dynamic programming

Complexity: The multiplication is constant, Ο(2^3) = Ο(1). Hence, the algorithm is limitedd by the divide and conquer Ο(log n).

Description:
F(n)   = 1 * F(n-1) + 1 * F(n-2)
F(n-1) = 1 * F(n-1) + 0 * F(n-2)

[ F(n) ] = [1 1] [F(n-1)] = [1 1]^2 [F(n-2)] = [1 1]^(n-1) [F(1)]
[F(n-1)]   [1 0] [F(n-2)]   [1 0]   [F(n-3)]   [1 0]       [F(0)]

[1 1]^(n-1) = [ F(n)  F(n-1)]
[1 0]         [F(n-1) F(n-2)]
*/
#include <iostream>
using namespace std;
typedef long long ll;
int n;
ll A[2][2], B[2][2], I[2][2], MEM[2][2];

void multiply(ll A[2][2], ll B[2][2]) {
    for(int i = 0; i <= 1; ++i) {
        for(int j = 0; j <= 1; ++j) {
            MEM[i][j] = 0;
            for(int y = 0; y <= 1; ++y) {
                MEM[i][j] += A[i][y] * B[y][j];
            }
        }
    }
    for(int i = 0; i <= 1; ++i) {
        for(int j = 0; j <= 1; ++j) {
            A[i][j] = MEM[i][j];
        }
    }
}

int main() {
    A[0][0]=1; A[0][1]=1; /**/ B[0][0]=1; B[0][1]=1; /**/ I[0][0]=1; I[0][1]=0;
    A[1][0]=1; A[1][1]=0; /**/ B[1][0]=1; B[1][1]=0; /**/ I[1][0]=0; I[1][1]=1;
    printf("Fib(0) = 0 and Fib(1) = 1. Enter n for Fib(n): ");
    scanf("%d", &n);
    if(n < 0) {
        printf("Enter a positive integer.\n");
        return 2;
    } else if(n == 0 || n == 1) {
        printf("Trivial result.\n");
        return 1;
    } else {
        --n;
        while(n) {
            if(n & 1) multiply(I, A);
            multiply(A, A);
            n >>= 1;
        }
        printf("%lld = %lld + %lld\n", I[0][0], I[0][1], I[1][1]);
        return 0;
    }
}
