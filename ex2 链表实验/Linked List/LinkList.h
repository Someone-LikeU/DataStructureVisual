#ifndef _List_H
#define _List_H
#include <stdbool.h>
#define SIZE (sizeof(struct Node))
struct Node;			//定义见.c文件
typedef struct Node *List;
typedef struct Node *node;
typedef int ElementType;
struct Node
{
	ElementType Element;  		//数据项
	node        Next;						//下一个结点
};
List CreateListInsertHead(); //头插法创建
List CreateListInsertRear(); //尾插法创建
bool IsEmpty( List Head );
bool IsExist(List Head);
int ReverseList( List Head );
int DestoryList( List Head );
int TravelList( List Head );
int DeleteElement( int i, List Head );//按序号删除结点
int Insert( ElementType X, List Head, int i );//这个也一样，参数应该只给位置和表
int InsertIncrease( ElementType x, List Head );	//有序的插入
int ListLength( List Head );
int Separate ( List Head );							//分解奇偶数
List FindCommon( List L1, List L2);		  //将相同元素放到新表
void OrderedListDelSame( List Head ); //递增有序表去重
void UnionAandB( List L1, List L2 );	 //合并两表到表1,成为一个集合，11.8，19.42
node Find( ElementType X, List Head ); 	//按值取结点
node FindPrevious( int i, List Head );		//按序号取前驱结点
ElementType GetElementInOrder( List Head, int i ); //按序号取元素
int AInsertBToC( List A, List B, List C );  //C = A∩B //done at 11.12 11:40
int AUnionBToC( List A, List B, List C ); //C = A∪B  //done at 11.12 11:40
int ASubBToC( List A, List B, List C );     //C = A - B  //done at 11.12 22.37
void AInsertBToA( List A, List B ); 			//A = A∩B
int AUnionBToA( List A, List B );		   	//A =  A∪B
int ASubBToA( List A, List B );				//A = A-B
int GetReverseOrder( List Head, int k );  //找链表倒数第k个结点的值
void FindMid( List A, List B );
bool AisSubB( List A, List B );		//判断A是否是B的子集
#endif
