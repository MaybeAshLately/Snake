#include "Manager.h"
#include "Board.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <errno.h>
#include <string>

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
  else if(counter==0)
  {
   snake_is_dead();
   counter++;
    
  }
  
   
}


void Manager::snake_is_dead()
{
  std::cout<<"PUNKTY: "<< score<<std::endl;

  std::fstream plik("/home/runner/Snake/plik.txt",std::ios_base::app);


  if(!plik)
  {
    std::cerr<<"Błąd: "<<strerror(errno)<<std::endl;
    exit(-1);
  }

  plik<<snake_body.get_snake_name()<<" ";
  Level level=snake_board.get_game_level();
  std::string level_name;

  if(level==EASY) level_name="EASY";
  else if(level==MEDIUM) level_name="MEDIUM";
 else level_name="HARD";

  plik<<level_name<<" "<<score<<std::endl;
  plik.close();

}