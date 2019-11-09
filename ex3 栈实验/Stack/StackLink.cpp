#include "StackLink.h"
#include <iostream>
#include <cstdio>
using namespace std;

//*********************************************************
//函数功能：初始化链栈
//输入参数：无
//输出参数：无
//返回值： 无
//*********************************************************
void LinkStack::InitiStack()
{
    LinkStack::Head = new node; //先分配头结点
    LinkStack::Head->Next = NULL;//然后让它指空
}

//*********************************************************
//函数功能：入栈
//输入参数：elementype的引用x
//输出参数：无
//返回值： 无
//*********************************************************
void LinkStack::Push(ElementType &x)
{
    node *s = new node;
    if ( NULL == s )  //分配失败，返回到主调函数
    {
        cout << "memory allocate failed. please try again.\n" ;
        return;
    }
    s->data = x;
    s->Next = LinkStack::Head->Next;//头插法入链表
    LinkStack::Head->Next = s;
}

//*********************************************************
//函数功能：取栈顶元素
//输入参数：elementype的引用x
//输出参数：无
//返回值： true or false
//*********************************************************
bool LinkStack::Top(ElementType &x)
{
    if(LinkStack::StackEmpty())     //栈空，返回false
        return false;
    x = LinkStack::Head->Next->data;        //给x赋值，返回成功
    return true;
}

//*********************************************************
//函数功能：弹栈顶
//输入参数：无
//输出参数：无
//返回值： true or false
//*********************************************************
bool LinkStack::Pop()
{
    if (LinkStack::StackEmpty())        //站为空，返回false
        return false;
    node *t = LinkStack::Head->Next; //待删除的结点，用一个临时指针指向它
    LinkStack::Head->Next = t->Next; //更新头结点的指向
    delete t;                                              //释放内存
    t = NULL;
    return true;
}

//*********************************************************
//函数功能： 判断栈是否为空
//输入参数：无
//输出参数：无
//返回值： true or false
//*********************************************************
bool LinkStack::StackEmpty()
{
    return LinkStack::Head->Next == NULL;
}

//*********************************************************
//函数功能：从栈底开始遍历栈元素
//输入参数：无
//输出参数：无
//返回值：     无
//*********************************************************
void LinkStack::TravelStack()
{
    node *t = LinkStack::Head->Next;
    while (t != NULL)
    {
        cout << t->data;
        t = t->Next;
    }
    cout << endl;
}
//*********************************************************
//函数功能：销毁链栈
//输入参数：无
//输出参数：无
//返回值：    无
//*********************************************************
void LinkStack::DestoryStack()
{
    bool Notdone;
    do
    {
        Notdone = LinkStack::Pop(); //由Pop函数的返回值来判断栈空
    }while(Notdone == true);
    delete LinkStack::Head;     //再释放头结点
    LinkStack::Head = NULL;
}

//*********************************************************
//函数功能： 利用链栈做进制转换
//输入参数： 十进制待转换数n，目标进制mode
//输出参数：无
//返回值： true or false
//*********************************************************
void LinkChangeScale(int n, int mode )
{
    LinkStack S;        //先来一个链栈对象
    S.InitiStack();     //然后初始化
    int m,t = n;
    char characters[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8','9', 'A', 'B', 'C', 'D', 'E', 'F'};//16进制的各字符
    while (n != 0)                  //短除法
    {
        m = n % mode;
        S.Push(characters[m]);//入栈对应字符
        n /= mode;
    }
    printf("\n%d的%d进制表示为: ",t, mode);
    S.TravelStack();
    S.DestoryStack();
    cout << endl;
}

//*********************************************************
//函数功能：判断一个表达式中的括号是否匹配
//输入参数：表达式字符串
//输出参数：无
//返回值： 	  true or false
//*********************************************************
bool LinkIsmatch( char *str )       //done at 11.20  20.55
{
    bool ismatch = true;    //先假设 都匹配
    int i = 0, j = -1;        //i用来遍历表达式字符串，j用来选择括号类型
    LinkStack S;            //一个链栈对象
    S.InitiStack();         //先初始化
    ElementType t;      //存放栈顶元素
    char brac[3] = {'(', '[', '{'};
    while (str[i] != '\0' && ismatch)      //表达式未遍历完或者ismatch为真
    {
        if(str[i] == '(' || str[i] == '[' || str[i] == '{')         //如果看到的是左括号，就入栈
        {
            S.Push(str[i]);
        }
        else        //不是左括号，就是运算符或数字
        {
            switch (str[i])         //分情况判断
            {
            case ')':                   //看是哪种括号，然后给j赋值，后面用j来处理
                j = 0;
                break;

            case ']':
                j = 1;
                break;

            case '}':
                j = 2;
                 break;

            default :           //运算符或者数字，就继续看后面的
                break;
            }
            //switch完了后看j
            if ( j < 0 || j > 2 )   //如果不是右括号，就跳过判断操作继续看后面
            {
                i++;
                continue;
            }
            else        //是右括号之一就判断是否匹配
            {
                if(S.StackEmpty())     //如果栈顶为空，即前面没有左括号入栈,则不匹配
                    ismatch = false;
                else        //栈不为空，就取栈顶元素
                {
                    S.Top(t);
                    if (t != brac[j] )  //不匹配相应的括号
                        ismatch = false;        //就把ismatch设为false
                    else        //栈顶括号匹配
                        S.Pop();  //就把左括号给弹出栈，继续判断后面
                }
            }
        }
        i++;
    }                               //前面操作如果匹配的话都会弹栈，
    if (!S.StackEmpty())    //执行完后如果栈不为空说明有一个括号不匹配
    {
         ismatch = false;
    }
    return ismatch;     //最后返回ismatch
}
