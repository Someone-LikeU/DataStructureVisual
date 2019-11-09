#ifndef _StackArray
#define _StackArray
#define MAXN 100            //栈最大容量
#include <queue>
#include <stack>
using namespace std;
typedef char ElementType;
class seqStack
{
private:
    ElementType data[MAXN];
    int top;
public:
    void InitiStack();      //初始化
    bool IsEmpty();         //判断是否栈空
    bool IsFull();          //栈满
    bool Top( ElementType &x );   //取栈顶元素
    bool Pop();             //弹栈
    bool  Push( ElementType &x ); //入栈
    void travel();
};
void ChangeScale( int n, int mode );      //转换进制
bool IsMatch( char *s );                        //判断表达式中括号是否合法
bool IsSeqValid( int *arr, int len );   //判断一个出栈序列是否合法
void AllValidSeq(queue<int> &Q1  ,stack<int> &S1,  queue<int> &Q2);        //栈的合法输出序列
double CalculateExpression(char *str); //计算表达式
#endif // _StackArrary
