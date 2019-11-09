//**************************************************************
//Filename	         : Search.cpp
//Abstract           : 该文件是查找的相关算法实现文件
//Author  	         : 周健军
//Accomplished Date  : 2018.12.22
//Beginning Date     : 2018.12.22
//Student ID         : 2017217866
//**************************************************************

#include "Search.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
struct BinSearchTree
{
	BSTelement data;
	BSTnode left;
	BSTnode right;
};


//*****************************************************
//函数功能：在二叉搜索树中查找某个元素
//输入参数：待查找元素x，树根T
//输出参数：无
//返回值：	找到返回结点指针，失败返回空指针
//*****************************************************
BSTnode Find( BSTelement &x, BSTnode T )
{
	if ( T == NULL ) //空树或者没有树中没有这个值，返回空指针
	{
		return NULL;
	}
	if ( T->data < x )				 //小于根节点，递归在左子树找
	{
		return Find( x, T->left );
	}
	else if ( T->data >x )				//大于，在右子树里找
	{
		return Find( x, T->right );
	}
	else								//找到了，就返回这个结点
	{
		return T;
	}
}

//*****************************************************
//函数功能：在二叉搜索树中查找某个元素
//输入参数：待查找元素x，树根T
//输出参数：无
//返回值：	找到返回结点指针，失败返回空指针
//*****************************************************
BSTnode Find2( BSTelement &x, BSTnode T )
{
	while ( T )
	{
		if ( x > T->data )			 //大于根节点，在右子树中继续找
		{
			T = T->right;
		}
		else if ( x < T->data )		  //小于，在左子树中继续找
		{
			T = T->left;
		}
		else							  //相等，就返回这个指针
			return T;
	}
	return NULL;
}

//*****************************************************
//函数功能：找二叉搜索树中的最小值
//输入参数：树根T
//输出参数：无
//返回值：	最小值结点指针
//*****************************************************
BSTnode FindMin( BSTnode T )
{
	if ( T == NULL ) //empty tree, return NULL
	{
		return NULL;
	}
	BSTnode t = T;	   //none recursion
	while ( t->left )
	{
		t = t->left;
	}
	return t;
}

//*****************************************************
//函数功能：找二叉搜索树中的最大值
//输入参数：树根T
//输出参数：无
//返回值：	最小值结点指针
//*****************************************************
BSTnode FindMax( BSTnode T )
{
	if ( T == NULL )  //empty tree, return NULL
	{
		return NULL;
	}
	else if ( T->right == NULL ) //if fight sibling tree is empty,return itself,which is answer
	{
		return T;
	}
	else
	{
		return FindMax( T->right );
	}
}

//*****************************************************
//函数功能：销毁二叉搜索树
//输入参数：树根
//输出参数：无
//返回值：	无
//*****************************************************
void DestoryBST( BSTnode &T )
{
	if ( T )				//like last order travel
	{
		DestoryBST( T->left );
		DestoryBST( T->right );
		delete T;
		T = NULL;
	}
}

//*****************************************************
//函数功能：在二叉搜索树中插入一个结点
//输入参数：树的引用T，待插入值x
//输出参数：新树根T
//返回值：	无
//*****************************************************
bool Insert( BSTnode &T, BSTelement &x )
{
	if ( T == NULL )		   //本就是一棵空树，插入节点成为新根节点
	{
		T = new BST;
		/*if ( T == NULL )
		{
			cout << "Memory allocate failed.Please try agiain.\n";
			return false;
		}*/
		T->data = x;
		T->left = NULL;
		T->right = NULL;
	}
	else if ( x > T->data )		   //待插入的x大于当前结点值
	{
		Insert( T->right, x );	   //就到右子树中插
	}
	else if ( x < T->data )
	{
		Insert( T->left, x );		//否则就到左子树中插
	}
	//if there is a x ,do nothing
}

//*****************************************************
//函数功能：中序遍历
//输入参数：树根指针
//输出参数：无
//返回值：	无
//*****************************************************
void MidOrderTravel( BSTnode T )
{
	if ( T )
	{
		MidOrderTravel( T->left );
		cout << setw( 3 ) << T->data << " ";
		MidOrderTravel( T->right );
	}
}

//*****************************************************
//函数功能：删除操作一个元素x
//输入参数：树根，待删除元素x
//输出参数：无
//返回值：	删除后的新树树根
//*****************************************************
BSTnode Delete( BSTnode T, BSTelement &x )
{
	BSTnode temp;
	if ( T == NULL )
	{
		cout <<endl;
		cout << setw(3) << x <<  " was not found! Please try again.\n";
	}
	else if ( x < T->data )				 //x比T值小，到左子树中删除
	{
		T->left = Delete( T->left, x );
	}
	else if ( x > T->data )				//x比T的大，到右子树中删
	{
		T->right = Delete( T->right, x );
	}
	else  //找到要删除的结点了
	{
		if ( T->left && T->right )
		{
			temp = FindMin( T->right );//在右子树中找一个最小的结点
			T->data = temp->data;
			T->right = Delete( T->right, T->data );//再在右子树中删除最小元素
		}
		else	//待删结点只有一个子结点或无子节点
		{
			temp = T;
			if ( !T->left )//有右子节点或无子节点
				T = T->right;
			else if ( !T->right )
				T = T->left;
			free( temp );
			temp = NULL;
		}
	}
	return T;
}

//*****************************************************
//函数功能：从数组创建一个二叉搜索树
//输入参数：树根指针引用，数据数组
//输出参数：创建好的树根
//返回值：	成功返回0，失败返回1
//*****************************************************
bool CreateBSTfromArr( BSTnode &T, BSTelement *arr, int len )
{
	//核心思想就是不断的用调用插入函数
	int i;
	for ( i = 0; i < len; i++ )
	{
		 Insert( T, arr[ i ] );
		//{
		//	cout << "Create failed.Please try again.\n";
		//	return false;
		//}
	}
	return true;
}

//*****************************************************
//函数功能：二分查找
//输入参数：数据数组，待查找元素x
//输出参数：无
//返回值：	成功返回待查找元素下标，失败返回-1
//*****************************************************
int BinarySearch( BSTelement *arr, int len, BSTelement &x )
{
	int mid, low, high;
	low = 0;
	high = len - 1;
	while ( low <= high )
	{
		mid = ( low + high ) / 2;
		if ( x > arr[ mid ] )
		{
			low = mid + 1;
		}
		else if ( x < arr[ mid ] )
		{
			high = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

//*****************************************************
//函数功能：递归法二分查找
//输入参数：查找数组，待查元素x，low，high
//输出参数：无
//返回值：	成功返回下标，失败返回-1
//*****************************************************
int BinSearchRecu( BSTelement *arr, BSTelement &x, int low, int high )
{
	int mid;
	if ( low > high )  //递归的两个条件
	{
		return -1;
	}
	else
	{
		mid = ( low + high ) / 2;
		if ( x > arr[ mid ] )
		{
			return BinSearchRecu( arr, x, mid + 1, high );
		}
		else if ( x < arr[ mid ] )
		{
			return BinSearchRecu( arr, x, low, mid - 1 );
		}
		else
		{
			return mid;
		}
	}
}
//*****************************************************
//函数功能：
//输入参数：
//输出参数：
//返回值：
//*****************************************************
