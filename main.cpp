#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Snake.h"
#include "Board.h"
#include "Manager.h"
#include <ctime>
#include "Test.h"
#include <cstdlib>


int main()
{
  srand(time(0));
	

    Snake snake1("nazwa");
    Board board1(snake1,HARD);
    Manager manager1(board1,snake1);

   Test test_snake(snake1,board1,manager1);

  while(snake1.is_alive()==true)
  {
    test_snake.playing_test();
  }


   
/*
    sf::RenderWindow window(sf::VideoMode(800, 600), "SNAKE test");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(10);
  
    int n=0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) 
                window.close();
        }
        
        window.clear();
        sf::RectangleShape r;
        r.setFillColor(sf::Color::Red);
        r.setSize(sf::Vector2f(10,10));
        r.setPosition(sf::Vector2f(0+n,0));
       
       window.draw(r);
        window.display();
        n=n+10;
        if(n==800) n=0;

        manager1.play();
        
    }
*/
  return 0;
} 