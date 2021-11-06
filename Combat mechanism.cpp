//
// Created by sitaker on 19-2-16.
//
#include <iostream>
#include <ctime>
#include "professional.h"
#include "weapon.h"
#include <unwind.h>
#include "format_control.h"
#include "Animation.h"
using namespace std;


/////////////////////////////////////////////////////////////////////////////////////

void Data_visualization(double Data=0);

void Combat_sence(player &My_saber,monster &ghost);

/////////////////////////////////////////////////////////////////////////////////////



int enter_combat_Ghost(saber &My_saber,Ghost &ghost)
{


    do
    {

        if (My_saber.ATK<ghost.ATK)
        {
            ghost_attack();
            Combat_sence(My_saber,ghost);
            ghost.attack(My_saber);
            cout<<"You have been attacked by a aggressive ghost!";
            cout<<My_saber.name<<"'HP-"<<ghost.ATK<<endl;
        }

        int choose=0;

        do
        {

            cin>>choose;
            switch (choose)
            {
                default:
                {
                    break;
                }
                case 1:
                {
                    if (My_saber.EDU>0)
                    {
                        ghost_hurted();
                        Combat_sence(My_saber,ghost);
                        My_saber.attack(ghost);
                        cout<<"HP-"<<My_saber.HP<<endl;
                        My_saber.EDU-=20;
                    }
                    else
                    {
                        cout<<"You feel tired,can't attack"<<endl;
                        My_saber.EDU=My_saber.EDU_MAX;
                    }
                    break;
                }
                case 2:
                {
                    return 0;
                }

            }

            ghost_attack();
            Combat_sence(My_saber,ghost);

            ghost.attack(My_saber);
            cout<<My_saber.name<<"'HP-"<<ghost.ATK<<endl;

            Combat_sence(My_saber,ghost);

        }while (choose!=1&&choose!=2);



    }while (ghost.HP>0&&My_saber.HP>0);

    if (My_saber.HP<=0)//初始化,即复活
    {

        return 0;
    }
    else if (ghost.HP<=0)//战斗胜利
    {
        //My_saber.EXP+=ghost.EXP_Lost;
        My_saber.EDU=My_saber.EDU_MAX;
        My_saber.level_updater(ghost.EXP_Lost);
        cout<<" _____________________________________"<<endl;
        cout<<"|     Congratulation! "<<My_saber.name<<" You win    |"<<endl;
        cout<<"|EXP+"<<ghost.EXP_Lost<<"                             |\n"
                                       "|                                    |\n"
                                       "|                                    |\n"<<endl;

        
    }
    else
    {
        cout<<"error_compat!"<<endl;
    }
    return 1;
}

void Combat_sence(player &My_saber,monster &ghost)
{
    cout<<"HP";
    Data_visualization(ghost.HP);
    cout<<"_____________________________________________________________________________"<<endl;
    cout<<"∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎"<<endl;

    cout<<"HP";
    Data_visualization(My_saber.HP);
    cout<<"MP";
    Data_visualization(My_saber.MP);
    cout<<"EDU";
    Data_visualization(My_saber.EDU);
    cout<<" __________________________"<<endl;
    cout<<"|   1-attack   2-run away  |";
}

