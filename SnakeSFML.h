#ifndef SNAKESFML_H
#define SNAKESFML_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Snake.h"
#include "Board.h"
#include "Manager.h"
#include <string>
#include <vector>
//Ta klasa odpowiada za wyświetlanie rozgrywki w trybie graficznym 


enum app{INSTRUCTION,ALIVE,DIED,RESULT};
class SnakeSFML
{

  Snake &snake_sfml;
  Board &board_sfml;
  Manager &manager_sfml;
   
  app app_state;

  sf::RectangleShape wall_icon;
  sf::RectangleShape wall_icon1;
  sf::RectangleShape wall_icon2;
  sf::RectangleShape wall_icon3;
  sf::RectangleShape wall_icon4;

  int counter=0;


  sf::CircleShape food_icon;
  sf::CircleShape snake_icon;
  sf::CircleShape snake_icon2;

  sf::CircleShape eye_icon;

  sf::CircleShape blood_icon;

  void draw_eyes(int row, int col,sf::RenderWindow & win);
  void draw_blood(sf::RenderWindow & win);

  void draw_instruction(sf::RenderWindow & win);
  void draw_alive(sf::RenderWindow & win);
  void draw_died(sf::RenderWindow & win);
  void draw_board(sf::RenderWindow & win);
  void draw_results(sf::RenderWindow & win);

  sf::Font font1;
  sf::Text txt1;
  sf::RectangleShape back;


  
  
  std::vector <std::string> best_results;
 

 void upload_from_file();

public:
explicit SnakeSFML(Snake & snake_sfml,  Board & board_sfml, Manager & manager_sfml);
void draw(sf::RenderWindow & win);


app get_app_state() const;
void zobacz_wyniki_pressed();
void rozpocznij_pressed();

};

#endif