#ifndef _seqQueue
#define _seqQueue
#define MAXLEN 100
typedef int ElementType;
typedef struct sQueue  //顺序表的定义
{
    ElementType data[MAXLEN];
    int Front;
    int Rear;
}seqQueue;
typedef seqQueue* Queue;

void InitialQueue(  seqQueue &Q );   //初始化队列
bool IsQueueEmpty( seqQueue &Q );   //判断队空
bool IsQueueFull( seqQueue &Q );    //判断队满
int GetQueueFront( seqQueue &Q,ElementType &x );    //取队头
int EnQueue( Queue Q, ElementType &x ); //入队
int DeQueue( Queue Q ); //出队
int TravelQueue( seqQueue &Q ); //遍历队中元素
int CoutElement( seqQueue &Q ); //计数队中元素
#endif // _seqQueue

