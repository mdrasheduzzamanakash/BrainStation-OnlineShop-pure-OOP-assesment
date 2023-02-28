// cash on delivery order class
class CashOnDeliveryOrder : public Order
{
    string paymentMethod;

public:
    CashOnDeliveryOrder() : Order()
    {
        this->paymentMethod = "";
    }
    CashOnDeliveryOrder(string orderId, string userId, vector<OrderDetails> orderDetails, double totalOrderPrice, string paymentMethod) : Order(orderId, userId, orderDetails, totalOrderPrice)
    {
        this->paymentMethod = paymentMethod;
    }
    void setPaymentMethod(string paymentMethod) override;
    string getPaymentMethod() override;
};
// creating the methods of the CashOnDeliveryOrder
void CashOnDeliveryOrder::setPaymentMethod(string paymentMethod)
{
    this->paymentMethod = paymentMethod;
}
string CashOnDeliveryOrder::getPaymentMethod()
{
    return paymentMethod;
}
