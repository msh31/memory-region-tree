#pragma once
#include <memory>

class Node {
    public:
        Node(int val) : value(val), left(nullptr), right(nullptr) {}

        int value;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;
};
