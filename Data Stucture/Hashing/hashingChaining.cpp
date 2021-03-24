#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define size 10

struct nodeHash{
	char nama[21];
	int hashVal;
	struct nodeHash *next;
}*head[size], *tail[size], *curr;

int count;
int hash(char nama[])
{
	int jmAsc=0, hashVal;
	for(int i=0; i<strlen(nama); i++)
	{
		jmAsc=jmAsc+nama[i];
	}
	hashVal=jmAsc%size;
	return hashVal;
}

void insertHash(int hashVal, char nama[])
{
	curr=(struct nodeHash*)malloc(sizeof(struct nodeHash));
	strcpy(curr->nama, nama);
	curr->hashVal=hashVal;
	curr->next=NULL;
	
	if(head[hashVal]==NULL)
	{
		head[hashVal]=tail[hashVal]=curr;
	}
	else
	{
		tail[hashVal]->next=curr;
		tail[hashVal]=curr;
	}
	
}

void printData()
{
	printf("Hash Value | String \n");
	printf("--------------------\n");
	for(int i=0; i<size; i++)
	{
		if(head[i]!=NULL)
		{
			curr=head[i];
			printf("%-10d | ", curr->hashVal);
			while(curr!=NULL)
			{
				if(curr->next!=NULL)
					printf("%s -> ", curr->nama);
				else
					printf("%s\n", curr->nama);
				
				curr=curr->next;
			}
		}
	}
}

int searchData(int hashVal, char nama[])
{
	//int flag=0;
	count=0;
	curr=head[hashVal];
	if(head[hashVal]!=NULL)
	{
		curr=head[hashVal];
		while(curr!=NULL)
		{
			if(strcmp(curr->nama, nama)==0)
			{
				count++;
			}
			curr=curr->next;
		}
		if(count>0)
			return count;
		else return 0;
	}
	else
		return 0;
}

void removeData(int hashVal, char nama[])
{
	struct nodeHash *pCurr;
	//printf("\n%d", searchData(hashVal, nama));
	if(searchData(hashVal, nama)>0)
	{
		curr=head[hashVal];
		while(curr!=NULL && strcmp(curr->nama, nama)!=0)
			curr=curr->next;
		
		//printf("\n%s", curr->nama);
		
		if(curr==NULL)
			printf("Data is not found");
		else if(curr==head[hashVal] && curr==tail[hashVal])
		{
			head[hashVal]=tail[hashVal]=NULL;
			free(curr);
		}
		else if(curr==head[hashVal])
		{
			head[hashVal]=head[hashVal]->next;
			free(curr);
		}
		else if(curr==tail[hashVal])
		{
			pCurr=head[hashVal];
			
			pCurr->next=NULL;
			tail[hashVal]=pCurr;
			free(curr);
		}
		else
		{
			pCurr=head[hashVal];
			while(pCurr->next!=curr)
				pCurr=pCurr->next;
			pCurr->next=curr->next;
			free(curr);
		}
	}
	else
		printf("Data is not found");
}

void deleteAll()
{
	for(int i=0; i<size; i++)
	{
		if(head[i]!=NULL)
		{
			while(head[i]!=NULL)
			{
				curr=head[i];
				head[i]=head[i]->next;
				free(curr);
			}
			tail[i]=NULL;
		}
	}
}

int main()
{
	int menu, res;
	char nama[21];
	do{
		system("cls");
		printData();
		printf("1. Insert hash\n");
		printf("2. Search hash\n");
		printf("3. Delete hash\n");
		printf("4. Delete all\n");
		printf("5. Exit\n");
		printf("Insert menu: "); scanf("%d", &menu); getchar();
		switch(menu)
		{
			case 1:
				printf("Insert name: "); gets(nama);
				insertHash(hash(nama), nama);
				break;
			case 2:
				printf("Insert name need to be searched: "); gets(nama);
				res=searchData(hash(nama), nama);
				if(res>0)
					printf("\n%d Name %s is found at index %d", res,nama, hash(nama));
				else
					printf("\nName is not found");
				getchar();
				break;
			case 3:
				printf("Insert name need to be deleted: "); gets(nama);
				removeData(hash(nama), nama);
				break;
			case 4:
				deleteAll();
				break;
		}
		
	}while(menu!=5);
	
	return 0;
}
