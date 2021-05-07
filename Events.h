#ifndef EVENTS_H
#define EVENTS_H
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Snake.h"
#include "Board.h"
#include "Manager.h"
#include "SnakeSFML.h"
/*
Ta klasa odpowiada za obsługę zdarzeń 
*/

class Events
{
  Snake & snake_control;
  Board & board_control;
  Manager & manager_control;
  SnakeSFML & sfml_control;
  
  void died_control(sf::Event event);
  
  public:
  explicit Events(Snake & snake_control,Board & board_control,Manager & manager_control,SnakeSFML & sfml_control);
  void key_was_pressed(sf::Event event);

  void mouse_button_pressed(sf::Event event);
  
  

};

#endif