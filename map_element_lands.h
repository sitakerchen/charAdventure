//
// Created by sitaker on 19-2-16.
//

#ifndef CORE_MAP_ELEMENT_LANDS_H
#define CORE_MAP_ELEMENT_LANDS_H

#include "format_control.h"

int enter_combat_Ghost(saber &My_saber,Ghost &ghost);
///////////////////////////////////////////////
int remian=0;
class lands
{
private:

    bool flag_discover;//ture:已探索    false:未探索
    bool flag_monster ;//ture:有怪     false:没怪
    Ghost ghost;
public:
    lands(unsigned seed =(unsigned)rand()%40):ghost(180+seed)
    {

        flag_discover  = false;

        int temp = rand();
        if (temp < RAND_MAX/2)
        {
            flag_monster = false;
        }
        else
        {
            flag_monster = true;
            remian++;
        }


    }

    int get_monster_num()
    {

        return remian;

    }

    void show_map()
    {
        cout<<this->flag_discover;
        //cout<<this->flag_monster;
    }

    void pass_by()
    {
        this->flag_discover=true;
    }

    int meet_monster(saber &My_saber)
    {
        if (this->flag_monster==true)
        {
            return enter_combat_Ghost(My_saber,this->ghost);
        }
        return true;
    }

};

#endif //CORE_MAP_ELEMENT_LANDS_H
