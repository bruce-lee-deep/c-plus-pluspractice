#include <cstdio>
#include <cstdint>

const size_t MAX_IN = 50000000;  // 足够容纳最大输入 (约 42 MB)
const size_t MAX_OUT = 50000000; // 足够容纳最大输出 (约 44 MB)
char inbuf[MAX_IN];
char outbuf[MAX_OUT];

int main() {
    // 一次性读入全部输入
    size_t len = std::fread(inbuf, 1, MAX_IN, stdin);
    inbuf[len] = '\0';
    char* p = inbuf;

    // 跳过前导空白符
    while (*p == ' ' || *p == '\n' || *p == '\r' || *p == '\t') ++p;

    // 读取 n
    uint64_t n = 0;
    while (*p >= '0' && *p <= '9') {
        n = n * 10 + (uint64_t)(*p - '0');
        ++p;
    }

    char* out = outbuf;
    uint64_t sum = 0;

    for (uint64_t i = 0; i < n; ++i) {
        // 跳过数字前的空白符
        while (*p == ' ' || *p == '\n' || *p == '\r' || *p == '\t') ++p;

        // 解析 A_i
        uint64_t a = 0;
        while (*p >= '0' && *p <= '9') {
            a = a * 10 + (uint64_t)(*p - '0');
            ++p;
        }

        sum += a; // 无符号 64 位自动模 2^64

        // 将 sum 写入输出缓冲区
        if (sum == 0) {
            *out++ = '0';
        }
        else {
            char tmp[20];
            int len = 0;
            uint64_t x = sum;
            while (x) {
                tmp[len++] = '0' + (x % 10);
                x /= 10;
            }
            while (len--) *out++ = tmp[len];
        }
        *out++ = (i == n - 1) ? '\n' : ' ';
    }

    std::fwrite(outbuf, 1, out - outbuf, stdout);
    return 0;
}