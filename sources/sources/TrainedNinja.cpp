#include"Ninja.hpp"
#include"TrainedNinja.hpp"
//#pragma once
namespace ariel{
    //TrainedNinja::TrainedNinja(string name, Point location): Ninja(std::move(name), 120, location, 12){}
    TrainedNinja::TrainedNinja(string name, const Point &location): Ninja(name, 120, location, 12){}
}
