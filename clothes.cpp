
// creating a class for the clothes
class Clothes : public Product
{
    string category;

public:
    Clothes() : Product("", 0, "")
    {
        this->category = "Clothes";
    }
    Clothes(string name, double price, string description) : Product(name, price, description)
    {
        this->category = "Clothes";
    }
    void setCategory(string category) override;
    string getCategory() override;
    void getDetails() override;
};
/*Creating the methods of the Clothes*/
void Clothes::setCategory(string category)
{
    this->category = category;
}
string Clothes::getCategory()
{
    return category;
}
void Clothes::getDetails()
{
    cout << "ID: " << getId() << endl;
    cout << "Name: " << getName() << endl;
    cout << "Price: " << getPrice() << endl;
    cout << "Description: " << getDescription() << endl;
    cout << "Category: " << getCategory() << endl;
}
