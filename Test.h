#ifndef TEST_H
#define TEST_H
#include "Snake.h"
#include "Board.h"
#include "Manager.h"
//To jest klasa służąca tylko do testowania przed SFML (wersji "tekstowej")

class Test
{
  Snake &snake_test;
  Board &board_test;
  Manager &manager_test;

  void rysowanie();
  
  public:
  Test(Snake & snake_test,  Board & board_test, Manager & manager_test);
  
  void playing_test();
};


#endif