#ifndef BEGIN_H
#define BEGIN_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Board.h"
#include <string>

//Ta klasa odpowiada za ustalenie stanu początkowego gry;
//1. wyświetla ekran powitalny
//2. wyświetla ekran wyboru poziomu
//3. wyświetla ekran wpisywania nazwy użytkownika
//Zwraca wybrany poziom i nazwę 

enum State {INTRO,LEVEL_CHOICE, NAME_CHOICE };

class Begin
{
  State begin_state;
  sf::RectangleShape rect;
  sf::Font font1;
  sf::Text txt1;


  void draw_intro(sf::RenderWindow & win);
  void draw_level(sf::RenderWindow & win);
  void draw_name(sf::RenderWindow & win);

  void mouse_intro(sf::Event event);
  void mouse_level(sf::Event event);
  void mouse_name(sf::Event event);

  Level choosed_level;
  std::string choosed_name;
  bool end;
  bool error;
  
  public:
  Begin();

  void draw(sf::RenderWindow & win);
  void mouse_was_pressed(sf::Event event);
  void text_was_entered(sf::Event event);

  std::string get_name();
  Level get_level();
};
#endif