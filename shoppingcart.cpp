
// creating shoppingCart class
class ShoppingCart
{
    vector<string> products;   // id of the products
    map<string, int> quantity; // id and quantity of the products
public:
    void addProduct(string id, int quantity);
    void removeProduct(string id);
    void updateQuantity(string id, int quantity);
    void showCart();
    double getTotalPrice();
    vector<string> getProducts();
    map<string, int> getQuantity();
    void clearCart();
};
// creating the methods of the ShoppingCart
void ShoppingCart::addProduct(string id, int quantity)
{
    this->products.push_back(id);
    this->quantity[id] = quantity;
}
void ShoppingCart::removeProduct(string id)
{
    for (int i = 0; i < products.size(); i++)
    {
        if (products[i] == id)
        {
            products.erase(products.begin() + i);
            break;
        }
    }
    this->quantity.erase(id);
}
void ShoppingCart::updateQuantity(string id, int quantity)
{
    this->quantity[id] = quantity;
}
void ShoppingCart::showCart()
{
    double total = getTotalPriceOfCart(products, quantity);
    spaceUp();
    cout << "----------------------------------------------showing the cart----------------------------------------------" << endl;
    cout << "---------------------------------------------"
         << "total is " << total << " ---------------------------------------------" << endl;
    for (int i = 0; i < products.size(); i++)
    {
        cout << "Quantity: " << this->quantity[products[i]] << endl;
        printProduct(products[i]);
    }
    cout << "----------------------------------------------end of the cart-----------------------------------------------" << endl;
    cout << "------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl
         << endl
         << endl;
}
double ShoppingCart::getTotalPrice()
{
    double total = 0;
    // for (int i = 0; i < products.size(); i++) {
    //     total += this->quantity[products[i]] * Product::getPrice();
    // }
    return total;
}
vector<string> ShoppingCart::getProducts()
{
    return products;
}
map<string, int> ShoppingCart::getQuantity()
{
    return quantity;
}
void ShoppingCart::clearCart()
{
    products.clear();
    quantity.clear();
}
