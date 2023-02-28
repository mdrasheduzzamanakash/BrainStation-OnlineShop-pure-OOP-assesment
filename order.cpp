// creating an order class
class Order
{
    string orderId;
    string userId;
    vector<OrderDetails> orderDetails;
    double totalOrderPrice;

public:
    Order()
    {
        this->orderId = "";
        this->userId = "";
        this->totalOrderPrice = 0;
    }
    Order(string orderId, string userId, vector<OrderDetails> orderDetails, double totalOrderPrice)
    {
        this->orderId = orderId;
        this->userId = userId;
        this->orderDetails = orderDetails;
        this->totalOrderPrice = totalOrderPrice;
    }
    void setOrderId(string orderId);
    string getOrderId();
    void setUserId(string userId);
    string getUserId();
    void setOrderDetails(vector<OrderDetails> orderDetails);
    vector<OrderDetails> getOrderDetails();
    void setTotalOrderPrice(double totalOrderPrice);
    void addOrderDetails(OrderDetails orderDetails);
    void removeOrderDetails(string productId);
    void updateOrderDetails(string productId, int quantity);
    void showOrderDetails();
    double getTotalOrderPrice();
    virtual void setPaymentMethod(string paymentMethod) = 0;
    virtual string getPaymentMethod() = 0;
};
// creating the methods of the Order
void Order::setOrderId(string orderId)
{
    this->orderId = orderId;
}
string Order::getOrderId()
{
    return orderId;
}
void Order::setUserId(string userId)
{
    this->userId = userId;
}
string Order::getUserId()
{
    return userId;
}
void Order::setOrderDetails(vector<OrderDetails> orderDetails)
{
    this->orderDetails = orderDetails;
}
vector<OrderDetails> Order::getOrderDetails()
{
    return orderDetails;
}
void Order::setTotalOrderPrice(double totalOrderPrice)
{
    this->totalOrderPrice = totalOrderPrice;
}
double Order::getTotalOrderPrice()
{
    return totalOrderPrice;
}
void Order::addOrderDetails(OrderDetails orderDetails)
{
    this->orderDetails.push_back(orderDetails);
}
void Order::removeOrderDetails(string productId)
{
    for (int i = 0; i < orderDetails.size(); i++)
    {
        if (orderDetails[i].getProductId() == productId)
        {
            orderDetails.erase(orderDetails.begin() + i);
            break;
        }
    }
}
void Order::updateOrderDetails(string productId, int quantity)
{
    for (int i = 0; i < orderDetails.size(); i++)
    {
        if (orderDetails[i].getProductId() == productId)
        {
            orderDetails[i].setQuantity(quantity);
            break;
        }
    }
}
void Order::showOrderDetails()
{
    cout << "Order ID: " << getOrderId() << endl;
    cout << "User ID: " << getUserId() << endl;
    for (int i = 0; i < orderDetails.size(); i++)
    {
        orderDetails[i].showOrderDetails();
    }
    cout << "Total Order Price: " << getTotalOrderPrice() << endl;
}
