#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

struct Hospital{
    int con;
    char name[50],condition[50];
    struct Hospital *next,*prev;
}*head[SIZE],*tail[SIZE];


void insertqueue(Hospital *node,char name[],char condition[])
{
    if(head[1]==NULL)
    {
        head[1]=tail[1]=node;
        return;
    }
    tail[1]->next=node;
    node->prev=tail[1];
    tail[1]=node;
}

void insertGoodFair(Hospital *curr)
{
    Hospital *node=(Hospital*)malloc(sizeof(Hospital));
    if(head[2]==NULL)
    {
        head[2]=tail[2]=node;
        strcpy(node->name,curr->name);
        strcpy(node->condition,curr->condition);
        return;
    }
    tail[2]->next=node;
    node->prev=tail[2];
    tail[2]=node;
    strcpy(node->name,curr->name);
    strcpy(node->condition,curr->condition);
    printf("%s is in consultation room\n",node->name);
}

void insertSerious(Hospital *curr)
{
    Hospital *node=(Hospital*)malloc(sizeof(Hospital));
    if(head[3]==NULL)
    {
        head[3]=tail[3]=node;
        strcpy(node->name,curr->name);
        strcpy(node->condition,curr->condition);
        return;
    }
    tail[3]->next=node;
    node->prev=tail[3];
    tail[3]=node;
    strcpy(node->name,curr->name);
    strcpy(node->condition,curr->condition);
    printf("%s is in examination room\n",node->name);
}

void insertCritical(Hospital *curr)
{
    Hospital *node=(Hospital*)malloc(sizeof(Hospital));
    if(head[4]==NULL)
    {
        head[4]=tail[4]=node;
        strcpy(node->name,curr->name);
        strcpy(node->condition,curr->condition);
        return;
    }
    tail[4]->next=node;
    node->prev=tail[4];
    tail[4]=node;
    strcpy(node->name,curr->name);
    strcpy(node->condition,curr->condition);
    printf("%s is in emergency room\n",node->name);
}


int check(Hospital *curr,char condition[])
{
    if(strcmp(condition,"Good")==0)
    {
        curr->con=1;
        return 1;
    }
    if(strcmp(condition,"Fair")==0)
    {
        curr->con=2;
        return 2;
    }
    if(strcmp(condition,"Serious")==0)
    {
        curr->con=3;
        return 3;
    }
    if(strcmp(condition,"Critical")==0)
    {
        curr->con=4;
        return 4;
    }
	return 0;
}

void deletequeue(Hospital *curr)
{
    int x;
    if(strcmp(curr->condition,"Good")==0||strcmp(curr->condition,"Fair"))
    {
        x=2;
    }
    else if(strcmp(curr->condition,"Serious"))
    {
        x=3;
    }
    else if(strcmp(curr->condition,"Critical"))
    {
        x=4;
    }

    if(head[x]==tail[x])
    {
        head[x]=tail[x]=NULL;
        free(curr);
        return;
    }
    if(head[x]==curr)
    {
        head[x]=head[x]->next;
        head[x]->prev=NULL;
        free(curr);
        return;
    }
    if(tail[x]==curr)
    {
        tail[x]=tail[x]->prev;
        tail[x]->next=NULL;
        free(curr);
        return;
    }
    curr->prev->next=curr->next;
    curr->next->prev=curr->prev;
    free(curr);
}

void move(char name[])
{
    Hospital *curr=head[1];
    int x;
    while(curr!=NULL)
    {
        if(strcmp(curr->name,name)==0)
        {
            break;
        }
        curr=curr->next;
    }

    if(strcmp(curr->condition,"Good")==0)
    {
        insertGoodFair(curr);
        deletequeue(curr);
    }
    else if(strcmp(curr->condition,"Fair")==0)
    {
        insertGoodFair(curr);
        deletequeue(curr);
    }
    else if(strcmp(curr->condition,"Serious")==0)
    {
        insertSerious(curr);
        deletequeue(curr);
    }
    else if(strcmp(curr->condition,"Critical")==0)
    {
        printf("Oh no");
        insertCritical(curr);
        deletequeue(curr);
    }
}

void search()
{
    int max=0,n;
    Hospital *curr=(Hospital*)malloc(sizeof(Hospital));
    Hospital *node=(Hospital*)malloc(sizeof(Hospital));
    curr=head[1];
    node=head[1];
    printf("%s",curr->name);
    while(curr!=NULL)
    {
        n=check(curr,curr->condition);
        if(max<=n)
        {
            max=n;
        }
        curr=curr->next;
    }

    while(node!=NULL)
    {
        if(node->con==max)
        {
            break;
        }
        node=node->next;
    }

    if(max==0)
    {
        printf("No Patient is Queing!\n");
    }
    else
    {
        move(node->name);
    }
}

void traverse()
{
    int x;
    printf("Waiting Room: ");
    Hospital *curr=head[1];
    while(curr!=NULL)
    {
        printf("%s, ",curr->name);
        curr=curr->next;
        x=1;
    }
    if(x==0)
    {
        printf("No one\n");
    }
}

int main()
{
    int input;
    char condition[30],name[30],action[30];
    scanf("%d",&input);
    for(int i=0; i<input; i++)
    {
        scanf("%s",action);
        if(strcmp(action,"CALL")==0)
        {
            search();
        }
        else if(strcmp(action,"ADD")==0)
        {
            scanf("%s %s",name,condition);
            Hospital *node=(Hospital*)malloc(sizeof(Hospital));
            strcpy(node->name,name);
            strcpy(node->condition,condition);
            node->prev=NULL;
            node->next=NULL;
            insertqueue(node,name,condition);
        }
    }
    traverse();
    return 0;
}