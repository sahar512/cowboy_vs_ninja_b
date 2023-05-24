#include "Ninja.hpp"
#include"OldNinja.hpp"
namespace ariel{
   //OldNinja::OldNinja(string name, Point location):
   // OldNinja::OldNinja(string name, Point location): Ninja(std::move(name), 150, location, 8){} 
    //OldNinja::OldNinja(string name, Point location): Ninja(name, 150, location, 8){} 
    OldNinja::OldNinja(string name,const Point &location):Ninja(name, 150,const_cast<Point&>(location), 8){

    }
}