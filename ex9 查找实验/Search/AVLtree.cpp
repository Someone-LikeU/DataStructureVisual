#include "AVLtree.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
struct AVL
{
	TreeElement data;
	AVLnode     left;
	AVLnode     right;
	int         height;
};

//*****************************************************
//函数功能：从数组中创建AVL树
//输入参数：树根引用，数据数组
//输出参数：无
//返回值：	成功返回true，否则返回false
//*****************************************************
bool CreateAVLformArr( AVLTree &T, TreeElement *arr, int len )
{
	int i;
	for ( i = 0; i < len; i++ )
	{
		AVLInsert( arr[ i ], T );
	}
	return true;
}

//*****************************************************
//函数功能：在AVL树中找元素值为x的结点
//输入参数：树结点
//输出参数：无
//返回值：	无
//*****************************************************
AVLnode AVLFind( TreeElement x, AVLTree T )
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
//函数功能：找AVL树中的最小值
//输入参数：树根T
//输出参数：无
//返回值：	最小值结点指针
//*****************************************************
AVLnode AVLFindMin( AVLTree T )
{
	if ( T == NULL ) //empty tree, return NULL
	{
		return NULL;
	}
	AVLnode t = T;	   //none recursion
	while ( t->left )
	{
		t = t->left;
	}
	return t;
}

//*****************************************************
//函数功能：找AVL树中的最大值
//输入参数：树根T
//输出参数：无
//返回值：	最小值结点指针
//*****************************************************
AVLnode AVLFindMax( AVLTree T )
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
		return AVLFindMax( T->right );
	}
}

//*****************************************************
//函数功能：销毁AVL树
//输入参数：树结点
//输出参数：无
//返回值：	无
//*****************************************************
void DestoryAVLtree( AVLTree &T )
{
	if ( T )
	{
		DestoryAVLtree( T->left );
		DestoryAVLtree( T->right );
		delete T;
		T = NULL;
	}
}

//*****************************************************
//函数功能：中序遍历AVL树
//输入参数：树结点
//输出参数：无
//返回值：	无
//*****************************************************
void AVLmidorderTravel( AVLTree T)
{
	if ( T )
	{
		AVLmidorderTravel( T->left );
		cout << setw( 3 ) << T->data << " ";
		AVLmidorderTravel( T->right );
	}
}

//*****************************************************
//函数功能：删除AVL树中元素x
//输入参数：树结点，待删除元素x
//输出参数：无
//返回值：	删除后的树根
//*****************************************************
AVLTree AVLDelete(  AVLTree T, TreeElement x )
{
	AVLnode temp;
	if ( T == NULL )
	{
		cout << "Element not found! Please try again.\n";
	}
	else if ( x < T->data )				 //x比T值小，到左子树中删除
	{
		T->left = AVLDelete( T->left, x );
	}
	else if ( x > T->data )				//x比T的大，到右子树中删
	{
		T->right = AVLDelete( T->right, x );
	}
	else  //找到要删除的结点了
	{
		if ( T->left && T->right )
		{
			temp = AVLFindMin( T->right );//在右子树中找一个最小的结点
			T->data = temp->data;
			T->right = AVLDelete( T->right, T->data );//再在右子树中删除最小元素
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
//函数功能：求AVL树结点的高度
//输入参数：AVL结点
//输出参数：无
//返回值：	高度height
//*****************************************************
static int Height( AVLnode p )
{
	if ( p == NULL )   //定义空树高度为-1
	{
		return -1;
	}
	else
	{
		return p->height;
	}
}

//*****************************************************
//函数功能：向AVL树中插入元素x
//输入参数：待插入元素x，树T
//输出参数：无
//返回值：	删除后的新树
//*****************************************************
AVLTree AVLInsert( TreeElement x, AVLTree &T )
{
	if ( T == NULL )//if it's empty, create and return a one-node tree
	{
		T = new AVL;
		T->data = x;
		T->height = 0;
		T->left = NULL;
		T->right = NULL;
	}
	else if ( x < T->data ) //x is smaller, go left son tree to insert
	{
		T->left = AVLInsert( x, T->left );
		if ( Height( T->left ) - Height( T->right ) == 2 )//left sibtree heigher than right
		{
			if ( x < T->left->data )   //LL rotate
			{
				T = RotateLL( T );
			}
			else				    //LR rotate
			{
				T = RotateLR( T );
			}
		}
	}
	else if ( x > T->data )//x is bigger than T's data,
	{
		T->right = AVLInsert( x, T->right );	// then go T's right sibtree to insert
		if ( Height( T->right ) - Height( T->left ) == 2 )
		{	//right sib son's balance was broken by x
			if ( x > T->right->data )//if x is bigger than T's right son
			{
				T = RotateRR( T );  //then RR rotate
			}
			else  //x is smaller than T's right son
			{
				T = RotateRL( T ); //then RL rotate
			}
		}
	}
	//else x is in the tree already, do nothing
	//upgrate T's height
	T->height = Max( Height( T->left ), Height( T->right ) ) + 1;
	return T;
}

//*****************************************************
//函数功能：求两个数较大的那个
//输入参数：两个整数
//输出参数：无
//返回值：	最大值
//*****************************************************
int Max( int a, int b )
{
	return a > b ? a : b;
}

//*****************************************************
//函数功能：右右旋转
//输入参数：待旋转结点
//输出参数：无
//返回值：  旋转后的子树根节点
//*****************************************************
AVLnode RotateRR( AVLTree k2 )
{
	AVLnode k1;
	k1 = k2->right;
	k2->right = k1->left;
	k1->left = k2;
	k2->height = Max( Height( k2->left ), Height( k2->right ) ) + 1;
	k1->height = Max( Height( k1->right ), k2->height ) + 1;
	return k1;
}

//*****************************************************
//函数功能：左左旋转
//输入参数：带旋转结点
//输出参数：无
//返回值：	旋转后的新树
//*****************************************************
AVLnode RotateLL( AVLTree k2 )
{
	AVLnode k1;
	k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	k2->height = Max( Height( k2->left ), Height( k2->right ) ) + 1;
	k1->height = Max( Height( k1->left ), k2->height ) + 1;
	return k1;
}

//*****************************************************
//函数功能：左右旋转
//输入参数：待旋转树
//输出参数：无
//返回值：	无
//*****************************************************
AVLnode RotateLR( AVLTree k3 )
{
	k3->left = RotateRR( k3->left );//rotate k1 and k2
	return RotateLL( k3 );		 //rotate k3 and k2
}

//*****************************************************
//函数功能：右左旋转
//输入参数：待旋转树
//输出参数：无
//返回值：	旋转后的新树
//*****************************************************
AVLnode RotateRL( AVLTree k3 )
{
	k3->right = RotateLL( k3->right );
	return RotateRR( k3 );
}
