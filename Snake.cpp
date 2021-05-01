#include "Snake.h"

//KONSTRUKTOR
//wąż ma domyślnie długość jeden, znajduje się w polu 1,1 i kieruje się na wschód 
Snake::Snake(std::string name): snake_name(name)
{
  snake_cells.push_back(sf::Vector2f(1,1));
  length=static_cast<int>(snake_cells.size());
  move_to=EAST;
  alive=true;
}



void Snake::update()
{

}


//ZWRACA DŁUGOŚĆ WĘŻA
int Snake::get_snake_length() const
{
   return length;
}
  
//ZWRACA KIERUNEK RUCHU WĘŻA  
Directions Snake::get_snake_direction() const
{
  return move_to;
}

//ZWRACA IMIĘ WĘŻA 
std::string Snake::get_snake_name() const
{
  return snake_name;
}

//ZWRACA TRUE JEŚLI WĄŻ ŻYJE, FALSE JEŚLI NIE 
bool Snake::is_alive() const
{
  return alive;
}