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
#include "Begin.h"
#include <iostream>

int main()
{
  srand(time(0));



sf::RenderWindow window(sf::VideoMode(800, 600), "SNAKE");
window.setVerticalSyncEnabled(false);
window.setFramerateLimit(20);

sf::RenderWindow window_begin(sf::VideoMode(800, 600), "SNAKE");
window_begin.setVerticalSyncEnabled(false);
window_begin.setFramerateLimit(5);
  
  
  Begin begin1;

while (window_begin.isOpen())
    {
        sf::Event event;
        while (window_begin.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
              window_begin.close();
              window.close();
            }
            else if(event.type == sf::Event::MouseButtonPressed)
              {
                begin1.mouse_was_pressed(event);
              }   
            else if(event.type == sf::Event::TextEntered )
            {
              begin1.text_was_entered(event);
            }    
        }
        
        window_begin.clear(sf::Color(0,35,118));
        begin1.draw(window_begin);
        window_begin.display();    
    }
  
    Snake snake1(begin1.get_name());
    Board board1(snake1,begin1.get_level());
    Manager manager1(snake1,board1);
    SnakeSFML sfml1(snake1,board1,manager1);
    Events events1(snake1,board1,manager1,sfml1);

   /*
    Snake snake1("nazwa");
    Board board1(snake1,HARD);
    Manager manager1(snake1,board1);
    SnakeSFML sfml1(snake1,board1,manager1);
    Events events1(snake1,board1,manager1,sfml1);
*/
  
/*
Test test_snake(snake1,board1,manager1);
  while(snake1.is_alive()==true)
  {
    test_snake.playing_test();
  }
*/

  

   
   
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
            else if(event.type == sf::Event::MouseButtonPressed)
               {
                 events1.mouse_button_pressed(event);
               }
              
        }
        
        window.clear(sf::Color(0,35,118));
        sfml1.draw(window);
        window.display(); 
        
     
        
        
    }

  return 0;
} 