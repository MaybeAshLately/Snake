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

/*
1.Spis klas i plików
   a. lista klas (szczegółowy opis zadań danej klasy w odpowiednich plikach nagłówkowych)
       -Begin--> odpowiada za wstęp do gry (wybór poziomu trudności, nazwy użytkownika), w tym obsługa graficzna i obsługa zdarzeń 
       -Snake--> reprezentuje ciało węża
       -Board--> reprezentuje planszę 
       -Manager--> zarządza rozgrywką 
       -SnakeSFML-->odpowiada za graficzne wyświetlanie rozgrywki
       -Events--> obsługa zdarzeń
       -Test--> klasa testowa wyświetlająca "tekstową" formę Snake
    b. inne pliki
    -plik.txt-->przechowuje 10 najlepszych wyników (lub mniej jeśli nie rozegrano jeszcze 10 gier)
    -CMakeLists.txt
    -.replit  
    -.gitignore
    -resources
2. Zapożyczenia w kodzie. Zgodnie z instrukcją z moodle poniżej dokumentuję wszystkie zapożyczenia;
    -wczytywanie fontu do czcionki--> wykorzystane w konstruktorze klasy Begin oraz konstruktorze klasy SnakeSFML; źródło: https://zts.ita.pwr.wroc.pl/gitlab/bartlomiej.golenko/kreski/-/blob/master/SFML/WidokPlanszy.cpp 
    -CMakeLists.txt--> źródło fork projektu https://replit.com/@bgolenko/SFML-TEMPLATE-SAPER
    -resources--> źródło fork projektu https://replit.com/@bgolenko/SFML-TEMPLATE-SAPER
Poza powyższymi przypadkami cały kod napisałem samodzielnie 
3. logika działania funkcji main
   Tworzę dwa okna oraz obiekt klasy Begin--> w pierwszym oknie wykorzystując obiekt Begin wyświetlam użytkownikowi wstęp do gry, w którym gracz wybiera poziom trudności oraz nazwę użytkownika--> następnie wykorzystując wprowadzone dane tworzę obiekty klas Snake, Board, Manager, SnakeSFML oraz Events; wykorzytując je w drugim oknie przeprowadzona zostaje rozgrywka oraz wyświetlone wyniki (pierwsze okno zamyka się automatycznie w momencie gdy użytkownik skończy przechodzić przez etapy wstępu ) 
   W funkcji zostawiam też wykomentowany fragment z deklaracją obiektu klasy Test--> ten fragment służył testowemu przeprowadzeniu "tekstowej" rozgrywki
*/