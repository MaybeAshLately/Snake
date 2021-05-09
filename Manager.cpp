#include "Manager.h"
#include "Board.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <errno.h>
#include <string>
#include <sstream>


//Konstruktor
Manager::Manager(Snake & snake_body, Board & snake_board):snake_body(snake_body), snake_board(snake_board) 
{
  
}

//----------------------------------
//1. Przeprowadzanie rozgrywki 

//przeprowadzanie rozgrywki--> wywoływanie odpowiednich funkcji 
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

//symulowanie ruchu (w tym sprawdzanie czy wąż coś zjadł/umarł i jeśli tak wywołuje odpowiednie funkcje)
void Manager::movement()
{
  std::vector <sf::Vector2f> snake_bufor;
  snake_bufor=snake_body.return_body();
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
  else if(snake_hit(snake_bufor,row,col)==true)
  {
    snake_body.snake_died();
  }
  else if(snake_board.field_has_food(row,col)==true)
  {
    snake_body.add_cell(last_position);
    snake_board.eat(row,col);
    score++;
  } 
}

//Sprawdza czy wąż uderzył głową w ciało
bool Manager::snake_hit(std::vector <sf::Vector2f>& snake_bufor,int row,int col)
{
  for(size_t i=0;i<snake_bufor.size();i++)
  {
    if(snake_bufor[i]==sf::Vector2f(row,col)) return true;
  }
   return false;
}

//wąż umarł--> zapis do pliku
void Manager::snake_is_dead()
{
  std::ifstream plik("/home/runner/Snake/plik.txt");

  if(!plik)
  {
    std::cerr<<"Błąd: "<<strerror(errno)<<std::endl;
    exit(-1);
  }
  
  int idx=0;
    while(plik)
    {
      results.push_back("");      
      getline(plik, results[idx]);
    idx++;
    }
   if(results.size()>10) number_of_position=vec_full(); 
   else number_of_position=vec_not_full();

  plik.close();
    if(number_of_position==-1) 
    {
      one_of_winner_game=0;
      return;
    }
    
  if(results.size()>10) 
  {
    vec_ten(number_of_position);
  }
  else
  {
    vec_less(number_of_position);
  }
}

//-------------------------------------------------
//2. Funkcje pomocnicze przy zapisie do pliku

//zapis jeśli wektor był pełny
void Manager::vec_ten(int number_of_position)
{
  Level level=snake_board.get_game_level();
  std::string level_name;
  if(level==EASY) level_name="EASY";
  else if(level==MEDIUM) level_name="MEDIUM";
 else level_name="HARD";

   std::ofstream plik1("/home/runner/Snake/plik.txt",std::ios_base::trunc);
  if(!plik1)
  {
    std::cerr<<"Błąd: "<<strerror(errno)<<std::endl;
    exit(-1);
  }
  
  if(number_of_position==0) 
  {
    plik1<<snake_body.get_snake_name()<<" "<<level_name<<" "<<score<<std::endl;
    for(int i=0; i<9;++i)
    {
      plik1<<results[i]<<std::endl;
    }
    return;
  }
  
  for(int i=0;i<number_of_position;++i)
  {
    plik1<<results[i]<<std::endl;
  }
  plik1<<snake_body.get_snake_name()<<" "<<level_name<<" "<<score<<std::endl;
  if(number_of_position==9) return;

  for(int i=number_of_position;i<=8;i++)
  {
    plik1<<results[i]<<std::endl;
  }
  plik1.close();
}

//zapis jeśli wektor nie jest pełen
void Manager::vec_less(int number_of_position)
{
   Level level=snake_board.get_game_level();
   std::string level_name;
   if(level==EASY) level_name="EASY";
   else if(level==MEDIUM) level_name="MEDIUM";
   else level_name="HARD";

   std::ofstream plik2("/home/runner/Snake/plik.txt",std::ios_base::trunc);
  if(!plik2)
  {
    std::cerr<<"Błąd: "<<strerror(errno)<<std::endl;
    exit(-1);
  }

  if(number_of_position==0) 
  {
    plik2<<snake_body.get_snake_name()<<" "<<level_name<<" "<<score<<std::endl;
    for(size_t i=0; i<results.size();++i)
    {
      plik2<<results[i]<<std::endl;
    }
    return;
  }

  for(int i=0;i<number_of_position;++i)
  {
    plik2<<results[i]<<std::endl;
  }
  plik2<<snake_body.get_snake_name()<<" "<<level_name<<" "<<score<<std::endl;
  
  for(size_t i=number_of_position;i<results.size()-1;i++)
  {
    plik2<<results[i]<<std::endl;
  }
  plik2.close();
}

//zwraca numer pozycji jeśli wektor jest pełen
int Manager::vec_full()
{
   std::vector <int> help_vec;
    for(size_t i=0;i<results.size();i++)
    {
    int dlugosc=results[i].length();
      int liczba=0;
      int mnoznik=1;
      for(int j=dlugosc-1;j>=0;j--)
      {
        if(isdigit(results[i][j])==1) 
        {
          std::stringstream ss;
          int help;
          ss<<results[i][j];
          ss>>help;
          liczba=liczba+help*mnoznik;
          mnoznik=mnoznik*10;
        }
      } 
       help_vec.push_back(liczba);
    }    
     if(score<help_vec[9]) return -1;
    for(int i=0;i<=9;++i)
    {
       if(score>help_vec[i]) return i;
    }
    return -1;
}

//zwraca numer pozycji jeśli wektor nie jest pełny
int Manager::vec_not_full()
{
   std::vector <int> help_vec;
    for(size_t i=0;i<results.size();i++)
    {
    int dlugosc=results[i].length();
      int liczba=0;
      int mnoznik=1;
      for(int j=dlugosc-1;j>=0;j--)
      {
        if(isdigit(results[i][j])==1) 
        {
          std::stringstream ss;
          int help;
          ss<<results[i][j];
          ss>>help;
          liczba=liczba+help*mnoznik;
          mnoznik=mnoznik*10;
        }      
      } 
       help_vec.push_back(liczba);
    }  
    
    for(size_t i=0;i<help_vec.size();++i)
    {
       if(score>help_vec[i]) return i;
    }
    return help_vec.size()-1;
}

//------------------------------
//3. Zwraca informacje

//zwraca ilość punktów
int Manager::get_score() const
{
  return score;
}

//zwraca prawdę jeśli wynik przeprowadzonej właśnie gry znajduje się wśród 10 najlepszych (czyli innymi słowy został wpisany do pliku)
bool Manager::is_on_table() const
{
  if(one_of_winner_game==true) return true;
  return false;
}


//zwraca numer wpisanej pozycji
int Manager::get_number_of_position() const
{
  return number_of_position;
}