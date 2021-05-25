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
    for (auto it=tree_of_ints.begin_preorder(); it!=tree_of_ints.end_preorder(); ++it) { // never go inside the loop
        CHECK((*(++it)) ==  expected_preorder_arr.at(i++)); // added ++ before iterator to maniully add,
        // can check manually with begin_preorder function and check equal for 10,
        // then use end_preorder function to check it points to 12 after incrememnt to the pointer it
        
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
        int chip_number;
        Pet(string type, int chip_number) : type(type), chip_number(chip_number) {}
    };

    BinaryTree<Pet> tree_of_pets;
    Pet pet1("dog", 111);
    Pet pet2("cat", 222);
    Pet pet3("horse", 333);
    CHECK_THROWS(tree_of_pets.add_right(pet1, pet2)); // no root - should throw exepction
    CHECK_THROWS(tree_of_pets.add_left(pet2, pet1)); //  no root - should throw exepction
    // Build tree
    CHECK_NOTHROW(tree_of_pets.add_root(pet1));
    CHECK_NOTHROW(tree_of_pets.add_right(pet1, pet2));
    CHECK_NOTHROW(tree_of_pets.add_left(pet1, pet3));
    CHECK_THROWS(tree_of_pets.add_right(pet3, Pet("mouse", 444))); // no root pet3 - should throw exepction
    CHECK_THROWS(tree_of_pets.add_left(pet3, Pet("bird", 555))); // no root pet3 - should throw exepction

    cout << tree_of_pets << endl; // Print tree
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