#ifndef List_Array
#define List_Array
#include <stdbool.h>
#define MAXLEN 100
#define ElementType int
struct sList
{
    ElementType data[MAXLEN];   //用来存放元素的数组
    int listLen;                //记录表长度
};
typedef struct sList seqList;
typedef struct sList &ptList;   //指向这个结构的引用

int GetElement( ptList L, ElementType *x, int i );//按序号取值
int InsertElement( ptList L, ElementType x, int i );//在第i个结点前插入值为x的结点
int DeleteElementOrder( ptList L, int i );//删除第i个结点
int OrderInsert( ptList L, ElementType x ); //在递增有序顺序表插入元素，插入后仍有序
int seprate( ptList L , ptList A, ptList C );
int func6( ptList L1, ptList L2, ptList L3 );
int OrderedListDeleteSame( ptList A );      //删除有序顺序表的重复元素
void AunionBtoA( ptList A, ptList B );      //A = AUB
void InterSecToA( ptList A, ptList B );     //A = A∩B
void SubtractToA( ptList A, ptList B );     //A = A-B
void Intersection( ptList A, ptList B, ptList C ); //C=A∩B
void Union( ptList A, ptList B, ptList C ); //C = A U B
void setSubtract( ptList A, ptList B, ptList C );   //C = A-B
bool IsSub( ptList A, ptList B );           //判断递增表A，B，A是否是B的子集
int L1pulsL2ToL1( ptList L1, ptList L2 );   //合并集合表1，2
int FindMidNum( ptList L1, ptList L2 );     //找到两个递增有序表的中位数

//以上是本次实验的题目，以下函数是测试辅助函数

int TravelList( ptList L );                 //遍历列表，用于测试前面的函数
int DeleteElement( ptList L, ElementType x );//按值删除元素，用测试前面的函数
bool IsEmpty( ptList L );
void InitialList( ptList L );
bool IsFull( ptList L );
#endif // List_Array
