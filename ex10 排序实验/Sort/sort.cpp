#include "sort.h"
#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <string>
using namespace std;

//*********************************************************
//函数功能：
//输入参数：
//输出参数：
//返回值：
//*********************************************************

//*********************************************************
//函数功能：打印结果
//输入参数：数组，长度
//输出参数：无
//返回值： 	无
//*********************************************************
void ShowResult( ElementType *arr, int &len )
{
	int i;
	for ( i = 0; i < len; i++ )
	{
		cout << arr[ i ] << " ";
	}
	cout << "\n";
}

//*********************************************************
//函数功能：直接插入排序算法
//输入参数：待排序数组arr，数组长度len，Re是否递减，show是否显示排序过程
//输出参数：排好序的数组arr
//返回值： 	无
//*********************************************************
void InsertSort( ElementType *arr, int len, bool &Re, bool &show )
{
	int i, j ,cnt = 0;	  //a counter
	if ( Re == false )		//增序排序
	{
		for ( i = 2; i <= len; i++ )			//begin with second element, exeute insert operation
		{							  //use arr[0] as a solider
			arr[0] = arr[ i ];				 //arr[0] represent the num to be insert
			j = i - 1;							//j is the i pre num 's index
			while ( arr[ j ] > arr[0] )	 //increase order sort
			{
				arr[ j + 1 ] = arr[ j ];   //move a[j] to it's back
				cnt++;
				j--;
			}
			arr[ j + 1 ] = arr[0]; //insert arr[0]
			if ( show == true )		 //show each steps
			{
				cout << "第 " << i - 1 << " 趟排序后：\n";
				ShowResult( arr, len );
				Sleep( 500 );
			}
		}
	}
	else	  //decrease order sort
	{
		for ( i = 2; i <= len; i++ )			//begin with second element, exeute insert operation
		{							  //use arr[0] as a solider
			arr[0] = arr[ i ];				 //arr[0] represent the num to be insert
			j = i - 1;							//j is the i pre num 's index
			while ( arr[ j ] > arr[0] )	 //increase order sort
			{
				arr[ j + 1 ] = arr[ j ];   //move a[j] to it's back
				cnt++;
				j--;
			}
			arr[ j + 1 ] = arr[0]; //insert arr[0]
			if ( show == true )		 //show each steps
			{
				cout << "第 " << i - 1 << " 趟排序后：\n";
				cout << "第 " << i - 1 << " 趟排序后：\n";
				ShowResult( arr, len );
				Sleep( 500 );
			}
		}
	}
	cout << "\nFor " << len << " elements, Insert Sort algorithm moved elements " << cnt << " tiems";
}

//*********************************************************
//函数功能：希尔排序
//输入参数：待排数组arr，数组长度r，show变量，步长数组dh及其长度，
//输出参数：排好序的数组arr
//返回值： 	无
//*********************************************************
void ShellSort( ElementType *arr, int r, bool &show, int *dh, int dhlen )
{
	//步长序列1.5.19.。。。。即4^i - 3 * 2 ^ i + 1
	//1 4 13 40 121 364 1093 3280... h = 1 h = 3 * h +1
	//1.3.7......2^k - 1
	//1.4.13........即（3^k - 1) / 2
	int i, j, d, step, temp;
	int cntCom, cntMove;
	cntCom = cntMove = 0;
	if ( show == true )
	{
		for ( step = dhlen - 1; step >= 0; step-- )//从步长序列中选择步长
		{
			d = dh[ step ]; //每次从步长序列中选择步长
			for ( i = d; i < r; i++ )	   //依次插入元素到前面有序表中
			{								   //i指示待插元素
				temp = arr[ i ];				  //腾出空位，j指示空位	   
				for ( j = i; j >= d && arr[ j - d ] > temp; j -= d )
				{
					arr[ j ] = arr[ j - d ];   //移动元素
					//j-=d	j前移
					cntCom++; //比较次数++
					cntMove++;	//移动次数++
				}
				arr[ j ] = temp;
				cntMove++;	//移动次数++
			}
			ShowResult( arr, r ); //打印一趟排序的结果
			Sleep( 500 );
		}
	}
	else
	{
		for ( step = dhlen - 1; step >= 0; step-- )//从步长序列中选择步长
		{
			d = dh[ step ]; //每次从步长序列中选择步长
			for ( i = d; i < r; i++ )	   //依次插入元素到前面有序表中
			{								   //i指示待插元素
				temp = arr[ i ];				  //腾出空位，j指示空位	   
				for ( j = i; j >= d && arr[ j - d ] > temp; j -= d )
				{
					arr[ j ] = arr[ j - d ];   //移动元素
					//j-=d	j前移
					cntCom++; //比较次数++
					cntMove++;	//移动次数++
				}
				arr[ j ] = temp;
				cntMove++;	//移动次数++
			}
		}
	}
	cout << "该步长序列比较次数 " << cntCom << " ，交换元素次数 " << cntMove << endl;
}

//*********************************************************
//函数功能：快速排序的划分
//输入参数：数组，划分两端位置s，t，逆序Re，中间元素位置cutpoint
//输出参数：划分后的数组
//返回值： 	无
//*********************************************************
void Partition( ElementType *arr, int s, int t, bool &Re, int &cutPoint, int &cntComp, int &cntExchange )
{
	int x, i, j;
	x = arr[ s ]; //save mid element to temp element x to make a empty palce
	i = s;		  //init search place
	j = t;
	if ( Re == false )  //increase
	{
		while ( i != j )	   //两端搜索位置未重合，继续
		{
			while ( i < j && arr[ j ] > x )		//从后面搜索比中间元素小的数
			{
				j--;
				cntComp++;  //比较次数加1
			}
			if ( i < j )				  //找到了就放到前面的空位中
			{
				arr[ i ] = arr[ j ];
				cntExchange++;  //交换次数加1
				++i;
			}
			while ( i < j && arr[ i ] < x )	  //从前面找比中间元素大的数
			{
				i++;
				cntComp++;  //比较次数加1
			}
			if ( i < j )						  //找到了就把它换到后面空位中
			{
				arr[ j ] = arr[ i ];
				cntExchange++;  //交换次数加1
				--j;
			}
		}
	}
	else			  //decrease order
	{
		while ( i != j )	   //两端搜索位置未重合，继续
		{
			while ( i < j && arr[ j ] > x )		//从后面搜索比中间元素小的数
			{
				j--;
				cntComp++;  //比较次数加1
			}
			if ( i < j )				  //找到了就放到前面的空位中
			{
				arr[ i ] = arr[ j ];
				cntExchange++;  //交换次数加1
				++i;
			}
			while ( i < j && arr[ i ] < x )	  //从前面找比中间元素大的数
			{
				i++;
				cntComp++;  //比较次数加1
			}
			if ( i < j )						  //找到了就把它换到后面空位中
			{
				arr[ j ] = arr[ i ];
				cntExchange++;  //交换次数加1
				--j;
			}
		}
	}
	arr[ i ] = x;		 //把中间元素放到最终位置上
	cutPoint = i; //返回中间元素的位置
}

//*********************************************************
//函数功能：快速排序
//输入参数：数组，数组长度，划分两端位置s，t，逆序Re，显示结果show
//输出参数：排好序的数组
//返回值： 	无
//*********************************************************
void QuickSort( ElementType *arr, int len, int s, int t, bool &Re, int &cntComp, int &cntExchange )
{
	int i;
	if ( s < t )						  //表中至少两个元素
	{
		Partition( arr, s, t, Re, i,cntComp, cntExchange );	//先进行一次划分
		QuickSort( arr, len, s, i - 1, Re, cntComp, cntExchange );
		QuickSort( arr, len, i + 1, t, Re, cntComp, cntExchange );
	}
}

void QuickShow( ElementType *arr, int len, int s, int t, bool &Re, int &cntComp, int &cntExchange )
{
	int i;
	if ( s < t )						  //表中至少两个元素
	{
		Partition( arr, s, t, Re, i,cntComp, cntExchange );	//先进行一次划分
		DrawResult( arr, len, i );
		Sleep( 250 );
		QuickShow( arr, len, s, i - 1, Re, cntComp, cntExchange );
		QuickShow( arr, len, i + 1, t, Re, cntComp, cntExchange );
	}
}

//*********************************************************
//函数功能：build a max heap
//输入参数：an array, root place p, total size n
//输出参数：a max heap
//返回值： 	无
//*********************************************************
void PercDown( ElementType *arr, int p, int &n )
{
	int parent, child;
	ElementType x;
	x = arr[ p ];  //取出根值
	for ( parent = p; ( parent * 2 + 1 ) < n; parent = child )
	{
		child = parent * 2 + 1;		   //数组下标从一开始的话，左子树下标为2*i+1
		if ( ( child != n - 1 ) && ( arr[ child ] < arr[ child + 1 ] ) )
		{
			child++;				  //找到最大的那个子节点
		}
		if ( x >= arr[ child ] )
		{
			break;   //find the suitable place
		}
		else			  //otherwise , go down to find the suitable place
		{
			arr[ parent ] = arr[ child ];
		}
	}
	arr[ parent ] = x;
}

//*********************************************************
//函数功能：heap sort
//输入参数：array and it's len and show
//输出参数：an sorted array
//返回值： 	none
//*********************************************************
void HeapSort( ElementType *arr, int len, bool &show )
{
	int i;
	for ( i = len / 2 - 1; i >= 0; i-- ) //first, build the max heap
	{
		PercDown( arr, i, len );
	}
	if ( show == true )					//show each steps 's result
	{
		for ( i = len - 1; i > 0; i-- )
		{
			//delete the top of heap, that means swap top and arr[i]
			swap( arr[ 0 ], arr[ i ] );
			PercDown( arr, 0, i );
			DrawResult( arr, len, i );
			Sleep( 250 );
		}
	}
	else
	{
		for ( i = len - 1; i > 0; i-- )
		{
			//delete the top of heap, that means swap top and arr[i]
			swap( arr[ 0 ], arr[ i ] );
			PercDown( arr, 0, i );
		}
	}
}
//*********************************************************
//函数功能：
//输入参数：
//输出参数：
//返回值：
//*********************************************************
void swap( ElementType &a, ElementType &b )
{
	ElementType t = a;
	a = b;
	b = t;
}

//*********************************************************
//函数功能：
//输入参数：
//输出参数：
//返回值：
//*********************************************************
void Merge( ElementType A[ ], ElementType TmpA[ ], int L, int R, int RightEnd, int &cntcmp )
{ /* 将有序的A[L]~A[R-1]和A[R]~A[RightEnd]归并成一个有序序列 */
	int LeftEnd, NumElements, Tmp;
	int i;

	LeftEnd = R - 1; /* 左边终点位置 */
	Tmp = L;         /* 有序序列的起始位置 */
	NumElements = RightEnd - L + 1;

	while ( L <= LeftEnd && R <= RightEnd )
	{
		if ( A[ L ] <= A[ R ] )
			TmpA[ Tmp++ ] = A[ L++ ]; /* 将左边元素复制到TmpA */
		else
			TmpA[ Tmp++ ] = A[ R++ ]; /* 将右边元素复制到TmpA */
		cntcmp++;
	}

	while ( L <= LeftEnd )
		TmpA[ Tmp++ ] = A[ L++ ]; /* 直接复制左边剩下的 */
	while ( R <= RightEnd )
		TmpA[ Tmp++ ] = A[ R++ ]; /* 直接复制右边剩下的 */

	for ( i = 0; i < NumElements; i++, RightEnd-- )
		A[ RightEnd ] = TmpA[ RightEnd ]; /* 将有序的TmpA[]复制回A[] */
}

//*********************************************************
//函数功能：归并排序辅助函数
//输入参数：
//输出参数：
//返回值：
//*********************************************************
void Msort( ElementType A[ ], ElementType TmpA[ ], int L, int RightEnd, int &cntcmp )
{ /* 核心递归排序函数 */
	int Center;

	if ( L < RightEnd )
	{
		Center = ( L + RightEnd ) / 2;
		Msort( A, TmpA, L, Center, cntcmp );              /* 递归解决左边 */
		Msort( A, TmpA, Center + 1, RightEnd, cntcmp );     /* 递归解决右边 */
		Merge( A, TmpA, L, Center + 1, RightEnd, cntcmp );  /* 合并两段有序序列 */
	}
}

//*********************************************************
//函数功能：归并排序入口函数
//输入参数：待排数组
//输出参数：排好的数组
//返回值：	无
//*********************************************************
void MergeSort( ElementType A[ ], int N, int &cntcmp )
{ /* 归并排序 */
	ElementType *TmpA;
	TmpA = new ElementType[ N ];

	if ( TmpA != NULL )
	{
		Msort( A, TmpA, 0, N - 1, cntcmp );
		delete TmpA;
	}
	else cout << "空间不足";
}


void ChooseSort( ElementType *arr, int len )
{
	int low, high, p, cntCom, cntExch;
	low = p = cntCom = cntExch = 0;
	high = len - 1;
	while ( p < len )	 //第一次选择，把3的倍数放到数组左边
	{
		if ( arr[ p ] % 3 == 0  )//如果p指示的元素是3的倍数，就和low位置指示的交换
		{
			swap( arr[ p ], arr[ low ] );
			cntExch++;  //交换次数++
			low++;
		}
		p++;
		cntCom++;
	}
	p = high;  //然后从表尾开始往前遍历，把除3余2的元素放到表右边
	while ( p >= low )
	{
		if ( arr[ p ] % 3 == 2 )
		{
			swap( arr[ p ], arr[ high ] );
			high--;
			cntExch++;
		}
		p--;
		cntCom++;
	}
	cout << "比较次数 " << cntCom << " ，交换次数 " << cntExch << " .\n";
}
