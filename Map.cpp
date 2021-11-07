//
// Created by sitaker on 19-2-16.
//
#include <iostream>
#include <ctime>
#include "professional.h"
#include "weapon.h"
#include "map_element_lands.h"
#include "format_control.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////

void reflash_map(lands **map,int row,int col,saber ME);
void Data_visualization(double Data);


////////////////////////////////////////////////////////////////////////////////////////////





void enter_map(saber &My_saber)
{
    int remain_monster=0;  //怪物数量计数


    srand((unsigned) time(NULL));
    int row = 0, col = 0;
    do
    {

        row = rand() % 10;

    } while (row <= 5 || row >= 10);

    do
    {

        col = rand() % 10;

    } while (col <= 5 || row >= 10);
    lands **map_land = new lands *[row];

    for (int i = 0; i < row; i++)
    {
        map_land[i] = new lands[col];
    }

    //memset(map_land,0,sizeof(map_land));

    //bool flag_discover=false;//ture:已探索    false:未探索
    //bool flag_monster =false;//ture:有怪     false:没怪

    remain_monster = map_land[0][0].get_monster_num();

    Position record_point(My_saber.position.x,My_saber.position.y);//存档点,记录上一位置

    while (remain_monster!=0)
    {

        reflash_map(map_land,row,col,My_saber);
        cout<<"reamin_monster="<<remain_monster<<endl;

        {
            record_point.x=My_saber.position.x;
            record_point.y=My_saber.position.y;
        }

        My_saber.Move();

        cout<<"my position:"<<My_saber.position.x<<" "<<My_saber.position.y<<endl;
        if ((My_saber.position.x<0||My_saber.position.x>col)||(My_saber.position.y<0||My_saber.position.y>row))
        {

            cout<<"\t\t\t\tMestery:there is no land to walk!"<<endl;
            My_saber.position.x=record_point.x;
            My_saber.position.y=record_point.y;

        }
        else
        {

            map_land[My_saber.position.x][My_saber.position.y].pass_by();

            if (map_land[My_saber.position.x][My_saber.position.y].meet_monster(My_saber))
            {
                remain_monster--;
            }

        }

        //reflash_map(map_land,row,col);

        cout<<"\n"<<endl;//分割页面


        //remain_monster--;

    }


    ///////////////////////////free space ; dont touch it!
    for (int i=0;i<row;i++)
    {
        delete [] map_land[i];
    }
    delete [] map_land;
    ///////////////////////////
}


void reflash_map(lands **map,int row,int col,saber ME)
{

    map[ME.position.y][ME.position.x]=6;
    for (int i=0;i<row;i++)
    {

        cout<<" ";
        for (int j=0;j<col-1;j++)
        {

            cout<<"__";
        }
        cout<<"\n"<<"|";

        for (int j=0;j<col;j++)
        {

            map[i][j].show_map();
            cout<<"|";

        }
        cout<<"\n";
    }
    cout<<" ";
    for (int i=0;i<col-1;i++)
    {
        cout<<"__";
    }


    cout<<"EXP:";
    Data_visualization(ME.EXP);
    cout<<"HP:";
    Data_visualization(ME.HP);
    cout<<"∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎"<<endl;
    cout<<"∎       1-MINE INFO                  2-GO A HEAD         ∎"<<endl;
    cout<<"∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎∎"<<endl;
    int choose=0;
    //Begin :
    cout<<"\n";
    cin>>choose;

    switch (choose)
    {
        default:
        {
            cout<<"error!"<<endl;
            //goto Begin;
        }
        case 1:
        {
            ME.MINE_INFO();
            break;
        }
        case 2:
        {
            return;
            break;
        }
    }

}
