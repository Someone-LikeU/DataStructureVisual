#ifndef _TreeAndForst
#define _TreeAndForst
#include <cstdlib>
#define MAXLEN 100			 //最多节点数
typedef char TreeElement;
//**************************************************
//孩子兄弟表示法
typedef struct csnode* CsRoot;	 //树根指针
struct csnode
{
    TreeElement data;
	CsRoot FirstSon, NextBro;
};
//**********************************************************
//双亲表示法的树的结点信息
typedef struct pnode ParentTree;
struct pnode
{
	TreeElement data;		   //数据
	int parent;				//父节点编号
};
typedef struct something Ptree;	  //	  双亲表示树
struct something
{
	ParentTree Treenodes[ MAXLEN ];		//结点数组
	int n; //树结点总数
};
//*************************************************************
//孩子链表表示法
typedef struct balabala *ListNode;
struct balabala				   //这里相当于一个单链表的结点定义
{
	int ChildIndex;		//结点数据,这里是子节点的数组下标
	ListNode next;	//孩子链表
};
typedef struct lalala		//这里才是孩子链表表示的结构定义
{
	TreeElement data;	  //数据
	ListNode FirstChild;  //首孩子指针，相当于单链表的表头指针
}ArrNode;
typedef struct total	   //封装成一个整体 ,总共经过了三次封装
{
	ArrNode NodeTable[ MAXLEN ];
	int len;
}ChildLink;

//bool IsVisited[ MAXLEN ];//在这里声明一个是否被访问的全局变量数组
//**************************************************************
//双亲表示法相关函数声明
void InitParentForm( Ptree &ParentTree );   //初始化双亲表示法
//void InitVisit();
bool CreateTreeFromFile( Ptree &Ptree );
void ShowAllAncestor( Ptree &ParentTree, TreeElement x );  //求元素x的所有祖先结点值
void ShowChildren( Ptree &ParentTree, TreeElement x );//求元素x的所有孩子结点
void PreOrderTravel( Ptree &ParentTree, int v );   //双亲表示法的先序遍历,v表示根节点
void PreTraverse( Ptree &ParentTree );  //这是先序遍历的入口
void LastOrderTravel( Ptree &ParentTree, int index );  //双亲表示法后序遍历
void LastTraverse( Ptree &ParentTree ); //后序遍历入口
void LevelTravel( Ptree &ParentTree ); //层序遍历
int GetTreeHeight( Ptree &ParentTree, int v ); //求树高度
int TreeHeightEnter(Ptree &ParentTree );
int GetTreeNodes( Ptree &ParentTree );	 //总结点数
int NumOfLeaf( Ptree &ParentTree );	//叶结点数 ，还可以先转换为孩子链表表示法再数children指针为空的结点数
int DegOfTree( Ptree &ParentTree );  //双亲表示法求叶结点数
void PreAndOrder( Ptree &ParentTree, int v, int level );//先序输出结点值及其层次
void PreAndOrderEnter( Ptree &ParentTree );//上一个函数的入口函数
bool GetNodeIndex( int &index, Ptree &Ptree, TreeElement &x );
//下面两个是先序遍历的辅助函数
int GetFirstChildIndex( Ptree &ParentTree, int v );//找下标为v的第一个孩子结点的下标
int NextBroIndex( Ptree &ParentTree, int w ); //找v的在w孩子的兄弟
//*********************************************************************
//孩子链表表示相关函数
bool CreateChildLink( Ptree &ParentTree, ChildLink &CL ); //由双亲表示法创建孩子链表表示法
int GetLeafChildLink( ChildLink &CL );     //由孩子链表表示法求叶结点
int DegOfTreeChildLink( ChildLink &CL ); //由孩子链表表示法，求树的度
void DestoryCLtree( ChildLink &CL );
void RemoveSp( char *str );
//**********************************************************************
//孩子兄弟链表表示相关
void ChangeCStoP( CsRoot &csT, Ptree &ParentTree,int &index ); //将孩子兄弟表示的树转换为双亲表示
void AssistChange( CsRoot csT, Ptree &ParentTree, int &index, int &parent );  //辅助函数
void Create( CsRoot &csT, Ptree &ParentTree, int v );//由双亲表示法创建孩子兄弟表示法的树
void CreateCS( CsRoot &csT, Ptree &ParentTree ); //入口函数
void CsPreOrder( CsRoot csT );	  //孩子兄弟表示法的先序遍历
void CsBreadthTable( CsRoot csT );//广义表输出
void CsLastOrder( CsRoot csT );	   //后序遍历
void CsMidOrder( CsRoot csT );	  //中序遍历
void Csvisit( CsRoot csT );		  //访问函数
void DestoryCStree( CsRoot &csT );
#endif // _TreeAndForst
