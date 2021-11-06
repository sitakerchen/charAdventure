//
// Created by sitaker on 19-2-16.
//

#ifndef CORE_PROFESSIONAL_H
#define CORE_PROFESSIONAL_H
#include <iostream>
#include <string.h>
#include "format_control.h"
using namespace std;
//alliance同盟
#define   ALLIANCE    1
//hostile敌对
#define    HOSTILE   -1
//neutral中立
#define    NEUTRAL     0

void Data_visualization(double Data);
//////////////////////////////////////////////////////////////////////////////////////////

class  Position
{

public:

    int x;
    int y;

    Position(int a,int b)
    {
        x=a;
        y=b;
    }

};
/////////////////////////////////////////////////////////////

class Skill_monster//怪物技能基类
{



};

class Skill_player//玩家技能基类
{



};

//////////////////////////////////////////////////////////////////////////////////////////

class monster//怪物基类
{
public:

    double HP;
    double MP;
    double ATK;

    monster(double H)
    {
        ATK=100;
        HP =H;
        MP =20;
    }

};



class player //玩家基类,不参与游戏!
{

    friend class Position;//不可删


public:

    char    name[100];
    int     age;
    int     relationship;
    int     level;
    double  hight;
    double  weight;
    double  ATK;//attack
    double  HP;//health points
    double  MP;//magic  points
    double  EXP;//Experience points
    double  EDU;//endurance;


    double  EXP_MAX;
    double  EDU_MAX;
    double  HP_MAX;
    double  MP_MAX;

    Position position;

    int set_name(char *nname)
    {
        strcpy(this->name,nname);
        return true;
    }

    void attack()
    {



    }



    int Equip_additional_properties_updater()//装备加成
    {

        return false;
    }

    int Move()//移动机制,土办法,一定要改进
    {
        char direction;

        do
        {

            cout<<"please input a move instruction with W S A D"<<endl;

            //BEGIN :

            cin>>direction;

            if (direction>='Z')

            {
                direction-=('a'-'A');
            }


            switch (direction)//x : col y:row
            {
                default:
                {

                    break;

                }
                case 'W':
                {
                    this->position.x-=1;
                    break;
                }
                case 'S':
                {
                    this->position.x+=1;
                    break;
                }
                case 'A':
                {
                    this->position.y-=1;
                    break;
                }
                case 'D':
                {
                    this->position.y+=1;
                    break;
                }

            }

        }while (direction!='W'&&direction!='S'&&direction!='A'&&direction!='D');
        return true;
    }

    player():position(0,0)//最好不要初始化其他要素
    {

    }

};



/////////////////////////////////////////////////////////////怪物类



class Ghost : public monster//杂兵
{
public:
    int     relationship;
    double  EXP_Lost;
    Ghost(int H):monster(H)
    {
        EXP_Lost    =300;
        relationship=HOSTILE;
    }

    int attack(player &aim)
    {
        aim.HP-=this->ATK;
        return true;
    }

};



/////////////////////////////////////////////////////////////玩家职业类

class saber : public player//剑士
{


public:
    saber()
    {

        strcpy(name,"Not Specific!");
        //memset(name,0, sizeof(name));
        relationship=ALLIANCE;
        EDU     =   100;
        age     =   20;
        hight   =   1.85;//m
        weight  =   80;//kg
        HP      =   2000.0;
        MP      =   500.0;
        level   =   1;
        EXP     =   0;
        ATK     =   20;

        EXP_MAX =   200;
        HP_MAX  =   HP;
        MP_MAX  =   MP;
        EDU_MAX =   EDU;

    }

    int level_updater(double EXP_GET=0)
    {
        /*static  double Total_EXP = 0;
        Total_EXP=*/
        this->EXP+=EXP_GET;

        if (this->EXP>=this->EXP_MAX)
        {
            this->level+=1;
            this->HP_MAX+=200.0;
            this->MP_MAX+=100.0;
            this->EDU_MAX+=20.0;
            this->ATK+=30.0;
            this->EXP-=EXP_MAX;

            this->HP    =   HP_MAX;//升级满血

            (this->EXP_MAX)*=2;


            level_updater();
        }

        if (this->HP<=0||this->MP<=0||this->EXP_MAX<=0||this->EXP<=0)
        {
            return -1;
        }
        else
        {
            return 0;
        }

    }

    virtual void attack(Ghost &ghost)
    {

        ghost.HP-=this->ATK;

    }

    int MINE_INFO()
    {
        cout<<"_________________________________________"<<endl;
        cout<<"NAME:"<<this->name<<endl;
        cout<<"PROFESSIONAL: saber\n";
        cout<<"HP:";Data_visualization(this->HP);
        cout<<"MP:";Data_visualization(this->MP);
        cout<<"ATK:";cout<<this->ATK<<endl;
        cout<<"LEVEL:";cout<<this->level<<endl;
        cout<<"_________________________________________"<<endl;
        return true;
    }

};

class archer:public player//弓箭手
{
public:
    archer()
    {

        strcpy(name,"Not Specific!");
        //memset(name,0, sizeof(name));
        relationship=ALLIANCE;
        EDU     =   150;
        age     =   20;
        hight   =   1.75;//m
        weight  =   60;//kg
        HP      =   1000.0;
        MP      =   1500.0;
        level   =   1;
        EXP     =   0;
        EXP_MAX =   15;
        ATK     =   15;

    }

    int level_updater(double EXP_GET=0)
    {
        /*static  double Total_EXP = 0;
        Total_EXP=*/
        this->EXP+=EXP_GET;

        if (this->EXP>=this->EXP_MAX)
        {
            this->level+=1;
            this->HP+=110.0;
            this->MP+=200.0;
            this->EDU+=25.0;
            this->ATK+=7;
            this->EXP-=EXP_MAX;
            (this->EXP_MAX)*=3;
            level_updater();
        }

        if (this->HP<=0||this->MP<=0||this->EXP_MAX<=0||this->EXP<=0)
        {
            return -1;
        }
        else
        {
            return 0;
        }

    }


};
////////////////////////////////////////////////////////

////////////////////////////////////////////////////////

#endif //CORE_PROFESSIONAL_H
