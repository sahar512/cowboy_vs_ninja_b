#include"Ninja.hpp"
#pragma once
namespace ariel{
    class YoungNinja: public Ninja{
        public:
            YoungNinja(string name, const Point &location);
            //YoungNinja(string name, Point &&location): Ninja(std::move(name), 100, location, 14){} 


    };

}