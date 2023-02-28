// creating user class
class User
{
    string id;
    string password;
    ShoppingCart *shoppingCart;
    vector<Order *> orders;

public:
    User()
    {
        this->id = "";
        this->password = "";
        this->shoppingCart = new ShoppingCart();
    }
    User(string id, string password)
    {
        this->id = id;
        this->password = password;
        this->shoppingCart = new ShoppingCart();
    }
    void setId(string id);
    string getId();
    void setPassword(string password);
    string getPassword();
    void setShoppingCart(ShoppingCart *shoppingCart);
    ShoppingCart *getShoppingCart();
    void setOrders(vector<Order *> orders);
    vector<Order *> getOrders();
    void addOrder(Order *order);
    void removeOrder(string orderId);
    void showOrders();
    void showOrderDetails(string orderId);
    void showShoppingCart();
    void addToShoppingCart(string productId, int quantity);
    void removeFromShoppingCart(string productId);
    void updateQuantity(string productId, int quantity);
    void checkout(string paymentMethod);
};
// creating the methods of the User
void User::setId(string id)
{
    this->id = id;
}
string User::getId()
{
    return id;
}
void User::setPassword(string password)
{
    this->password = password;
}
string User::getPassword()
{
    return password;
}
void User::setShoppingCart(ShoppingCart *shoppingCart)
{
    this->shoppingCart = shoppingCart;
}
ShoppingCart *User::getShoppingCart()
{
    return shoppingCart;
}
void User::setOrders(vector<Order *> orders)
{
    this->orders = orders;
}
vector<Order *> User::getOrders()
{
    return orders;
}
void User::addOrder(Order *order)
{
    this->orders.push_back(order);
}
void User::removeOrder(string orderId)
{
    for (int i = 0; i < orders.size(); i++)
    {
        if (orders[i]->getOrderId() == orderId)
        {
            orders.erase(orders.begin() + i);
            break;
        }
    }
}
void User::showOrders()
{
    spaceUp();
    for (int i = 0; i < orders.size(); i++)
    {
        cout << "Order ID: " << orders[i]->getOrderId() << endl;
        cout << "Order Total Price: " << orders[i]->getTotalOrderPrice() << endl;
        cout << "-------------------------In detail-----------------------" << endl;
        cout << "---------------------------------------------------------" << endl;
        vector<OrderDetails> orderDetails;
        orderDetails = orders[i]->getOrderDetails();
        for (int j = 0; j < orderDetails.size(); j++)
        {
            cout << "Product ID: " << orderDetails[j].getProductId() << endl;
            cout << "Product Name: " << products[orderDetails[j].getProductId()]->getName() << endl;
            cout << "Product Description: " << products[orderDetails[j].getProductId()]->getDescription() << endl;
            cout << "Product Quantity: " << orderDetails[j].getQuantity() << endl;
            cout << "Product Price: " << orderDetails[j].getPrice() << endl;
            cout << "--------------------------------------------------------" << endl;
        }
        cout << "-----------------------End of order no " << i + 1 << "----------------------" << endl;
        cout << "---------------------------------------------------------------------------" << endl
             << endl
             << endl
             << endl;
    }
}
void User::showOrderDetails(string orderId)
{
    for (int i = 0; i < orders.size(); i++)
    {
        if (orders[i]->getOrderId() == orderId)
        {
            orders[i]->showOrderDetails();
            break;
        }
    }
}
void User::showShoppingCart()
{
    shoppingCart->showCart();
}
void User::addToShoppingCart(string productId, int quantity)
{
    shoppingCart->addProduct(productId, quantity);
}
void User::removeFromShoppingCart(string productId)
{
    shoppingCart->removeProduct(productId);
}
void User::updateQuantity(string productId, int quantity)
{
    shoppingCart->updateQuantity(productId, quantity);
}
void User::checkout(string paymentMethod)
{
    // creating the order
    if (paymentMethod == "cash")
    {
        vector<OrderDetails> orderDetails;
        double totalPrice = 0;
        // making order details
        for (int i = 0; i < shoppingCart->getProducts().size(); i++)
        {
            OrderDetails orderDetail;
            orderDetail.setProductId(shoppingCart->getProducts()[i]);
            orderDetail.setQuantity(shoppingCart->getQuantity()[shoppingCart->getProducts()[i]]);
            orderDetail.setPrice(products[shoppingCart->getProducts()[i]]->getPrice() * shoppingCart->getQuantity()[shoppingCart->getProducts()[i]]);
            orderDetails.push_back(orderDetail);
            totalPrice += orderDetail.getPrice();
        }
        CashOnDeliveryOrder *order = new CashOnDeliveryOrder(generate_unique_id(), getId(), orderDetails, totalPrice, "cash on delivery");
        // adding the order to the user
        addOrder(order);
        // adding the order to the orders
        Allorders[getId()].push_back(order);
    }
    else if (paymentMethod == "online")
    {
        vector<OrderDetails> orderDetails;
        double totalPrice = 0;
        // making order details
        for (int i = 0; i < shoppingCart->getProducts().size(); i++)
        {
            OrderDetails orderDetail;
            orderDetail.setProductId(shoppingCart->getProducts()[i]);
            orderDetail.setQuantity(shoppingCart->getQuantity()[shoppingCart->getProducts()[i]]);
            orderDetail.setPrice(products[shoppingCart->getProducts()[i]]->getPrice() * shoppingCart->getQuantity()[shoppingCart->getProducts()[i]]);
            orderDetails.push_back(orderDetail);
            totalPrice += orderDetail.getPrice();
        }
        OnlineBankingOrder *order = new OnlineBankingOrder(generate_unique_id(), getId(), orderDetails, totalPrice, "online banking payment");
        // adding the order to the user
        addOrder(order);
        // adding the order to the orders
        Allorders[getId()].push_back(order);
    }

    // clearing the shopping cart
    shoppingCart->clearCart();
}
