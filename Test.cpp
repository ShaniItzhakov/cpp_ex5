#include "doctest.h"
#include "sources/BinaryTree.hpp"
using namespace ariel;

#include <iostream>
#include <array>
#include <string>
using namespace std;


TEST_CASE("Test int binary tree") {
    BinaryTree<int> tree_of_ints;
    CHECK_THROWS(tree_of_ints.add_right(10,5)); // no root - should throw exepction
    CHECK_THROWS(tree_of_ints.add_left(10,2)); //  no root - should throw exepction
    CHECK_NOTHROW(tree_of_ints.add_root(10) // Build tree
    .add_right(10, 5)
    .add_right(10, 5)
    .add_left(10, 2)
    .add_left(10, 12)  
    .add_right(12, 4)
    .add_left(12, 3)
    .add_left(4, 6)
    .add_right(4, 7)
    .add_left(5, 11)
    .add_right(5, 13)
    .add_right(5, 2)
    .add_right(2, 8));

    cout << tree_of_ints << endl; // Print tree

    array<int, 10> expected_preorder_arr{10, 12, 3, 4, 6, 7, 5, 11, 2, 8};
    array<int, 10> expected_inorder_arr{3, 12, 6, 4, 7, 10, 11, 5, 2, 8};
    array<int, 10> expected_postorder_arr{3, 6, 7, 4, 12, 11, 8, 2, 5, 10};
    
    unsigned long i = 0;
    auto it = tree_of_ints.begin_preorder();
    CHECK((*(++it)) ==  expected_preorder_arr.at(i++)); // check 10
    CHECK((*(++it)) ==  expected_preorder_arr.at(i++)); // check 12
    CHECK((*(++it)) ==  expected_preorder_arr.at(i++)); // check 3
    CHECK((*(++it)) ==  expected_preorder_arr.at(i++)); // check 4
    CHECK((*(++it)) ==  expected_preorder_arr.at(i++)); // check 6
    CHECK((*(++it)) ==  expected_preorder_arr.at(i++)); // check 7
    CHECK((*(++it)) ==  expected_preorder_arr.at(i++)); // check 5
    CHECK((*(++it)) ==  expected_preorder_arr.at(i++)); // check 11
    CHECK((*(++it)) ==  expected_preorder_arr.at(i++)); // check 2
    CHECK((*(++it)) ==  expected_preorder_arr.at(i)); // check 8
    it = tree_of_ints.end_preorder();

    i = 0;
    auto it1 = tree_of_ints.begin_inorder();
    CHECK((*(++it1)) ==  expected_inorder_arr.at(i++)); // check 3
    CHECK((*(++it1)) ==  expected_inorder_arr.at(i++)); // check 12
    CHECK((*(++it1)) ==  expected_inorder_arr.at(i++)); // check 6
    CHECK((*(++it1)) ==  expected_inorder_arr.at(i++)); // check 4
    CHECK((*(++it1)) ==  expected_inorder_arr.at(i++)); // check 7
    CHECK((*(++it1)) ==  expected_inorder_arr.at(i++)); // check 10
    CHECK((*(++it1)) ==  expected_inorder_arr.at(i++)); // check 11
    CHECK((*(++it1)) ==  expected_inorder_arr.at(i++)); // check 5
    CHECK((*(++it1)) ==  expected_inorder_arr.at(i++)); // check 2
    CHECK((*(++it1)) ==  expected_inorder_arr.at(i)); // check 8
    it1 = tree_of_ints.end_inorder(); 

    i = 0;
    auto it2 = tree_of_ints.begin_postorder();
    CHECK((*(++it2)) ==  expected_postorder_arr.at(i++)); // check 3
    CHECK((*(++it2)) ==  expected_postorder_arr.at(i++)); // check 6
    CHECK((*(++it2)) ==  expected_postorder_arr.at(i++)); // check 7
    CHECK((*(++it2)) ==  expected_postorder_arr.at(i++)); // check 4
    CHECK((*(++it2)) ==  expected_postorder_arr.at(i++)); // check 12
    CHECK((*(++it2)) ==  expected_postorder_arr.at(i++)); // check 11
    CHECK((*(++it2)) ==  expected_postorder_arr.at(i++)); // check 8
    CHECK((*(++it2)) ==  expected_postorder_arr.at(i++)); // check 2
    CHECK((*(++it2)) ==  expected_postorder_arr.at(i++)); // check 5
    CHECK((*(++it2)) ==  expected_postorder_arr.at(i)); // check 10
    it2 = tree_of_ints.end_postorder();    
    
    i = 0;
    for (auto it=tree_of_ints.begin_preorder(); it!=tree_of_ints.end_preorder(); ++it) {
        CHECK((*(++it)) ==  expected_preorder_arr.at(i++));     
    }  // checks: 10 12 3 4 6 7 5 11 2 8
    i = 0;
    for (auto it=tree_of_ints.begin_inorder(); it!=tree_of_ints.end_inorder(); ++it) {
        CHECK((*it) ==  expected_inorder_arr.at(i++));
    }  // checks: 3 12 6 4 7 10 11 5 2 8
    i = 0;
    for (auto it=tree_of_ints.begin_postorder(); it!=tree_of_ints.end_postorder(); ++it) {
        CHECK((*it) == expected_preorder_arr.at(i++));
    }  // checks: 3 6 7 4 12 11 8 2 5 10
    i = 0;
    for (int value: tree_of_ints) {  // this should work like inorder
        CHECK(value == expected_preorder_arr.at(i++));
    }  // checks: 3 12 6 4 7 10 11 5 2 8
}

TEST_CASE("Test string binary tree") {
    BinaryTree<string> tree_of_strings;
    CHECK_THROWS(tree_of_strings.add_right("j","a")); // no root - should throw exepction
    CHECK_THROWS(tree_of_strings.add_left("b","e")); //  no root - should throw exepction
    CHECK_NOTHROW(tree_of_strings.add_root("j") // Build tree
    .add_right("j", "e")
    .add_right("j", "e")
    .add_left("j", "b")
    .add_left("j", "l")  
    .add_right("l", "d")
    .add_left("l", "c")
    .add_left("d", "f")
    .add_right("d", "g")
    .add_left("e", "k")
    .add_right("e", "m")
    .add_right("e", "b")
    .add_right("b", "h"));
    CHECK_THROWS(tree_of_strings.add_right("z", "q")); // no root z - should throw exepction
    CHECK_THROWS(tree_of_strings.add_left("r", "p")); // no root r - should throw exepction

    cout << tree_of_strings << endl; // Print tree

    array<string, 10> expected_preorder_arr{"j", "l", "c", "d", "f", "g", "e", "k", "b", "h"};
    array<string, 10> expected_inorder_arr{"c", "l", "f", "d", "g", "j", "k", "e", "b", "h"};
    array<string, 10> expected_postorder_arr{"c", "f", "g", "d", "l", "k", "h", "b", "e", "j"};
    unsigned long i = 0;
    for (auto it=tree_of_strings.begin_preorder(); it!=tree_of_strings.end_preorder(); ++it) {
        CHECK((*it) ==  expected_preorder_arr.at(i++));
    }  // checks: j l c d f g e k b h
    i = 0;
    for (auto it=tree_of_strings.begin_inorder(); it!=tree_of_strings.end_inorder(); ++it) {
        CHECK((*it) ==  expected_inorder_arr.at(i++));
    }  // checks: c l f d g j k e b h
    i = 0;
    for (auto it=tree_of_strings.begin_postorder(); it!=tree_of_strings.end_postorder(); ++it) {
        CHECK((*it) == expected_preorder_arr.at(i++));
    }  // checks: c f g d l k h b e j
    i = 0;
    for (string& value: tree_of_strings) {  // this should work like inorder
        CHECK(value == expected_preorder_arr.at(i++));
    }  // checks: c l f d g j k e b h

    // demonstrate the arrow operator:
    for (auto it=tree_of_strings.begin_postorder(); it!=tree_of_strings.end_postorder(); ++it) {
        CHECK(it->size() == 1);
    } // checks: 1 1 1 1 1 1 1 1 1 1
}

TEST_CASE("Test object binary tree") {    
    struct Pet{
        string type;
        Pet(string type) : type(type) {}
    };
    
    BinaryTree<Pet> tree_of_pets;
    Pet pet1("dog");
    Pet pet2("cat");
    Pet pet3("horse");
    CHECK_THROWS(tree_of_pets.add_right(pet1, pet2)); // no root - should throw exepction
    CHECK_THROWS(tree_of_pets.add_left(pet2, pet1)); //  no root - should throw exepction
    // Build tree
    CHECK_NOTHROW(tree_of_pets.add_root(pet1));
    CHECK_NOTHROW(tree_of_pets.add_right(pet1, pet2));
    CHECK_NOTHROW(tree_of_pets.add_left(pet1, pet3));
    CHECK_NOTHROW(tree_of_pets.add_right(pet3, Pet("mouse")));
    CHECK_NOTHROW(tree_of_pets.add_left(pet3, Pet("bird")));

   // cout << tree_of_pets << endl; // Print tree
    /* should print:
           dog
            |
        |--------|
      horse     cat
    */

    array<string, 3> expected_preorder_arr{"dog", "horse", "cat"};
    array<string, 3> expected_inorder_arr{"horse", "dog", "cat"};
    array<string, 3> expected_postorder_arr{"horse", "cat", "dog"};
    unsigned long i = 0;
    for (auto it=tree_of_pets.begin_preorder(); it!=tree_of_pets.end_preorder(); ++it) {
        CHECK((*it).type ==  expected_preorder_arr.at(i++));
    }  // checks: dog horse cat
    i = 0;
    for (auto it=tree_of_pets.begin_inorder(); it!=tree_of_pets.end_inorder(); ++it) {
        CHECK((*it).type ==  expected_inorder_arr.at(i++));
    }  // checks: horse dog cat
    i = 0;
    for (auto it=tree_of_pets.begin_postorder(); it!=tree_of_pets.end_postorder(); ++it) {
        CHECK((*it).type == expected_preorder_arr.at(i++));
    }  // checks: horse cat dog
    i = 0;
    for (const Pet& pet: tree_of_pets) {  // this should work like inorder
        CHECK(pet.type == expected_preorder_arr.at(i++));
    }  // checks: horse dog cat
    }