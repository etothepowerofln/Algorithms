/*
Author: Luiz Filipi de Sousa Moura, March 19 2022

Paradigm: Dynamic programming

Complexity: Ο(log e).

Description: n ^ e, where n is an integer (..., -2, 0, +2, ...) and e is a natural (0, 1, 2, ...).
*/
#include <iostream>
using namespace std;
long long n, e, r=1;

int main() {
    scanf("%lld%lld", &n, &e);
    while(e) {
        if(e & 1) r *= n;
        n *= n;
        e >>= 1;
    }
    printf("%lld\n", r);
    return 0;
}
