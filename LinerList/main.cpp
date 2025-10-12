#include "headerfile.h"
using namespace LinerList;

int main() {
    // 测试构造函数和输出
    List L1;  
    for (int i = 1; i <= 5; i++) L1.add(i * 10);
    std::cout << "L1: " << L1 << std::endl;

    // 测试带数组的构造函数
    int arr[] = {2, 4, 6, 8, 10};
    List L2(5, arr);
    std::cout << "L2: " << L2 << std::endl;

    // 测试 search
    std::cout << "Search 6 in L2: " << L2.search(6) << std::endl;
    std::cout << "Search 7 in L2: " << L2.search(7) << std::endl;

    // 测试 modify
    L2.modify(2, 100);
    std::cout << "L2 after modify index 2 -> 100: " << L2 << std::endl;

    // 测试 insert
    L2.insert(200, 1);
    std::cout << "L2 after insert 200 at index 1: " << L2 << std::endl;

    // 测试 del
    L2.del(3);
    std::cout << "L2 after delete index 3: " << L2 << std::endl;

    // 测试 operator+
    List L3 = L1 + L2;
    std::cout << "L1 + L2 = " << L3 << std::endl;

    // 测试 is_full 和 is_empty
    std::cout << "L1 is empty? " << (L1.is_empty() ? "yes" : "no") << std::endl;
    std::cout << "L1 is full? " << (L1.is_full() ? "yes" : "no") << std::endl;

    return 0;
}
