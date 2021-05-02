#include "Manager.h"
#include <iostream>

Manager::Manager(Board & snake_board,Snake & snake_body): snake_board(snake_board), snake_body(snake_body)
{

}



void Manager::play()
{
  
  

  if(clk.getElapsedTime().asSeconds()>0.2)
  {
    snake_body.update();
    
    clk.restart();
  }
  

  
}