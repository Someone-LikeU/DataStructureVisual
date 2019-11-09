#include "StackArray.h"
#include "StackLink.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    int n, mode, i, choose, ars, *arr;
    queue<int> Q;
    queue<int> Q2;
    stack<int> S1;
    mode = 16;
    char s[80];
    while(true)
    {
        printf("***********************************************\n");
        printf("测试函数\n");
        printf("*1.顺序栈实现进制转换。\n");
        printf("*2.顺序栈判断表达式中的括号是否匹配。\n");
        printf("*3.链栈实现进制转换。\n");
        printf("*4.链栈判断表达式中括号匹配。\n");
        printf("*5.拓展题1.\n");
        printf("*6.拓展题2.\n");
        printf("*7.拓展题3\n");
        printf("*8.退出\n");
        printf("***********************************************\n");
        printf("请选择：");
        scanf("%d",&choose);
        while (choose > 8 || choose < 1)
        {
            printf("选择错误，请重选: ");
            scanf("%d",&choose);
        }
        switch(choose)
        {
        case 1:
             for ( i = 0 ; i < 4 ; i++)
            {
                printf("第%d组测试：\n",i + 1);
                printf("请输入你想转换的数\n");
                scanf("%d",&n);
                ChangeScale(n,mode);
            }
            break;

        case 2:
            printf("请输入一个算术表达式（不超过79个字符）：\n");
            scanf("%s",s);
            if(IsMatch(s))//5+{10-[6*(2+8)}
            {
                printf("该表达式中的括号匹配。\n");
            }
            else                        //5+{6+7*[5*(1+2)]
            {
                printf("该表达式中的括号不匹配。\n");
            }
            break;

        case 3:
            for ( i = 0 ; i < 4 ; i++)
            {
                printf("第%d组测试：\n",i + 1);
                printf("请输入要转换的数：");
                scanf("%d",&n);
                LinkChangeScale(n, mode);
            }
            break;

        case 4:
            printf("请输入一个算术表达式（不超过79个字符）：\n");
            scanf("%s",s);
             if(LinkIsmatch(s))//5+{10-[6*(2+8)}
            {
                printf("该表达式中的括号匹配。\n");
            }
            else                        //5+{6+7*[5*(1+2)]
            {
                printf("该表达式中的括号不匹配。\n");
            }
            break;

        case 5: //done at 11.21   15.04，
            printf( "请输入序列长度：");
            scanf("%d",&ars);
            arr = new int (sizeof(int) * ars);
            printf("请输入这个序列：\n");
            for ( i = 0 ; i < ars ; i++ )
            {
                scanf("%d",&arr[i]);
            }
            if(IsSeqValid(arr, ars))
            {
                cout << "该序列合法\n";
            }
            else
            {
                cout << "该序列不合法\n";
            }
            break;

        case 6:         //ok

            printf("请输入一个序列，以#结束：\n");
            while (scanf("%d",&n) == 1)
            {
                Q.push(n);
            }
            printf("该序列所有合法输出栈序列为：\n");
            AllValidSeq(Q, S1, Q2);
            break;

        case 7:
            cout << "请输入一个表达式，以#结束输入（不超过79个字符）：";
            scanf("%s",s);
            cout << "计算结果是" << CalculateExpression(s) << endl;
            break;

        default :
            break;
        }
        system("pause");
        system("CLS");
        fflush(stdin);
    }
    return 0;
}
