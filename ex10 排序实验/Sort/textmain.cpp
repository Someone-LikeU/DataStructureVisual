#include "sort.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <ctime>
#include <Windows.h>
#include <graphics.h>
#include <conio.h>
#if _MSC_VER
#define snprintf _snprintf
#endif

using namespace std;

void GetDh1( int *dh, int &dhlen, int &scale );
void GetDh2( int *dh, int &dhlen, int &scale );
void GetDh3( int *dh, int &dhlen, int &scale );
void GetDh4( int *dh, int &dhlen, int &scale );
int main()
{
	int choose, cntCom, cntExch, i, j, dhlen;
	int datas[ 6 ] = { SCALE1, SCALE2, SCALE3, SCALE4, SCALE5, SCALE6 };
	clock_t begin, end;
	int text21[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26 };
	int text22[] = { 11, 12, 13, 14, 15, 1, 2, 3, 4, 5, 6, 10, 16, 1, 22, 23, 2, 17, 18, 19, 20, 24, 7, 8, 9, 25, 26 };
	int text23[] = { 5, 6, 7, 1, 2, 3, 4, 8, 9, 10, 11, 12, 13, 16, 17, 18, 14, 25, 26, 15, 19, 20, 21, 22, 23, 24 };
	int text3[] = { 180, 203, 32, 46, 25, 76, 17, 58, 99, 100, 11, 102, 13, 54, 75, 6, 27, 18, 19, 29, 2, 82 };
	int text4[ 40 ] = { 0 };
	int text[] = { 106, 213, 325, 446, 579, 654, 721, 870, 917, 510, 21, 632, 73, 14, 815, 316, 412, 18, 619, 720, 21, 808, 923, 25, 26 };
	int *text1 = NULL;
	int *temp = NULL;
	int *dh = NULL,len;
	HWND hwnd;		//窗口句柄
	bool exit = false, re = false, show;
	while ( !exit )
	{
		cout << "*********************************************\n";
		cout << "***************排序算法测试程序************\n";
		cout << "* 1.快速排序  ||   2.关键字排序\n";
		cout << "* 3.希尔排序  ||   5.堆排序演示\n";
		cout << "* 4.归并排序  ||   6.快速排序演示。\n";
		cout << "* 7.退出";
		cout << "************************************************\n";
		cout << "请选择：";
		cin >> choose;
		while ( choose > 7 || choose < 1 )
		{
			cout << "选项错误，请重新选择: ";
			cin >> choose;
		}
		switch ( choose )
		{
			case 1:						//分析快排	,pass
				system( "CLS" );
				show = false;  //先设置打印结果为false
				srand( time( NULL ) );				   //设置随机数种子
				re = false;
				for ( i = 0; i < 6; i++ )
				{
					cout << "第 " << i + 1 << " 组测试," << datas[ i ] << "个数据:\n";
					text1 = new int[ datas[ i ] + 1 ]; //每次分配对应个数个空间
					if ( text1 == NULL )			  //分配内存失败，就退出
					{
						cout << "Memory allocate failed.exit.\n";
						exit = true;
						break;
					}
					for ( j = 0; j < datas[ i ]; j++ )	   //赋随机值
					{
						text1[ j ] = rand();
					}
					len = datas[ i ];  //每次的测试数据量
					cntCom = cntExch = 0;	  //初始化计数器
					begin = clock();		  //计时每一次快婿排序用时
					QuickSort( text1, len, 0, len, re, cntCom, cntExch );
					end = clock();
					cout << "元素交换次数 " << cntExch << " ，比较次数 " << cntCom;
					cout << " 该数据量下用时" << ( double ) ( end - begin ) / CLK_TCK << "秒\n";
					delete[] text1;//记得回收前面分配的空间
				   	system( "pause" );	 //暂停，等待键入回车键
					system( "CLS" );	 //清屏，然后接着来
				}
				break;

			case 2:					 //关键字排序，pass
				system( "CLS" );	 //清屏，然后接着来
				cout << "第一组测试：\n";
				cout << "排序前：\n";
				len = sizeof( text21 ) / sizeof( ElementType );
				ShowResult( text21, len );
				cout << "排序后：\n";
				ChooseSort( text21, len );
				ShowResult( text21, len );
				system( "pause" );	 //暂停一会儿
				system( "CLS" );	 //清屏，然后接着来

				cout << "第二组测试:\n";
				len = sizeof( text22 ) / sizeof( ElementType );
				ShowResult( text22, len );
				cout << "排序后：\n";
				ChooseSort( text22, len );
				ShowResult( text22, len );
				system( "pause" );	 //暂停一会儿
				system( "CLS" );	 //清屏，然后接着来

				cout << "第三组测试：\n";
				len = sizeof( text23 ) / sizeof( ElementType );
				ShowResult( text23, len );
				cout << "排序后：\n";
				ChooseSort( text23, len );
				ShowResult( text23, len );
				break;

			case 3:					 //希尔排序
				system( "CLS" );	 //清屏，然后接着来
				cout << "题目测试，排序步长1，2，4，。。。。\n";
				i = 0;
				j = 1;
				len = sizeof( text3 ) / sizeof( ElementType );	  //测试数据数量
				dh = new int[ len / 2 ];		 //申请一个步长数组
				if ( dh == NULL )
				{
					cout << "Memory allocate failed.exit.\n";
					exit = true;
					break;
				}
				while ( j < len )  //步长不能超过数组长度，所以j 小于len
				{
					dh[ i ] = j;   //将步长写入步长数组
					i++;		   //数组下标指示器i
					j = 1 << i;	   //1左移i位，实现2的指数
				}
				show = false;
				cout << "希尔排序前，数组为：\n";
				ShowResult( text3, len );
				cout << "开始排序.\n";
				begin = clock();
				ShellSort( text3, len, show, dh, i );
				end = clock();
				cout << "\n用时 " << ( double ) ( end - begin ) / CLK_TCK << " 秒，排序后，数组为：\n";
				ShowResult( text3, len );
				delete[] dh;
				cout << "拓展测试:\n";
				system( "pause" );
				system( "CLS" );

				//题目测试完毕，下面是拓展测试，
				dh = new int[ 100 ];
				show = false;
				for ( i = 0; i < 6; i++ )
				{
					cout << "拓展测试 " << i + 1 << ":" << datas[ i ] << "个数据：\n";
					text1 = new int[ datas[ i ] + 1 ]; //每次分配对应多个空间
					temp = new int[ datas[ i ] + 1 ] ;
					if ( text1 == NULL )
					{
						cout << "Memory allocate failed.exit.\n";
						exit = true;
						break;
					}
					//然后赋随机数
					for ( j = 0; j < datas[i]; j++ )
					{
						text1[ j ] = rand();
					}
					memcpy( temp, text1, sizeof( text1 ) );//先复制到temp数组中
					//then begin to text
					len = datas[ i ];		  //每次测试的数据量
					cout << "第一个步长序列1.5.19.。。。即 4^i - 3 * 2 ^ i + 1:\n";
					GetDh1( dh, dhlen, len );		//测试第一种步长
					begin = clock();
					ShellSort( text1, len, show, dh, dhlen );
					end = clock();
					cout << "用时 " << ( double ) ( end - begin ) / CLK_TCK << "秒\n";
					system( "pause" );
					system( "CLS" );		//清屏，测试第二个步长
					
					//memcpy( text1, temp, sizeof( temp ) );  //把temp拷回去，测试另一个序列
					cout << "第二个步长序列 1 4 13 40 121 364 1093 3280...h = 1 h = 3 * h + 1:\n";
					GetDh2( dh, dhlen, len );		//测试第2种步长
					begin = clock();
					ShellSort( text1, len, show, dh, dhlen );
					end = clock();
					cout << "用时 " << ( double ) ( end - begin ) / CLK_TCK << "秒\n";
					system( "pause" );
					system( "CLS" );		//清屏，测试第3个步长

					memcpy( text1, temp, sizeof( temp ) );  //把temp拷回去，测试另一个序列
					cout << "第3个步长序列 1.3.7......2 ^ k - 1 :\n";
					GetDh3( dh, dhlen, len );		//测试第3种步长
					begin = clock();
					ShellSort( text1, len, show, dh, dhlen );
					end = clock();
					cout << "用时 " << ( double ) ( end - begin ) / CLK_TCK << "秒\n";
					system( "pause" );
					system( "CLS" );		//清屏，测试第4个步长

					memcpy( text1, temp, sizeof( temp ) );  //把temp拷回去，测试另一个序列
					cout << "第4个步长序列 1.4.13........即（3^k - 1) / 2:\n";
					GetDh4( dh, dhlen, len );		//测试第3种步长
					begin = clock();
					ShellSort( text1, len, show, dh, dhlen );
					end = clock();
					cout << "用时 " << ( double ) ( end - begin ) / CLK_TCK << "秒\n";
					system( "pause" );
					system( "CLS" );		//清屏

					delete[] text1; 		//一组数据测试完，回收空间，进行虾夷则测试
					delete[] temp;
				}
				break;

			case 4:	   				  //归并排序 ,pass
				system( "CLS" );
				cout << "排序前,数组元素：\n";
				len = sizeof( text ) / sizeof( ElementType );
				ShowResult( text, len );
				cout << "开始排序。\n";
				cntCom = 0;
				MergeSort( text, len, cntCom );
				cout << "排序后，数组元素:\n";
				ShowResult( text, len );
				cout << "比较了" << cntCom << "次\n";
				system( "pause" );
				cout << "接下来6组测试：\n";
				for ( i = 0; i < 6; i++ )
				{
					cout << "第 " << i + 1 << "组，" << datas[ i ] << "个数据。\n";
					cntCom = 0;
					text1 = new int[ datas[ i ] ]; //每次分配对应多个空间
					if ( text1 == NULL )
					{
						cout << "Memory allocate failed.exit.\n";
						exit = true;
						break;
					}
					//然后赋随机数
					for ( j = 0; j < datas[ i ]; j++ )
					{
						text1[ j ] = rand( );
					}
					//then begin to text
					len = datas[ i ];		  //每次测试的数据量
					begin = clock( );
					MergeSort( text1, len, cntCom );
					end = clock( );
					cout << "用时 " << ( double ) ( end - begin ) / CLK_TCK << "秒\n";
					cout << "比较次数为 " << cntCom << "\n";
					system( "pause" );
					system( "CLS" );		//清屏，测试下一组数据
					delete[ ] text1; 		//一组数据测试完，回收空间，进行虾夷则测试
				}
				break;

			case 5:	   //堆排序演示 ,pass
				system( "CLS" );
				srand( time( NULL ) );
				initgraph( 1000,600, SHOWCONSOLE ); //生成一个2000 * 1000的窗口
				setbkcolor( WHITE );
				hwnd = GetHWnd( ); //让窗口置前
				len = sizeof( text4 ) / sizeof( int );
				show = true;
				cout << "before heap sort.\n";
				for ( i = 0; i < len; i++ )
				{
					text4[ i ] = rand() % 450 + 50;
				}
				ShowResult( text4, len );
				HeapSort( text4, len, show );
				DrawResult( text4, len, 0 );
				MessageBox( hwnd, "Sort succeed!", "Information", MB_OK );
				closegraph();
				system( "pause" );
				break;

			case 6:					 //快排演示	,pass
				system( "CLS" );
				srand( time( NULL ) );
				initgraph( 1000,600, SHOWCONSOLE ); //生成一个2000 * 1000的窗口
				setbkcolor( WHITE );
				hwnd = GetHWnd( ); //让窗口置前
				len = sizeof( text4 ) / sizeof( int );
				show = true;
				cout << "before heap sort.\n";
				for ( i = 0; i < len; i++ )
				{
					text4[ i ] = rand() % 450 + 50;
				}
				ShowResult( text4, len );
				cntCom = cntExch = 0;
				QuickShow( text4, len, 0, len, re, cntCom, cntExch );
				DrawResult( text4, len, 0 );
				MessageBox( hwnd, "Sort succeed!", "Information", MB_OK );
				closegraph();
				system( "pause" );
				break;

			case 7:
				exit = true;
				break;
		}
		fflush( stdin );
		system( "CLS" );
	}
}

void DrawResult( ElementType *arr, int len, int j )
{
	int  i;
	char s[ 5 ] = { 0 };			   //数字字符串
	cleardevice();					  //每次画之前先把之前画过的擦掉
	setbkcolor( WHITE );			  //设置背景色为白色
	settextcolor( BLACK );			 //设置字体颜色为黑色
	for ( i = 0; i < len; i++ )
	{
		if ( j <= i )//快速排序中以j位置为划分，j的左边都比它小，画成绿色，右边比它大，画成红色
		{
			setfillcolor( GREEN );
		}					//堆排序中，j就成了每次调整大根堆的最后那个元素，即已排好的那个
		else
		{
			setfillcolor( RED );
		}
		fillrectangle( 10 + i * 24, 600 - arr[ i ], 10 + ( i + 1 ) * 24, 570 ); //画矩形
		snprintf(s, sizeof(s), "%d", arr[i]);
		outtextxy( 13 + i * 24, 560 - arr[ i ], s );	   //写数字
	}
}

void GetDh1( int *dh, int &dhlen, int &scale )
{
	int a, b ,t;		   //第一个步长1.5.19.。。。即 4^i - 3 * 2 ^ i + 1
	int i;
	b = 2;
	a = 4;
	i = 0;
	t = a - 3 * b + 1;
	while ( t < scale )	//把步长序列写进步长数组中
	{
		dh[ i ] = t;
		i++;
		b *= 2;
		a *= 4;
		t = a - b * 3 + 1;
	}
	dhlen = i;  //步长数组长度更新
}


void GetDh2( int *dh, int &dhlen, int &scale )
{
	int a;					 // 1 4 13 40 121 364 1093 3280...h = 1 h = 3 * h + 1
	int i;
	a = 1;
	i = 0;
	while ( a < scale )   //然后把步长写入步长数组
	{
		dh[ i ] = a;
		i++;
		a = a * 3 + 1;		 //a,b不断自乘，实现指数增长
	}
	dhlen = i;  //步长数组长度更新
}

void GetDh3( int *dh, int &dhlen, int &scale )
{
	int a;					 // 1.3.7......2 ^ k - 1
	int i;
	a = 1;
	i = 0;
	while ( a < scale )	//把步长序列写进步长数组中
	{
		dh[ i ] = a;
		i++;
		a = (1 << ( i + 1 )) - 1;
	}
	dhlen = i;  //步长数组长度更新
}

void GetDh4( int *dh, int &dhlen, int &scale )
{
	int a, b;			 //1.4.13........即（3^k - 1) / 2
	int i;
	b = 3;
	a = 1;
	i = 0;
	while ( a < scale )	//把步长序列写进步长数组中
	{
		dh[ i ] = a;
		i++;
		b *= 3;
		a = ( b - 1 ) / 2;
	}
	dhlen = i;  //步长数组长度更新
}

