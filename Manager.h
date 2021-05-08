#ifndef MANAGER_H
#define MANAGER_H
#include <string>
#include <vector>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Snake.h"
#include "Board.h"

/*
Klasa zarządzająca grą. Do jej obowiązków należy;
-sprawdzanie czy wąż nie umarł 
-sprawdzanie czy zjadł jedzenie 
-liczenie ilości punktów (ilość zjedzonego jedzenia)
-zapisuje wynik do pliku (odczytuje wyniki z pliku)

Korzysta z referencji na planszę 
*/

class Manager
{
  int score=0;
  int counter=0;
  
  Snake & snake_body;
  Board & snake_board;
  sf::Clock clk;
  int number_of_position;
  void movement();
  void snake_is_dead();
  
  bool snake_hit(std::vector <sf::Vector2f>& snake_bufor,int row,int col);

  std::vector <std::string> results;
  int vec_full();
  int vec_not_full();
  void vec_ten(int number_of_position);
  void vec_less(int number_of_position);
  bool one_of_winner_game=1;
  
  public:
  explicit Manager( Snake & snake_body,Board & snake_board);
  
  void play();

  int get_score() const;

  bool is_on_table();
  int get_number_of_position();
};


#endif