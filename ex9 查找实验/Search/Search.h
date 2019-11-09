#ifndef _Search_H
#define _Search_H
typedef int BSTelement;//定义结点值类型
struct BinSearchTree;
typedef struct BinSearchTree *BSTnode; //二叉搜索树结点指针
typedef struct BinSearchTree BST;//结点


//二叉搜索树相关算法
BSTnode Find( BSTelement &x, BSTnode T ); //查找元素x
BSTnode Find2( BSTelement &x, BSTnode T ); //循环方式查找元素x
BSTnode FindMin( BSTnode T ); //找最小值
BSTnode FindMax( BSTnode T ); //找最大值
BSTnode Delete( BSTnode T, BSTelement &x );
bool CreateBSTfromArr( BSTnode &T, BSTelement *arr, int len );//从数组创建二叉搜索树
void DestoryBST( BSTnode &T ); //二叉搜索树的销毁
bool Insert( BSTnode &T, BSTelement &x ); //插入
void MidOrderTravel( BSTnode T );	//中序遍历，用于检验所创建的二叉搜索树
int BinarySearch( BSTelement *arr, int len, BSTelement &x );//二分查找
int BinSearchRecu( BSTelement *arr, BSTelement &x, int low, int high );//递归算法
//平衡二叉树相关算法

#endif // _Search_H
