/*
main menu for a contact management system
sim_gui style main menu

function:
draw() -> show the main menu
    return: void

get_choice() -> get the choice from user
    return: int


*/

#include "menu.h"
#include "file_process.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void draw()
{
    system("cls");
    //tittle
    printf("                                           Contact Management System\n");
    //author
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("                                                Author: martin\n");
    //menu
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("                                   1. Add a contact        2. List all contacts\n");
    printf("                                   3. Delete a contact     4.Search a contact\n");
    printf("                                   5. Modify a contact     6.Exit\n");
    printf("--------------------------------------------------------------------------------------------------\n");
}

int get_choice()
{
    int choice;
    printf("                                     Please enter your choice:");
    while(scanf("%d", &choice) != 1 || choice < 1 || choice > 8)
    {
        system("cls");
        draw();
        printf("                        Invalid choice, please enter again:");
        while(getchar() != '\n');
    }
    return choice;
}

void draw_list() {
    // 读取联系人列表
    int count;
    struct contact* contacts = read_contact_file(&count);
    system("cls");
    printf("                                           Contact Management System\n");
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("                              Name            \t\tPhone        \t\tEmail\n");
    printf("                                   Read %d contacts\n", count);
    printf("--------------------------------------------------------------------------------------------------\n");
    
    if (contacts != NULL) {
        for (int i = 0; i < count; i++) {
            printf("                           %-25s\t%-20s\t%-30s\n", contacts[i].name, contacts[i].phone, contacts[i].email);
        }
        free(contacts); // 释放分配的内存
    } else {
        printf("                                   No contacts found.\n");
    }

    printf("--------------------------------------------------------------------------------------------------\n");
    printf("                                   Press any key to return to main menu\n");
    scanf("%*c");
    while(getchar() != '\n'); // 等待用户按下任意键
}


void draw_add()
{
    system("cls");
    printf("                                           Contact Management System\n");
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("                                   Add a contact\n");
    printf("--------------------------------------------------------------------------------------------------\n");
    struct contact con;
    printf("                                   Name:");
    scanf("%s", con.name);
    printf("                                   Phone:");
    scanf("%s", con.phone);
    printf("                                   Email:");
    scanf("%s", con.email);
    write_contact_file(con);
    printf("                                   Contact added successfully\n");
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("                                   Press any key to return to main menu\n");
    scanf("%*c");
    while(getchar() != '\n');
}

void draw_search(){
    //search type: name or phone or email
    system("cls");
    printf("                                           Contact Management System\n");
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("                                   Search a contact\n");
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("                                   1. Search by name\n");
    printf("                                   2. Search by phone\n");
    printf("                                   3. Search by email\n");
    printf("--------------------------------------------------------------------------------------------------\n");
    int choice;
    printf("                                   Please enter your choice:");
    while(scanf("%d", &choice) != 1 || choice < 1 || choice > 3)
    {
        system("cls");
        printf("                                           Contact Management System\n");
        printf("--------------------------------------------------------------------------------------------------\n");
        printf("                                   Search a contact\n");
        printf("--------------------------------------------------------------------------------------------------\n");
        printf("                                   1. Search by name\n");
        printf("                                   2. Search by phone\n");
        printf("                                   3. Search by email\n");
        printf("--------------------------------------------------------------------------------------------------\n");
        printf("                                   Invalid choice, please enter again:");
        while(getchar() != '\n');
    }
    switch (choice)
    {

    case 1:
    system("cls"); // 清屏
    printf("                                           Contact Management System\n");
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("                                   Search a contact\n");
    printf("--------------------------------------------------------------------------------------------------\n");

    char name[50];
    printf("                                   Name: ");
    scanf("%s", name);
    printf("--------------------------------------------------------------------------------------------------\n");

    int count = 0;
    struct contact* contacts = read_contact_file(&count);
    int found = 0;

    if (contacts != NULL) {
        for (int i = 0; i < count; i++) {
            if (strncmp(contacts[i].name, name, strlen(name)) == 0) { // 使用 strncmp 比较前几位
                printf("                                   Name: %s\n", contacts[i].name);
                printf("                                   Phone: %s\n", contacts[i].phone);
                printf("                                   Email: %s\n", contacts[i].email);
                printf("--------------------------------------------------------------------------------------------------\n");
                found = 1;
            }
        }
        free(contacts); // 释放分配的内存
    }

    if (!found) {
        printf("                                   Contact not found\n");
    }
    scanf("%*c");
    while(getchar() != '\n');
    break;

case 2:
    system("cls"); // 清屏
    printf("                                           Contact Management System\n");
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("                                   Search a contact\n");
    printf("--------------------------------------------------------------------------------------------------\n");

    char phone[20];
    printf("                                   Phone: ");
    scanf("%s", phone);
    printf("--------------------------------------------------------------------------------------------------\n");

    count = 0;
    contacts = read_contact_file(&count);
    found = 0;

    if (contacts != NULL) {
        for (int i = 0; i < count; i++) {
            if (strncmp(contacts[i].phone, phone, strlen(phone)) == 0) { // 使用 strncmp 比较前几位
                printf("                                   Name: %s\n", contacts[i].name);
                printf("                                   Phone: %s\n", contacts[i].phone);
                printf("                                   Email: %s\n", contacts[i].email);
                printf("--------------------------------------------------------------------------------------------------\n");
                found = 1;
            }
        }
        free(contacts); // 释放分配的内存
    }

    if (!found) {
        printf("                                   Contact not found\n");
    }
    scanf("%*c");
    while(getchar() != '\n');
    break;
    case 3:
    system("cls"); // 清屏
    printf("                                           Contact Management System\n");
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("                                   Search a contact\n");
    printf("--------------------------------------------------------------------------------------------------\n");

    char mail[20];
    printf("                                   Phone: ");
    scanf("%s", mail);
    printf("--------------------------------------------------------------------------------------------------\n");

    count = 0;
    contacts = read_contact_file(&count);
    found = 0;

    if (contacts != NULL) {
        for (int i = 0; i < count; i++) {
            if (strncmp(contacts[i].email, mail, strlen(mail)) == 0) { // 使用 strncmp 比较前几位
                printf("                                   Name: %s\n", contacts[i].name);
                printf("                                   Phone: %s\n", contacts[i].phone);
                printf("                                   Email: %s\n", contacts[i].email);
                printf("--------------------------------------------------------------------------------------------------\n");
                found = 1;
            }
        }
        free(contacts); // 释放分配的内存
    }

    if (!found) {
        printf("                                   Contact not found\n");
    }
    scanf("%*c");
    while(getchar() != '\n');
    break;
    while(getchar() != '\n');
    }
}

void draw_delet() {
    while(getchar() != '\n');
    system("cls");
    printf("                                           Contact Management System\n");
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("                                   Delete a contact\n");
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("                                   1. Delete by name\n");
    printf("                                   2. Delete by phone\n");
    printf("                                   3. Delete by email\n");
    printf("--------------------------------------------------------------------------------------------------\n");
    
    int choice;
    printf("                                   Please enter your choice: ");
    while (scanf("%d", &choice) != 1 || choice < 1 || choice > 3) {
        system("cls");
        printf("                                           Contact Management System\n");
        printf("--------------------------------------------------------------------------------------------------\n");
        printf("                                   Delete a contact\n");
        printf("--------------------------------------------------------------------------------------------------\n");
        printf("                                   1. Delete by name\n");
        printf("                                   2. Delete by phone\n");
        printf("                                   3. Delete by email\n");
        printf("--------------------------------------------------------------------------------------------------\n");
        printf("                                   Invalid choice, please enter again: ");
        while (getchar() != '\n');
    }

    char input[50];
    printf("                                   Please enter the current %s: ", (choice == 1) ? "name" : (choice == 2) ? "phone" : "email");
    scanf("%s", input);
    
    int count = 0;
    struct contact* contacts = read_contact_file(&count);
    int found = 0;

    if (contacts != NULL) {
        for (int i = 0; i < count; i++) {
            if ((choice == 1 && strncmp(contacts[i].name, input, strlen(input)) == 0) ||
                (choice == 2 && strncmp(contacts[i].phone, input, strlen(input)) == 0) ||
                (choice == 3 && strncmp(contacts[i].email, input, strlen(input)) == 0)) {
                printf("                                   Found Contact:\n");
                printf("                                   Name: %s\n", contacts[i].name);
                printf("                                   Phone: %s\n", contacts[i].phone);
                printf("                                   Email: %s\n", contacts[i].email);
                printf("                                   Are you sure to delete this contact? (y/n): ");

                char confirm;
                while (getchar() != '\n');
                scanf("%c", &confirm);
                if (confirm == 'y' || confirm == 'Y') {
                    found = 1;
                    break; // Exit loop after finding the contact to delete
                } else {
                    free(contacts);
                    return;
                }
            }
        }
    }

    if (!found) {
        printf("                                   Contact not found\n");
    } else {
        FILE *fp = fopen("contact.dat", "w");
        if (fp == NULL) {
            printf("Error: contact.dat not found\n");
            printf("Creating contact.dat\n");
            fp = fopen("contact.dat", "w");
            fclose(fp);
        }
        for (int i = 0; i < count; i++) {
            if ((choice == 1 && strncmp(contacts[i].name, input, strlen(input)) != 0) ||
                (choice == 2 && strncmp(contacts[i].phone, input, strlen(input)) != 0) ||
                (choice == 3 && strncmp(contacts[i].email, input, strlen(input)) != 0)) {
                write_contact_file(contacts[i]);
            }
        }
        free(contacts);
        printf("                                   Contact deleted successfully\n");
    }

    scanf("%*c");
    while (getchar() != '\n');
}


void draw_modify(){
    while(getchar() != '\n');
    system("cls");
    printf("                                           Contact Management System\n");
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("                                   Modify a contact\n");
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("                                   1. Modify by name\n");
    printf("                                   2. Modify by phone\n");
    printf("                                   3. Modify by email\n");
    printf("--------------------------------------------------------------------------------------------------\n");
    int choice;
    printf("                                   Please enter your choice:");
    while(scanf("%d", &choice) != 1 || choice < 1 || choice > 3)
    {
        system("cls");
        printf("                                           Contact Management System\n");
        printf("--------------------------------------------------------------------------------------------------\n");
        printf("                                   Modify a contact\n");
        printf("--------------------------------------------------------------------------------------------------\n");
        printf("                                   1. Modify by name\n");
        printf("                                   2. Modify by phone\n");
        printf("                                   3. Modify by email\n");
        printf("--------------------------------------------------------------------------------------------------\n");
        printf("                                   Invalid choice, please enter again:");
        while(getchar() != '\n');
    }

    char input[50];
    printf("                                   Please enter the current %s: ", (choice == 1) ? "name" : (choice == 2) ? "phone" : "email");
    scanf("%s", input);
    
    int count = 0;
    struct contact* contacts = read_contact_file(&count);
    int found = 0;

    if (contacts != NULL) {
        for (int i = 0; i < count; i++) {
            if ((choice == 1 && strncmp(contacts[i].name, input, strlen(input)) == 0) ||
                (choice == 2 && strncmp(contacts[i].phone, input, strlen(input)) == 0) ||
                (choice == 3 && strncmp(contacts[i].email, input, strlen(input)) == 0)) {
                printf("                                   Found Contact:\n");
                printf("                                   Name: %s\n", contacts[i].name);
                printf("                                   Phone: %s\n", contacts[i].phone);
                printf("                                   Email: %s\n", contacts[i].email);
                printf("                                   Do you want to modify this contact? (y/n): ");
                
                char confirm;
                scanf(" %c", &confirm);
                if (confirm == 'y' || confirm == 'Y') {
                    printf("                                   Enter new details:\n");
                    printf("                                   Name: ");
                    scanf("%s", contacts[i].name);
                    printf("                                   Phone: ");
                    scanf("%s", contacts[i].phone);
                    printf("                                   Email: ");
                    scanf("%s", contacts[i].email);

                    found = 1;
                    break; // Exit loop after modification
                } else {
                    printf("                                   Modification canceled.\n");
                    free(contacts);
                    return;
                }
            }
        }
    }

    if (!found) {
        printf("                                   Contact not found\n");
    } else {
        FILE *fp = fopen("contact.dat", "w");
        if (fp == NULL) {
            printf("Error: contact.dat not found\n");
            printf("Creating contact.dat\n");
            fp = fopen("contact.dat", "w");
            fclose(fp);
        }
        for (int i = 0; i < count; i++) {
            write_contact_file(contacts[i]);
        }
        free(contacts);
        printf("                                   Contact modified successfully\n");
    }

    scanf("%*c");
    while(getchar() != '\n');
}
