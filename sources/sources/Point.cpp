#include"Point.hpp"
#include<math.h>
#include<string>
#include<iostream>
using namespace std; 
using namespace ariel; 
Point::Point(double x, double y): x(x), y(y){}
//getters
double Point::getX()const{
    return x; 
}
double Point::getY()const{
    return y; 
}
//setters
void Point::setX(double x){
    x=x; 
}
void Point::setY(double y){
    y=y; 
}
double Point::distance(const Point& point)const{
     double distansee= sqrt(pow(point.getX()-this->x,2)+pow(point.getY()-this->y,2));  
     return distansee;
    
}
void Point::Print(){
    cout<<"(" <<this->getX()<<","<<this->getY()<<")"<<endl; 
}
Point Point::moveTowards(const Point& sources ,const Point& dest,const double dist){
    if(dist<0){
        throw invalid_argument("distance can not be negative!!");
    }
    double dist0= sources.distance(dest); 
    if(dist0 <= dist ){
        return dest; 
    }
    else{
        double dist1= dist/dist0; 
        double dx = dest.getX()- sources.getX(); 
        double dy = dest.getY() - sources.getY(); 
        Point ans= Point(sources.getX()+dist1*dx , sources.getY()+dist1*dy); 
        return ans; 
    }



   
}
