#include "Board.h"
#include <cstdlib>

//KONSTRUKTOR
Board::Board(Snake & snake_body ,const Level g_level): snake_body(snake_body), game_level(g_level)
{
  generate_walls();
  generate_food();

}


//generuje położenie jedzenia
void Board::generate_food()
{
  int number_of_food=300;
  int placed_food=0;
  int row,col;
  
  while(placed_food!=number_of_food)
  {
        col=rand()%79;
        row=rand()%59;
       if((fields[row][col].has_wall==false)and(fields[row][col].has_food==false))
       {
         fields[row][col].has_food=true;
         placed_food++;
       }     
  }


}

//pomocnicza funkcja generująca zewnętrzne ściany
void Board::generate_outside_walls()
{
  for(int row=0;row<60;row++)
  {
    fields[row][0].has_wall=true;
  }
  for(int col=0;col<60;col++)
  {
    fields[0][col].has_wall=true;
  }
  
  for(int row=0;row<60;row++)
  {
    fields[row][79].has_wall=true;
  }
  for(int col=0;col<60;col++)
  {
    fields[59][col].has_wall=true;
  }

}

//generuje przeszkody (w lewym górnym rogu mała przestrzeń bez przeszkód aby nie wszedł umarł od razu po starcie)
void Board::generate_walls()
{
  generate_outside_walls();
  int number_of_walls=0;
  int placed_walls=0;
  if(game_level==EASY) number_of_walls=150;
  else if(game_level==MEDIUM) number_of_walls=200;
  else number_of_walls=250;
  int row,col;
  
  while(placed_walls!=number_of_walls)
  {
        col=rand()%79;
        row=rand()%59;
       if((col<11)and(row<11)) continue;
       if(fields[row][col].has_wall==false)
       {
         fields[row][col].has_wall=true;
         placed_walls++;
       }     
  }

}

//ZWRACA POZIOM TRUDNOŚCI GRY
Level Board::get_game_level() const
{
  return game_level;
}
 