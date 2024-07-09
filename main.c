/*
TODO:
IMPORTANT: decide how to store the data in .dat files
encrypt the password
caesar for contact.dat using sum md5(password) as key




1.main menu for a contact management system
2. details listing page
3.login system
4. add page
5. list page
6. search page
7. delete page
8. modify page
9. exit page
10. author page
function:
1.1 sim_gui style main menu
2.1 hidden password input(how?)
2.2 password verification using file, hidden password, md5 compare
3.1 add name, preprossing: name->pinyin search index
4.1 list all contacts by pinyin or phone number
5.1 search by name, phone number, pinyin
6.1 delete by name, phone number, pinyin, using search
7.1 modify in details, showing a eidtable page
7.2 exit with save/ not save option
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"menu.h"
#include"login.h"

struct contact
{
    char name[50];
    char phone[20];
    char email[50];
    char address[100];
    char pinyin[50];
};

int main()
{
    // basic statues
    int mainexit=0;
    // consle clear
    system("cls");
    //console title
    printf("\033]0;Contact Management System\007");
    // modify the console size
    system("mode con cols=100 lines=100");
    // main menu
    draw_loggin();
    // check if contact.dat exists  
    // if not, create one


    while (mainexit==0)
    {
        draw();
        // get choice
        int choice = get_choice();
        // switch choice
        switch (choice)
        {
        // case 1:
            // details listing
            // break;
        case 1:
            draw_add();
            // add a contact
            break;
        case 2:
            draw_list();
            // list all contacts
            break;
        case 4:
            draw_search();
            // search a contact
            break;
        case 3:
            draw_delet();
            // delete a contact
            break;
        case 5:
            draw_modify();
            // modify a contact
            break;
        case 6:
            // exit
            mainexit=1;
            break;
        }
    }

    // scanf("%d");
    return 0;
}
