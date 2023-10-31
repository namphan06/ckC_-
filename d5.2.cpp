#include <iostream>
#include <vector>
using namespace std;
class Person{
    private:
    string name;
    int age;
    string add;
    string tel;
    string sex;
    public:
    Person(){}
    Person(string name,int age,string add,string tel,string sex):name(name),age(age),add(add),tel(tel),sex(sex){}
    string getName(){
        return name;
    }
    int getAge(){
        return age;
    }
    string getAdd(){
        return add;
    }
    string getTel(){
        return tel;
    }
    string getSex(){
        return sex;
    }
    void setName(string name){
        this->name = name;
    }
    void setAge(int age){
        this->age = age;
    }
    void setAdd(string add){
        this->add = add;
    }
    void setTel(string tel){
        this->tel = tel;
    }
    void setSex(string sex){
        this->sex = sex;
    }
    virtual void display(){
        cout<<"Name : "<<name<<endl;;
        cout<<"Age : "<<age<<endl;
        cout<<"Sex : "<<sex<<endl;
        cout<<"Add : "<<add<<endl;
        cout<<"Tel : "<<tel<<endl;
    }
    virtual long salary()=0;
    static vector<Person *> findPerson(vector<Person *> vt){
        vector<Person *> str;
        for(int i =0; i<vt.size();i++){
            if(vt[i]->add == "HN"){
                str.push_back(vt[i]);
            }
        }
        return str;
    }
};
class EmployeePT : public Person{
    private:
    int hour;
    long money;
    public:
    EmployeePT(){}
    EmployeePT(string name, int age,string add, string tel,string sex,int hour, long money):Person(name,age,add,tel,sex),hour(hour),money(money){}
    int getHour(){
        return hour;
    }
    long getMoney(){
        return money;
    }
    void setHour(int hour){
        this->hour = hour;
    }
    void setMoney(long money){
        this->money = money;
    }
    long salary(){
        return long(hour)*money;
    }
    void display(){
        Person :: display();
        cout<<"Hour : "<<hour<<endl;
        cout<<"Money : "<<money<<endl;
        cout<<"Salary : "<<salary()<<endl;
    }
    static vector<EmployeePT> getMaxSalary(vector<EmployeePT> vt){
        vector<EmployeePT> pt;
        long max = vt[0].salary();
        for(int i =0;i<vt.size();i++){
            if(max<vt[i].salary()){
                max = vt[i].salary();
            }
        }
        for(int i=0; i<vt.size();i++){
            if(vt[i].salary()== max){
                pt.push_back(vt[i]);
            }
        }
        return pt;
    }
};
class EmployeeFT : public Person{
    private:
    int day;
    long money;
    public:
    EmployeeFT(){}
    EmployeeFT(string name,int age,string add,string tel,string sex,int day,long money):Person(name,age,add,tel,sex),day(day),money(money){}
    int getDay(){
        return day;
    }
    long getMoney(){
        return money;
    }
    void setDay(int day){
        this->day = day;
    }
    void setMoney(long money){
        this->money = money;
    }
    long salary()
    {
        return long(day) * money;
    }

     static vector<EmployeeFT> getMaxSalary(vector<EmployeeFT> ft)
    {
        long max = ft[0].salary();
        for (int i = 1; i < ft.size(); i++)
        {
            if (ft[i].salary() > max)
            {
                max = ft[i].salary();
            }
        }
        vector<EmployeeFT> v;
        for (int i = 0; i < ft.size(); i++)
        {
            if (ft[i].salary() == max)
            {
                v.push_back(ft[i]);
            }
        }
        return v;
    }

};
int main(){
    vector<EmployeeFT> fulltimes(3);
    fulltimes[0] = EmployeeFT("A", 1, "HN", "123", "M", 10, 1000);
    fulltimes[1] = EmployeeFT("B", 2, "HM", "234", "M", 5, 1000);
    fulltimes[2] = EmployeeFT("C", 3, "HN", "345", "M", 3, 1000);
    for (auto &v : fulltimes)
        v.display();
    for (auto &v : EmployeeFT::getMaxSalary(fulltimes))
        v.display();


   vector<EmployeePT> parttimes(3);
    parttimes[0] = EmployeePT("D", 1, "HP", "123", "M", 10, 1000);
    parttimes[1] = EmployeePT("E", 2, "HN", "234", "M", 5, 1000);
    parttimes[2] = EmployeePT("F", 3, "HN", "345", "M", 3, 1000);
    for (auto &v : parttimes)
        v.display();
    for (auto &v : EmployeePT::getMaxSalary(parttimes))
        v.display();


    vector<Person *> persons({&fulltimes[0], &fulltimes[1], &parttimes[0]});
    for (auto &v : Person::findPerson(persons))
        v->display();



}