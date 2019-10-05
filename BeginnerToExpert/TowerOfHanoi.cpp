#include<iostream>

using namespace std;

void Hanoi(int n, stack<int> src, stack<int> dst, stack<int> tmp) {
    if(n > 0) {
        Hanoi(n-1, src, tmp, dst);
        dst.push(src.top());
        src.pop();
        Hanoi(n-1, tmp, dst, src);
    }
}
 int main(int argc, char const *argv[])
{
    /* code */
    int n;
    cin >> n;
    return 0;
}
