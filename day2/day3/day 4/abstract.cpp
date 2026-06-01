#include<iostream>
#include<string>
using namespace std;
class shape{
    protected:
    string color;
    public:
    shape(string c):color(c){}
    virtual double area() const=0;
    virtual void draw() const=0;
    string getcolor() const{
        return color;
    }
    virtual ~shape(){};
};
class circle:public shape{
    private:
    double radius;
    public:
    circle(string c,double r):shape(c),radius(r){}
    double area() const override{
        return 3.14159*radius*radius;
    }
    void draw() const override{
        cout<<"Drawing a "<<color<<" circle with radius "<<radius<<endl;
    }
};
int main(){
    shape*shape[2];
    shape[0]=new circle("red",5.0);
    shape[1]=new circle("blue",3.0);
    for(int i=0;i<2;i++){
        shape[i]->draw();
        
    }
    for(int i=0;i<2;i++){
        delete shape[i];
    }
    return 0;
}