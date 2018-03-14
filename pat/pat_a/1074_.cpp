#include <iostream>
using namespace std;
int main() {
    int first, k, n;
    cin >> first >> n >> k;
    // 把地址为temp的数的数值存入data[temp]中，把temp的下一个结点的地址存入next[temp]中。
    int temp;
    int data[100005];
    int next[100005];
    for (int i = 0; i < n; i++) {
        cin >> temp;
        cin >> data[temp];
        cin >> next[temp];
    }

    int list[100005];
    int sum = 0;//不一定所有的输入的结点都是有用的，加个计数器
    while (first != -1) {
        list[sum++] = first;
        first = next[first];
    }
    int result[100005];
    for (int i = 0; i < sum; i++) {
        result[i] = list[i];
    }

    for (int i = 0; i < (sum - sum % k); i++) {
        result[i] = list[i / k * k + k - 1 - i % k];
    }


    for (int i = 0; i < sum - 1; i++)
        printf("%05d %d %05d\n", result[i], data[result[i]], result[i + 1]);
    printf("%05d %d -1", result[sum - 1], data[result[sum - 1]]);
    return 0;
}
