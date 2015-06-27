#include <cstdio>
#include <cstring>

#define MAX 10000

// sum[i]表示前i个元素之和。i>0时，sum[i]表示 A[0]....A[i-1]之和。
int sum[MAX+1] = {0};
int flag[MAX] = {0};

int main() {
    int n = 0;
    int A[MAX] = {0};

    while (scanf("%d", &n) != EOF) {
        memset(A, 0, sizeof(A));
        memset(sum, 0, sizeof(sum));
        memset(flag, -1, sizeof(flag));
        for (int i = 0; i < n; ++i) {
            scanf("%d", &A[i]);
        }
        // 注意把sum[0]先填入
        int m = sum[0] % n;
        flag[m] = 0;
        for (int i = 1; i <= n; ++i) {
            sum[i] = (sum[i-1] + A[i-1]) % n;
            int t = sum[i];
            if (flag[t] < 0) {
                flag[t] = i;
            } else {
                printf("%d\n", i - flag[t]);
                for (int j = flag[t]; j < i; ++j) {
                    printf("%d\n", A[j]);
                }
                break;
            }
        }
    }
    return 0;
}
