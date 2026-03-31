#include <iostream>
#include "tree.h"

int main() {
    Tree t;
    std::cout << "Empty: " << t.empty() << std::endl;

    t.insert(8);
    t.insert(4);
    t.insert(13);
    t.insert(2);
    t.insert(6);
    t.insert(17);

    std::cout << "Size: " << t.size() << std::endl;
    std::cout << "Empty: " << t.empty() << std::endl;
    std::cout << "Leaves: " << t.countLeaves() << std::endl;

    Tree t2 = t;
    std::cout << "Copy size: " << t2.size() << std::endl;

    Tree t3 = std::move(t2);
    std::cout << "Move size: " << t3.size() << std::endl;
    std::cout << "After move empty: " << t2.empty() << std::endl;

    return 0;
}
