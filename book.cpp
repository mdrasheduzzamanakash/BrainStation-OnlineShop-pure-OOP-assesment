// creating a class for the books
class Book : public Product
{
    string author;
    string category;

public:
    Book() : Product("", 0, "")
    {
        this->category = "Book";
        this->author = "";
    }
    Book(string name, double price, string description, string author) : Product(name, price, description)
    {
        this->author = author;
        this->category = "Book";
    }
    void setAuthor(string author);
    string getAuthor();
    void setCategory(string category) override;
    string getCategory() override;
    void getDetails() override;
};
/*Creating the methods of the Book*/
void Book::setAuthor(string author)
{
    this->author = author;
}
string Book::getAuthor()
{
    return author;
}
void Book::setCategory(string category)
{
    this->category = category;
}
string Book::getCategory()
{
    return category;
}
void Book::getDetails()
{
    cout << "ID: " << getId() << endl;
    cout << "Name: " << getName() << endl;
    cout << "Price: " << getPrice() << endl;
    cout << "Description: " << getDescription() << endl;
    cout << "Author: " << getAuthor() << endl;
    cout << "Category: " << getCategory() << endl;
}
