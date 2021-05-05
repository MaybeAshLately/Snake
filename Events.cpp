#include "Events.h"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Snake.h"
#include "Board.h"
#include "Manager.h"
#include "SnakeSFML.h"
#include <iostream>

Events::Events(Snake & snake_control,Board & board_control,Manager & manager_control,SnakeSFML & sfml_control): snake_control(snake_control), board_control(board_control), manager_control(manager_control), sfml_control(sfml_control)
{

}


void Events::key_was_pressed(sf::Event event)
{
  
  if(event.key.code==sf::Keyboard::Left)
  {
    snake_control.move_corner_left();
    
  }
  else if(event.key.code==sf::Keyboard::Right)
  {
       snake_control.move_corner_right();
  }
  
}