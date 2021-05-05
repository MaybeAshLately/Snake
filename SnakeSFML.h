#ifndef SNAKESFML_H
#define SNAKESFML_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Snake.h"
#include "Board.h"
#include "Manager.h"
//Ta klasa odpowiada za wyświetlanie rozgrywki w trybie graficznym 

class SnakeSFML
{

  Snake &snake_sfml;
  Board &board_sfml;
  Manager &manager_sfml;

  sf::RectangleShape wall_icon;
  sf::RectangleShape food_icon;
  sf::RectangleShape snake_icon;
  

public:
explicit SnakeSFML(Snake & snake_sfml,  Board & board_sfml, Manager & manager_sfml);
void draw(sf::RenderWindow & win);


};

#endif