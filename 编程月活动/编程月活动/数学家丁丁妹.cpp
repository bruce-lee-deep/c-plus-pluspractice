#include <cstring>
#include <iostream>
using namespace std;

const int K = 3;
const long long MOD = 1000000007LL;

struct Matrix {
    long long mat[K][K];
    Matrix(bool identity = false) {
        memset(mat, 0, sizeof(mat));
        if (identity) {
            for (int i = 0; i < K; ++i) {
                mat[i][i] = 1;
            }
        }
    }
};

Matrix multiply(const Matrix& A, const Matrix& B) {
    Matrix C;
    for (int i = 0; i < K; ++i) {
        for (int k = 0; k < K; ++k) {
            for (int j = 0; j < K; ++j) {
                C.mat[i][j] = (C.mat[i][j] + (__int128)A.mat[i][k] * B.mat[k][j]) % MOD;
            }
        }
    }
    return C;
}

Matrix power(Matrix base, long long exp) {
    Matrix result(true);
    while (exp > 0) {
        if (exp & 1LL) {
            result = multiply(result, base);
        }
        base = multiply(base, base);
        exp >>= 1;
    }
    return result;
}

int mod3(long long x) {
    x %= 3;
    if (x < 0) {
        x += 3;
    }
    return (int)x;
}

int main() {
    long long N = 0, L = 0, R = 0;
    cin >> N >> L >> R;

    long long cnt[K] = {0, 0, 0};
    long long len = R - L + 1;
    long long base = len / 3;
    for (int i = 0; i < K; ++i) {
        cnt[i] = base;
    }

    int start = mod3(L);
    for (int i = 0; i < len % 3; ++i) {
        cnt[(start + i) % 3]++;
    }

    Matrix trans;
    long long c0 = cnt[0] % MOD;
    long long c1 = cnt[1] % MOD;
    long long c2 = cnt[2] % MOD;
    trans.mat[0][0] = c0;
    trans.mat[0][1] = c2;
    trans.mat[0][2] = c1;
    trans.mat[1][0] = c1;
    trans.mat[1][1] = c0;
    trans.mat[1][2] = c2;
    trans.mat[2][0] = c2;
    trans.mat[2][1] = c1;
    trans.mat[2][2] = c0;

    if (N == 0) {
        cout << 1 << '\n';
        return 0;
    }

    Matrix tn = power(trans, N);
    long long answer = tn.mat[0][0] % MOD;
    cout << answer << '\n';
    return 0;
}
