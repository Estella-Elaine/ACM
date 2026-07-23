#include<bits/stdc++.h>
using namespace std;

const int MAX_DIGITS = 200; // 足够存储99!的位数(约156位)

void multiply(int result[], int &length, int multiplier) {
    int carry = 0;
    for (int i = 0; i < length; i++) {
        int product = result[i] * multiplier + carry;
        result[i] = product % 10;
        carry = product / 10;
    }
    
    while (carry > 0) {
        result[length] = carry % 10;
        carry /= 10;
        length++;
    }
}

void factorial(int n) {
    int result[MAX_DIGITS] = {0};
    result[0] = 1;
    int length = 1;
    
    for (int i = 2; i <= n; i++) {
        multiply(result, length, i);
    }
    
    cout << "ans = ";
    for (int i = length - 1; i >= 0; i--) {
        cout << result[i];
    }
    cout << endl;
}

int main() {
	clock_t start,end;
	start = clock(); 
    int n;
    cin >> n; 
    factorial(n);
    end = clock();
    cout << (double)(end - start)/CLOCKS_PER_SEC << endl;
    return 0;
}
