#include <iostream>
#include <vector>
#include <algorithm>

bool compareSecondElement(const std::vector<int>& a, const std::vector<int>& b) {
    return a[1] > b[1];
}

int main() {
    std::vector<std::vector<int>> jobs = {
        {1, 5},
        {2, 3},
        {3, 8},
        {4, 1},
        {5, 6}
    };

    std::sort(jobs.begin(), jobs.end(), compareSecondElement);

    for (const auto& job : jobs) {
        std::cout << job[0] << " " << job[1] << std::endl;
    }

    return 0;
}
