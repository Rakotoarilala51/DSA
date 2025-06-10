#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
    string input = "junkmul(3,4)stuffmul(12,8)badmul(999,9999)";  // exemple
    regex pattern(R"(mul\((\d{1,3}),(\d{1,3})\))");  // regex avec 2 groupes

    auto words_begin = sregex_iterator(input.begin(), input.end(), pattern);
    auto words_end = sregex_iterator();

    int total = 0;
    for (auto it = words_begin; it != words_end; ++it) {
        smatch match = *it;
        int x = stoi(match[1]);
        int y = stoi(match[2]);
        total += x * y;
    }

    cout << "Total: " << total << endl;
    return 0;
}