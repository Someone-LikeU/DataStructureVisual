#include "queueLink.h"
#include <iostream>
#include <cstdio>
using namespace std;

//*********************************************************
//函数功能：
//输入参数：
//输出参数：
//返回值：
//*********************************************************

//*********************************************************
//函数功能：初始化链队列,这是不带头结点的
//输入参数：队列的引用
//输出参数：初始化后的队列
//返回值： 	  无
//*********************************************************
void InitLinkQueue( LinkQueue &Q )
{
    //这是带头结点的做法，
    /*Q.Front = new node; //头结点，front指向它
    Q.Rear = Q.Front;       //rear也指向头结点
    Q.Front->Next = NULL;//头结点next设为NULL*/
    //不带头结点
    Q.Front = NULL;
    Q.Rear = NULL;
    Q.Length = 0;
}

//*********************************************************
//函数功能：判断队列是否为空
//输入参数：队列引用
//输出参数：无
//返回值： 	  true or false
//*********************************************************
bool IsLinkQueueEmpty( LinkQueue &Q )
{
    //return ( Q.Front == Q.Rear); //带头结点的做法
    return  Q.Length == 0;
}

//*********************************************************
//函数功能：判断队列是否满
//输入参数：队列引用
//输出参数：无
//返回值： 	  true or false
//*********************************************************
bool IsLinkQueueFull( LinkQueue &Q )
{
    return Q.Length == LMAXLEN;
}

//*********************************************************
//函数功能：取队头元素
//输入参数：队列的引用，待放入变量x
//输出参数：变量x
//返回值： 	  0表示成功，1表示失败
//*********************************************************
int GetLinkQFront( LinkQueue &Q, ElementType &x )
{
    if ( IsLinkQueueEmpty( Q ) )    //空队列，无法取队头元素，返回1
    {
        return 1;
    }
    else
    {
        //带头结点
        //x = ( (Q.Front)->Next)->data;  //队头是front->next指向的结点
        x = Q.Front->data;      //不带头结点
    }
}

//*********************************************************
//函数功能：入队
//输入参数：队列的引用，待入队元素x
//输出参数：无
//返回值： 	  成功返回0，失败返回1
//*********************************************************
int EnLinkQueue( LinkQueue &Q, ElementType &x)
{
    node *p = new node;         //申请新节点
    if ( NULL == p )    //分配失败，返回1
    {
        return 1;
    }
    if( LMAXLEN == Q.Length )
    {
        cout << "队满，不能再入队\n";
        return 1;
    }
    p->data = x;
    p->Next = NULL;            //相当于尾插法建链表
    //有头
    //Q.Rear->Next = p;               //新节点放到原表尾
    //Q.Rear = p;                           //尾指针指向新节点
    if (Q.Front == NULL )   //只有一个结点时再删除的情况
    {
        Q.Front = p;
    }
    if(Q.Rear!= NULL)
    {
        Q.Rear->Next = p;
    }
    Q.Rear = p;
    Q.Length++;     //更新长度
    return 0;
}

//*********************************************************
//函数功能：出队
//输入参数：队列引用
//输出参数：无
//返回值： 	  成功返回0，失败返回1
//*********************************************************
int DeLinkQueue(LinkQueue &Q )
{
    if (IsLinkQueueEmpty(Q) ) //空队列，无法出队，返回1
    {
        return 1;
    }
    else
    {
        node *t;
        //有头
        /*t = Q.Front->Next;          //暂时指向首元素结点
        Q.Front->Next = t->Next; //更新队头指针
        delete t;                               //释放内存
        t = NULL;
        if ( Q. Front->Next == NULL )   //如果删除结点后队空，就修改Rear指针
            Q.Rear = Q.Front;                   //不这样做的话，rear会变成野指针*/
        //无头
        t = Q.Front;
        Q.Front = t->Next;
        delete t;
        t = NULL;
        Q.Length--;         //长度减一
        if(Q.Front == NULL)
            Q.Rear = NULL;
    }
}

//*********************************************************
//函数功能：打印链队列中的元素
//输入参数：队列引用
//输出参数：无
//返回值：    成功0，失败1
//*********************************************************
int TravelLinkQueue( LinkQueue &Q )
{
    if( IsLinkQueueEmpty( Q ) ) //队空，返回1
    {
        return 1;
    }
    else            //队不空，就遍历
    {
        node *p = Q.Front;     //无头结点
        //node *p = Q.Front->Next;  //有头
        cout << "当前队列有元素：\n";
        while(p != NULL)
        {
            cout << p->data << " ";
            p = p->Next;
        }
        cout << endl;
    }
    return 0;       //return success 0
}

//*********************************************************
//函数功能：计数表中元素个数
//输入参数：表的引用
//输出参数：无
//返回值：    元素个数
//*********************************************************
int CountLinkQ( LinkQueue &Q )
{
    node *p = Q.Front;  //这是没有头结点的情况
    //node *p = Q.Front->Next; //youtou
    int total = 1;
    while(p != Q.Rear)
    {
        total++;
        p = p->Next;
    }
    return total;
}
