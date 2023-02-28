// header files
#include <bits/stdc++.h>
using namespace std;

#include "utilitydeclaration.cpp"
#include "product.cpp"
#include "book.cpp"
#include "food.cpp"
#include "clothes.cpp"
#include "orderdetails.cpp"
#include "order.cpp"
#include "cashondeliveryorder.cpp"
#include "onlinebankingorder.cpp"
#include "shoppingcart.cpp"

// storage
map<string, Product *> products;        // id, product
map<string, vector<Order *>> Allorders; // id, array of orders
string currentUser = "none";

#include "user.cpp"

// storage or Database
map<string, User *> users; // id, user

#include "utilityimplementation.cpp"

// main function
int main()
{
    User rashed = User("rashed", "123");
    User rahim = User("rahim", "123");
    User karim = User("karim", "123");
    User jahid = User("jahid", "123");
    users["rashed"] = &rashed;
    users["rahim"] = &rahim;
    users["karim"] = &karim;
    users["jahid"] = &jahid;
    // making dummy products
    Product *p1 = new Food("Burger", 100, "Fast Food but very very testy!");
    Product *p2 = new Food("Pizza", 200, "Fast Food but very very testy!");
    Product *p3 = new Clothes("Shirt", 300, "Good quality shirt");
    Product *p4 = new Clothes("Pant", 400, "Good quality pant");
    Product *p5 = new Book("C++ in OOP way", 500, "Learn C++ in OOP way", "Illya Cantor");
    Product *p6 = new Book("Java in OOP way", 600, "Learn Java in OOP way", "Denich Ritchi");

    // save the products in the map
    products[p1->getId()] = p1;
    products[p2->getId()] = p2;
    products[p3->getId()] = p3;
    products[p4->getId()] = p4;
    products[p5->getId()] = p5;
    products[p6->getId()] = p6;
    login();
}