#include"Ninja.hpp"
#pragma once
namespace ariel{
    class TrainedNinja: public Ninja{
        public: 
            TrainedNinja(string name, const Point &location);
            //TrainedNinja(string name, Point &&location): Ninja(std::move(name), 120, location, 12){} 

    };

}
