#include<iostream>
#include<vector>
using namespace std;
class People
{
private:
    string name;
    int age;
    string job;
    string id;


public:
    People() {}
    People(string name, int age, string job, string id) : name(name), age(age), job(job), id(id) {}
    string getName()
    {
        return name;
    }
    int getAge()
    {
        return age;
    }
    string getJob()
    {
        return job;
    }
    string getId()
    {
        return id;
    }
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Job: " << job << endl;
        cout << "Id: " << id << endl;
    }
};

class Family
{
private:
    string nameF;
    string status;
    string add;
    vector<People> p;


public:
    Family()
    {
    }
    Family(string add, string status, vector<People> p) : add(add), status(status), p(p)
    {
        nameF = p[0].getName();
    }
    string getNameF()
    {
        return nameF;
    }
    string getStatus()
    {
        return status;
    }
    string getAdd()
    {
        return add;
    }
    vector<People> getP()
    {
        return p;
    }
    void display()
    {
        cout << "householder's name: " << nameF << endl;
        cout << "Number Member: " << p.size() << endl;
        cout << "Address: " << add << endl;
        cout << "Status: " << status << endl;
        cout << "List Information Member" << endl;
        for (int i = 0; i < p.size(); i++)
        {
            p[i].display();
        }
    }
    static vector<Family> getPoorHousehold(vector<Family> &fa)
    {
        vector<Family> v;
        for (int i = 0; i < fa.size(); i++)
        {
            
            if (fa[i].getStatus() == "poor")
            {
                v.push_back(fa[i]);
                // cout << fa[i].getNameF() << endl;
            }
        }
        return v;
    }
    static vector<Family> findFamilySurename(vector<Family> &fa, string surename)
    {
        vector<Family> v;
        for (int i = 0; i < fa.size(); i++)
        {
            if (fa[i].getNameF() == surename)
            {
                v.push_back(fa[i]);
            }
        }
        return v;
    }
};
class Group
{
private:
    string nameGr;
    vector<Family> f;


public:
    Group() {}
    Group(string name, vector<Family> &f) : nameGr(name), f(f) {}
    void display()
    {
        cout << "Name Group " << nameGr << endl;
        for (int i = 0; i < f.size(); i++)
        {
            f[i].display();
        }
    }
    vector<Family> getF()
    {
        return f;
    }
    int getNumberFamily()
    {
        return f.size();
    }
    static double avgAgeGroup(Group &v)
    {
        vector<Family> F(v.getF());
        double sum = 0;
        int n = 0;
        for (int i = 0; i < F.size(); i++)
        {
            vector<People> P(F[i].getP());
            for (int j = 0; j < P.size(); j++)
            {
                sum += P[j].getAge();
            }
            n += P.size();
        }
        return sum / n;
    }
    static vector<People> getPeopleHaveNotJob(Group &g)
    {
        vector<People> v;
        vector<Family> F(g.getF());
        for (int i = 0; i < F.size(); i++)
        {
            vector<People> P(F[i].getP());
            for (int j = 0; j < P.size(); j++)
            {
                if (P[j].getJob() == "")
                {
                    v.push_back(P[j]);
                }
            }
        }
        return v;
    }
};
int main()
{
    vector<People> people(4);
    people[0] = People("A", 1, "1", "1");
    people[1] = People("B", 2, "2", "1");
    people[2] = People("C", 3, "3", "1");
    people[3] = People("D", 4, "", "1");
    cout << "People:" << endl;
    for (auto &v : people)
        v.display();


    vector<Family> families(2);


    families[0] = Family("HN", "poor", {people[0], people[1]});
    families[1] = Family("SG", "poor", {people[2], people[3]});


    cout << "Poor families:" << endl;
    for (auto &v : Family::getPoorHousehold(families))
        cout << v.getNameF() << endl;


    cout << "Family SurName:" << endl;
    for (auto &v : Family::findFamilySurename(families, "A"))
        v.display();


    cout << "Name group" << endl;
    Group groups("1", families);
    groups.display();


    cout << "Number of families: " << groups.getNumberFamily() << endl;
    cout << "Ave age of group: " << groups.avgAgeGroup(groups) << endl;
    cout << "Unemployment" << endl;
    for (auto &v : Group::getPeopleHaveNotJob(groups))
        v.display();
}


