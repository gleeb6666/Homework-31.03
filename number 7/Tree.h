#pragma once

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Tree {
private:
    Node* root;
    int nodeCount;

    Node* insert(Node* node, int val);
    void destroy(Node* node);
    Node* copy(Node* node);
    bool equal(Node* a, Node* b);
    int countLeaves(Node* node);

public:
    Tree();
    Tree(const Tree& other);
    Tree(Tree&& other);
    ~Tree();

    Tree& operator=(const Tree& other);
    Tree& operator=(Tree&& other);
    bool operator==(const Tree& other);

    void insert(int val);
    int countLeaves();
    int size() const;
    bool empty() const;
};