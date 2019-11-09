#ifndef _StackLink
#define _StackLink

typedef char ElementType;
struct node                         //链表结点
{
    ElementType data;
    node* Next;
};
class LinkStack         //定义链栈类
{
private :
    node *Head;          //头结点
public:
    void InitiStack();
    void Push(ElementType &x);
    bool Pop();
    bool Top(ElementType &x);
    bool StackEmpty();
    void TravelStack();
    void DestoryStack();        //销毁栈
};

void LinkChangeScale(int n, int mode );     //进制转换
bool LinkIsmatch( char *str );                      //判断运算表达式括号是否匹配
#endif // _StackLink
