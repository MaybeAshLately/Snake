#include "SnakeSFML.h"
#include <iostream>

SnakeSFML::SnakeSFML(Snake & snake_sfml,  Board & board_sfml, Manager & manager_sfml): snake_sfml(snake_sfml), board_sfml(board_sfml), manager_sfml(manager_sfml)
{
  
  wall_icon.setSize(sf::Vector2f(10,10));
  wall_icon.setFillColor(sf::Color(160,160,160));

  wall_icon1.setSize(sf::Vector2f(10,1));
  wall_icon1.setFillColor(sf::Color::Black);
  wall_icon2.setSize(sf::Vector2f(10,1));
  wall_icon2.setFillColor(sf::Color::Black);
  wall_icon3.setSize(sf::Vector2f(1,10));
  wall_icon3.setFillColor(sf::Color::Black);
  wall_icon4.setSize(sf::Vector2f(1,10));
  wall_icon4.setFillColor(sf::Color::Black);


  food_icon.setRadius(4);
  food_icon.setFillColor(sf::Color(255,255,0));

  snake_icon.setRadius(6);
  snake_icon.setFillColor(sf::Color(0,204,0));
  snake_icon.setOutlineThickness(1);
  snake_icon.setOutlineColor(sf::Color::Black);
  snake_icon2.setRadius(3);
  snake_icon2.setFillColor(sf::Color::Red);

  eye_icon.setRadius(2);
  eye_icon.setFillColor(sf::Color(0,0,204));

  
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
        wall_icon1.setPosition(col*10,row*10+3);
        win.draw(wall_icon1);
        wall_icon2.setPosition(col*10,row*10+7);
        win.draw(wall_icon2);
        wall_icon3.setPosition(col*10+3,row*10);
        win.draw(wall_icon3);
        wall_icon4.setPosition(col*10+7,row*10);
        win.draw(wall_icon4);

      }
      else if(board_sfml.field_has_food(row,col)==true)
      {
        
        food_icon.setPosition(col*10+2,row*10+2);
        win.draw(food_icon);
      }
      else if(board_sfml.is_snake_on_field(row,col)==true)
      {
        snake_icon.setPosition(col*10,row*10);
        //win.draw(snake_icon);
        if(snake_sfml.is_cell_head(row,col)==true) 
        { 
          snake_icon.setFillColor(sf::Color(150,110,0));
          win.draw(snake_icon);
          snake_icon.setFillColor(sf::Color(0,204,0));
           draw_eyes(row,col, win);
           
        }
        else 
        {
          win.draw(snake_icon);
          snake_icon2.setPosition(col*10+3,row*10+3);
          win.draw(snake_icon2);
        } 
  
      }
    }
  }

 /*
 if(snake_sfml.is_alive()) manager_sfml.play();
 else std::cout<<"TEST"<<std::endl;
  */
  manager_sfml.play();
}


//funkcja pomocnicza rysująca oczy 
void SnakeSFML::draw_eyes(int row, int col,sf::RenderWindow & win)
{
   
    eye_icon.setPosition(col*10+2,row*10+3);
   win.draw(eye_icon);
    eye_icon.setPosition(col*10+8,row*10+3);
    win.draw(eye_icon);
    
  
}