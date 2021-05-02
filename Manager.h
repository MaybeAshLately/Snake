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
  Board & snake_board;
  Snake & snake_body;
  sf::Clock clk;

  void movement();
  

  
  public:
  explicit Manager(Board & snake_board, Snake & snake_body);
  
  void play();
};


#endif