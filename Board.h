#ifndef BOARD_H
#define BOARD_H
#include <string>
#include <vector>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Snake.h"
/*
Klasa reprezentująca planszę; 
1. Generuje losowo pozycję jedzenia i przeszkód (ścian)
2. Przechowuje pola planszy jako dwuwymiarową tablicę
3. Zwraca informacje (czy na danym polu jest ściana/jedzenie/wąż, poziom gry)
4. symuluje jedzenie (zabiera je jeśli wąż "zjadł")
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

  void eat(int row, int col);

  Level get_game_level() const;
  bool field_has_wall(int row,int col) const;
  bool field_has_food(int row,int col) const;
  bool is_snake_on_field(int row, int col);
 };


#endif