#include <iostream>
#include "tree.h"

int main() {
    Tree t;
    t.insert(8);
    t.insert(4);
    t.insert(13);
    t.insert(2);
    t.insert(6);
    t.insert(17);

    std::cout << "Leaves: " << t.countLeaves() << std::endl;

    Tree t2 = t;
    std::cout << "Equal: " << (t == t2) << std::endl;

    Tree t3 = std::move(t2);
    std::cout << "Leaves after move: " << t3.countLeaves() << std::endl;

    return 0;
}
