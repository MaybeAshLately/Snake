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

//skręcanie strzałkami
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


//klikanie 
void Events::mouse_button_pressed(sf::Event event)
{
  if(sfml_control.get_app_state()==INSTRUCTION) instruction_control(event);
  else if(sfml_control.get_app_state()==ALIVE) return;
  else if(sfml_control.get_app_state()==DIED) died_control(event);
}



void Events::died_control(sf::Event event)
{
  if(event.mouseButton.button==1) return; //prawy

  int x=event.mouseButton.x;
  int y=event.mouseButton.y;

  if((x>280)and(x<530)and(y>290)and(y<340))
    sfml_control.zobacz_wyniki_pressed();
    
}


void Events::instruction_control(sf::Event event)
{
  if(event.mouseButton.button==1) return; //prawy

  int x=event.mouseButton.x;
  int y=event.mouseButton.y;

  if((x>330)and(x<580)and(y>380)and(y<430))
    sfml_control.rozpocznij_pressed();
}