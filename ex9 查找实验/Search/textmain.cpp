#include "AVLtree.h"
#include "Search.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
using namespace std;

int main()
{
	int search,choose,i,j,k,len;
	BSTnode Bfind = NULL;
	BSTnode BSTree = NULL;
	AVLnode Afind = NULL;
	AVLTree AVLt = NULL;
	int text11[]   = { 1, 2, 3, 4, 6, 7, 8, 9, 10, 11, 12, 13, 17, 18, 19, 20, 24, 25, 26, 30, 35, 40, 45, 50, 100 };
	int text12[]   = { 2, 3, 5, 7, 8, 10, 12, 15, 18, 20, 22, 25, 30, 35, 40, 45, 50, 55, 60, 80, 100 };
	int toFind11[] = { 2, 8, 20, 30, 50, 5, 15, 33, 110 };
	int toFind12[] = { 22, 8, 80, 3, 100, 1, 13, 120 };
	int text21[]   = { 100, 150, 120, 50, 70, 60, 80, 170, 180, 160, 110, 30, 40, 35, 175 };
	int text22[]   = { 100, 70, 60, 80, 150, 120, 50, 160, 30, 40, 170, 180, 175, 35 };
	int toFind3[]  = { 150, 70, 160, 190, 10, 55, 175 };
	int toDel4[]   = { 30, 150, 100 };
	int text51[]   = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26 };
	int text52[]   = { 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 66, 78, 91, 105, 120, 136, 153, 171, 190, 210, 231, 253, 277, 302, 328 };
	bool exit = false;
	while ( !exit )
	{
		cout << "*********************************************\n";
		cout << "***************查找相关算法测试程序************\n";
		cout << "*1.用二分查找查找指定元素  || 2.构造一棵二叉排序树\n";
		cout << "*3.在二叉排序树中找指定元素|| 4.在二叉排序树中删除指定元素\n";
		cout << "*5.构造一棵AVL树     	   || 6.退出\n";
		cout << "*********************************************\n";
		cout << "请选择：";
		cin >> choose;
		while ( choose > 6 || choose < 1 )
		{
			cout << "Error chioce.Please enter again.";
			cin >> choose;
		}
		fflush( stdin );
		switch ( choose )
		{
			case 1:
				cout << "text 1 :\n";
				len = sizeof( text11 ) / sizeof( int );
				for ( j = 0; j < len; j++ )
				{
					cout << setw(3) << text11[ j ] << " ";
				}
				cout << endl;
				len = sizeof( toFind11 ) / sizeof( int );
				k = sizeof( text11 ) / sizeof( int );
				for ( j = 0; j < len; j++ )
				{
					search = BinarySearch( text11, k, toFind11[ j ] );
					if ( search != -1 )
					{
						cout << setw( 3 ) << toFind11[ j ] << " was found\n";
					}
					else
					{
						cout << setw( 3 ) << toFind11[ j ] << " is not in the array\n";
					}
				}

				cout << "text 2: \n";
				len = sizeof( text12 ) / sizeof( int );
				for ( j = 0; j < len; j++ )
				{
					cout << setw( 3 ) << text12[ j ] << " ";
				}
				cout << endl;
				k = sizeof( toFind12 ) / sizeof( int );
				for ( j = 0; j < k; j++ )
				{
					search = BinarySearch( text12, len, toFind12[ j ] );
					if ( search != -1 )
					{
						cout << setw( 3 ) << toFind11[ j ] << " was found\n";
					}
					else
					{
						cout << setw( 3 ) << toFind11[ j ] << " is not in the array\n";
					}
				}
				break;

			case 2:
				cout << "text 1: \n";
				if ( CreateBSTfromArr( BSTree, text21, sizeof( text21 ) / sizeof( int ) ) )
				{
					cout << "Create successed. Mid order travel as follow:\n";
					MidOrderTravel( BSTree );
					cout << endl;
				}
				else
				{
					cout << "Create failed.\n";
					break;
				}
				DestoryBST( BSTree );
				cout << "text 2: \n";
				if ( CreateBSTfromArr( BSTree, text22, sizeof( text22 ) / sizeof( int ) ) )
				{
				    cout << "Create successed. Mid order travel as follow:\n";
					MidOrderTravel( BSTree );
					cout << endl;
				}
				else
				{
					cout << "Create failed.\n";
					break;
				}
				DestoryBST( BSTree );
				break;

			case 3:
				cout << "text as follow:\n";
				len = sizeof( toFind3 ) / sizeof( int );
				k = sizeof( text11 ) / sizeof( int );
				if ( !CreateBSTfromArr( BSTree, text11, k ) )
				{
					cout << "Create BinarySearch Tree faild.\n";
					break;
				}
				cout << "way 1, Recursion:\n";
				for ( i = 0; i < len; i++ )
				{
					Bfind = Find( toFind3[ i ], BSTree );
					if ( Bfind )
					{
						cout << setw( 3 ) << toFind3[ i ] << " was found.\n";
					}
					else
					{
						cout << setw( 3 ) << toFind3[ i ] << " was not found.\n";
					}
				}

				cout << "\nway2, while circle:\n";
				for ( i = 0; i < len; i++ )
				{
					Bfind = Find2( toFind3[ i ], BSTree );
					if ( Bfind )
					{
						cout << setw( 3 ) << toFind3[ i ] << " was found.\n";
					}
					else
					{
						cout << setw( 3 ) << toFind3[ i ] << " was not found.\n";
					}
				}
				DestoryBST( BSTree );
				break;

			case 4:
				len = sizeof( toDel4 ) / sizeof( int );
				k = sizeof( text11 ) / sizeof( int );
				if ( !CreateBSTfromArr( BSTree, text11, k ) )
				{
					cout << "Create BinarySearch Tree faild.\n";
					break;
				}
				for ( i = 0; i < len; i++ )
				{
					cout << "\nBefore delete " << toDel4[ i ] << ", tree contains:\n";
					MidOrderTravel( BSTree );
					BSTree = Delete( BSTree, toDel4[ i ] );
					cout << "\nAfter delete, BSTree contains:\n";
					MidOrderTravel( BSTree );
				}
				DestoryBST( BSTree );
				break;

			case 5:
				len = sizeof( text51 ) / sizeof( int );
				cout << "text 1:\n";
				if ( CreateAVLformArr( AVLt, text51, len ) )
				{
					cout << "Create succeed.\n";
				}
				cout << "Mid order as follow:\n";
				AVLmidorderTravel( AVLt );
				DestoryAVLtree( AVLt );
				cout << "\ntext 2: \n";
				len = sizeof( text52 ) / sizeof( int );
				if ( CreateAVLformArr( AVLt, text52, len ) )
				{
					cout << "Create succeed.\n";
				}
				cout << "Mid order as follow:\n";
				AVLmidorderTravel( AVLt );
				DestoryAVLtree( AVLt );
				cout <<endl;
				break;

			case 6:
				exit = true;
				break;
		}
		system( "pause" );
		system( "CLS" );
		fflush( stdin );
	}

}
