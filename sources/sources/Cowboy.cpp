#include "Cowboy.hpp"
#include <iostream>
using namespace std;
using namespace ariel;
// Cowboy::Cowboy(const std::string& name, const Point& location ):
// (std::move(name),location,11) ,bullets(6){}
// Cowboy::Cowboy(string name, Point &location) : bullets(6), Character(std::move(name), 11, location){}
// Cowboy::Cowboy(string name, Point &&location) : bullets(6), Character(std::move(name), 11, location){}
// Cowboy::Cowboy(string name , const Point &location): Character(name,110, const_cast<Point&> (location)), bullets(6){}
// Cowboy::Cowboy(const Cowboy& other):Character(other), bullets(other.bullets){}
// Cowboy& Cowboy::operator=(const Cowboy& other){
//     if(this!=&other){
//         Character::operator=(other);
//         bullets=other.bullets;
//     }
//     return *this;
// }
// Cowboy::Cowboy(Cowboy&& other)noexcept: Character(move(other)),bullets(other.bullets){
//     other.bullets=0;
// }
// Cowboy& Cowboy::operator=(Cowboy&& other)noexcept{
//     if(this!=&other){
//         Character::operator=(std::move(other));
//         bullets=other.bullets;
//         other.bullets=0;
//     }
//     return *this;
// }
// Cowboy::~Cowboy(){}; //destructor
Cowboy::Cowboy(string name, const Point &location) : Character(name, location, 110), bullets(6) {}

void Cowboy::shoot(Character *enemy)
{
    if (enemy == nullptr)
        throw invalid_argument("Null!!");
    else if (enemy == this)
        throw runtime_error("cannt attack self");
    else if (!isAlive())
        throw runtime_error("Cowboy is dead!!");
    else if (!enemy->isAlive())
        throw runtime_error("cant attack dead character");
    if (hasboolets())
    {
        enemy->hit(10);
        this->bullets -= 1;
    }
}
// reload the cowboy gun with 6 new bullets
void Cowboy::reload()
{
    if (!isAlive())
        throw runtime_error("Cowboy is dead!!");
    this->bullets = 6;
}
// return true if the cowboy has bullets left
bool Cowboy::hasboolets()
{
    return this->bullets > 0;
}
string Cowboy::print() const
{
    string Cowboyyy = "Cowboy";
    // if(!isAlive())
    //     return "Name: C (" + getName()+ " ), Location: "+ getLocation().Print();
    // return "Name :C "+ getName()+" , hitPoints : "+ to_string(getCharacterHit())+ ", Location: "+ getLocation().Print();
    return Cowboyyy;
}
