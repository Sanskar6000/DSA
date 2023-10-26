#include<bits/stdc++.h>
using namespace std;

void incr();

int func(int z) {
    if(z == 6) return 5;
    else return 6;
}

int main() {
    incr();
    incr();
    incr();

}

void incr() {
    static int i;
    cout << ++i;
}