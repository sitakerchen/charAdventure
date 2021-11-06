//
// Created by sitaker on 19-2-18.
//
#include <iostream>
#include "Animation.h"
#include "format_control.h"
using namespace std;


int ghost_basic()
{

      DIVIDING_LINE
      cout<<"     --------                \n"
            "    -        -               \n"
            "   -   |   |  -              \n"
            "   -          -              \n"
            "   -          -              \n"
            "   ''''''''''''              \n"
            "   |    |    |               \n"
            "   |    |    |               \n"
            "   |    |    |          "<<endl;
      DIVIDING_LINE
      return 1;
}


int ghost_hurted()
{
      DIVIDING_LINE
      cout<<"     --------                \n"
            "    -        -               \n"
            "   -   >   <  -   _________           \n"
            "   -          -  /         |__@   \n"
            "   -          - \\_________|  @        \n"
            "   ''''''''''''              \n"
            "   |    |    |               \n"
            "   |    |    |               \n"
            "  /    |    \\        "<<endl;

      DIVIDING_LINE
      return 1;
}

int ghost_attack()
{
      DIVIDING_LINE
      cout<<"     --------                          \n"
            "    -        -                 _______            \n"
            "   -   |   |  -      YOU ->   |       |       \n"
            "   -          - ▶    ▶        | >   < |     \n"
            "   -    ⋁⋁   -   ▶   ▶  ▶    |_______|        \n"
            "   '''''''''''' ▶    ▶            |        \n"
            "   |    |    |                    |         \n"
            "   |    |    |                  / |\\        \n"
            "   |    |    |                    |           \n"
            "                                 / \\             "<<endl;
      DIVIDING_LINE
      return 1;
}

int saber_dead()
{
      DIVIDING_LINE
      cout<<"           @ @                   \n"
            "          __|_                   \n"
            "         |    |                \n"
            "         |    |                \n"
            "         |    |  YOU DEAD !             \n"
            "         |    |                \n"
            "         \\   |                \n"
            "          \\  |           \n"
            "          \\__|                "<<endl;

      DIVIDING_LINE
    return true;
}






///////////////////////////////////////////////////////////////////////
void The_canvas()
{
      DIVIDING_LINE
      cout<<"                             \n"
            "                             \n"
            "                             \n"
            "                             \n"
            "                             \n"
            "                             \n"
            "                             \n"
            "                             \n"
            "                               "<<endl;

      DIVIDING_LINE

}
