#include "SnakeSFML.h"
#include <iostream>

SnakeSFML::SnakeSFML(Snake & snake_sfml,  Board & board_sfml, Manager & manager_sfml): snake_sfml(snake_sfml), board_sfml(board_sfml), manager_sfml(manager_sfml)
{
  
  wall_icon.setSize(sf::Vector2f(10,10));
  wall_icon.setFillColor(sf::Color(160,160,160));

  snake_icon.setSize(sf::Vector2f(10,10));
  snake_icon.setFillColor(sf::Color(0,255,0));

  food_icon.setSize(sf::Vector2f(10,10));
  food_icon.setFillColor(sf::Color(255,255,0));
}



void SnakeSFML::draw(sf::RenderWindow & win)
{
  for(int row=0;row<60;row++)
  {
    for(int col=0;col<80;col++)
    {
      if(board_sfml.field_has_wall(row,col)==true)
      {
        wall_icon.setPosition(col*10,row*10);
        win.draw(wall_icon);
      }
      else if(board_sfml.field_has_food(row,col)==true)
      {
        food_icon.setPosition(col*10,row*10);
        win.draw(food_icon);
      }
      else if(board_sfml.is_snake_on_field(row,col)==true)
      {
        snake_icon.setPosition(col*10,row*10);
        win.draw(snake_icon);
      }
    }
  }

 /*
 if(snake_sfml.is_alive()) manager_sfml.play();
 else std::cout<<"TEST"<<std::endl;
  */
  manager_sfml.play();
}