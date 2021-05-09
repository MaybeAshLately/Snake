#ifndef BEGIN_H
#define BEGIN_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Board.h"
#include <string>

/*
Ta klasa odpowiada za ustalenie stanu początkowego gry;
 1. wyświetla graficznie poszczególne tryby aplikacji (ekran powitalny,ekran wyboru poziomu,ekran wpisywania nazwy użytkownika)
 2. obsługuje zdarzenia (kliknięcia na przyciski, wpisywanie nazwy użytkownika) 
 3. zwraca nazwę użytkownika i wybrany poziom 
*/

enum State {INTRO,LEVEL_CHOICE, NAME_CHOICE };

class Begin
{
  Level choosed_level;
  std::string choosed_name;
  
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

  bool end;
  bool error;
  
  public:
  Begin();

  void draw(sf::RenderWindow & win);
  void mouse_was_pressed(sf::Event event);
  void text_was_entered(sf::Event event);

  std::string get_name() const;
  Level get_level() const;
};
#endif