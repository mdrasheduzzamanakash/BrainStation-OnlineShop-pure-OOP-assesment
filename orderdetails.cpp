
// creating an order details class
class OrderDetails
{
    int quantity;
    double price;
    string product_id;

public:
    OrderDetails()
    {
        this->quantity = 0;
        this->price = 0;
        this->product_id = "";
    }
    OrderDetails(int quantity, double price, string product_id)
    {
        this->quantity = quantity;
        this->price = price;
        this->product_id = product_id;
    }
    void setQuantity(int quantity);
    int getQuantity();
    void setPrice(double price);
    double getPrice();
    void setProductId(string product_id);
    string getProductId();
    void showOrderDetails();
};
// creating the methods of the OrderDetails
void OrderDetails::setQuantity(int quantity)
{
    this->quantity = quantity;
}
int OrderDetails::getQuantity()
{
    return quantity;
}
void OrderDetails::setPrice(double price)
{
    this->price = price;
}
double OrderDetails::getPrice()
{
    return price;
}
void OrderDetails::setProductId(string product_id)
{
    this->product_id = product_id;
}
string OrderDetails::getProductId()
{
    return product_id;
}
void OrderDetails::showOrderDetails()
{
    cout << "Product ID: " << getProductId() << endl;
    cout << "Quantity: " << getQuantity() << endl;
    cout << "Price: " << getPrice() << endl;
}
