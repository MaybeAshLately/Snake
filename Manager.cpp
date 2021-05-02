#include "Manager.h"
#include <iostream>

Manager::Manager(Board & snake_board,Snake & snake_body): snake_board(snake_board), snake_body(snake_body)
{

}


void Manager::movement()
{
  //zaktualizować ciało węża
  //sprawdzić czy głowa nie jest na przeszkodzie jeśli tak to ustawić że nie żyje 
  //sprawdzić czy głowa zjadła jedzenie jeśli tak to wydłużyć, usunąć jedzenie z danego pola
  sf::Vector2f last_position;
  int size=snake_body.get_snake_length();
  last_position=snake_body.get_position_of_cell(size-1);

  snake_body.update();
  sf::Vector2f head_position=snake_body.get_position_of_cell(0);
  int row,col;
  row=head_position.y;
  col=head_position.x;

  if(snake_board.field_has_wall(row,col)==true)
  {
    snake_body.snake_died();
  }

  if(snake_board.field_has_food(row,col)==true)
  {
    
    snake_body.add_cell( last_position);
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
  }
  
   
}


