#ifndef FILE_PROCESS_H
#define FILE_PROCESS_H

#include <stdio.h>

struct usr {
    char username[20];
    char password[20];
};

struct contact {
    char name[20];
    char phone[20];
    char email[20];
};

int create_user_file();
int create_contact_file();

int read_user_file(struct usr** users, int* count);
struct contact* read_contact_file(int* count);

int write_user_file(struct usr user);
int write_contact_file(struct contact con);

#endif // FILE_PROCESS_H
