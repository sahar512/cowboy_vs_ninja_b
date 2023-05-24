#include"Ninja.hpp"
#pragma once
namespace ariel{
    class OldNinja: public Ninja{
        // public:
        //     OldNinja(string name, Point &location): Ninja(std::move(name), 150, location, 8){}
        //     OldNinja(string name, Point &&location): Ninja(std::move(name), 150, location, 8){} 
        public:
        OldNinja(std::string name,const Point &location); 

    };

}

