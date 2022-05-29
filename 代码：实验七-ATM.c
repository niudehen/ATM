#include<stdio.h>
#include<stdlib.h> 
#include<string.h> 

struct Account
{
	char name[100];//���� 
	char tel[12];//�绰 
	char idCard[19];//���֤	
	char username[20];//�����˺ſ���
	char password[7];//���� 
	float money;//���
	
	struct Account * next; //��һ���˻����ĵ�ַ 
};
typedef struct Account Account; 

Account * head;//ָ��ͷ����ͷָ��
Account * tail;//ָ��β����βָ�� 

void showMenuEnglish()
{
	
}

void signUpChinese()
{
	//����һ����ڴ�ռ䣬�����ַ��ֵ��ָ��newNodeP�������ֲ�������ȫ�ֱ�����ͬѧ�ǹۿ�Ⱥ�����ƵC�����ڴ���䣩 
	Account * newNodeP=(Account *)malloc(sizeof(Account));
	printf("������������\n"); 
	scanf("%s",newNodeP->name);
	
	printf("������绰��\n");
	scanf("%s",newNodeP->tel); 
	
	printf("���������֤��\n");
	scanf("%s",newNodeP->idCard); 
	
	printf("�������˺ţ�\n");
	scanf("%s",newNodeP->username); //�˺�Ӧ���������и��ģ�Ӧ����ϵͳ���ɵģ�˼����ô����
	
	printf("���������룺\n");
	scanf("%s",newNodeP->password); 
	
	newNodeP->money=0.0f;
	newNodeP->next=NULL;
	
	//��ӽ�㵽������
	if(head==NULL)
	{
		head=newNodeP;
		tail=newNodeP;
	} 
	else
	{
		tail->next=newNodeP;
		tail=newNodeP;
	}
	
	printf("��ӳɹ�\n");
	system("pause");
}

void signInChinese()
{
	
}

void signOut()
{
	exit(0);
}

void showMenuChinese()
{
	while(1)
	{
		system("cls");
		printf("��1������\n");
		printf("��2����¼\n");
		printf("��3���˳�\n");
		int n;
		scanf("%d",&n);
		if(n==1)
		{
			signUpChinese();
		}
		else if(n==2)
		{
			signInChinese();
		}
		else if(n==3)
		{
			signOut();
		}
	}
}

struct Account
{
	char username[100];
	char password[100];
	
	struct Account * next;	
};
typedef struct Account Account;

Account * head=NULL;//ָ��ͷ����ָ��
Account * tail=NULL;//ָ��β����ָ�� 

int findAccount(Account a)
{
	Account *curP=head;
	while(curP!=NULL)
	{
		if((strcmp(curP->username,a.username)==0)
		&&(strcmp(curP->password,a.password)==0))
		{
			return 1;
		}
		curP=curP->next;
	}
	return 0;
}

void signIn()
{
	Account a;
	printf("�������˺ţ�\n");
	scanf("%s",a.username);
	
	printf("���������룺\n");
	scanf("%s",a.password);
	
	if(findAccount(a))
	{
		printf("��¼�ɹ���\n");	
	}
	else
	{
		printf("��¼ʧ��!\n");
	}
}

int loadData()
{
	FILE*fp=fopen("C:/atm.txt","r");
	if(fp==NULL)
	{
		return 0;
	}
	else
	{
		while(!feof(fp))
		{
				//�������
				Account *newNode=(Account *)malloc(sizeof(Account));
				
				//����ʼ��
				newNode->next=NULL;
				fscanf(fp,"%s %s\n",newNode->username,newNode->password); 
				
				//��ӵ�����
				if(head==NULL)
				{
					head=newNode;
					tail=newNode;
				} 
				else
				{
					tail->next=newNode;
					tail=newNode;
				}
		}	
		return 1;
	}
}

void printLinkedList()
{
	Account* curP=head;
	while(curP!=NULL)
	{
		printf("%s\t%s\n",curP->username,curP->password);
		curP=curP->next;
	}	
}
struct Account
{
	char username[100];
	char password[100];
	
	struct Account * next;	
};
typedef struct Account Account;

Account * head=NULL;//ָ��ͷ����ָ��
Account * tail=NULL;//ָ��β����ָ�� 
Account * curAccount=NULL;//��ǰ��¼�˻���ָ�� 

int findAccount(Account a)
{
	Account *curP=head;
	while(curP!=NULL)
	{
		if((strcmp(curP->username,a.username)==0)
		&&(strcmp(curP->password,a.password)==0))
		{
			curAccount=curP;
			return 1;
		}
		curP=curP->next;
	}
	return 0;
}

void updatePassword()
{
	printf("����������룺\n");
	char oldPassword[100];
	scanf("%s",oldPassword);
	if(strcmp(oldPassword,curAccount->password)==0)
	{
		printf("�����������룺\n");
		scanf("%s",curAccount->password);
		printf("�޸�����ɹ���\n");
	}
	else
	{
		printf("������󣬲����޸ģ�\n");
	}
}

void homePage()
{
	printf("Press...\n");
	printf("��...\n");
	updatePassword();
}

void signIn()
{
	for(int i=0;i<3;i++)
	{
		Account a;
		printf("�������˺ţ�\n");
		scanf("%s",a.username);
		
		printf("���������룺\n");
		scanf("%s",a.password);
		
		if(findAccount(a))
		{
			printf("��¼�ɹ���\n");	
			homePage();
			break;
		}
		else
		{
			printf("��¼ʧ��!\n");
		}
	}
}

int loadData()
{
	FILE*fp=fopen("C:/atm.txt","r");
	if(fp==NULL)
	{
		return 0;
	}
	else
	{
		while(!feof(fp))
		{
				//�������
				Account *newNode=(Account *)malloc(sizeof(Account));
				
				//����ʼ��
				newNode->next=NULL;
				fscanf(fp,"%s %s\n",newNode->username,newNode->password); 
				
				//��ӵ�����
				if(head==NULL)
				{
					head=newNode;
					tail=newNode;
				} 
				else
				{
					tail->next=newNode;
					tail=newNode;
				}
		}	
		return 1;
	}
}

void printLinkedList()
{
	Account* curP=head;
	while(curP!=NULL)
	{
		printf("%s\t%s\n",curP->username,curP->password);
		curP=curP->next;
	}	
}

int main()
{
	printf("Press 1, English Service\n");
	printf("��2�����ķ���\n");
	int language, status=loadData();
	scanf("%d",&language);
	if(language==1)
	{
		showMenuEnglish(); //��ʾ���в˵� 
	}
	else if(language==2)
	{
		showMenuChinese(); //��ʾӢ�Ĳ˵� 
	}
	
	if(status==1)
	{
		printf("���سɹ���\n");
		printLinkedList();
	}
	else
	{
		printf("����ʧ��!\n");
	}
	signIn();
	if(status==1)
	{
		printf("���سɹ���\n");
		printLinkedList();
	}
	else
	{
		printf("����ʧ��!\n");
	}
	signIn();
	
	saveData();
	
	return 0;
}




