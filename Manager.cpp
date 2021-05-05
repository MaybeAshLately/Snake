#include "Manager.h"
#include <iostream>

Manager::Manager(Snake & snake_body, Board & snake_board):snake_body(snake_body), snake_board(snake_board) 
{
  
}


void Manager::movement()
{
  
  sf::Vector2f last_position;
  int size=snake_body.get_snake_length();
  last_position=snake_body.get_position_of_cell(size-1);

  snake_body.update();
  sf::Vector2f head_position=snake_body.get_position_of_cell(0);
  int row,col;
  row=head_position.x;
  col=head_position.y;

  if(snake_board.field_has_wall(row,col)==true)
  {
    snake_body.snake_died();
  }

  if(snake_board.field_has_food(row,col)==true)
  {
    
    snake_body.add_cell(last_position);
    
    snake_board.eat(row,col);
    score++;
    
   
  }

 
}

void Manager::play()
{
  if(snake_body.is_alive()==true)
  {
    if(clk.getElapsedTime().asSeconds()>0.2)
     {
      movement();
     clk.restart();
     }
  }
  else
  {
    //tu będzie obsługa tego co się stanie po game over
    std::cout<<"GAME OVER"<<std::endl;
    
  }
  
   
}


