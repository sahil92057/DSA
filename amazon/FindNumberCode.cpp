#include <iostream>
#include <vector>
#include <string>
using namespace std;

string findNumber(vector<int> numbers) {
    while (numbers.size() > 2) {
        vector<int> temp;
        for (int i = 0; i < numbers.size() - 1; i++) {
            temp.push_back((numbers[i] + numbers[i + 1]) % 10);
        }
        numbers = temp;
    }
    return to_string(numbers[0]) + to_string(numbers[1]);
}

int main() {
    vector<int> numbers = {4, 5, 6, 7};
    cout << "Result: " << findNumber(numbers) << endl;
    return 0;
}
