#ifndef _LinkQueue
#define _LinkQueue
#define LMAXLEN 100
typedef int ElementType;
typedef struct  LNode                        //跟链表的结点定义一样的意思
{
    ElementType data;           //数据元素
    struct LNode *Next;          //下一个结点
}node;
typedef struct                       //将Front和Rear封装，表示一个队列结构
{
    node *Front;                    //队头
    node *Rear;                     //队尾
    int Length;                        //队列长度
}LinkQueue;

void InitLinkQueue( LinkQueue &Q );
bool IsLinkQueueEmpty( LinkQueue &Q );
bool IsLinkQueueFull( LinkQueue &Q );
int GetLinkQFront( LinkQueue &Q, ElementType &x );
int EnLinkQueue( LinkQueue &Q, ElementType &x );
int DeLinkQueue(LinkQueue &Q );
int TravelLinkQueue( LinkQueue &Q );
int CountLinkQ( LinkQueue &Q );
#endif // _LinkQueue
