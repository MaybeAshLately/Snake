#include "SnakeSFML.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <errno.h>
#include <string>


SnakeSFML::SnakeSFML(Snake & snake_sfml,  Board & board_sfml, Manager & manager_sfml): snake_sfml(snake_sfml), board_sfml(board_sfml), manager_sfml(manager_sfml)
{
  app_state=INSTRUCTION;
  wall_icon.setSize(sf::Vector2f(10,10));
  wall_icon.setFillColor(sf::Color(160,160,160));

  wall_icon1.setSize(sf::Vector2f(10,1));
  wall_icon1.setFillColor(sf::Color::Black);
  wall_icon2.setSize(sf::Vector2f(10,1));
  wall_icon2.setFillColor(sf::Color::Black);
  wall_icon3.setSize(sf::Vector2f(1,10));
  wall_icon3.setFillColor(sf::Color::Black);
  wall_icon4.setSize(sf::Vector2f(1,10));
  wall_icon4.setFillColor(sf::Color::Black);


  food_icon.setRadius(4);
  food_icon.setFillColor(sf::Color(255,255,0));

  snake_icon.setRadius(6);
  snake_icon.setFillColor(sf::Color(0,204,0));
  snake_icon.setOutlineThickness(1);
  snake_icon.setOutlineColor(sf::Color::Black);
  snake_icon2.setRadius(3);
  snake_icon2.setFillColor(sf::Color::Red);

  eye_icon.setRadius(2);
  eye_icon.setFillColor(sf::Color(0,0,204));

  blood_icon.setRadius(10);
  blood_icon.setFillColor(sf::Color(204,0,0));
  blood_icon.setOutlineThickness(2);
  blood_icon.setOutlineColor(sf::Color(255,0,0));


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
     abort();
   }
  
  txt1.setFont(font1);

  
}


//Funkcja przekazująca rysowanie planszy do funkcji w zależności od stanu aplikacji
void SnakeSFML::draw(sf::RenderWindow & win)
{ 
  if(app_state==INSTRUCTION) draw_instruction(win);
  else if(app_state==ALIVE) draw_alive(win);
  else if(app_state==DIED) draw_died(win);
  else draw_results(win);
  
  
}


//Funkcja rysująca aplikację w trybie instrukcji
void SnakeSFML::draw_instruction(sf::RenderWindow & win)
{
  draw_board(win);

  txt1.setString("WAZ ZNAJDUJE SIE W LEWYM GORNYM ROGU");
   txt1.setCharacterSize(20);
   txt1.setPosition(160,200);
   txt1.setFillColor(sf::Color::Black);
   back.setSize(sf::Vector2f(650,250));
   back.setFillColor(sf::Color(204,204,0));
   back.setPosition(120,200);
   back.setOutlineColor(sf::Color::Black);
   back.setOutlineThickness(1);
   win.draw(back);
   win.draw(txt1);
   txt1.setString("JEST SKIEROWANY NA POLUDNIE");
   txt1.setPosition(250,230);
   win.draw(txt1);
   txt1.setString("MOZESZ SKRECAC W LEWO I PRAWO STRZALKAMI");
   txt1.setPosition(140,260);
   win.draw(txt1);
   txt1.setString("ZJADAJAC JEDZENIE ZBIERASZ PUNKTY");
   txt1.setPosition(210,290);
   win.draw(txt1);
   txt1.setString("UMRZESZ JESLI UDERZYSZ W PRZESZKODE LUB SIEBIE");
   txt1.setPosition(130,320);
   win.draw(txt1);
   txt1.setString("POWODZENIA");
   txt1.setPosition(380,350);
   win.draw(txt1);
   back.setSize(sf::Vector2f(250,50));
   back.setPosition(330,380);
   win.draw(back);
   txt1.setCharacterSize(30);
   txt1.setString("ROZPOCZNIJ");
   txt1.setPosition(340,385);
   win.draw(txt1);
   
  
}


//Funkcja rysująca aplikację w trybie alive
void SnakeSFML::draw_alive(sf::RenderWindow & win)
{
  draw_board(win);

  if(snake_sfml.is_alive()==false)
  {
    draw_blood(win);
    app_state=DIED;
  }
 
  manager_sfml.play();

}

//funkcja rysująca aplikacje w trybie died
void SnakeSFML::draw_died(sf::RenderWindow & win)
{
  draw_board(win);
  draw_blood(win);

   txt1.setString("GAME OVER");
   txt1.setCharacterSize(50);
   txt1.setPosition(210,200);
   txt1.setFillColor(sf::Color::Black);
   back.setSize(sf::Vector2f(400,150));
   back.setFillColor(sf::Color(204,204,0));
   back.setPosition(200,200);
   back.setOutlineColor(sf::Color::Black);
   back.setOutlineThickness(1);
   win.draw(back);
   win.draw(txt1);
   txt1.setCharacterSize(25);
   txt1.setString("WYNIK: ");
   txt1.setPosition(310,255);
   win.draw(txt1);
   txt1.setString(std::to_string(manager_sfml.get_score()));
   txt1.setPosition(430,255);
   win.draw(txt1);
   back.setSize(sf::Vector2f(250,50));
   back.setPosition(280,290);
   win.draw(back);
   txt1.setString("ZOBACZ WYNIKI");
   txt1.setPosition(285,295);
   win.draw(txt1);
   

   
}


//funkcja rysująca aplikacje w trybie results
void SnakeSFML::draw_results(sf::RenderWindow & win)
{
  if(counter==0) load_results();
  counter++;

  for(size_t i=0;i<results.size();i++)
  {
    txt1.setCharacterSize(10);
    txt1.setPosition(10,10*i);
    txt1.setString(results[i]);
    win.draw(txt1);
  }
 
   
}

//wczytuje z pliku
void SnakeSFML::load_results()
{
   std::ifstream plik("/home/runner/Snake/plik.txt");
   if(!plik)
   {
    std::cerr<<"Błąd: "<<strerror(errno)<<std::endl;
    exit(-1);
   }
    
    int i=0;
    while(plik)
    {
      results.push_back("");      
      getline(plik, results[i]);
    i++;
    }
   
   plik.close();
   

     

}



//funkcja rysująca planszę
void SnakeSFML::draw_board(sf::RenderWindow & win)
{
  for(int row=0;row<60;row++)
  {
    for(int col=0;col<80;col++)
    {
      if(board_sfml.field_has_wall(row,col)==true)
      {
        wall_icon.setPosition(col*10,row*10);
        win.draw(wall_icon);
        wall_icon1.setPosition(col*10,row*10+3);
        win.draw(wall_icon1);
        wall_icon2.setPosition(col*10,row*10+7);
        win.draw(wall_icon2);
        wall_icon3.setPosition(col*10+3,row*10);
        win.draw(wall_icon3);
        wall_icon4.setPosition(col*10+7,row*10);
        win.draw(wall_icon4);

      }
      else if(board_sfml.field_has_food(row,col)==true)
      {
        
        food_icon.setPosition(col*10+2,row*10+2);
        win.draw(food_icon);
      }
      else if(board_sfml.is_snake_on_field(row,col)==true)
      {
        snake_icon.setPosition(col*10,row*10);
        
        if(snake_sfml.is_cell_head(row,col)==true) 
        { 
          snake_icon.setFillColor(sf::Color(150,110,0));
          win.draw(snake_icon);
          snake_icon.setFillColor(sf::Color(0,204,0));
           draw_eyes(row,col, win);
           
        }
        else 
        {
          win.draw(snake_icon);
          snake_icon2.setPosition(col*10+3,row*10+3);
          win.draw(snake_icon2);
        } 
  
      }
    }
  }
}



//funkcja rysująca krew
void SnakeSFML::draw_blood(sf::RenderWindow & win)
{
  sf::Vector2f head(snake_sfml.get_position_of_cell(0));
  blood_icon.setPosition(head.y*10-4,head.x*10-4);
  win.draw(blood_icon);

}

//funkcja pomocnicza rysująca oczy 
void SnakeSFML::draw_eyes(int row, int col,sf::RenderWindow & win)
{
   
    eye_icon.setPosition(col*10+2,row*10+3);
   win.draw(eye_icon);
    eye_icon.setPosition(col*10+8,row*10+3);
    win.draw(eye_icon);
    
  
}

//zwraca stan aplikacj
app SnakeSFML::get_app_state() const
{
  return app_state;
}


//zmienia stan aplikacji na result
void SnakeSFML::zobacz_wyniki_pressed()
{
  app_state=RESULT;
}

//zmienia stan aplikacji na alive
void SnakeSFML::rozpocznij_pressed()
{
  app_state=ALIVE;
}