#ifndef _LinkBiTree
#define _LinkBiTree
#define MAXNODES 100        //规定最多100个结点
#include "AVLTree.h"
#include "seqBiTree.h"
typedef char ElementType;   //先定为字符类型
typedef struct TreeNode *BiTree;    //树结点指针
typedef struct TreeNode BiNode;     //树结点
struct TreeNode
{
    ElementType data;
    BiTree Left;               //左孩子
	BiTree Right;            //右孩子
};
//遍历算法及其应用
void Visit( BiTree BT );                                                                        //遍历函数，具体实现视情况定
void PreOrderTravel( BiTree BT );           //二叉树的先序遍历
void MidOrderTravel( BiTree BT);          //二叉树中序遍历
void LastOrderTravel( BiTree BT);          //二叉树后序遍历
void PreTravelNoRec( BiTree BT);            //非递归先序遍历
void MidTravelNoRec( BiTree BT);     //非递归中序遍历
void LastTravelNoRec( BiTree BT );       //非递归后序遍历
void LevelOrderTravel( BiTree BT );             //层次遍历
void MidTravelAndLevel( BiTree BT, int Level );  //中序遍历并输出结点所在层次
int GetTreeHeight( BiTree BT );                       //求二叉树高度
void TotalNodes( BiTree BT, int &cnt );            //求总结点数
void NumOfLeaf( BiTree BT, int &cnt );           //求二叉树叶结点数
void ShowLeaves( BiTree BT );            //打印所有叶结点的值
void NumOfDeg2( BiTree BT, int &cnt );                     //求二叉树2度结点数
void RelativeOfNode( BiTree BT, ElementType &x );     //找元素为x的结点的亲戚结点
void LevelOfNode( BiTree BT, ElementType &x, int level, bool &flag );          //求元素为x的结点的层次
void ChangeArrIntoLink( BiTree &BT, SeqBiTree &Tree,int i );  //将顺序二叉树转换成链二叉树
void GetChild( BiTree BT, ElementType &x, BiNode* &C1, BiNode* &C2);  //取值为x的结点的子结点
void GetFather( BiTree BT, ElementType &x, BiNode* &S );                    //求父节点
void GetBro( BiTree BT,ElementType &x, BiNode* &Bro );        //求兄弟节点
//拓展
BiNode* GetNode( ElementType x, BiTree BT ); //在二叉树中找结点值为x的结点
void PathOfNode( ElementType &x, BiTree BT, char* str, int &i, bool &flag ); //值为x的结点的路径
void CopyTree( BiTree SourceT, BiTree &T );                //复制一棵二叉树
void EachPathOfLeaf( BiTree BT, char* str,int &i );            //求每个叶结点的路径
BiNode* FindCommonAnc( ElementType &e1, ElementType &e2, BiTree BT );   //找两个结点最近的共同祖先
BiNode* FindComAnc2( BiNode *e1, BiNode *e2, BiTree BT ); //方法二
int FindLongestPath( BiTree BT );//求二叉树中一条最长路径长度并输出路径上的值

//创建二叉树算法
void CreateTreeUsingFile( BiTree &BT ); //文件方式创建二叉树
void CreateTreeInteractive( BiTree &BT ); //交互方式创建二叉树
void GetTreeData( char TreeData[ MAXNODES ][ 4 ], int &len );
void CreateNode( BiTree &pNode , char data[MAXNODES][4], int len, int &cur ); //文件方式创建协助函数
void AssistCreate( BiNode* &p, ElementType &x,int left, int right );	//交互方式创建协助函数
void RemoveSp( char *str );

//二叉树的销毁
void DestoryBiTree( BiTree &BT );

//二叉树的修改
void ExchangeRightLeft( BiTree BT );    //交换左右子树
void DeleteSibTree( BiTree BT );    //删除子树
#endif // _LinkBiTree
