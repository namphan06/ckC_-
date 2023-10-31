#include <iostream>
#include <vector>
using namespace std;
class Score{
    protected:
    double math;
    double literature;
    double english;
    public:
    Score(){}
    Score(double math, double literature, double english):math(math),literature(literature),english(english){}
    double getMath(){
        return math;
    }
    double getLiterature(){
        return literature;
    }
    double getEnglish(){
        return english;
    }
    virtual double pointA(){
        return 0;
    }
    virtual double pointB(){
        return 0;
    }
    virtual double pointC(){
        return 0;
    }
    virtual double pointD(){
        return math + literature + english;
    }
    virtual double avgPoint() = 0; 
    virtual void display()
    {
        cout << "Avg = " << avgPoint() << endl;
    }

    bool isPass(){
        if(avgPoint()>5){
            return true;
        }
        else{
            return false;
        }
    }
    static double getMaxAvg(vector<Score *> vt){
        double max=0;
        for(int i=0;i<vt.size();i++){
            if(max<vt[i]->avgPoint()){
                max = vt[i]->avgPoint();
            }
        }
        return max;
    }
    static double getMinAvg(vector<Score *> vt){
        double min = vt[0]->avgPoint();
        for(int i =0;i<vt.size();i++){
            if(min<vt[i]->avgPoint()){
                min = vt[i]->avgPoint();
            }
        }
        return min;
    }
    static double getMaxPointA(vector<Score *> vt)
     {
        double max = vt[0]->pointA();
        for (int i = 1; i < vt.size(); i++)
        {
            if (vt[i]->pointA() > max)
            {
                max = vt[i]->pointA();
            }
        }
        return max;
    }
    static double getMaxPointD(vector<Score *> vt)
    {
        double max = vt[0]->pointD();
        for (int i = 1; i < vt.size(); i++)
        {
            if (vt[i]->pointD() > max)
            {
                max = vt[i]->pointD();
            }
        }
        return max;
    }
    static double getMaxPointB(vector<Score *> vt)
    {
        double max = vt[0]->pointB();
        for (int i = 1; i < vt.size(); i++)
        {
            if (vt[i]->pointB() > max)
            {
                max = vt[i]->pointB();
            }
        }
        return max;
    }
    static double getMaxPointC(vector<Score *> vt)
    {
        double max = vt[0]->pointA();
        for (int i = 1; i < vt.size(); i++)
        {
            if (vt[i]->pointC() > max)
            {
                max = vt[i]->pointC();
            }
        }
        return max;
    }

};
class ScoreNatural : public Score
{
private:
    double physic;
    double chemistry;
    double biology;


public:
    ScoreNatural() {}
    ScoreNatural(double math, double literature, double english, double physic, double chemistry, double biology)
        : Score(math, literature, english), physic(physic), chemistry(chemistry), biology(biology) {}
    double getPhysic()
    {
        return physic;
    }
    double getChemistry()
    {
        return chemistry;
    }
    double getBiology()
    {
        return biology;
    }
    double pointA()
    {
        return math + chemistry + physic;
    }
    double pointB()
    {
        return math + chemistry + biology;
    }
    double pointNatual()
    {
        return physic + chemistry + biology;
    }
    double avgPoint()
    {
        return (physic + chemistry + biology + math + literature + english) / 6;
    }
};
class ScoreSocial : public Score
{
private:
    double ce;
    double geography;
    double history;


public:
    ScoreSocial() {}
    ScoreSocial(double math, double literature, double english, double ce, double geography, double history) : Score(math, literature, english), ce(ce), geography(geography), history(history) {}
    double getCe()
    {
        return ce;
    }
    double getGeography()
    {
        return geography;
    }
    double getHistory()
    {
        return history;
    }
    double pointC()
    {
        return literature + history + geography;
    }
    double pointSocial()
    {
        return literature + history + geography;
    }
    double avgPoint()
    {
        return (literature + history + geography + math + literature + english) / 6;
    }
};
int main()
{
    vector<ScoreNatural> naturals(3);
    naturals[0] = ScoreNatural(1, 1, 1, 1, 1, 1);
    naturals[1] = ScoreNatural(2, 2, 2, 2, 2, 2);
    naturals[2] = ScoreNatural(3, 3, 3, 3, 3, 3);


    vector<ScoreSocial> socials(3);
    socials[0] = ScoreSocial(1, 1, 1, 1, 1, 1);
    socials[1] = ScoreSocial(2, 2, 2, 2, 2, 2);
    socials[2] = ScoreSocial(3, 3, 3, 3, 3, 3);


    for (auto &v : naturals)
        if (v.isPass())
            v.display();


    for (auto &v : socials)
        cout << v.avgPoint() << endl;


    vector<Score *> scores({&naturals[0], &naturals[1], &socials[0]});
    for (auto &v : scores)
        v->avgPoint();


    cout << "Trung binh lon nhat:" << Score::getMaxAvg(scores) << endl;
    cout << "Trung binh nho nhat:" << Score::getMinAvg(scores) << endl;
    cout << "Trung binh lon nhat khoi A:" << Score::getMaxPointA(scores) << endl;
    cout << "Trung binh lon nhat khoi B:" << Score::getMaxPointB(scores) << endl;
    cout << "Trung binh lon nhat khoi C:" << Score::getMaxPointC(scores) << endl;
    cout << "Trung binh lon nhat khoi D:" << Score::getMaxPointD(scores) << endl;
}




