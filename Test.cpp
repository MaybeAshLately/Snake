#include "Test.h"
#include <iostream>


//KONSTRUKTOR
Test::Test(Snake & snake_test,  Board & board_test, Manager & manager_test): snake_test(snake_test), board_test(board_test), manager_test(manager_test)
{

}



//"RYSOWANIE" WERSJI TEKSTOWEJ 
void Test::rysowanie()
{
   for(int row=0;row<60;row++)
  {
    for(int col=0;col<80;col++)
     {
        
        if(board_test.field_has_wall(row,col)==true) std::cout<<"W";
        else if(board_test.field_has_food(row,col)==true) std::cout<<"f";
        else if(board_test.is_snake_on_field(row,col)==true) std::cout<<"s";
        else std::cout<<"_";
     }
     std::cout<<std::endl;
  }
  
}



//funkcja symulująca w trybie tekstowym grę. We właściwej grze wąż będzie szedł naprzód automatycznie (tu w celach diagnostycznych za każdym razem będzie czekał na wskazanie kierunku)
void Test::playing_test()
{
   
   rysowanie();
   char choice;
   std::cout<<"Czy skręcić? l-left, r-right,no-any ";
   std::cin>>choice;
   if(choice=='l')
   {
    snake_test.move_corner_left();
   }
   else if(choice=='r')
   {
    snake_test.move_corner_right();
   }
   else
   {

   }
   
   manager_test.play();
}

