#include"Ninja.hpp"
//#include"Character.hpp"

#include<iostream>
//#pragma once
using namespace std; 
namespace ariel{
    Ninja::Ninja(string name, int hitpoints, const Point &location , int speed):Character(name, const_cast<Point&>(location) ,hitpoints),speed(speed){}
    //Ninja::~Ninja(){} //destructor
    //Ninja::Ninja(string name, int hitpoints, Point location , int speed): Character(name, hitpoints,location), speed(speed) {} 

    void Ninja::move(Character *enemy ){
        // if(this->isAlive()){
        //     if(this->getLocation().distance(enemy->getLocation())> this->speed){
        //         double x0 = this->getLocation().getX()+(this->speed *(enemy->getLocation().getX()-this->getLocation().getX()))/(this->getLocation().distance(enemy->getLocation()));
        //         double y0 = this->getLocation().getY()+(this->speed*(enemy->getLocation().getY()-this->getLocation().getY()))/(this->getLocation().distance(enemy->getLocation())); 
        //         this->setLocation(Point(x0,y0));

        //     }
        //     else{
        //         this->setLocation(enemy->getLocation()); 
        //     }
        // }

        if (enemy == nullptr)
            throw invalid_argument("cant move to null character");

        else if (this == enemy)
            throw runtime_error("cant move to itself");

        else if (!isAlive())
            throw runtime_error("cant move dead character");

        else if (!enemy->isAlive())
            throw runtime_error("cant move to dead character");

        Point newLocation = Point::moveTowards(getLocation(), enemy->getLocation(), speed);
        setLocation(newLocation);
    }
    void Ninja::slash(Character *enemy){
        if(!isAlive()) 
        throw runtime_error("cant attack dead character");
        if(this==enemy) 
        throw runtime_error("cant attack it self"); 
        
        if(!enemy->isAlive())
        throw runtime_error("cant attack dead ");
        if(getLocation().distance(enemy->getLocation())<=1)
        enemy->hit(40); 
    }
    string Ninja::print()const{
        string Ninjaaa ;
        Ninjaaa="name: N "+getName();
        if(isAlive())
        Ninjaaa +="HP: "+to_string(getCharacterHit());
        Ninjaaa +="Location: ("+ to_string(getLocation().getX())+","+ to_string(getLocation().getY()) + ")";
        
        
        return Ninjaaa; 
    }
    
}