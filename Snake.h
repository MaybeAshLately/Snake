#ifndef SNAKE_H
#define SNAKE_H
#include <string>
#include <vector>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

/*
To klasa reprezentująca ciało węża; do jej zadań należy;
-znanie aktualnej długości węża (jej zwracanie i modyfikacja)
-znanie położenia węża (każdego kawałka, zwracanie i modyfikacja)
-znanie kierunku ruchu (północ- góra planszy itp.)
-znanie nazwy użytkownika (i zwracanie)
-wie czy wąż jest "żywy"

Ad. położenie węża;
każdy kawałek węża jest dwuelementowym wektorem współrzędnej x i y; plansza podzielona będzie na kwadraty o boku 10x10 i współrzędne będą wskazywać właśnie na taki kwadrat (numeracja standardowo- od 0 w lewym górnym rogu, uwaga najbardziej skarajne pola to ściany)
*/
 
enum Directions {NORTH, SOUTH, WEST,EAST};
enum Corner {RIGHT,LEFT,ANY};
class Snake
{
  int length; 
  Directions move_to;
  const std::string snake_name;
  std::vector <sf::Vector2f> snake_cells;
  bool alive;


  Corner move_corner;
  void update_position();
  void update_head_position();

  void turn_right();
  void turn_left();

  public:
  explicit Snake(std::string name);
  int get_snake_length() const;
  Directions get_snake_direction() const;
  std::string get_snake_name() const;
  bool is_alive() const;

  void update();

  sf::Vector2f get_position_of_cell(int number);
  void snake_died();
  void add_cell(sf::Vector2f cell);

  void move_corner_left();
  void move_corner_right();

  bool is_cell_head(int row,int col);
 

};

#endif