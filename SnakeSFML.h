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
  sf::RectangleShape wall_icon1;
  sf::RectangleShape wall_icon2;
  sf::RectangleShape wall_icon3;
  sf::RectangleShape wall_icon4;




  sf::CircleShape food_icon;
  sf::CircleShape snake_icon;
  sf::CircleShape snake_icon2;

  sf::CircleShape eye_icon;

  void draw_eyes(int row, int col,sf::RenderWindow & win);
  
  

public:
explicit SnakeSFML(Snake & snake_sfml,  Board & board_sfml, Manager & manager_sfml);
void draw(sf::RenderWindow & win);


};

#endif