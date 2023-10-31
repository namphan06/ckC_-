#include <iostream>
#include <vector>
using namespace std;
class Food{
    private:
    string name;
    double price;
    public:
    Food(){}
    Food(string name,double price):name(name),price(price){}
    string getName(){
        return name;
    }
    void setName(string name){
        this->name=name;
    }
    double getPrice(){
        return price;
    }
    void setPrice(double price){
        this->price=price;
    }
};
class CannedFood : public Food{
    private:
    int numberBox;
    public:
    CannedFood(){}
    CannedFood(string name, double price,int numberBox):Food(name,price),numberBox(numberBox){}
    void display(){
        cout<<"Name : "<<Food::getName()<<endl;
        cout<<"Price : "<<Food::getPrice()<<endl;
        cout<<"Number box : "<<numberBox<<endl;
    }
    int getNumberBox(){
        return numberBox;
    }
    void setNumberBox(int numberBox){
        this->numberBox=numberBox;
    }
    static void sortNumberBox(vector<CannedFood> &vt){
        for(int i=0;i<vt.size()-1;i++){
            for(int j=i+1;j<vt.size();j++){
                if(vt[i].getNumberBox()>vt[j].getNumberBox()){
                    swap(vt[i],vt[j]);
                }
            }
        }
    }
};
class NonCFood : public Food
{
private:
    double weight;
public:
    NonCFood() {}
    NonCFood(string name, double price, double weight) : Food(name, price)
    {
        this->weight = weight;
    }
    void display()
    {
        cout << "Name: " << Food::getName() << endl;
        cout << "Price: " << Food::getPrice() << endl;
        cout << "Weight: " << this->weight << endl;
    }
    double getWeight()
    {
        return weight;
    }
    void setWeight(double weight){
        this->weight=weight;
    }
    static void sortWeight(vector<NonCFood> &vt)
    {
        for (int i = 0; i < vt.size() - 1; i++)
        {
            for (int j = i + 1; j < vt.size(); j++)
            {
                if (vt[j].weight < vt[i].weight)
                {
                    swap(vt[j], vt[i]);
                }
            }
        }
    }
};
int main()
{
    vector<CannedFood> cfoods(3);
    cfoods[0] = CannedFood("A", 3.0, 3);
    cfoods[1] = CannedFood("B", 2.0, 2);
    cfoods[2] = CannedFood("C", 1.0, 1);


    int maxNumberBoxIndex = 0;
    for (int i = 0; i < cfoods.size(); i++)
        if (cfoods[i].getNumberBox() > cfoods[maxNumberBoxIndex].getNumberBox())
            maxNumberBoxIndex = i;


    cfoods[maxNumberBoxIndex].setPrice(cfoods[maxNumberBoxIndex].getPrice()/2);


    CannedFood::sortNumberBox(cfoods);
    for (auto v : cfoods)
        v.display();


    vector<NonCFood> ncfoods(3);
    ncfoods[0] = NonCFood("A", 1.0, 1);
    ncfoods[1] = NonCFood("B", 2.0, 1);
    ncfoods[2] = NonCFood("C", 3.0, 1);


    int maxWeightIndex = 0;
    for (int i = 0; i < ncfoods.size(); i++)
        if (ncfoods[i].getWeight() > ncfoods[maxWeightIndex].getWeight())
            maxWeightIndex = i;


    ncfoods[maxWeightIndex].setWeight(ncfoods[maxWeightIndex].getWeight()/2);


    NonCFood::sortWeight(ncfoods);
    for (auto v : ncfoods)
        v.display();
}


