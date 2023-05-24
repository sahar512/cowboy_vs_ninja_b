#include"Ninja.hpp"
#include"YoungNinja.hpp"
//#pragma once
using namespace ariel; 
using namespace std; 
    //YoungNinja(string name, Point &location): Ninja(std::move(name), 100, location, 14){}
    YoungNinja::YoungNinja(string name, const Point &location): Ninja(name, 100, location, 14){}
                
   
