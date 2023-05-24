#include"Character.hpp"
#include<iostream>
using namespace ariel; 
//namespace ariel{}
// Character::Character(string name, int characterHit , const Point &location):name(std::move(name)),characterHit(characterHit),location(const_cast<Point&>(location)),InTeam(false) {

// }  
// Character::Character(const Character& other): name(other.name),characterHit(other.characterHit), location(other.location),InTeam(other.InTeam){}
// Character::Character(Character&& other)noexcept: name(move(other.name)),characterHit(other.characterHit),location(other.location){
//     other.characterHit=0; 
// }
// Character& Character::operator=(const Character& other){
//     if(this!= &other){
//         characterHit=other.characterHit; 
//         name= other.name; 
//         //name=move(other.name); 
//         //other.characterHit=0; 
//     }
//     return *this; 
// }
// Character& Character::operator=(Character&& other)noexcept{
//     if(this!= &other){
//         characterHit=other.characterHit; 
//         name= move(other.name); 
//         //name=move(other.name); 
//         other.characterHit=0; 
//     }
//     return *this; 
// }





bool Character::isAlive()const{ //return true if characterhit points >0
    return (characterHit>0); 
        
}
double Character::distance(Character *other)const{ //calculate the distamce between two characters
if(other == nullptr){
    throw invalid_argument("character is null"); 
}
    Point CLocation = other->getLocation(); 
    return this->location.distance(CLocation); 
       
}
void Character::hit(int HitPoints){ // reduse the hit points from the characters point 
    //this->characterHit -=characterHit;
    if(HitPoints <0){
        throw invalid_argument("cant be smaller than zero!!"); 
    } 
    characterHit-= HitPoints;

}
// bool Character::InTeamm(){
//     return InTeam; 
// }
//getters
bool Character::getInTeam() const{
    return InTeam; 
}
void Character::setInTeam(bool InTeam){
    this->InTeam=InTeam; 
}
const Point& Character::getLocation()const{
    return location; 

}
string Character::getName()const{
    return name; 
    
}
int Character::getCharacterHit()const{
    return characterHit; 

}
//setters
void Character::setName(string name){
    this->name=name; 
}
void Character::setLocation(const Point& location ){
    this->location= location; 

}
void Character::setCharacterHit(int characterHit){
    this->characterHit= characterHit; 

}




