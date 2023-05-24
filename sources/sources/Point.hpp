#pragma once
namespace ariel{
    class Point{
    private:
        double x ; 
        double y; 
    public:
        //constructor
        Point(double x, double y);
        //getters
        double getX()const; 
        double getY()const; 
        //setters
        void setX(double x); 
        void setY(double y); 
        //get the distance between two points
        double distance (const Point& point)const; 
        //print the x,y to this point 
        void Print(); 
        //return the closets point to the destination point 
        static Point moveTowards(const Point& sources ,const Point& dest,const double dist);  

      

};

};
