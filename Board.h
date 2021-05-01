#ifndef BOARD_H
#define BOARD_H
#include <string>
#include <vector>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Snake.h"


/*
Klasa reprezentująca planszę; 
-zna (stałe) wymiary planszy 
-zna poziom trudności
-generuje losowy układ jedzenia i przeszkód (ilość przeszkód zależna od poziomu, zewnętrzne pola są przeszkodami (ścianami))

Plansza korzysta z węża (referencja)
*/
struct Field
{
 bool has_food;
 bool has_wall;

};
enum Level {EASY,MEDIUM,HARD};
 
 class Board
 {
  Snake & snake_body;
  const Level game_level;


  Field fields[60][80];

  void generate_walls();
  void generate_food();
  void generate_outside_walls();
 

  public:
  explicit Board(Snake & snake_body ,const Level g_level);

  Level get_game_level() const;

 };


#endif