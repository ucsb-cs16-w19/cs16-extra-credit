#include "contacts.h"

/*=============================================================================
 |     Author:    JUNTONG JING
 |   To Compile:  make contacts 
 |
 |        Class:  CS16
 |            
 |    Concepts:  for loop, if else, switch, while loop, function, pointer, linkedlist
 |
 +-----------------------------------------------------------------------------
 |
 |  Description:  It is a contacts book, which has the functions to add, search, delete, 
 |                and edit contacts.
 |
 |        Input:  1-Open My Contacts Book
 |                2-Add New Contact
 |                3-Search
 |                4-Delete Contact
 |		  5-Edit Contact
 |		  q-Quit
 |                
 |                w-PreviousPage 
 |                s-NextPage 
 |		  b-MainMenu
 |
 | 		  c-NewSearch 
 |		  u-Edit 
 |		  d-Delete
 |
 |       Output:  Too many outputs! Try it yourself!
 |
 |    Algorithm:  OUTLINE THE APPROACH USED BY THE PROGRAM TO SOLVE THE
 |      PROBLEM.
 |
 |   Known Bugs: If you try to read or edit the new contacts you just added, it would                         |                produce a seg fault. :( 
 |      
 |
 *===========================================================================*/


int g_menu_type;
char g_key;

char *str_copy(char *des, const char *src)
{
     assert(src != NULL);
     assert(des != NULL);
     while ((*des++ = *src++) != '\0');
     return des;
}


int main()
{
	Node* pHead = NULL;
	Node* pEnd = NULL;
	Page* page ;
	char c;
	//Initialize 
	InitInfo(&pHead,&pEnd,120);

	while(1)
	{

		printf("1.Open My Contacts Book\n");
		printf("2.Add New Contact\n");
		printf("3.Search\n");
		printf("4.Delete Contact\n");
		printf("5.Edit Contact\n");
		printf("q.Quit\n");
		//Keys

		c = Getkey();

		switch(c)
		{
		case '1':
			g_menu_type = 1;
			LookTXL(pHead);
			break;
		case '2':
			AddNode(&pHead,&pEnd,GetNodeInput());
			break;
		case '3':
			g_menu_type = 3;
			Query(pHead);
			break;
		case '4':
			g_menu_type = 4;
			Del(&pHead,&pEnd);
			break;
		case '5':
			g_menu_type = 5;
			Edit(pHead);
			break;
		case 'q':
			return 0;	
		}

	}

	return 0;
}


int GetSerialNum()
{
	static int i = 0;
	return ++i;
}


Node* GetNode()
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->serialNum = GetSerialNum();
	node->name = GetName(); 
	node->phone = GetPhone();
	node->pNext =NULL;

	return node;
}


Node* GetNodeInput()
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->serialNum = GetSerialNum();
	printf("Please type in the name: \n");
	node->name = GetString(); 
	printf("Please type in the number: \n");
	node->phone = GetString();
	node->pNext =NULL;

	return node;
}


void AddNode(Node** ppHead,Node** ppEnd,Node* node)
{
	//Add
	if(NULL == *ppHead)
	{
		*ppHead = node;
	}
	else
	{
		//End's next points to the new node
		(*ppEnd)->pNext = node;
	}

	*ppEnd = node;
}


void InsertNode(Node** ppHead,Node** ppEnd, int serialNum,Node* node)
{
	Node* mark = *ppHead;
	if(*ppHead == NULL )
	{
		return;
	}

	//Determine if we want to insert to head
	if((*ppHead)->serialNum == serialNum)
	{
		node->pNext = *ppHead;
		*ppHead = node;
		return;
	}

	//Determine if we want to insert in the middle
	while(mark->pNext != NULL)
	{
		if(mark->pNext->serialNum == serialNum)
		{
			node->pNext = mark->pNext;
			mark->pNext = node;
			return ;

		}
		mark = mark->pNext;	
	}

	//Determine if we want to insert to end
	(*ppEnd)->pNext = node;
	*ppEnd = node;
}


void DelNode(Node** ppHead,Node** ppEnd,int serialNum)
{
	Node* mark = *ppHead;
	Node* pDel = NULL;
	//Delete Head
	if((*ppHead)->serialNum == serialNum)
	{
		//pDel is a pointer, point to the node we want to delete
		pDel = *ppHead;
		//move *ppHead
		*ppHead = (*ppHead)->pNext;
		//free
		free(pDel);
		pDel = NULL;
		return ;
	}

	//Delete a contact in the middle
	while(mark->pNext != NULL)
	{
		if(mark->pNext->serialNum == serialNum)
		{
			//pDel is a pointer, point to the node we want to delete
			pDel = mark->pNext;
			//First link the nodes on two sides of the target			                mark->pNext = mark->pNext->pNext;
			//free
			free(pDel);
			pDel = NULL;
			//Determine if we have deleted the end
			if(mark->pNext == NULL)
			{
				//ppend point to mark
				*ppEnd = mark;

			}
			return ;	
		}	
		mark = mark->pNext;	
	}
}


char* GetName()
{
	char* name = (char*)malloc( sizeof(char)*6 );
	int i;

	for(i=0;i<5;i++)
	{
		name[i] = rand()%26 + 97;
	}
	name[i] = '\0';
	return name;
}


char* GetPhone()
{
	//create 12 spaces of the size char*
	char* phone = (char*)malloc(12);
	int i;
	//Choose the first three nums 805 785 310 408
	switch(rand()%4)
	{
	case 0:
		str_copy(phone,"805");
		break;
	case 1:
		str_copy(phone,"785");
		break;
	case 2:
		str_copy(phone,"310");
		break;
	case 3:
		str_copy(phone,"408");
		break;
	}

	for(i=3;i<=10;i++)
	{
		phone[i] = rand()%10 + '0';
	}

	phone[i] = '\0';
	return phone;
}


void InitInfo(Node** pHead,Node** pEnd,int n)
{
	int i;
	srand((unsigned int)time(0));
	for(i=0;i<n;i++)
	{
		AddNode(pHead,pEnd,GetNode());
	}
}


Page* GetPage(Node* pHead, int onePageItem)
{
	Page* page = (Page*)malloc(sizeof(Page));
	page->TotalItem = 0;
	//Get into the list
	while(pHead)
	{
		page->TotalItem++;
		pHead = pHead->pNext;
	}
	page->OnePageItem = onePageItem;
	page->CurrentPage = 0;

	page->TotalPage = page->TotalItem % page->OnePageItem == 0 ?  page->TotalItem /  page->OnePageItem : page->TotalItem /  page->OnePageItem + 1;

	return page;
}

void ShowMenu(Page* page)
{
	switch(g_menu_type)
	{
	case 1:
		printf("CurrentPage: %d ; TotalPage(s): %d ; TotalContact(s): %d ; w-PreviousPage ; s-NextPage ; b-MainMenu\n",page->CurrentPage,page->TotalPage,page->TotalItem);
		break;
	case 3:
		printf("CurrentPage: %d ; TotalPage(s): %d ; TotalContact(s): %d ; w-PreviousPage ; s-NextPage ; c-NewSearch ; b-MainMenu\n",page->CurrentPage,page->TotalPage,page->TotalItem);
		break;
	case 4:
		printf("CurrentPage: %d ; TotalPage(s): %d ; TotalContact(s): %d ; w-PreviousPage ; s-NextPage ; c-NewSearch ; d-Delete ; b-MainMenu\n",page->CurrentPage,page->TotalPage,page->TotalItem);
		break;
	case 5:
		printf("CurrentPage: %d ; TotalPage(s): %d ; TotalContact(s): %d ; w-PreviousPage ; s-NextPage ; c-NewSearch ; u-Edit ; b-MainMenu\n",page->CurrentPage,page->TotalPage,page->TotalItem);
		break;
	}
}
void ShowInfo(Node* pHead,Page* page)
{
	//The number of contacts depends on our current page  
	int begin = (page->CurrentPage-1) * page->OnePageItem + 1;
	int end = page->CurrentPage * page->OnePageItem;
	int count = 0;
	while(pHead)
	{
		count++;
		if(begin <= count && count <= end)
		{
			printf("%d\t%s\t%s\n", pHead->serialNum,pHead->name,pHead->phone);
		}

		pHead = pHead->pNext;
	}
}


void OperatePage(Node* pHead,Page* page)
{
	char c = 's';
	int a;
	while(1)
	{

		// s ，w，b
		switch(c)
		{
		case 'w':
			if(1 == page->CurrentPage)
			{
				printf("It's already the first page!\n");
			}
			else
			{
				page->CurrentPage--;
				ShowInfo(pHead,page);
				ShowMenu(page);
			}
			break;
		case 's':
			if(page->CurrentPage == page->TotalPage)
			{
				printf("It's already the last page!\n");
			}
			else
			{
				page->CurrentPage++;
				ShowInfo(pHead,page);
				ShowMenu(page);
			}
			break;
		case 'b':
			return;
		case 'c':
			if(g_menu_type == 1)
			{
				printf("ERROR!\n");	
				break;
			}
			return;
			break;
		case 'd':
			return;
			break;
		case 'u':
			return;
			break;
		default:
			printf("CANNOT UNDERSTAND!\n");	
		}

		c = Getkey();	
		g_key = c;

	}
}




char* GetString()
{
	char c;
	char size = 5;
	char* str = (char*)malloc(size);
	char* newStr = NULL;
	char* mark = str;
	int count = 0;
	int a = 1;
	while((c=getchar()) != '\n' || a==1)
	{
		a = 0;
		if(c == '\n')
		{
			continue;
		}
		*str = c;
		str++;
		count++;
		if(count +1 == size)
		{
			size += 5;
			*str = '\0';
			newStr = (char*)malloc(size);
			str_copy(newStr,mark);
			free(mark);

			str = newStr + count;
			mark = newStr;
		}
	}

	*str = '\0';
	return mark;	
}

void LookTXL(Node* pHead)
{
	Page* page = GetPage(pHead,10);
	OperatePage(pHead,page);
}

//Get my input without wasting spaces, and take away my '\n'.
//Even if we input something in the buffer, where already exists a '\n', we can still 
//continue inputting
char Getkey()
{
	char c;
	char z = 0;
	int mark = 1;
	while((c=getchar()) != '\n' || mark == 1)
	{

		mark = 0;
		z = c;
	}

	return z;
}


void Query(Node* pHead)
{
	char* keyword = NULL;
	Node* node = NULL;
	Node* newHead = NULL;
	Node* newEnd = NULL;
	Node* pDel = NULL;
	Node* mark = pHead;

	while(1)
	{
		while(1)
		{
			printf("Please type in the key words: ");
			keyword = GetString();
			printf("Press 'a' to confirm, press other buttons to retype: ");
			if(Getkey() == 'a')
			{
				break;
			}
			else
			{
				free(keyword);
				keyword = NULL;
			}		
		}


		//Get into the link
		pHead = mark;
		while(pHead)
		{
			//Match the key words with contacts
			if(strncmp( pHead->phone,keyword,strlen(keyword) ) == 0 ||
				strncmp( pHead->name,keyword,strlen(keyword) ) == 0)
			{
				//Allocate a new node, and get the info
				node = (Node*)malloc(sizeof(Node));
				node->serialNum = pHead->serialNum;
				node->name = pHead->name;
				node->phone = pHead->phone;
				node->pNext = NULL;

				//Add
				AddNode(&newHead,&newEnd,node);
			}
			pHead = pHead->pNext;
		}


		//Determine if we find the target or not
		if(newHead != NULL)
		{
			LookTXL(newHead);
			//Free
			while(newHead)
			{
				pDel = newHead;
				newHead = newHead->pNext;
				free(pDel);
				pDel = NULL;
			}
			newHead = NULL;
			newEnd = NULL;

			//c b d u
			if(g_key == 'b' || g_key == 'd' || g_key == 'u')	 
			{
				return ;
			}
		}
		else
		{
			printf("NO RESULT\n");
		}
	}
}


void Del(Node** pHead,Node** pEnd)
{
	int serialNum;
	while(1)
	{
		//Query func
		Query(*pHead);

		if(g_key == 'b')
		{
			return ;
		}

		printf("Please type in the serial number of the contact you want to delete: ");
		serialNum = atoi(GetString());
		DelNode(pHead,pEnd,serialNum);

		printf("Press 'y' to continue deleting, press other buttons to return to the main menu: ");
		if(Getkey() != 'y')
		{
			return;
		}
	}	

}

void Edit(Node* pHead)
{
	int serialNum;
	Node* mark = pHead;

	while(1)
	{
		pHead = mark;
		Query(pHead);

		if(g_key == 'b')
		{
			return;
		}

		printf("Please type in the serial number of the contact you want to edit: ");
		//serialNum = atoi(GetString());
		scanf("%d",&serialNum);
		//Look for the target
		while(pHead )
		{
			if(pHead->serialNum == serialNum)
			{
				printf("Please type in the new name: ");
				free(pHead->name);
				pHead->name = GetString();
				printf("Please type in the new number: ");
				free(pHead->phone);
				pHead->phone = GetString();
			}
			pHead = pHead->pNext;
		}

		printf("Press 'y' to continue deleting, press other buttons to return to the main menu: ");
		if(Getkey() != 'y')
		{
			return;
		}
	}
}
