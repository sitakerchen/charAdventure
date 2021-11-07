#include <iostream>
#include <ctime>
#include "professional.h"
#include "weapon.h"
#include "format_control.h"
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////

inline int charater_menu();
inline int start_menu();
inline int exit_menu();
void saber_life();
void archer_life();
void show_author_Info();

/////////////////////////////////////////////////////////////////////////////////////////////////



int main()
{

    start_menu();


    exit_menu();


    return 0;
}



//////////////////////////////////////////////////////////////////////////////////////////////////
inline int start_menu()
{
    while (1)
    {

        printf(FORMAT_CONVERSATION"∎--- 1-New game ---∎\n"
               FORMAT_CONVERSATION"∎--- 2-Load game---∎\n"
               FORMAT_CONVERSATION"∎--- 3-Setting  ---∎\n"
               FORMAT_CONVERSATION"∎--- 4-Author   ---∎\n"
               FORMAT_CONVERSATION"∎--- 5-Plug-in  ---∎\n"
               FORMAT_CONVERSATION"∎--- 6-Exit     ---∎\n");

        int sel=0;
        cin>>sel;
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        switch (sel)
        {
            default:
            {
                start_menu();
                break;
            }
            case 1:
            {
                charater_menu();

                return 0;
            }
            case 2:
            {
                cout<<FORMAT_CONVERSATION"文件操作未上线"<<endl;
                break;
            }
            case 3:
            {
                cout<<FORMAT_CONVERSATION"暂时不太现实....."<<endl;
                break;
            }
            case 4:
            {
                show_author_Info();
                break;
            }
            case 5:
            {
                cout<<FORMAT_CONVERSATION"没有...."<<endl;
                break;
            }
            case 6:
            {
                return 0;
            }
        }
    }
    return true;
}


inline int exit_menu()
{

    cout<<FORMAT_CONVERSATION"∎Thanks for playing∎"<<endl;
    return true;

}

inline int charater_menu()
{
    int chose=0,temp=0;
    cout<<FORMAT_CONVERSATION"I may be remember that i am ..."<<endl;
    cout<<FORMAT_CONVERSATION"1-saber\n"
          FORMAT_CONVERSATION"2-archer"<<endl;
    do
    {
        cin>>chose;

        if (!chose)
        {
            cout<<FORMAT_CONVERSATION"Mystery:Think twice ..."<<endl;
        }

        if (chose==1)
        {
            cout<<FORMAT_CONVERSATION"Yes i am a saber!"<<endl;
            saber_life();
        }
        else if (chose==2)
        {
            cout<<FORMAT_CONVERSATION"It looks that i am an archer"<<endl;
            archer_life();
        }
        temp = chose;
        chose=0;
    }while(temp!=1&&temp!=2);
    return true;
}
