
#define GETPASSWORD     1


#define ANS_GETPASSWORD 1

struct user{
	int idnum_len;
	int pwd_len;
	char idnum[20];
	char pwd[20];
};

struct reg{
	char name[10];
	char idnum[20];
	char born[10];
	int sex;
	char old[5];
	char pwd[20];
};

struct protocol{
	int type;
	int data_len;
};