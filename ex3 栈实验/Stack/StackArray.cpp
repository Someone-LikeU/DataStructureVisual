#include "StackArray.h"
#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
#include <map>
using namespace std;
//********************************
//函数功能：初始化顺序栈
//输入参数：无
//输出参数：无
//返回值： 无
//********************************
void seqStack::InitiStack()
{
    seqStack::top = -1;
}

//********************************
//函数功能：判断栈是否为空
//输入参数：无
//输出参数：无
//返回值： 真或假
//********************************
bool seqStack::IsEmpty()
{
    return seqStack::top == -1;
}

//********************************
//函数功能：判断栈是否满
//输入参数：无
//输出参数：无
//返回值： 真或假
//********************************
bool seqStack::IsFull()
{
    return seqStack::top == MAXN - 1;
}

//********************************
//函数功能：取栈顶元素
//输入参数：无
//输出参数：无
//返回值：  true or false
//********************************
bool seqStack::Top(ElementType &x)
{
    if (seqStack::IsEmpty())
    {
        return false;
    }
    x = seqStack::data[seqStack::top];
    return true;
}

//********************************
//函数功能：弹栈
//输入参数：无
//输出参数：无
//返回值：  true or false
//********************************
bool seqStack::Pop()
{
    if(seqStack::IsEmpty())
    {
        return false;
    }
    seqStack::top--;
    return true;
}

//********************************
//函数功能：入栈
//输入参数：无
//输出参数：无
//返回值：  true or false
//********************************
bool seqStack::Push( ElementType &x )
{
    if(seqStack::IsFull())
    {
        return false;
    }
    seqStack::top++;
    seqStack::data[seqStack::top] = x;
    return true;
}

//********************************
//函数功能：遍历栈
//输入参数：无
//输出参数：无
//返回值：  无
//********************************
void seqStack::travel()
{
    int t = seqStack::top;
    while (t != -1)
    {
        cout << seqStack::data[t--] << " ";
    }
}

//*********************************************************
//函数功能：将一个数转换为相应n进制
//输入参数：待转换数n，进制mode
//输出参数：无
//返回值： 	  wu
//*********************************************************
void ChangeScale( int n, int mode )
{
    seqStack S;         //栈对象
    S.InitiStack();     //初始化先
    int m ,t = n;         //余数
    char s;                 //输出时要用到的字符
    char characters[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8','9', 'A', 'B', 'C', 'D', 'E', 'F'};     //16进制的情况要用到
    while (n != 0)
    {
        m = n % mode;
        S.Push(characters[m]);//入栈对应字符
        n /= mode;
    }
    printf("\n%d的%d进制表示为: ",t, mode);
    while( !S.IsEmpty() )
    {
        S.Top(s);
        printf("%c",s);
        S.Pop();
    }
    cout << endl;
}

//*********************************************************
//函数功能：判断一个表达式中的括号是否匹配
//输入参数：表达式字符串
//输出参数：无
//返回值： 	  true or false
//*********************************************************
bool IsMatch( char *str )
{
    bool ismatch = true;    //先假设 都匹配
    int i = 0, j = -1;        //i用来遍历表达式字符串，j用来选择括号类型
    seqStack S;     //顺序栈对象
    S.InitiStack(); //先初始化
    ElementType t;      //栈顶元素赋给t
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
                if(S.IsEmpty())     //如果栈顶为空，即前面没有左括号入栈,则不匹配
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
    if (!S.IsEmpty())    //执行完后如果栈不为空说明有一个括号不匹配
    {
         ismatch = false;
    }
    return ismatch;     //最后返回ismatch
}

//*********************************************************
//函数功能：判断一个出战序列是否合法
//输入参数：一个整形数组，表示出栈序列
//输出参数：无
//返回值： 	  true or false
//*********************************************************
bool IsSeqValid( int *arr, int len )
{
    bool isValid = true;    //先默认合法
    int i = 0, j;    //i控制遍历序列，j
    while( i < len && isValid )  //true 并且没越界
    {
        j = i + 1;  //从i的后一个开始，找比a[i]小的
        while ( j < len && arr[j] < arr[i] )    //还要确保j不会越界
        {
            j++;
        }
        for ( i = i + 1 ; j < len && i < j && isValid ; i++ )  //从i+1位置到j - 1，判断是否是降序
        {
            if( arr[i + 1] > arr[i] )
            {
                isValid = false;        //递增的，不满足
            }
        }
        i = j;      //让i = j，又从j位置开始判断
    }
    return isValid;     //最后return isValid 即可
}

//*********************************************************
//函数功能：求一个栈的所有合法输出序列
//输入参数：三个顺序栈的引用
//输出参数：无
//返回值： 	  无
//*********************************************************
void AllValidSeq( queue<int> &Q1 ,stack<int> &S1,  queue<int> &Q2)
{                                   //该算法参考于CSDN博客
    int t;
    if( Q1.empty() )    //如果输入队列为空
    {
        if( S1.empty())  //如果中间栈为空
        {
            while(!Q2.empty())      //就输出输出队列里的元素
            {
                cout << Q2.front() << " ";
                Q2.pop();
            }
            printf("\n");
        }
        else        //中间栈不空，就把栈顶弹出，并push到输出队列里
        {
            t = S1.top();
            S1.pop();
            Q2.push(t);
            AllValidSeq(Q1, S1, Q2);    //再递归调用
        }
    }
    else            //输入队列不为空
    {
        if ( !S1.empty() )      //中间栈不空
        {
            queue<int> newQ;        //借助新的队列和栈
            queue<int> newQ2;
            stack<int> newS;
            newQ = Q1;
            newQ2 = Q2;
            newS = S1;
            t = newS.top(); //将新栈弹栈
            newS.pop();
            newQ2.push(t);  //栈顶元素push到输出队列里
            AllValidSeq(newQ, newS, newQ2 );    //递归调用本函数
        }
        t = Q1.front();         //输入队列取队头元素
        S1.push(t);               //入中间栈
        Q1.pop();
        AllValidSeq(Q1, S1, Q2);    //再调用本函数
    }
}

//*********************************************************
//函数功能：计算表达式的值
//输入参数：字符串形式的表达式
//输出参数：无
//返回值： 	  计算结果
//*********************************************************
double CalculateExpression(char *str) //注，运行此题前需先修改头文件中elementtpe的定义
{
    //利用矩阵存放符号的优先级比较
                                         //+    -     *     /    (     )    #
    char Priority[7][7] = {{'>', '>', '<', '<', '<', '>', '>'},
                                           {'>', '>', '<', '<', '<', '>', '>'},
                                           {'>', '>', '>', '>', '<', '>', '>'},
                                           {'>', '>', '>', '>', '<', '>', '>'},
                                           {'<', '<', '<', '<', '<', '=', ' '},
                                           {'>', '>', '>', '>', ' ', '>', '>'},
                                           {'<', '<', '<', '<', '<', ' ', '='}
                                            };
    //再用map创建一个字典，来索引优先级的比较
    map<char, int> chars;
    chars.insert(pair<char, int>('+', 0));  //每个符号分别对应的索引
    chars.insert(pair<char, int>('-',1));
    chars.insert(pair<char, int>('*',2));
    chars.insert(pair<char, int>('/',3));
    chars.insert(pair<char, int>('(',4));
    chars.insert(pair<char, int>(')',5));
    chars.insert(pair<char, int>('#',6));
    int row, col, i;
    double t1, t2, T, num;       //借助两个变量来索引，不然只用字典的话不好看
    char TopS, CurrentS;       //TopS表示符号栈栈顶运算符，CurrentS表示刚扫描到的运算符
    i = num = 0;                //num为扫描到的操作数，i用于索引
    seqStack OpS;         //顺序栈存放符号
    stack<double> numS;    //借助模板
    OpS.InitiStack();     //初始化
    TopS = '#';
    OpS.Push(TopS);    //先将定界符压入符号栈
    row = chars[TopS];
    while(str[i] != '#' || TopS != '#')
    {
        if(str[i] >= '0' && str[i] <= '9')  //扫描到操作数
        {
            while(str[i] >= '0' && str[i] <= '9')
            {
                num = num * 10.0 + (str[i] - '0') * 1.0;
                cout << "num is " << num << endl;
                i++;
            }
            numS.push(num); //将这个操作数入栈
            num = 0.0;    //然后重置num为0 ,继续扫描后面的内容
        }
        else        //不是操作数
        {
            CurrentS = str[i];  //当前扫描到的操作符
            col = chars[CurrentS];
            if ( '<' == Priority[row][col] )    //栈顶运算符优先级比当前扫描的运算符小
            {
                OpS.Push(CurrentS);     //不能运算，push进符号栈
                OpS.Top(TopS);              //然后更新TopS，及对应优先级的索引
                row = chars[TopS];
            }
            else if ('>' == Priority[row][col] )//大于
            {
                OpS.Top(TopS);  //就取连续取两个运算数
                row = chars[TopS];
                OpS.Pop();      //先把这个运算符pop掉
                t2 = numS.top();    //后进的是t2
                numS.pop();
                t1 = numS.top();    //先进的是t1，这样的话除法才不会出错
                numS.pop();
                switch(TopS)        //根据运算符，计算结果后将结果压栈
                {
                    case '+':
                        T = t1 + t2;
                        numS.push(T);
                        cout << "push " << T << " into stack\n";
                        break;

                    case '-':
                        T = t1 - t2;
                        numS.push(T);
                        cout << "push " << T << " into stack\n";
                        break;

                    case '*':
                        T = t1 * t2;
                        numS.push(T);
                        cout << "push " << T << " into stack\n";
                        break;

                    case '/':
                        T = t1 / t2;
                        numS.push(T);
                        cout << "push " << T << " into stack\n";
                        break;

                    default :
                        break;
                }
                if(!OpS.IsEmpty())  //如果计算完后操作符栈不空，则还要继续用当前的
                {                                       //栈顶运算符继续与扫描的运算符比较
                    OpS.Top(TopS);
                    row = chars[TopS];
                    continue;
                }
            }
            else if( '=' == Priority[row][col])//优先级相等，即括号匹配时，就把左括号pop掉
            {
                OpS.Pop();
                OpS.Top(TopS);
                row = chars[TopS];
            }
            i++;
        }
    }
    T = numS.top();   //最后栈顶元素就是答案
    return T;
}
