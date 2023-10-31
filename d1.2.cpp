#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Book{
    private:
    string nameBook;
    string nameAuthor;
    int numberBook;
    public:
    Book(){}
    Book(string nameBook, string nameAuthor, int numberBook):nameBook(nameBook),nameAuthor(nameAuthor),numberBook(numberBook){}
    void display()
        {
        cout << "Name Book: " << this->nameBook << endl;
        cout << "Name Author: " << this->nameAuthor << endl;
        cout << "Number Book: " << this->numberBook << endl;
        }

    string getNameBook(){
        return nameBook;
    }
    string getNameAuthor(){
        return nameAuthor;
    }
    int getNumberBook(){
        return numberBook;
    }
};
class Person : public Book{
    private:
    string name;
    int age;
    string add;
    vector<Book> vb;
    public:
    Person() {}
    Person(string name, int age, string add, vector<Book> vb) : name(name), age(age), add(add), vb(vb) {}
    string getName(){
        return name;
    }
    int getAge(){
        return age;
    }
    vector<Book> getVB(){
        return vb;
    }
    virtual long moneyPay() = 0;
    virtual void display(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Add: " << add << endl;
        cout << "List Book Borrowed:" << endl;
        for (int i = 0; i < vb.size(); i++)
        {
            vb[i].display();
        }
        cout << "Money Pay: " << moneyPay() << endl;

    }
    static void sortPersonAge(vector<Person*> &vt){
        for(int i=0;i<vt.size();i++){
            for(int j= i+1;j<vt.size();j++){
                if(vt[i]->getAge() > vt[j]->getAge()){
                    swap(vt[i],vt[j]);
                }
            }
        }
    }
    static vector<int> getListAge(vector<Person *> vt){
        vector<int> str;
        for(int i =0;i <vt.size();i++){
            if(!(find(str.begin(),str.end(),vt[i]->getAge())!=str.end())){
                str.push_back(vt[i]->getAge());
            }
        }
        return str;
    }
    static vector<Book> getMaxBookBorrowed(vector<Person *> vp, vector<Book> vB){
        vector<int> count(vB.size(),0);
        for(int i=0;i<vB.size();i++){
            for(int j=0;j<vp.size();j++){
                vector<Book> b(vp[j]->getVB());
                for(int k =0;k< b.size();k++){
                    if(vB[i].getNameBook() == b[k].getNameBook()){
                        count[i]++;
                    }
                }
            }
        }
        int max = *max_element(count.begin(),count.end());
        vector<Book> res;
        for(int i=0; i<vB.size();i++){
            if(count[i] == max){
                res.push_back(vB[i]);
            }
        }
        return res;
    }
    
};
class Children : public Person
{
public:
    Children() {}
    Children(string name, int age, string add, vector<Book> vb) : Person(name, age, add, vb) {}
    long moneyPay()
    {
        return this->getVB().size() * 5000;
    }
    void display()
    {
        cout << "Children!" << endl;
        Person::display();
    }
};
  class Adult : public Person
{
public:
    Adult() {}
    Adult(string name, int age, string add, vector<Book> vb) : Person(name, age, add, vb) {}
    long moneyPay()
    {
        return this->getVB().size() * 10000;
    }
    void display()
    {
        cout << "Adult!" << endl;
        Person::display();
    }
};
int main()
{
    vector<Book> books(5);
    books[0] = Book("A", "A", 1);
    books[1] = Book("B", "B", 2);
    books[2] = Book("C", "C", 3);
    books[3] = Book("D", "D", 4);
    books[4] = Book("E", "E", 5);


    Children children[3];
    children[0] = Children("A", 10, "HN", {books[0], books[1]});
    children[1] = Children("B", 20, "HN", {books[2], books[4], books[3]});
    children[2] = Children("C", 30, "HN", {books[3], books[4]});


    Adult adults[2];
    adults[0] = Adult("A", 1, "HN", {books[0], books[1]});
    adults[1] = Adult("B", 2, "HN", {books[0], books[1], books[2], books[3], books[4]});


    vector<Person *> persons(5);
    persons[0] = &children[0];
    persons[1] = &children[1];
    persons[2] = &children[2];
    persons[3] = &adults[0];
    persons[4] = &adults[1];


    cout << "Danh sach tuoi" << endl;
    for (auto v : Person::getListAge(persons))
        cout << v << " ";


    cout << endl
         << "Sach muon nhieu nhat" << endl;
    for (auto v : Person::getMaxBookBorrowed(persons, books))
        v.display();


    cout << "Sap xep theo tuoi" << endl;
    Person::sortPersonAge(persons);
    for (auto v : persons)
        v->display();
}


