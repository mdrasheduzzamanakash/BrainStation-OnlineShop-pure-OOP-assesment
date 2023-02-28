// creating a class for the foods
class Food : public Product
{
    string category;

public:
    Food() : Product("", 0, "")
    {
        this->category = "Food";
    }
    Food(string name, double price, string description) : Product(name, price, description)
    {
        this->category = "Food";
    }
    void setCategory(string category) override;
    string getCategory() override;
    void getDetails() override;
};
/*Creating the methods of the Food*/
void Food::setCategory(string category)
{
    this->category = category;
}
string Food::getCategory()
{
    return category;
}
void Food::getDetails()
{
    cout << "ID: " << getId() << endl;
    cout << "Name: " << getName() << endl;
    cout << "Price: " << getPrice() << endl;
    cout << "Description: " << getDescription() << endl;
    cout << "Category: " << getCategory() << endl;
}
