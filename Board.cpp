#include "Board.h"
#include <cstdlib>
#include <iostream>

//KONSTRUKTOR
Board::Board(Snake & snake_body ,const Level g_level): snake_body(snake_body), game_level(g_level)
{
   for(int row=0;row<60;row++)
  {
    for(int col=0;col<80;col++)
     {
       fields[row][col].has_food=false;
       fields[row][col].has_wall=false;
     }
    
  }


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
        if((row==1)and(col==1)) continue;
        
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
  for(int col=0;col<80;col++)
  {
    fields[0][col].has_wall=true;
  }
  
  for(int row=0;row<60;row++)
  {
    fields[row][79].has_wall=true;
  }
  for(int col=0;col<80;col++)
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
  if(game_level==EASY) number_of_walls=250;
  else if(game_level==MEDIUM) number_of_walls=300;
  else number_of_walls=350;
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
 


  //ZWRACA PRAWDĘ JEŚLI POLE MA PRZESZKODĘ
  bool Board::field_has_wall(int row,int col)
  {
     if(fields[row][col].has_wall==true) return true;
     return false;
  }


  //ZWRACA PRAWDĘ JEŚLI POLE MA JEDZENIE
  bool Board::field_has_food(int row,int col)
  {
    
     if(fields[row][col].has_food==true) return true;
     
     return false;
  }


//USUWA JEDZENIE Z POLA
void Board::eat(int row, int col)
{
  
 fields[row][col].has_food=false;
}


//zwraca prawdę jeśli na polu jest część węża
bool Board::is_snake_on_field(int row, int col)
{
  int size=snake_body.get_snake_length();
  for(int i=0; i<size;i++)
  {
    sf::Vector2f vec=sf::Vector2f(row,col);
    if(vec==snake_body.get_position_of_cell(i)) return true;
  }
  return false;
}