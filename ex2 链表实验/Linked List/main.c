#include "LinkList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main( )
{
    int choice, DeEle, i, insertNum, len, location;
    List H = NULL;
    List H2 = NULL;
    List H3 = NULL;
    bool Exit = false;	     //Exit变量控制整个程序运行
    while ( !Exit )
    {
        printf("********************************\n");
        printf( "*单链表链表函数测试,请选择对应功能：\n" );
        printf("*1.头插法创建并打印结果\n");   //  no problem
        printf("*2.尾插法创建并打印结果。\n");//  no problem
        printf("*3.销毁链表。\n");//  no problem
        printf("*4.求链表长度.\n");          //small problem
        printf("*5.求第i个元素。\n");//  no problem
        printf("*6.插入结点\n");//  no problem
        printf("*7.由值查找结点。\n");   //big problem
        printf("*8.删除第i个结点.\n");
        printf("*9.有序插入结点。\n");
        printf("*10.分解链表。\n");
        printf("*11.求解公共元素\n");
        printf("*12.递增有序表删除重复元素\n");
        printf("*13.合并两表.\n");
        printf("*14.遍历链表.\n");
        printf("*15.拓展第一题。\n");
        printf("*16.拓展第二题。\n");
        printf("*17.拓展第三题。\n");
        printf("*18.拓展第四题。\n");
        printf("*19.退出。\n");
        printf("*********************************\n");
        printf( "请选择：" );
        scanf( "%d", &choice );
        while ( choice > 19 || choice < 1 )
        {
            printf( "选择错误 请重试：" );
            scanf( "%d", &choice );
        }
        switch ( choice )
        {
            case 1:  //头插
                H = CreateListInsertHead();
                if ( H == NULL )
                {
                    printf( "链表创建失败，请重试。\n" );
                    break;
                }
                printf( "链表创建成功！\n" );
                if(TravelList(H))
                    printf("遍历失败，请执行其他操作.\n");
                break;

            case 2:							//尾插
                H = CreateListInsertRear();
                if ( NULL == H )
                {
                    printf("链表创建失败.");
                    break;
                }
                printf("创建成功！\n");
                if (TravelList(H))
                    printf("遍历失败\n");
                break;

            case 3:  //销毁
                if ( DestoryList(H))
                {
                        printf("链表不存在，请选择创建链表\n");
                }
                else
                {
                        printf("链表销毁成功！\n");
                        H = NULL;
                }
                break;

            case 4:  //求长度,这里有问题
                len = ListLength(H);
                if ( len == -1 )
                {
                        printf("链表不存在，请选择创建链表.\n");
                        break;
                }
                else
                {
                        printf("链表长度为%d\n",len);
                }
                break;

            case 5:  //找第i个元素
                printf("请输入i：\n");
                scanf("%d",&i);
                len = GetElementInOrder( H, i );
                if(len == -1)
                {
                        printf("不存在这个元素,请重选.\n");
                }
                else
                {
                        printf("第%d个元素是：%d", i, len );
                }
                break;

            case 6:   //插入：ok
                printf( "请输入你想插入的数：" );
                scanf( "%d", &insertNum );
                printf( "\n你想在第几个结点插入？：(目前一共有%d个结点)\n", ListLength( H ) );
                scanf( "%d", &location );
                if ( Insert( insertNum, H, location ) )   //插入失败返回1，if判定为真，说明情况
                {
                    printf( "插入位置越界，请重新选择\n" );
                }
                else
                {
                    printf( "插入操作成功\n" );
                }
                break;

            case 7:   //找值为x的结点,ok
                printf("请输入你要查找的值：\n");
                scanf("%d",&len);
                node p = Find(len, H);          //返回这个结点指针
                if (p == NULL )                         //空指针说明没找到
                {
                        printf("查找失败，请选择其他选项。\n");
                }
                else
                {
                        printf("查找成功");
                }
                break;

            case 8:   //删除结点  //ok
                printf( "你想删除第几号结点？：" );
                scanf( "%d", &DeEle );
                if ( DeleteElement( DeEle, H ) )		 //操作失败返回1 ，失败返回0
                {
                    printf( "操作失败，请重试。\n" );
                }
                else
                {
                    printf( "操作成功\n" );
                }
                break;

            case 9:  //ok
                printf("请输入插入的数字:\n");
                scanf("%d",&len);
                printf("插入前:");
                TravelList(H);
                InsertIncrease(len,H);
                printf("\n插入后：");
                TravelList(H);
                break;

            case 10: //ok
                Separate(H);
                break;

            case 11:
                for ( int i = 0 ; i < 3 ; i++ )
                {
                        printf("\n第%d组测试：\n", i + 1);
                        printf("请先创建表1:\n") ;
                        H = CreateListInsertRear();  //尾插创建表1
                        if ( H == NULL )                         //判断创建是否成功
                        {
                                printf("表1创建失败，请重试.\n");
                                break;
                        }
                        getchar();//避免前面键入的回车符对后面产生影响
                        printf("\n然后创建表2：\n");
                        H2 = CreateListInsertRear(); //尾插创建表2
                        if ( H2 == NULL )                         //判断是否成功
                        {
                                printf("表2创建失败，请重试\n");
                                break;
                        }
                        getchar();
                        H3 = FindCommon( H, H2 );
                        printf("表1和表2公共元素为：\n");
                        TravelList( H3 );
                        DestoryList( H );  //回收三个表的空间，进行下一次测试
                        DestoryList( H2 );
                        DestoryList( H3 );
                }
                break;

            case 12:  //ok
                for ( int i = 0 ; i < 3 ; i++ )  //3组测试
                {
                        printf("\n第%d组测试：\n", i + 1);
                        H = CreateListInsertRear(); //尾插创建
                        getchar();              //万恶的回车
                        printf("去重前：");
                        TravelList( H );
                        OrderedListDelSame( H );
                        printf("\n去重后：");
                        TravelList( H );
                        DestoryList( H );//回收空间，进行下一次测试
                        printf("\n");
                }
                break;

            case 13: //ok
                 for ( int i = 0 ; i < 3 ; i++ )  //3组测试
                 {
                        printf("\n第%d组测试：\n", i + 1);
                        printf("请创建表1：\n");   //1 3 6 10 15 16 17 18 19 20
                        H = CreateListInsertRear();
                        getchar();              //避免前面键入的回车符对后面产生影响
                        printf("请创建表2：\n"); //1 2 3 4 5 6 7 8 9 10 18 20 30
                        H2 = CreateListInsertRear(); //2 4 5 7 8 9 12 22
                        getchar();//1 2 3 4 5 6 7 8 9 10
                        UnionAandB(H, H2);
                        printf("合并后");
                        TravelList(H);
                        DestoryList(H);
                }
                break;

            case 14:
                TravelList(H);
                break;

            case 15:
                printf("C = A∩B:\n");
                H = CreateListInsertRear();
                getchar();
                H2 = CreateListInsertRear();//1 3 6 10 15 16 17 18 19 20#
                getchar();
                H3 = (node)malloc(SIZE);//1 2 3 4 5 6 7 8 9 10 18 20 30#
                AInsertBToC( H, H2, H3 );
                printf("\nC:");//2 4 5 7 8 9 12 22#
                TravelList(H3);
                DestoryList(H);
                DestoryList(H2);
                DestoryList(H3);
                system("pause");
                system("CLS");
                printf("C = A∪B:\n");
                H = CreateListInsertRear();
                getchar();
                H2 = CreateListInsertRear();
                getchar();
                H3 = (node)malloc(SIZE);
                AUnionBToC( H, H2, H3 );
                printf("\nC:\n");
                TravelList(H3);
                DestoryList(H);
                DestoryList(H2);
                DestoryList(H3);
                system("pause");
                system("CLS");
                printf("C = A - B:\n");
                H = CreateListInsertRear();
                getchar();
                H2 = CreateListInsertRear();
                getchar();
                H3 = (node)malloc(SIZE);
                ASubBToC(H, H2, H3 );
                printf("\nC:\n");
                TravelList(H3);
                DestoryList(H);
                DestoryList(H2);
                DestoryList(H3);
                system("pause");
                system("CLS");

                printf("A =  A∩B:\n");
                H = CreateListInsertRear();
                getchar();
                H2 = CreateListInsertRear();
                getchar();
                AInsertBToA(H,H2);
                printf("\nAfter insert, \nA:");
                TravelList(H);
                DestoryList(H);
                DestoryList(H2);
                system("pause");
                system("CLS");

                printf("A = A∪B:\n");
                H = CreateListInsertRear();
                getchar();
                H2 = CreateListInsertRear();
                getchar();
                AUnionBToA(H, H2);
                printf("\bAfter union, \nA");
                TravelList(H);
                DestoryList(H);
                DestoryList(H2);
                system("pause");
                system("CLS");
                printf("A = A-B:\n");
                H = CreateListInsertRear();
                getchar();
                H2 = CreateListInsertRear();
                getchar();
                ASubBToA(H,H2);
                printf("\nAfter subtract, \nA");
                TravelList(H);
                DestoryList(H);
                DestoryList(H2);
                system("pause");
                system("CLS");
                break;

            case 16:
                printf("请创建表一：\n");
                H = CreateListInsertRear();
                getchar();
                printf("请创建表二：\n");
                H2 = CreateListInsertRear();
                getchar();
                if ( AisSubB(H, H2) )
                {
                        printf("表1是表2的子集。\n");
                }
                else
                {
                        printf("表1不是表2的子集。\n");
                }
                DestoryList(H);
                DestoryList(H2);
                break;

            case 17:
                printf("请创建表：\n");
                H = CreateListInsertRear();
                getchar();
                printf("你想找倒数第几个数？：\n");
                scanf("%d",&i);
                if ( !GetReverseOrder( H, i ))
                {
                        printf("位置越界，请重试");
                }
                break;

            case 18:
                printf("请创建表一：\n");
                H = CreateListInsertRear();
                getchar();
                printf("请创建表二：\n");
                H2 = CreateListInsertRear();
                getchar();
                FindMid( H, H2 );
                break;

            case  19:
                break;

            default:
                break;
        }
        system( "pause" );
        system( "CLS" );
        fflush(stdin);
    }
    if ( !IsExist( H ) )  //防止之前用户退出时没有选择删除链表操作。
    {
        DestoryList(H);
    }
    return 0;
}

