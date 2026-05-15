#include <iostream>
using namespace std;

int main() {
    register int i; // 🔹 هذا يعطي إشارة للكمبايلر إنه يحاول يخزّن المتغير في المعالج (CPU register) بدل الذاكرة (RAM)
    for (i = 0; i <= 1200; i++) {
        cout << i << endl;
    }
    return 0;
}