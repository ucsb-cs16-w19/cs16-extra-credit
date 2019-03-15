#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>

typedef struct PAGE
{
	int TotalItem;		//1.共多少条数据
	int TotalPage;		//2.共多少页
	int CurrentPage;		//3.当前是第几页
	int OnePageItem;		//4.一页显示多少条数据
}Page;

typedef struct NODE
{
	int serialNum;
	char* name;
	char* phone;
	struct NODE* pNext;
}Node;

char *str_copy(char *des, const char *src);
int GetSerialNum();
Node* GetNode();
Node* GetNodeInput();
char* GetName();
char* GetPhone();
void InsertNode(Node** ppHead,Node** ppEnd, int serialNum,Node* node);  
void AddNode(Node** ppHead,Node** ppEnd,Node* node);
void DelNode(Node** ppHead,Node** ppEnd,int serialNum);
void InitInfo(Node** pHead,Node** pEnd,int n);
Page* GetPage(Node* pHead, int onePageItem);
void ShowMenu(Page* page);
void ShowInfo(Node* pHead,Page* page);
void OperatePage(Node* pHead,Page* page);
char* GetString();
void LookTXL(Node* pHead);
char Getkey();
void Query(Node* pHead);
void Del(Node** pHead,Node** pEnd);
void Edit(Node* pHead);
