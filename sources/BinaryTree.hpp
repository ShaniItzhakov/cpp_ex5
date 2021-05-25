#pragma once
#include <iostream>
using namespace std;

namespace ariel {
    template<typename T>
    class BinaryTree {
    private:
        struct Node {
            T value;
            Node* leftNode;
            Node* rightNode;
            Node* parentNode;
            Node(const T& val, Node* left, Node* right, Node* parent) 
                : value(val), leftNode(left), rightNode(right), parentNode(parent){}
        };
        Node* root;

    public:
        class Iterator_pre_order {
        private:
            Node* pNode_pre_order;
        public:
            Iterator_pre_order(Node* ptr) : pNode_pre_order(ptr) {}
            
            T& operator*() const {
                return pNode_pre_order->value;
            }

            T* operator->() const {
                return &(pNode_pre_order->value);
            }

            Iterator_pre_order& operator++() { // ++i (needs all path and other iterators too)
            //  pNode_pre_order = pNode_pre_order->root;
                return *this;
            }

            const Iterator_pre_order& operator++(int flag) { // i++ (needs all path and other iterators too)
            //    Iterator_pre_order temp = pNode_pre_order;
            //    pNode_pre_order = pNode_pre_order->root;
            //    return temp;
                return *this; 
            }

            bool operator==(const Iterator_pre_order& bt) {
               return false;
                //return pNode_pre_order == bt.pNode_pre_order;
            }

            bool operator!=(const Iterator_pre_order& bt) {
                return false;
            //    return pNode_pre_order != bt.pNode_pre_order;
            }
        };

        class Iterator_in_order {
        private:
            Node* pNode_in_order;
        public:
            Iterator_in_order(Node* ptr) : pNode_in_order(ptr) {}
            T& operator*() const {
                return pNode_in_order->value;
            }

            T* operator->() const {
                return &(pNode_in_order->value);
            }

            Iterator_in_order& operator++() { // ++i
            //  pNode_in_order = pNode_in_order->leftNode;
                return *this;
            }

            const Iterator_in_order& operator++(int flag) { // i++
            //  Iterator_in_order temp = pNode_in_order;
            //  pNode_in_order = pNode_in_order->leftNode;
            //  return temp;
              return *this;
            }

            bool operator==(const Iterator_in_order& bt) {
                return false;
            //    return pNode_in_order == bt.pNode_in_order;
            }

            bool operator!=(const Iterator_in_order& bt) {
                return false;
            //    return pNode_in_order != bt.pNode_in_order;
            }
        };

        class Iterator_post_order {
        private:
            Node* pNode_post_order;
        public:
            Iterator_post_order(Node* ptr) : pNode_post_order(ptr) {}
            T& operator*() const {
                return pNode_post_order->value;
            }

            T* operator->() const {
                return &(pNode_post_order->value);
            }

            Iterator_post_order& operator++() { // ++i
              //  pNode_post_order = pNode_post_order->root;
                return *this;
            }

            const Iterator_post_order& operator++(int flag) { // i++
              //  Iterator_post_order temp = pNode_post_order;
              //  pNode_post_order = pNode_post_order->root;
              //  return temp;
              return *this;
            }

            bool operator==(const Iterator_post_order& bt) {
                return false;
            //    return pNode_post_order == bt.pNode_post_order;
            }

            bool operator!=(const Iterator_post_order& bt) {
                return false;
            //    return pNode_post_order != bt.pNode_post_order;
            }
        };
        BinaryTree() : root(nullptr) {}
        ~BinaryTree() {} // need to delete tree, check how
        BinaryTree(const BinaryTree& bt); // : {}
        BinaryTree& operator=(const BinaryTree& bt);
        // Binary tree functions
        BinaryTree& add_root(const T& root) {
            this->root = new Node(root, nullptr, nullptr, nullptr);
            return *this;
        }

        BinaryTree& add_left(const T& node, const T& leftNode) {
            return *this;
        }

        BinaryTree& add_right(const T& node, const T& rightNode) {
            return *this;
        }

        Iterator_pre_order begin_preorder() {
            // if (root== nullptr) {
            //     return Iterator_pre_order{nullptr};
            // }
            return Iterator_pre_order{root};
        }

        Iterator_pre_order end_preorder() {
            return Iterator_pre_order{nullptr};
        }

        Iterator_in_order begin_inorder() {
            return Iterator_in_order{root};
        }

        Iterator_in_order end_inorder() {
            return Iterator_in_order{nullptr};
        }

        Iterator_post_order begin_postorder() {
            return Iterator_post_order{root};
        }

        Iterator_post_order end_postorder() {
            return Iterator_post_order{nullptr};
        }

        Iterator_in_order begin() {
            return begin_inorder();
        }

         Iterator_in_order end() {
            return end_inorder();
        }

        friend std::ostream& operator<<(std::ostream& os, const BinaryTree& bt) {
            return os;
        }
    };
}