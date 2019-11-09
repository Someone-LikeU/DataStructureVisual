#include "LinkList.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


//*********************************************************
//函数功能：头插法创建链表
//输入参数：无
//输出参数：无
//返回值： 	成功创建则返回一个链表表头，否则返回NULL
//*********************************************************
List CreateListInsertHead()
{
	List Head;
	node cur;
	int num;
	Head = ( node ) malloc( SIZE );
	if ( Head == NULL )
	{
		printf( "Memory allocation failed, program exit !\n" );
		system( "pause" );
		return NULL;
	}
	Head->Next = NULL;
	printf( "请输入一些数，以空格分隔，以#结束。\n" );
	while ( scanf( "%d", &num ) == 1 )
	{
		cur = ( node ) malloc( SIZE );
		if ( cur == NULL )
		{
			printf( "Memory allocation failed, program exit !\n" );
			system( "pause" );
			return NULL;
		}
		cur->Element = num;
		cur->Next = Head->Next;
		Head->Next = cur;
	}
	return Head;
}

//*********************************************************
//函数功能：尾插法创建链表
//输入参数：无
//输出参数：无
//返回值： 	成功创建则返回一个链表表头，否则返回NULL
//*********************************************************
List CreateListInsertRear( )
{
	List Head;	  //头结点
	node cur, pre;
	int num;
	pre = ( node ) malloc( SIZE );   //生成头节点
	Head = pre;
	Head->Next = NULL;
	if ( Head == NULL )
	{
		printf( "Memory allocation failed, program exit !\n" );
		system( "pause" );
		return NULL;
	}
	printf( "请输入一些数，以#结束\n" );  //以特殊字符结束创建
	while ( scanf( "%d", &num ) == 1 )
	{
		cur = ( node ) malloc( SIZE );
		if ( cur == NULL )
		{
			printf( "Memory allocation failed, program exit !\n" );
			return NULL;
		}
		cur->Element = num;
		cur->Next = NULL;
		pre->Next = cur;
		pre = cur;
	}
	return Head;
}

//*********************************************************
//函数功能：判断一个链表是否为空表
//输入参数：一个链表的表头
//输出参数：无
//返回值： 	bool类型变量
//*********************************************************
bool IsEmpty( List Head )
{
	return Head->Next == NULL;
}

//*********************************************************
//函数功能：判断所给头结点是否为空
//输入参数：表头
//输出参数：无
//返回值： 	bool值
//*********************************************************
bool IsExist( List Head )
{
	if  ( Head == NULL )
	{
		printf("WTF!\n");
	}
	return Head == NULL;
}

int TravelList( List Head )
{
	if ( IsExist( Head ) )		//先判断这个头节点是否存在
	{
		printf( "链表不存在.\n" );
		return 1;
	}
	if ( IsEmpty( Head ) )	   //再判断是否为空
	{
		printf( "这是个空表.\n" );
		return 1;
	}
	printf( "链表包含如下元素：\n" );
	node cur = Head->Next;
	while ( cur != NULL )
	{
		printf( "%2d ", cur->Element );
		cur = cur->Next;
	}
	return 0;  //成功遍历，返回0
}

//*********************************************************
//函数功能：销毁链表
//输入参数：一个表头
//输出参数：无
//返回值： 	失败返回1，成功返回0
//*********************************************************
int DestoryList( List Head )
{
	if ( IsEmpty( Head ) ) //判断是否为空，是的话能剩下循环时间
	{
		free(Head);
		Head = NULL;
		return 0;
	}
	node P, Temp;
	P = Head;	 //首元素的位置
	while ( P != NULL )
	{
		Temp = P->Next;
		free( P );
		P = Temp;
	}
	return 0;
}

//*********************************************************
//函数功能：将链表分解成奇数元素链表和偶数元素链表
//输入参数：一个表头
//输出参数：无
//返回值： 	0表示成功，1表示失败
//*********************************************************
int Separate (List Head)
{
    List p1, p2;  //暂存奇偶元素的两个表
    p1 = (node)malloc(SIZE);
    p2 = (node)malloc(SIZE);
    if ( p1 == NULL || p2 == NULL )
    {
        printf("memory allocate failed!\n");
        system("pause");
        return 1;
    }
    p1->Next = NULL;
    p2->Next = NULL;
    node cur = Head->Next, t, Tp1, Tp2;
    Tp1 = p1; //tp1，tp2用于尾插法创建新表
    Tp2 = p2;
    while (cur != NULL)
    {
        t = (node)malloc(SIZE);  //cur != NULL, 就先生成个结点
        if( t == NULL )
        {
            printf("memory allocate failed!\n");
            system("pause");
            return 1;
        }
        t->Element = cur->Element;
        t->Next = NULL;
        if (cur->Element % 2 == 0)  //偶数，放到p1中
        {
            Tp1->Next = t;
            Tp1 = t;
        }
        else                                //奇数，放到p2中
        {
        	Tp2->Next = t;
            Tp2 = t;
        }
        cur = cur->Next;
    }
    printf("原表为：");                 //输出原表和分开的表
    TravelList(Head);
    printf("\n偶数表：");
    TravelList(p1);
    printf("\n奇数表：");
    TravelList(p2);
    DestoryList(p1);                    //销毁表1，和表2
    DestoryList(p2);
    return 0;
}

//*********************************************************
//函数功能：将两个递增有序表的公共元素放入新链表中
//输入参数：表1，2，3
//输出参数：无
//返回值： 	  成功返回新表表头，失败返回空指针
//*********************************************************
List FindCommon( List L1, List L2 )
{
	List L = NULL;			//要返回的新表
	node p = (node)malloc(SIZE);
	node p1, p2,cur;
	if ( NULL == p )
	{
		printf("memory allocate failed. Please try again.");
		return NULL;
	}
	p->Next = NULL;
	L = p;							//到此尾插法准备工作完毕
	p1 = L1->Next;
	p2 = L2->Next;
	while ( p1 != NULL && p2 != NULL )
	{
		if  ( p1->Element < p2->Element )
			p1 = p1->Next;
		else if ( p1->Element > p2->Element )
			p2 = p2->Next;
		else 											//相等，就尾插到新表
		{
			cur = (node)malloc(SIZE);
			if ( NULL == cur )
			{
				printf("memory allocate failed. Please try again.");
				return NULL;
			}
			cur->Element = p1->Element;
			cur->Next = NULL;
			p->Next = cur;
			p = cur;						//尾插操作完成
			p1 = p1->Next;			//后移p1,p2
			p2 = p2->Next;
		}
	}
	return L;								//返回新表表头
}

//*********************************************************
//函数功能：删除递增有序表中重复元素
//输入参数：表头
//输出参数：去重后的表
//返回值： 	  无
//*********************************************************
void OrderedListDelSame( List Head )//不对，还有一组1 2 3 4 5 6 7 7 7 10没过 11.11日22.20
{
	node p1, p2, t; //p1,p2遍历表，t，u用来删除结点
	p1 = Head->Next;
	p2 = p1->Next;
	while ( p2  != NULL )
	{
		if ( p1->Element != p2->Element ) //如果相邻两个结点元素不等
		{
			p1 = p1->Next;								 //就同时后移p1,p2
			p2 = p2->Next;
		}
		else 	//相等，则后移p2直到第一个不等于p1的结点，
		{
			while ( p2 != NULL && p2->Element == p1->Element )
			{
				t = p2;					//一边后移一边回收重复结点
				p2 = p2->Next;
				free(t);
			}
			p1->Next = p2;
		}
	}
}

//*********************************************************
//函数功能：按序号删除结点
//输入参数：位置i，表头
//输出参数：无
//返回值： 	int型变量，0表示成功，1表示失败
//*********************************************************
int DeleteElement( int i, List Head )
{
	if ( IsEmpty( Head) ) //空表，返回1
	{
		printf("空表，请先创建一个表\n");
		return 1;
	}
	int len = ListLength( Head );
	if ( i < 1 || i > len )
	{
		printf("位置越界，请重选 \n");
		return 1;
	}
	node cur, u;
	cur = Head;
	int j = 1;
	while ( j < i )		//找到第i号结点的前驱结点
	{
		cur = cur->Next;
		j++;
	}
	u = cur->Next; //u就为目标结点
	cur->Next = u->Next;	//跨过u，实现删除
	free(u);
	u = NULL;
	return 0;
}

//*********************************************************
//函数功能：在第i个结点插入元素x
//输入参数：ElementType 变量X ，一个表头，一个位置插入位置结点
//输出参数：无
//返回值： 	int型变量，0表示成功，1表示失败
//*********************************************************
int Insert( ElementType X, List Head, int i )
{
	if ( IsExist( Head ) )	//先判断如果头结点不存在，提示并返回失败
	{
		printf( "This list does not exist, please create it first.\n" );
		return 1;
	}
	else if ( i < 1 || i > ListLength( Head ) + 1) //越界
		return 1;

	node pre, New;		  //pre指针指向P这个结点的前一个结点
	New = ( node ) malloc( SIZE );	 //新分配一个结点
	if ( New == NULL )
	{
		printf( "Memory allocation failed.\n" );
		return 1;
	}
	pre = FindPrevious( i, Head );	//第i- 1个结点
	New->Element = X;
	New->Next = pre->Next;					//New结点的下一个结点是pre的下一个结点
	pre->Next = New;						//pre的下一个结点是new
	return 0;
}

//*********************************************************
//函数功能：在递增有序表中插入元素，插入后仍然有序
//输入参数：ElementType 变量X ，表头
//输出参数：无
//返回值： 	int型变量，0表示成功，1表示失败
//*********************************************************
int InsertIncrease( ElementType x, List Head )
{
    node cur = Head,p;
    while ( cur->Next != NULL && cur->Next->Element < x )  //找到最后一个小于待插入元素的结点
    {
        cur = cur->Next;
    }
    p = (node)malloc(SIZE); //分配新节点
    if ( NULL == p )
    {
        printf("memory allocate failed.\n");
        return 1;
    }
    p->Element = x;
    p->Next = cur->Next;
    cur->Next = p;
    return 0;
}

//*********************************************************
//函数功能：计算链表长度
//输入参数：一个表头
//输出参数：无
//返回值： 	 成功返回表长度，失败返回-1
//*********************************************************
int ListLength( List Head )
{

	if (IsExist(Head) )
	{
		printf("return -1.\n");
		return -1;
	}
	node cur = Head->Next;
	int count = 0;
	while ( cur != NULL )
	{
		count++;
		cur = cur->Next;
	}
	return count;
}

//*********************************************************
//函数功能：找到元素X所在结点
//输入参数：ElementType类型变量X，链表表头
//输出参数：无
//返回值： 	元素存在就返回一个结点指针，否则返回一个NULL指针
//*********************************************************
node Find( ElementType X, List Head )
{
	node cur = Head->Next;
	while (  cur != NULL &&  cur->Element != X )  //找到目标结点
	{
		cur = cur->Next;
	}
	if ( cur == NULL )	//找到最后cur为空，说明元素不存在，提示用户并返回NULL
	{
		printf( "不存在元素%d，请重选\n", X);
		return NULL;
	}
	else									   //元素存在，返回这个结点
	{
		return cur;
	}
}

//*********************************************************
//函数功能：返回第i个节点的前驱结点
//输入参数：第i个结点,表头
//输出参数：无
//返回值： 	  元素存在，就返回一个结点指针，否则返回空
//*********************************************************
node FindPrevious( int i, List Head )
{
	int len = ListLength(Head);
	if (i < 1 || i > len )
	{
		printf("位置越界，请重试。\n");
		return NULL;
	}
	node cur = Head; //要从第一个数据结点开始找，所以把头节点赋给cur
	int j;
	for ( j = 0 ; j < i - 1 ; j++ )
		cur = cur->Next;
	return cur;
}

//*********************************************************
//函数功能：按序号取结点元素
//输入参数：头指针
//输出参数：无
//返回值： 	链表里第i个结点的元素, -1表示越界
//*********************************************************
ElementType GetElementInOrder( List Head, int i )
{
	int total = ListLength( Head ), t = 1;
	node cur = Head->Next; //第一个结点
	if ( i < 1 || i > total )  //越界
	{
	    return -1;
	}
	while ( t != i )
	{
		cur = cur->Next;
		t++;
	}
	return cur->Element;
}

//*********************************************************
//函数功能：原地逆置一个单链表
//输入参数：一个表头
//输出参数：逆置后的表
//返回值： 	1表示失败，0表示成功
//*********************************************************
int ReverseList( List Head )
{
	if(IsEmpty(Head) || ListLength(Head) == 1) //空表或着只有一个结点
		return 1;
	node p1, p2, t;
	p1 = Head;			 		//p1指向头节点
	p2 = p1->Next; 		//p2指向第一个元素结点
	t = p2->Next;				//t指向第二个元素结点
	p2->Next = NULL;    //先断开头结点和后面的连接
	while ( t != NULL )	//t指向NULL时就结束
	{
		p1 = p2;					//先后移三个指针
		p2 = t;
		t = t->Next;
		p2->Next = p1;		//依次逆置两个相邻结点的指向
	}
	Head->Next = p2;		//第一个元素结点
	return 0;
}

//*********************************************************
//函数功能：合并两个单链表形成一个集合，只留下表1的头
//输入参数：表1，2
//输出参数：表1
//返回值： 	  无
//*********************************************************
void UnionAandB( List L1, List L2 )
{
	node t, p1, p2, u, s; //t用于释放表2的结点，u为表2的临时指针
	p1 = L1->Next;			//从两个头结点开始遍历
	p2 = L2->Next;
	s = L1;//s为表1的结点的前驱结点，先让它指向头，防止表1为空时程序的bug
	while ( p1 != NULL && p2 != NULL )
	{
		if ( p1->Element == p2->Element )		//如果表1当前元素等于表2的
		{
			t = p2;							//临时指针
			p2 = p2->Next; 		//就后移p2，然后继续比较
			free(t);						//释放掉表2中比较过的结点
		}
		else if ( p1->Element < p2->Element )  //小于
		{
			s = p1;						//就后移p1，并保证s始终是p1的前驱结点
			p1 = p1->Next;
		}
		else  //大于，说明可以并入表1
		{		//由于都是递增，所以大于时t一定指向p1的前驱
			u = p2->Next; //临时指向p2的下一个结点
			p2->Next = s->Next;		//将表2中当前结点插入表1
			s->Next = p2;
			s = s->Next;		 //更新p1的前驱结点
			p2 = u; 				//再让p2指向原来p2的下一个节点
		}
	}
	//上面while结束后，表2可能没有遍历完，则表2剩下的结点都能并入
	while( p2 != NULL )
	{
		s->Next = p2;
		s = p2;
		p2 = p2->Next;
	}
	free(L2);//最后释放掉L2头结点
	L2 = NULL;
}

//*********************************************************
//函数功能：
//输入参数：
//输出参数：
//返回值：
//*********************************************************

//*********************************************************
//函数功能：实现集合C = A∩B
//输入参数：链表表示的集合A，B，C
//输出参数：表C
//返回值： 	  成功返回0，失败返回1
//*********************************************************
int AInsertBToC( List A, List B, List C )
{
	node pA, pB, pC, cur;			//以下用a，b，表示A，B表当前元素
	pA = A->Next;
	pB = B->Next;
	pC = C;
	cur = NULL; 						//cur为准备分配的新节点，准备工作完毕
	while ( pA != NULL && pB != NULL )
	{
		if ( pA->Element < pB->Element ) //a 小于 b
		{
			//printf("pA = pA->Next\n");
			pA = pA->Next;	//后移pA，继续比较
		}
		else if ( pA->Element > pB->Element ) //大于
		{
			//printf("pB = pB->Next\n");
			pB = pB->Next;		//就后移pB
		}
		else				//相等，就尾插到C，然后同时后移pA，pB
		{
			cur = (node)malloc(SIZE);
			if ( NULL == cur )		//分配内存失败，返回1
			{
				printf("Memory allocation failed!\n");
				return 1;
			}
			cur->Element = pA->Element;
			pC->Next = cur;
			pC = cur;					//尾插到C完毕，然后后移A，B
			pA = pA->Next;
			pB = pB->Next;
			//printf("pC = cur;\n");
		}
	}
	pC->Next = NULL;
	return 0;
}

//*********************************************************
//函数功能： 递增有序表A，B，实现C =  A∪B
//输入参数： 链表表示的集合A，B，C
//输出参数： 表C
//返回值： 	   成功返回0，失败返回1
//*********************************************************
int AUnionBToC( List A, List B, List C )
{
	node pA, pB, pC, cur;			//以下用a，b，表示A，B表当前元素
	pA = A->Next;
	pB = B->Next;
	pC = C;
	cur = NULL; 						//cur为准备分配的新节点，准备工作完毕
	while ( pA != NULL && pB != NULL )//为确保操作完后c表仍然递增有序，
	{ 																//每次比较后只尾插较小的那个到C
		cur = (node)malloc(SIZE);	//先分配结点，尾插到C，值根据后面的比较情况再赋
		if ( NULL == cur )
		{
			printf("Memory allocate failed.");			//分配内存失败，返回1
			return 1;
		}
		pC->Next = cur;
		pC = cur;
		if( pA->Element < pB->Element ) //a < b
		{
			cur->Element = pA->Element;
			pA = pA->Next;
		}
		else if( pA->Element > pB->Element ) //a > b
		{
			cur->Element = pB->Element;
			pB = pB->Next;
		}
		else  //a = b
		{
			cur->Element = pB->Element;
			pA = pA->Next;
			pB = pB->Next;
		}
	}
	//while执行完后，A，B可能还没遍历完，则剩下的都可以并入C
	while ( pB != NULL )
	{
		cur = (node)malloc(SIZE);
		if ( NULL == cur )
		{
			printf("Memory allocate failed.");
			return 1;
		}
		cur->Element = pB->Element;
		pC->Next = cur;
		pC = cur;
		pB = pB->Next;
	}
	while(pA != NULL)
	{
		cur = (node)malloc(SIZE);
		if ( NULL == cur )
		{
			printf("Memory allocate failed.");
			return 1;
		}
		cur->Element = pA->Element;
		pC->Next = cur;
		pC = pC->Next;
		pA = pA->Next;
	}
	pC->Next = NULL;
	return 0;
}

//*********************************************************
//函数功能： 集合实现C = A - B
//输入参数： 表头A，B，C
//输出参数： 表C
//返回值： 	   成功返回0，失败返回1
//*********************************************************
int ASubBToC( List A, List B, List C )
{
	node pA, pB, pC, cur;			//以下用a，b，表示A，B表当前元素
	pA = A->Next;
	pB = B->Next;
	pC = C;
	cur = NULL; 						//cur为准备分配的新节点，准备工作完毕
	while ( pA != NULL && pB != NULL )
	{
		if ( pA->Element < pB->Element )  //a < b说明a满足条件
		{
			cur = (node)malloc(SIZE);			//就分配新内存给C
			if (cur == NULL )
			{
				printf("memory allocate failed.\n");
				return 1;
			}
			cur->Element = pA->Element; //尾插到C
			pC->Next = cur;
			pC = cur;
			pA = pA->Next;
		}
		else if (pA->Element == pB->Element)	// 相等，说明不满足要求，同时后移
		{
			pA = pA->Next;
			pB = pB->Next;
		}
		else 				//大于，则后移B
		{
			pB = pB->Next;
		}
	}
	//上面while肯定是表B先结束遍历，则剩下的A肯定满足差集要求
	while ( pA != NULL )
	{
		    cur = (node)malloc(SIZE);			//就分配新内存给C
			if (cur == NULL )
			{
				printf("memory allocate failed.\n");
				return 1;
			}
			cur->Element = pA->Element; //尾插到C
			pC->Next = cur;
			pC = cur;
			pA = pA->Next;
	}
	cur->Next = NULL;
	return 0;
}

//*********************************************************
//函数功能： 集合实现A = A∩B
//输入参数： 表头A，B，C
//输出参数： 表C
//返回值： 	   无
//*********************************************************
void AInsertBToA( List A, List B )
{
	node pA, pB, t, u; //t为pA的前驱结点，u用于回收结点
	t = A;
	pA = A->Next;
	pB = B->Next;			//以下用a，b，表示A，B表当前元素
	while ( pA != NULL && pB != NULL )
	{
		if ( pA->Element == pB->Element ) //a = b,说明a满足交集要求，就同时后移pA，pB
		{
			 t = pA;
			 pA = pA->Next;
			 pB = pB->Next;
		}
		else if ( pA->Element > pB->Element)	//a > b,就后移pB，继续比较B后面的
		{
			pB = pB->Next;
		}
		else 		//a < b,说明a不满足交集要求，就往后边移动边回收结点
		{
			while ( pA->Element < pB->Element )
			{
				u = pA->Next;
				free(pA);
				pA = u;
			}
			t->Next = pA;		//更新t的指向
		}
	}
}

int AUnionBToA( List A, List B )
{
	node cur, pA, pB, s; //cur用于申请新节点，u为表2的临时指针
	pA = A->Next;			//从两个头结点开始遍历
	pB = B->Next;
	s = A;//s为pA的前驱结点，先让它指向头，防止表1为空时程序的bug
	while ( pA != NULL && pB != NULL )
	{
		if ( pA->Element > pB->Element )	//a > b，就可以并入b
		{
			cur = (node)malloc(SIZE);
			if ( NULL == cur )     			//分配失败，返回1
			{
				return  1;
			}
			cur->Element = pB->Element;
			cur->Next = pA;
			s->Next = cur;
			s = cur;
			pB = pB->Next;			//再后移pB，继续看B后面的是否满足条件
		}
		else if ( pA->Element < pB->Element ) //a < b,后移pA，继续比较
		{
			s = pA;    					//pA的前驱结点也不要忘了
			pA = pA->Next;
		}
		else 									//a = b,就同时后移再比较
		{
			s = pA;
			pA = pA->Next;
			pB = pB->Next;
		}
	}
	//B可能没有遍历完，则剩下的b都可以并入A
	while(pB != NULL )
	{
		cur = (node)malloc(SIZE);
		if ( NULL == cur )     			//分配失败，返回1
		{
			return  1;
		}
		cur->Element = pB->Element;
		cur->Next = pA;
		s->Next = cur;
		s = cur;
		pB = pB->Next;
	}
	return 0;
}

//*********************************************************
//函数功能： 集合实现A = A-B
//输入参数： 表A，B
//输出参数： 表A
//返回值： 	   成功返回0，失败返回1
//*********************************************************
int ASubBToA( List A, List B )
{
	node pA, pB, u, s; //cur用于申请新节点，u为表2的临时指针
	pA = A->Next;			//从两个头结点开始遍历
	pB = B->Next;
	s = A;
	while ( pA != NULL && pB != NULL )
	{
		if ( pA->Element == pB->Element )  //a = b,就把a这个结点回收掉，
		{
			u = pA->Next;
			free(pA);
			pA = u;
			s->Next = pA;					//然后更新s的next项和pB
			pB = pB->Next;
		}
		else if ( pA->Element > pB->Element )  //a > b,就后移pB，继续比较
		{
			pB = pB->Next;
		}
		else 								//a < b,就同时后移pA和它的前驱指针
		{
			s = s->Next;
			pA = pA->Next;
		}
	}
	return 0;
}

//*********************************************************
//函数功能： 找链表倒数第k个结点的值
//输入参数： 表头，位置k
//输出参数： 表A
//返回值： 	   成功返回0，失败返回1
//*********************************************************
int GetReverseOrder( List Head, int k )
{
	int len = ListLength( Head ),i = 0;
	if ( k < 1 || k > len )			//越界，返回1
	{
		return 0;
	}
	node cur = Head->Next;
	while ( i < len - k )				//倒数第k，那就蒸熟过去len - k个位置就行。
	{
		cur = cur->Next;
		i++;
	}
	printf("倒数第%d个位置上的元素为：%d", k, cur->Element );
	return 1;
}

//*********************************************************
//函数功能： 找两个等长升序链表所有元素的升序中位数
//输入参数： 表A，B
//输出参数： 无
//返回值： 	   中位数n
//*********************************************************
void FindMid( List A, List B )
{
	ElementType mid;
	node pA, pB;
	pA = A->Next;
	pB = B->Next;
	int len = ListLength( A ),i = 0; //两个表等长有序递增，所以两两比较len次
	while ( i < len )				//每次比较让mid等于较小的那个，最后mid就是要求的
	{
		if(pA->Element < pB->Element)
		{
			mid = pA->Element;
			pA = pA->Next;
		}
		else if ( pA->Element > pB->Element )
		{
			mid = pB->Element;
			pB = pB->Next;
		}
		else
		{
			mid = pB->Element;
			pB = pB->Next;
		}
		i++;
	}
	printf("中位数是%d \n",mid);
}

//*********************************************************
//函数功能： 判断递增表A是否是表B的子集
//输入参数： 递增表A，B
//输出参数： 无
//返回值： 	    true or false
//*********************************************************
bool AisSubB( List A, List B )
{
	node pA, pB;
	bool flag = true;
	pA = A->Next;
	pB = B->Next;
	while (pA != NULL && pB != NULL && flag)
	{
		if ( pA->Element < pB->Element )
		{
			flag = false;			//如果a<b，则说明肯定不是子集，flag设为false
		}
		else if ( pA->Element > pB->Element ) //a < b
		{
			pB = pB->Next;		//后移pB，继续比较
		}
		else 								//a = b,同时后移
		{
			pA = pA->Next;
			pB = pB->Next;
		}
	}
	return flag;
}
