#include <vector>

#include "tree.hpp"

#ifdef _WIN32
#include <windows.h>
#endif

int main() {
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif

    Tree tree;

    std::vector<int> cool_numbers {
        25, 10, 40, 5, 20, 30, 50, 2, 35, 69, 420
    };

    for (auto number : cool_numbers) {
        tree.insert(number);
    }

    tree.print();
    return 0;
}
