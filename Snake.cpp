#include "Snake.h"
#include <iostream>
#include <vector>


//KONSTRUKTOR
//wąż ma domyślnie długość jeden, znajduje się w polu 1,1 i kieruje się na wschód 
Snake::Snake(std::string name): snake_name(name)
{
  snake_cells.push_back(sf::Vector2f(1,1));

  length=static_cast<int>(snake_cells.size());
  move_to=SOUTH;
 
  alive=true;
  move_corner=ANY;
}





//funkcja aktualizująca położenie głowy węża w zależności od kierunku ruchu
void Snake::update_head_position()
{
  switch(move_to)
  {
    case NORTH:
    {
      snake_cells[0]=snake_cells[0]+sf::Vector2f(-1,0);
    }
    break;
    case SOUTH:
    {
       snake_cells[0]=snake_cells[0]+sf::Vector2f(1,0);
    }
    break;
    case EAST:
    {
      
       snake_cells[0]=snake_cells[0]+sf::Vector2f(0,1);
    }
    break;
    case WEST:
    {
       snake_cells[0]=snake_cells[0]+sf::Vector2f(0,-1);
    }
    break;
    default:
    {
      exit(-1);
    }
  }
 
}


//aktualizuje pozycję węża
void Snake::update_position()
{
   
   int size;
   size=static_cast<int>(snake_cells.size());
   std::vector <sf::Vector2f> snake_bufor;
   snake_bufor=snake_cells;
   update_head_position();
   if(size==1) return;

   for(int i=1;i<size;i++)
   {
     snake_cells[i]=snake_bufor[i-1];
   }
}


//AKTUALIZUJE POZYCJĘ WĘŻA
void Snake::update()
{
  if(move_corner==RIGHT)
  {
    turn_right();
  }
  else if(move_corner==LEFT)
  {
    turn_left();
  }
  
  update_position();
}


//SKRĘCA W PRAWO
void Snake::turn_right()
{
   switch(move_to)
   {
     case NORTH:
     {
      move_to=EAST;
     }
     break;
     case SOUTH:
     {
      move_to=WEST;
     }
     break;
     case WEST:
     {
        move_to=NORTH;
     }
     break;
     case EAST:
     {
      move_to=SOUTH;
     }
     break;
     default:
     {
       exit(-1);
     }
   }
   move_corner=ANY;
}

//SKRĘCA W LEWO
void Snake::turn_left()
{
   switch(move_to)
   {
     case NORTH:
     {
      move_to=WEST;
     }
     break;
     case SOUTH:
     {
      move_to=EAST;
     }
     break;
     case WEST:
     {
        move_to=SOUTH;
     }
     break;
     case EAST:
     {
      move_to=NORTH;
     }
     break;
     default:
     {
       exit(-1);
     }
   }
   move_corner=ANY;
}


//ZWRACA DŁUGOŚĆ WĘŻA
int Snake::get_snake_length() const
{
   return static_cast<int>(snake_cells.size());
}
  
//ZWRACA KIERUNEK RUCHU WĘŻA  
Directions Snake::get_snake_direction() const
{
  return move_to;
}

//ZWRACA IMIĘ WĘŻA 
std::string Snake::get_snake_name() const
{
  return snake_name;
}

//ZWRACA TRUE JEŚLI WĄŻ ŻYJE, FALSE JEŚLI NIE 
bool Snake::is_alive() const
{
  return alive;
}


//ZWRACA POZYCJĘ ŻĄDANEJ CZĘŚCI WĘŻA
sf::Vector2f Snake::get_position_of_cell(int number)
{
 if((number<0)or(number>static_cast<int>(snake_cells.size())-1)) return sf::Vector2f(-1,-1);
 return snake_cells[number];
}

//SYGNALIZUJE ŻE WĄŻ UMARŁ
void Snake::snake_died()
{
  alive=false;
}


//Dodaje fragment węża
void Snake::add_cell(sf::Vector2f cell)
{
  
  snake_cells.push_back(cell);

  
}


void Snake::move_corner_left()
{
  move_corner=LEFT;
}

void Snake::move_corner_right()
{
  move_corner=RIGHT;
}



//funkcja sprawdzająca czy komórka na danym polu jest głową węża
bool Snake::is_cell_head(int row,int col)
{
  sf::Vector2f find(row,col);
  if(find==get_position_of_cell(0)) return true;
  return false;
}



//Zwraca ciało węża
std::vector <sf::Vector2f> Snake::return_body()
{
  return snake_cells;
}