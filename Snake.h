#ifndef SNAKE_H
#define SNAKE_H
#include <string>
#include <vector>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

/*
To klasa reprezentująca ciało węża; do jej zadań należy;
 1. Znanie położenia ciała węża
 2. Zmienianie położenia (ruch), skręcanie, dodawanie nowych komórek 
 3. Znanie i zwracanie informacji o wężu (sprawdzanie czy komórka jest głową; zwracanie ciała; zwracanie kierunku ruchu; zwracanie położenia danej komórki; sprawdzanie czy wąż żyje; zwrcanie nazwy węża  )
 4. zmienianie kierunku ruchu (wykorzystywane przez klasę Test)
 

Ad. położenie węża;
każdy kawałek węża jest dwuelementowym wektorem współrzędnej x i y; plansza jest oknem 800 na 600 podzielonym na kwadraty o boku 10x10 i współrzędne będą wskazywać właśnie na taki kwadrat (numeracja standardowo- od 0 w lewym górnym rogu, uwaga najbardziej skrajne pola to ściany)
*/
 
enum Directions {NORTH, SOUTH, WEST,EAST};
enum Corner {RIGHT,LEFT,ANY};
class Snake
{
  std::vector <sf::Vector2f> snake_cells;
  int length; 
  Directions move_to;
  const std::string snake_name;
  bool alive;

  Corner move_corner;
  void update_position();
  void update_head_position();

  void turn_right();
  void turn_left();

  public:
  explicit Snake(std::string name);

  void update();
  
  void move_corner_left();
  void move_corner_right();

  void snake_died();
  void add_cell(sf::Vector2f cell);

  Directions get_snake_direction() const;
  int get_snake_length() const;
  std::string get_snake_name() const;
  bool is_alive() const;
  sf::Vector2f get_position_of_cell(int number);
  bool is_cell_head(int row,int col) ;
  std::vector <sf::Vector2f> return_body() const;
 

};

#endif