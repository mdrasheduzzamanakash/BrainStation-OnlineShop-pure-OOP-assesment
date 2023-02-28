// creating the menu
void menu()
{
    spaceUp();
    cout << "1. Show all products" << endl;
    cout << "2. Show Shopping Cart" << endl;
    cout << "3. Show Orders" << endl;
    cout << "4. Logout" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        // show all products
        showAllProducts();
    }
    else if (choice == 2)
    {
        // show shopping cart
        showShoppingCart();
    }
    else if (choice == 3)
    {
        // show orders
        showOrders();
    }
    else if (choice == 4)
    {
        currentUser = "none";
        login();
    }
    else
    {
        cout << "Invalid choice" << endl;
        menu();
    }
}
// utility functions
void printProduct(string product_id)
{
    cout << "ID: " << products[product_id]->getId() << endl;
    cout << "Name: " << products[product_id]->getName() << endl;
    cout << "Price: " << products[product_id]->getPrice() << endl;
    cout << "Description: " << products[product_id]->getDescription() << endl;
    cout << "****************************************************************************************" << endl;
}
void showAllProducts()
{
    spaceUp();
    cout << "--------------------------------All Available products----------------------------------" << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;
    cout << "****************************************************************************************" << endl;

    for (auto it = products.begin(); it != products.end(); it++)
    {
        cout << "ID: " << it->second->getId() << endl;
        cout << "Name: " << it->second->getName() << endl;
        cout << "Price: " << it->second->getPrice() << endl;
        cout << "Description: " << it->second->getDescription() << endl;
        cout << "****************************************************************************************" << endl;
    }

    cout << "--------------------------------End of products-----------------------------------------" << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;
    cout << "----------------------------------------------------------------------------------------" << endl
         << endl
         << endl
         << endl;

    cout << "1. Add to cart" << endl;
    cout << "2. Back to menu" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        // add to cart
        cout << "Enter product id: ";
        string id;
        cin >> id;
        cout << "Enter quantity: ";
        int quantity;
        cin >> quantity;
        users[currentUser]->addToShoppingCart(id, quantity);
        showAllProducts();
    }
    else if (choice == 2)
    {
        // back to menu
        menu();
    }
    else
    {
        cout << "Invalid choice" << endl;
        showAllProducts();
    }
}
void showShoppingCart()
{
    users[currentUser]->showShoppingCart();
    cout << "1. Remove from cart" << endl;
    cout << "2. Update quantity" << endl;
    cout << "3. Checkout" << endl;
    cout << "4. Back to menu" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        // remove from cart
        cout << "Enter product id: ";
        string id;
        cin >> id;
        users[currentUser]->removeFromShoppingCart(id);
        showShoppingCart();
    }
    else if (choice == 2)
    {
        // update quantity
        cout << "Enter product id: ";
        string id;
        cin >> id;
        cout << "Enter quantity: ";
        int quantity;
        cin >> quantity;
        users[currentUser]->updateQuantity(id, quantity);
        showShoppingCart();
    }
    else if (choice == 3)
    {
        // checkout
        cout << "Enter payment method write (cash, online): ";
        string paymentMethod;
        cin >> paymentMethod;
        users[currentUser]->checkout(paymentMethod);
        menu();
    }
    else if (choice == 4)
    {
        // back to menu
        menu();
    }
    else
    {
        cout << "Invalid choice" << endl;
        showShoppingCart();
    }
}
void showOrders()
{
    users[currentUser]->showOrders();
    cout << "1. Back to menu" << endl;
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        // back to menu
        menu();
    }
    else
    {
        cout << "Invalid choice" << endl;
        showOrders();
    }
}
void login()
{
    string id, password;
    cout << "Enter your id: ";
    cin >> id;
    cout << "Enter your password: ";
    cin >> password;
    if (users.find(id) != users.end())
    {
        if (users[id]->getPassword() == password)
        {
            cout << "Login successful" << endl;
            currentUser = id;
            menu();
            // show the menu
        }
        else
        {
            cout << "Wrong password" << endl;
        }
    }
    else
    {
        cout << "User not found" << endl;
        login();
    }
}
string generate_unique_id()
{
    string id = "";
    for (int i = 0; i < 50; i++)
    {
        id += to_string(rand() % 10);
    }
    return id;
}
void spaceUp()
{
    cout << endl
         << endl
         << endl
         << endl;
}
double getTotalPriceOfCart(vector<string> pd_ids, map<string, int> qnt)
{
    double total = 0;
    for (int i = 0; i < pd_ids.size(); i++)
    {
        total += products[pd_ids[i]]->getPrice() * qnt[pd_ids[i]];
    }
    return total;
}
