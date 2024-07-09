# ifndef encrypt_h
# define encrypt_h

char* cal_md5(char* password);
int md5_str2int(char* md5);
char* caesar(char* contact, char* mdString)
char* decaesar(char* mdString , char* raw_contact);

# endif