#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Begin.h"
#include <iostream>
#include <cstring>

//konstruktor
Begin::Begin()
{
  begin_state=INTRO;

  //Zgodnie z instrukcją z moodle dokumentuję że poniższy fragment zapożyczyłem (z lekkimi zmianami) z https://zts.ita.pwr.wroc.pl/gitlab/bartlomiej.golenko/kreski/-/blob/master/SFML/WidokPlanszy.cpp 
  std::vector < std::string > fontSearchPath {
    
        "../resources/Roman SD.ttf",
        "C:/Windows/Fonts/Roman SD.ttf",
        "/usr/share/fonts/truetype/msttcorefonts/Roman SD.ttf"
    };
   bool fontLoaded=false;
   for(auto file: fontSearchPath)
   {
     fontLoaded=font1.loadFromFile(file);
     if(fontLoaded) break;
     std::cerr<<"CZCIONKA SIĘ NIE ŁADUJE!!!!"<<std::endl;
     exit(-1);
   }
   txt1.setFont(font1);
   //koniec zapożyczonego fragmentu 

  choosed_name="";
  end=false;
  error=false;
}

//---------------------------------------
//1. FUNKCJE RYSUJĄCE

//Funkcja przekazująca sterowanie rysowaniem w zależności od obecnego trybu aplikacji 
void Begin::draw(sf::RenderWindow & win)
{
  if(end==true) win.close();
   if(begin_state==INTRO) draw_intro(win);
   else if(begin_state==LEVEL_CHOICE) draw_level(win);
   else draw_name(win);

}

//funkcja rysująca w trybie wyświetlania powitania
void Begin::draw_intro(sf::RenderWindow & win)
{
  rect.setSize(sf::Vector2f(200,100));
  rect.setPosition(300,200);
  rect.setOutlineThickness(1);
  rect.setOutlineColor(sf::Color::Black);
  rect.setFillColor(sf::Color(204,204,0));
  win.draw(rect);
  txt1.setFillColor(sf::Color::Black);
  txt1.setCharacterSize(60);
  txt1.setPosition(303,205);
  txt1.setString("START");
  win.draw(txt1);
}


//funkcja rysująca w trybie wyświetlania wyboru poziomu
void Begin::draw_level(sf::RenderWindow & win)
{
  
  txt1.setCharacterSize(60);
  txt1.setString("WYBIERZ POZIOM");
  txt1.setPosition(100,50);
  win.draw(txt1);
  txt1.setCharacterSize(40);
  rect.setPosition(50,200);
  win.draw(rect);
  rect.setPosition(300,200);
  win.draw(rect);
  rect.setPosition(550,200);
  win.draw(rect);
  txt1.setString("EASY");
  txt1.setPosition(95,215);
  win.draw(txt1);
  txt1.setString("MEDIUM");
  txt1.setPosition(305,215);
  win.draw(txt1);
  txt1.setString("HARD");
  txt1.setPosition(595,215);
  win.draw(txt1);
}


//funkcja rysująca w trybie wyświetlania wyboru nazwy
void Begin::draw_name(sf::RenderWindow & win)
{
   txt1.setCharacterSize(40);
   rect.setSize(sf::Vector2f(400,250));
   rect.setPosition(200,100);
   win.draw(rect);
   if(error==true) txt1.setFillColor(sf::Color::Red);
   txt1.setString("WPISZ NAZWE:");
   txt1.setPosition(220,105);
   win.draw(txt1);
   txt1.setFillColor(sf::Color::Black);
   txt1.setString(choosed_name);
   txt1.setCharacterSize(20);
   txt1.setPosition(205,160);
   win.draw(txt1);
   rect.setSize(sf::Vector2f(200,50));
   rect.setPosition(300,210);
   win.draw(rect);
   txt1.setString("WYCZYSC");
   txt1.setPosition(350,215);
   win.draw(txt1);
   rect.setPosition(300,280);
   win.draw(rect);
   txt1.setString("DALEJ");
   txt1.setPosition(370,285);
   win.draw(txt1);
   
}

//------------------------------------------------
//2. FUNKCJE OBSŁUGUJĄCE ZDARZENIA 

//Funkcja przekazująca sterowanie obsługi zdarzeń kliknięcia w zależności od trybu aplikacji
void Begin::mouse_was_pressed(sf::Event event)
{
  if(begin_state==INTRO) mouse_intro(event);
  else if(begin_state==LEVEL_CHOICE) mouse_level(event);
  else mouse_name(event);
}


//obsługa kliknięcia w trybie intro
void Begin::mouse_intro(sf::Event event)
{
  if(event.mouseButton.button==1) return; 

  int x=event.mouseButton.x;
  int y=event.mouseButton.y;

  if((x>300)and(x<500)and(y>220)and(y<300))
    begin_state=LEVEL_CHOICE;
}

//obsługa kliknięcia w trybie wyboru poziomu
void Begin::mouse_level(sf::Event event)
{
  if(event.mouseButton.button==1) return; 

  int x=event.mouseButton.x;
  int y=event.mouseButton.y;
  
  if((x>50)and(x<250)and(y>200)and(y<300))
  {
    choosed_level=EASY;
    begin_state=NAME_CHOICE;
  }
  else if((x>300)and(x<500)and(y>200)and(y<300))
  {
    choosed_level=MEDIUM;
    begin_state=NAME_CHOICE;
  }
  else if((x>550)and(x<750)and(y>200)and(y<300))
  {
    choosed_level=HARD;
    begin_state=NAME_CHOICE;
  }
}

//obsługa kliknięcia w trybie wyboru nazwy
void Begin::mouse_name(sf::Event event)
{
   if(event.mouseButton.button==1) return; 

   int x=event.mouseButton.x;
   int y=event.mouseButton.y;

   if((x>300)and(x<500)and(y>210)and(y<260))
  {
    choosed_name.clear();
  }
  else if((x>300)and(x<500)and(y>280)and(y<330))
  {
    if(choosed_name!="") end=true;
    else error=true;
  }
}


//obsługa wpisywania nazwy
void Begin::text_was_entered(sf::Event event)
{
 char help=event.text.unicode;
 choosed_name=choosed_name+help;
}

//------------------------------------------------
//3. FUNKCJE ZWRACAJĄCE INFORMACJE

//zwraca wybraną nazwę 
std::string Begin::get_name() const
{
  return choosed_name;
}

//zwraca wybrany poziom 
Level Begin::get_level() const
{
  return choosed_level;
}