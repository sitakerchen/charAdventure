//
// Created by sitaker on 19-2-16.
//
#include <iostream>
#include <ctime>
#include "professional.h"
#include "weapon.h"
#include "format_control.h"

/////////////////////////////////////////////////////////////////////////////////////
using namespace std;

void enter_map(saber &My_saber);

/////////////////////////////////////////////////////////////////////////////////////
void saber_life()
{

    saber My_saber;
    cout<<FORMAT_CONVERSITION"Mystery:Ash,what's your name?= ="<<endl;
    char name[100];
    cin>>name;
    My_saber.set_name(name);
    cout<<FORMAT_CONVERSITION"emmmm,my name is "<<My_saber.name<<endl;
    cout<<FORMAT_CONVERSITION"Mystery:What ever,welcome to 2-Demension land"<<endl;
    enter_map(My_saber);

}



