#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Snake.h"
#include "Board.h"
#include "Manager.h"
#include <ctime>
#include "Test.h"
#include <cstdlib>
#include "SnakeSFML.h"
#include "Events.h"


int main()
{
  srand(time(0));
	

    Snake snake1("nazwa");
    Board board1(snake1,HARD);
    Manager manager1(snake1,board1);
    SnakeSFML sfml1(snake1,board1,manager1);
    Events events1(snake1,board1,manager1,sfml1);

  
/*
Test test_snake(snake1,board1,manager1);
  while(snake1.is_alive()==true)
  {
    test_snake.playing_test();
  }
*/

  

    sf::RenderWindow window(sf::VideoMode(800, 600), "SNAKE test");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(20);
  
   
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) 
            {
              window.close();
            }   
            else if(event.type == sf::Event::KeyPressed) 
              {
                events1.key_was_pressed(event);
              }
              
        }
        
        window.clear();
        sfml1.draw(window);
        window.display(); 
        
     
        
        
    }

  return 0;
} 