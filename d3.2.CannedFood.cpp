#include "d3.2.Food.cpp"
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