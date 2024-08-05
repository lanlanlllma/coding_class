#include "file_process.h"
#include <stdlib.h>
#include <string.h>

char *user_format(struct usr usr) {
    char *str = (char *)malloc(50);
    sprintf(str, "%s %s\n", usr.username, usr.password);
    return str;
}

char *contact_format(struct contact con) {
    char *str = (char *)malloc(100);
    sprintf(str, "%s %s %s\n", con.name, con.phone, con.email);
    return str;
}

struct usr user_deformat(char *str) {
    struct usr usr;
    sscanf(str, "%s %s", usr.username, usr.password);
    return usr;
}

struct contact contact_deformat(char *str) {
    struct contact con;
    sscanf(str, "%s %s %s", con.name, con.phone, con.email);
    return con;
}

int create_user_file() {
    FILE *fp = fopen("user.dat", "w");
    if (fp == NULL) {
        return 0;
    }
    fclose(fp);
    return 1;
}

int create_contact_file() {
    FILE *fp = fopen("contact.dat", "w");
    if (fp == NULL) {
        return 0;
    }
    fclose(fp);
    return 1;
}

int write_user_file(struct usr user) {
    FILE *fp = fopen("user.dat", "a");
    if (fp == NULL) {
        return 0;
    }
    char *data = user_format(user);
    fputs(data, fp);
    fclose(fp);
    free(data);
    return 1;
}

int write_contact_file(struct contact con) {
    FILE *fp = fopen("contact.dat", "a");
    if (fp == NULL) {
        return 0;
    }
    char *data = contact_format(con);
    fputs(data, fp);
    // fputs("\n", fp);
    fclose(fp);
    free(data);
    return 1;
}

struct contact* read_contact_file(int* count) {
    FILE *fp = fopen("contact.dat", "r");
    if (fp == NULL) {
        printf("Error: contact.dat not found\n");
        printf("Creating contact.dat\n");
        fp = fopen("contact.dat", "w");
        fclose(fp);
        *count = 0;
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    int estimatedCount = (fileSize / 100) + 1; // Adjusted estimate per contact record
    struct contact* contacts = (struct contact*)malloc(estimatedCount * sizeof(struct contact));
    if (contacts == NULL) {
        fclose(fp);
        *count = 0;
        return NULL;
    }

    char line[100];
    int i = 0;
    while (fgets(line, sizeof(line), fp)) {
        // Initialize contact fields to empty strings
        struct contact con = {"", "", ""};
        sscanf(line, "%49s %19s %29s", con.name, con.phone, con.email);
        contacts[i] = con;
        i++;
        if (i >= estimatedCount) {
            estimatedCount *= 2;
            struct contact* temp = (struct contact*)realloc(contacts, estimatedCount * sizeof(struct contact));
            if (temp == NULL) {
                free(contacts);
                fclose(fp);
                *count = 0;
                return NULL;
            }
            contacts = temp;
        }
    }
    fclose(fp);
    *count = i;
    return contacts;
}



int read_user_file(struct usr** users, int* count) {
    FILE *fp = fopen("user.dat", "r");
    if (fp == NULL) {
        printf("Error: user.dat not found\n");
        *count = 0;
        return 0;
    }

    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    int estimatedCount = fileSize / 40; // Adjusted estimate per user record
    *users = (struct usr*)malloc(estimatedCount * sizeof(struct usr));
    if (*users == NULL) {
        fclose(fp);
        *count = 0;
        return 0;
    }

    int i = 0;
    while (fscanf(fp, "%19s %19s", (*users)[i].username, (*users)[i].password) != EOF) {
        i++;
        if (i >= estimatedCount) {
            estimatedCount *= 2;
            *users = (struct usr*)realloc(*users, estimatedCount * sizeof(struct usr));
            if (*users == NULL) {
                fclose(fp);
                *count = i;
                return 0;
            }
        }
    }
    fclose(fp);
    *count = i;
    return 1;
}
