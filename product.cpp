// creating a class for the products
class Product
{
    string _id;
    string name;
    double price;
    string description;

public:
    Product(string name, double price, string description)
    {
        this->name = name;
        this->price = price;
        this->description = description;
        this->_id = generate_unique_id();
    }
    string getId();
    void setName(string name);
    string getName();
    void setPrice(double price);
    double getPrice();
    void setDescription(string description);
    string getDescription();
    // creating pure virtual functions
    virtual void getDetails() = 0;
    virtual void setCategory(string category) = 0;
    virtual string getCategory() = 0;
};
/*Craeting the methods of the Product*/
string Product::getId()
{
    return _id;
}
void Product::setName(string name)
{
    this->name = name;
}
string Product::getName()
{
    return name;
}
void Product::setPrice(double price)
{
    this->price = price;
}
double Product::getPrice()
{
    return price;
}
void Product::setDescription(string description)
{
    this->description = description;
}
string Product::getDescription()
{
    return description;
}
