#include "queueArray.h"
#include "queueLink.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main()
{
    seqQueue SQ;
    LinkQueue LQ;
    int choose, num, i;
    bool exit = false;
    while ( !exit )
    {
        cout << "*******************************\n";
        cout << "*队列测试程序（顺序队列默认最大容量100）：\n";
        cout << "*1.初始化顺序队列\n";
        cout << "*2.初始化链队列\n";
        cout << "*3.判断顺序队列空\n";
        cout << "*4.判断链队列空\n";
        cout << "*5.判断顺序队列满\n";
        cout << "*6.判断链队列满\n";
        cout << "*7.顺序队列入队\n";
        cout << "*8.链队列入队\n";
        cout << "*9.顺序队列出队\n";
        cout << "*10.链队列出队\n";
        cout << "*11.取顺序队列头\n";
        cout << "*12.取链队列头\n";
        cout << "*13.求当前顺序队列元素个数\n";
        cout << "*14.求当前链队列元素个数\n";
        cout << "*15.第8题顺序队列版\n";
        cout << "*16.第8题链队列版\n";
        cout << "*17.退出.\n";
        cout << "*******************************\n";
        cout << "*请选择：";
        scanf("%d",&choose);
        while ( choose < 1 || choose > 17)
        {
            cout << "错误输入，请重新选择.\n";
            cout << "请选择: ";
            scanf("%d",&choose);
        }
        switch (choose)
        {
        case 1:
            InitialQueue(SQ);
            printf("初始化完成\n");
            break;

        case 2:
            InitLinkQueue(LQ);
            printf("初始化完成\n");
            break;

        case 3:
            if(IsQueueEmpty(SQ))
            {
                cout << "顺序队列为空" << endl;
            }
            else
            {
                cout << "顺序队列不空" << endl;
            }
            break;

        case 4:
           if(IsLinkQueueEmpty(LQ))
           {
                cout << "链队列为空" << endl;
           }
           else
            {
                cout << "链队列不空" << endl;
            }
            break;

        case 5:
            cout << "第一组测试，输入数据，直到#退出\n";
            while(scanf("%d",&num) == 1)
            {
                if (IsQueueFull(SQ))    //先检查是否队满
                {
                    printf("队满，不能再入队\n");
                    break;
                }
                if(!EnQueue(&SQ, num))     //再入队操作
                {
                    cout << "入队成功" << endl;
                }
            }
            system("pause");
            InitialQueue(SQ);   //初始化，进行下一次测试
            cout << "length:" << CoutElement(SQ);
            cout << "第二组:" << endl;
            for ( i = 1 ; i < 100 ; i++ )
            {
                cout << "入队" << i << endl;
                EnQueue(&SQ, i);
            }
            if(IsQueueFull(SQ))
            {
                cout << "顺序队列满" << endl;
            }
            break;

        case 6: //done at 23.17
            cout << "第一组测试，输入数据，直到#退出\n";
            while(scanf("%d",&num) == 1)
            {
                if( IsLinkQueueFull( LQ ) )
                {
                    printf("队满，不能再入队\n");
                    break;
                }
                EnLinkQueue(LQ, num);
            }
            break;

        case 7:
            cout << "输入数据，直到#退出\n";
            while(scanf("%d",&num) == 1)
            {
                if (IsQueueFull(SQ))    //先检查是否队满
                {
                    printf("队满，不能再入队\n");
                    break;
                }
                EnQueue(&SQ, num);      //再入队操作
            }
            cout << "入队成功\n";
            break;

        case 8:
            cout << "输入数据，直到#退出\n";
            while(scanf("%d",&num) == 1)
            {
                if(IsLinkQueueFull(LQ))
                {
                    printf("队满，不能再入队\n");
                    break;
                }
                EnLinkQueue( LQ, num );
            }
            cout << "入队成功\n";
            break;

        case 9:
            if( IsQueueEmpty(SQ) )
            {
                cout << "队空，请先入队" << endl;
                break;
            }
            GetQueueFront(SQ, num);
            DeQueue(&SQ);
            cout << "队头为" << num << ", 出对成功\n";
            break;

        case 10:
            if(IsLinkQueueEmpty(LQ))
            {
                cout << "队空，请先入队" << endl;
                break;
            }
            GetLinkQFront(LQ, num);
            DeLinkQueue(LQ);
            cout << "队头为" << num << ", 出队成功\n";
            break;

        case 11:
            if( IsQueueEmpty(SQ) )
            {
                cout << "队空，请先入队" << endl;
                break;
            }
            GetQueueFront(SQ, num);
            cout << "队头为" << num << endl;
            break;

        case 12:
            if(IsLinkQueueEmpty(LQ))
            {
                cout << "队空，请先入队" << endl;
                break;
            }
            GetLinkQFront(LQ, num);
            cout << "队头为" << num << endl;
            break;

        case 13:
            cout << "当前顺序队列元素个数：" << CoutElement(SQ);
            break;

        case 14:
            cout << "当前链队列元素个数 :" << CountLinkQ(LQ);
            break;

        case 15:
            InitialQueue(SQ);
            cout << "请输入一些数,输入0结束：";
            scanf("%d",&num);
            while(num != 0)
            {
                if(num % 2 == 1)
                {
                    cout << "奇数,入队\n";
                    EnQueue(&SQ, num);
                }
                else
                {
                    cout << "偶数,出队\n";
                    if(IsQueueEmpty(SQ))
                    {
                        cout <<  "队空，无法出队\n";
                        break;
                    }
                    DeQueue(&SQ);
                }
                TravelQueue(SQ);
                scanf("%d",&num);
            }
            cout << "结束后，\n";
            TravelQueue(SQ);
            break;

        case 16:
            InitLinkQueue(LQ);
            cout << "请输入一些数,输入0结束：";
            scanf("%d",&num);
            while(num != 0)
            {

                if(num % 2 == 1)
                {
                    cout << "奇数,入队\n";
                    EnLinkQueue(LQ, num);
                }
                else
                {
                    cout << "偶数,出队\n";
                    if(IsLinkQueueEmpty(LQ))
                    {
                        cout <<  "队空，无法出队\n";
                        break;
                    }
                    DeLinkQueue(LQ);
                }
                TravelLinkQueue(LQ);
                scanf("%d",&num);
            }
            cout << "结束后，\n";
            TravelLinkQueue(LQ);
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
