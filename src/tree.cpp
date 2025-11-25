#include <iostream>
#include "tree.hpp"

void Tree::insert(int value) {
    if(root == nullptr) {
        root = std::make_unique<Node>(value);
    } else {
        auto raw_ptr = root.get();

        //TODO: account for higher than root
        //TODO: refactor like search
        while(true) {
            if(value < raw_ptr->value) {
                if(raw_ptr->left == nullptr) {
                    raw_ptr->left = std::make_unique<Node>(value);
                    return;
                } else {
                    raw_ptr = raw_ptr->left.get();
                }
            } else {
                if(raw_ptr->right == nullptr) {
                    raw_ptr->right = std::make_unique<Node>(value);
                    return;
                } else {
                    raw_ptr = raw_ptr->right.get();
                }
            }
        }
    }
}

void Tree::print() {
    printNode(root.get(), "", false);
    std::cout << "\n";
}

void Tree::printNode(Node* node, const std::string& prefix, bool isLeft) {
    if (node == nullptr) {
        return;
    }

    //thx stackoverflow user Adrian Schneider
    std::cout << prefix;
    std::cout << (isLeft ? "├──" : "└──" );

    std::cout << node->value << std::endl;

    printNode(node->left.get(), prefix + (isLeft ? "│   " : "    "), true);
    printNode(node->right.get(), prefix + (isLeft ? "│   " : "    "), false);
}

bool Tree::search_for(int value) {
    auto raw_ptr = root.get();

    while (raw_ptr != nullptr) {
        if (raw_ptr->value == value) {
            return true;
        }

        if (value < raw_ptr->value) {
            raw_ptr = raw_ptr->left.get();
        } else {
            raw_ptr = raw_ptr->right.get();
        }
    }

    return false;
}
