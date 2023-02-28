// cash on onlineBanking order class
class OnlineBankingOrder : public Order
{
    string paymentMethod;

public:
    OnlineBankingOrder() : Order()
    {
        this->paymentMethod = "";
    }
    OnlineBankingOrder(string orderId, string userId, vector<OrderDetails> orderDetails, double totalOrderPrice, string paymentMethod) : Order(orderId, userId, orderDetails, totalOrderPrice)
    {
        this->paymentMethod = paymentMethod;
    }
    void setPaymentMethod(string paymentMethod) override;
    string getPaymentMethod() override;
};
// creating the methods of the OnlineBankingOrder
void OnlineBankingOrder::setPaymentMethod(string paymentMethod)
{
    this->paymentMethod = paymentMethod;
}
string OnlineBankingOrder::getPaymentMethod()
{
    return paymentMethod;
}
