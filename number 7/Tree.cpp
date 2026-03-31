#include "tree.h"
#include <algorithm>

Tree::Tree() : root(nullptr), nodeCount(0) {}

Tree::Tree(const Tree& other) : root(copy(other.root)), nodeCount(other.nodeCount) {}

Tree::Tree(Tree&& other) : root(other.root), nodeCount(other.nodeCount) {
    other.root = nullptr;
    other.nodeCount = 0;
}

Tree::~Tree() {
    destroy(root);
}

Tree& Tree::operator=(const Tree& other) {
    if (this != &other) {
        destroy(root);
        root = copy(other.root);
        nodeCount = other.nodeCount;
    }
    return *this;
}

Tree& Tree::operator=(Tree&& other) {
    if (this != &other) {
        destroy(root);
        root = other.root;
        nodeCount = other.nodeCount;
        other.root = nullptr;
        other.nodeCount = 0;
    }
    return *this;
}

bool Tree::operator==(const Tree& other) {
    return equal(root, other.root);
}

Node* Tree::insert(Node* node, int val) {
    if (!node) return new Node(val);
    if (val < node->data)
        node->left = insert(node->left, val);
    else if (val > node->data)
        node->right = insert(node->right, val);
    return node;
}

void Tree::insert(int val) {
    root = insert(root, val);
    nodeCount++;
}

int Tree::size() const {
    return nodeCount;
}

bool Tree::empty() const {
    return nodeCount == 0;
}

void Tree::destroy(Node* node) {
    if (!node) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}

Node* Tree::copy(Node* node) {
    if (!node) return nullptr;
    Node* n = new Node(node->data);
    n->left = copy(node->left);
    n->right = copy(node->right);
    return n;
}

bool Tree::equal(Node* a, Node* b) {
    if (!a && !b) return true;
    if (!a || !b) return false;
    return a->data == b->data && equal(a->left, b->left) && equal(a->right, b->right);
}

int Tree::countLeaves(Node* node) {
    if (!node) return 0;
    if (!node->left && !node->right) return 1;
    return countLeaves(node->left) + countLeaves(node->right);
}

int Tree::countLeaves() {
    return countLeaves(root);
}