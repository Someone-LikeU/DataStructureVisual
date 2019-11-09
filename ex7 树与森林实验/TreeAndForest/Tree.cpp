//**************************************************************
//Filename	         : Tree.cpp
//Abstract           : 该文件是树(森林)的相关算法实现文件
//Author  	         : 周健军
//Accomplished Date  : 2018.12.
//Beginning Date     : 2018.12.16
//Student ID         : 2017217866
//**************************************************************
#include "Tree.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <cstring>
#include <windows.h>
using namespace std;

//*****************************************************
//函数功能：
//输入参数：
//输出参数：
//返回值：
//*****************************************************

//*****************************************************
//函数功能：初始化双亲表示法的树
//输入参数：双亲表示树的引用
//输出参数：该双亲表示树
//返回值：	无
//*****************************************************
void InitParentForm( Ptree &Ptree )
{
	Ptree.n = 0;  //将树结点数置0即可
}

/*void InitVisit()	 //初始化这个标记数组
{
	int i;
	for ( i = 0; i < MAXLEN; i++ )
	{
		IsVisited[ i ] = false;
	}
}*/
//*****************************************************
//函数功能：由文件创建双亲表示的树
//输入参数：双亲表示树
//输出参数：双亲表示树
//返回值：  成功返回true，失败返回false
//*****************************************************
bool CreateTreeFromFile( Ptree &Ptree )
{
	//下面的步骤先从文件读入数据到存放节点信息的二维数组中
	char name[ 10 ];   //文件名
	char path[ 20 ] = "tData\\"; //数据文件路径
	char strChoose[ 500 ];//每次从文件里读入一行
	int i = 0, j;
	bool tag = false;//二叉树文件的标识
	FILE *fp;		   //文件指针
	cout << "请输入树文件名称(例如tree10.tre)：";
	cin >> name;
	strcat( path, name );			//加上完整路径
	fp = fopen( path, "r" );//打开这个数据文件
	if ( NULL == fp )
	{
		cout << "文件打开失败, 请重试." << endl;
		system( "pause" );
		return false;
	}
	while ( !feof( fp ) ) //没到文件尾并且没找到标识
	{
		if ( tag == true )	//找到标记，break
		{
			//cout << "找到标记，break\n";
			break;
		}
		fgets( strChoose, 500, fp );	   //读入一行
		if ( strChoose[ 0 ] == ' ' )   //前面有空格，就去掉空格
			RemoveSp( strChoose );
		if ( strChoose[ 0 ] == '\n' )//空行，继续下一行
		{
			//cout << "空行或有空格，继续读下一行";
			continue;
		}
		else if ( ( strChoose[ 0 ] == '/' ) && ( strChoose[ 1 ] == '/' ) )  //注释行，跳过
		{
			//cout << "注释行，跳过" << endl;
			continue;
		}
		else
		{
			tag = true;		//既不是空行，空格也不是注释行，就把标记标为true
		}
	}
	//上面while结束后，strchoose中应该是树数据标识
	if ( strcmp( strChoose, "Tree or Forest\n" ) != 0 )//如果不是数据标识，就返回失败
	{
		cout << "该文件不是树数据文件，请重新输入文件名。\n";
		return false;
	}
	else		//是文件标识，接着从标识的下一行读入数据到二维数组中
	{
		while ( fgets( strChoose, 500, fp ) != NULL )
		{
			if ( strChoose[ 0 ] == '\n' )  //空行，继续读下一行
				continue;
			else if ( strChoose[ 0 ] == '/' && strChoose[ 1 ] == '/' ) //注释行,也跳过
				continue;
			else          //非空行或注释行，那就到了结点列表那一行，然后退出这个循环，将结点值放入数组
				break;
		}
		i = 0;	   //i索引结点信息数组
		j = 0;	   //j索引双亲表示的数组下标
		while ( strChoose[ i ] != '\0' )   //跳过空格来存储数据
		{
			if ( strChoose[ i ] != ' ' )
			{
				Ptree.Treenodes[ j ].data = strChoose[ i ];  //第j个结点的值
				Ptree.Treenodes[ j ].parent = -1;  //第j个结点的父节点先初始化为-1
				j++;
			}
			i++;
		}
		//退出后，更新结点数组的实际大小
		Ptree.n = j-1;
		cout << "Ptree.n = " << Ptree.n << endl;
		//然后接着往后读，
		int indexP;  //父结点下标
		int indexC;  //子结点下标
		TreeElement eF, eC;//父子结点对应的值
		while ( fgets( strChoose, 500, fp ) != NULL )
		{
			if ( strChoose[ 0 ] == '\n' )  //空行，继续读下一行
				continue;
			else if ( strChoose[ 0 ] == '/' && strChoose[ 1 ] == '/' ) //注释行,也跳过
				continue;
			else          //非空行或注释行，那就到了父子结点信息那一行，更新结点信息
			{
				eF = strChoose[ 0 ];	//父节点值
				eC = strChoose[ 2 ];	//子节点值
				GetNodeIndex( indexP, Ptree, eF );	//获取父节点值在数组中的下标
				GetNodeIndex( indexC, Ptree, eC );//获取子节点值在数组中的下标
				Ptree.Treenodes[ indexC ].parent = indexP;//然后子节点的父节点就是indexP
			}
		}
	}
	fclose( fp ); //创建完毕，关闭文件
	return true; //返回成功
}

//*****************************************************
//函数功能：获取结点在数组里的下标
//输入参数：index引用，双亲表示的树，待求结点元素x
//输出参数：index
//返回值：	无
//*****************************************************
bool GetNodeIndex( int &index, Ptree &Ptree, TreeElement &x )
{
	for ( index = 0; index < Ptree.n; index++ )
	{
		if ( Ptree.Treenodes[ index ].data == x )
		{
			return true;	 //碰到相等，就返回true,而index以参数形式返回
		}
	}
	return false;	  //否则，返回失败
}

//*****************************************************
//函数功能：去除数据文件一行中前面的空格
//输入参数：字符串
//输出参数：字符串
//返回值：	无
//*****************************************************
void RemoveSp( char *str )
{
	int i, cnt, n, j;
	i = cnt = j = 0;
	n = strlen( str ) + 1;
	while ( str[ i ] == ' ' )	//让i移动到第一个非空格字符
	{
		i++;
		cnt++;
	}
	while ( j < n - cnt )	   //去掉cnt个空格后
	{
		str[ j ] = str[ i ];   //往前移
		j++;
		i++;
	}
}

//*****************************************************
//函数功能：求元素x的所有祖先结点值
//输入参数：无
//输出参数：无
//返回值：	无
//*****************************************************
void ShowAllAncestor( Ptree &Ptree, TreeElement x )
{
	int indexNow, indexP; //当前结点的下标，父节点下标
	if ( !GetNodeIndex( indexNow, Ptree, x ) ) //先取得当前结点的下标
	{
		cout << "该结点不存在于树中，请重新选择.\n";	//找不到，就返回
		return;
	}
	if ( indexNow == 0 )	//如果传进来的是根节点值，则提示错误消息，并返回
	{
		cout << "该结点为根节点，没有祖先结点，请重新选择\n";
		return;
	}
	cout << "结点 " << x << "的所有祖先结点值如下 ：\n";
	do	  //前面没返回的话，至少要执行一遍，所以用do-while，前面操作已经找到了当前结点的下标
	{
		indexP = Ptree.Treenodes[ indexNow ].parent;//然后获取当前结点的父节点的下标
		cout << Ptree.Treenodes[ indexP ].data << " ";	   //然后输出父节点值
		indexNow = indexP;  //然后让父节点成为当前结点，继续找父节点的父节点
	} while ( indexP != 0 );   //到根节点为止
}

//*****************************************************
//函数功能：求元素x的所有子结点值
//输入参数：无
//输出参数：无
//返回值：	无
//*****************************************************
void ShowChildren( Ptree &Ptree, TreeElement x )
{
	int indexPar, indexCd;//当前结点下标，子节点下标
	if ( !GetNodeIndex( indexPar, Ptree, x ) )	  //尝试获取当前元素的下标
	{
		cout << "该结点不存在于树中，请重新选择.\n";	//找不到，就返回
		return;
	}
	cout << "该结点的子节点值如下：\n";
	for (  indexCd = indexPar + 1 ; indexCd < Ptree.n ; indexCd++ ) //从当前下标开始往后遍历
	{
		if ( Ptree.Treenodes[ indexCd ].parent == indexPar )  //碰到父节点是indexPar的就是它的子节点，然后输出
		{
			cout << Ptree.Treenodes[ indexCd ].data << " ";
		}
	}
}

//*****************************************************
//函数功能：先序遍历入口函数
//输入参数：双亲表示的树引用
//输出参数：无
//返回值：	无
//*****************************************************
void PreTraverse( Ptree &Ptree )
{
	int i;
	cout << "先序遍历如下：\n";
	for ( i = 0 ; i < Ptree.n ; i++ )		 //搜索根节点，因为可能是森林，哟多个根结点
	{
		if ( Ptree.Treenodes[ i ].parent == -1 )
		{
			PreOrderTravel( Ptree, i );
		}
	}
}

//*****************************************************
//函数功能：先序遍历函数
//输入参数：双亲表示的树引用，开始下标（根节点）index
//输出参数：无
//返回值：	无
//*****************************************************
void PreOrderTravel( Ptree &ParentTree, int v )
{
	int w;
	cout << ParentTree.Treenodes[ v ].data << " ";  //不管三七二十一，先输出根节点值
	w = GetFirstChildIndex( ParentTree, v );//然后搞到该结点的第一个子节点的下标
	while ( w != -1 )   //直到没有子节点
	{
		PreOrderTravel( ParentTree, w );//递归先序遍历子节点的子节点
		w = NextBroIndex( ParentTree, w ); //然后处理当前结点的兄弟节点
	}
}

//*****************************************************
//函数功能：后序遍历函数
//输入参数：双亲表示的树引用，开始下标（根节点）index
//输出参数：无
//返回值：	无
//*****************************************************
void LastOrderTravel( Ptree &ParentTree, int index )
{
	int w;  //第一个孩子结点下标
	w = GetFirstChildIndex( ParentTree, index );  //先取得第一个孩子结点的下标
	while ( w != -1 )  //一直取首孩子下标，直到不能取为止
	{
		LastOrderTravel( ParentTree, w ); //递归处理子节点
		w = NextBroIndex( ParentTree, w );//取兄弟结点，处理兄弟结点
	}
	cout << ParentTree.Treenodes[ index ].data << " "; //最后才访问根结点，实现后序遍历
}

//*****************************************************
//函数功能：后序遍历函数入口
//输入参数：双亲表示的树引用
//输出参数：无
//返回值：	无
//*****************************************************
void LastTraverse( Ptree &ParentTree )
{
	int i; //同理，搜索树中的根节点，可能是森林，有多个根节点
	cout << "后序遍历如下：\n";
	for ( i = 0; i < ParentTree.n; i++ )
	{
		if ( ParentTree.Treenodes[ i ].parent == -1 ) //根节点
		{
			LastOrderTravel( ParentTree, i );
		}
	}
}

//*****************************************************
//函数功能：层序遍历树（森林）
//输入参数：双亲表示树（森林）
//输出参数：无
//返回值：	无
//*****************************************************
void LevelTravel( Ptree &ParentTree )
{
	//双亲表示法中结点都是按顺序存储，所以直接顺序输出数组即可
	int i;
	cout << "层序遍历如下：\n";
	for ( i = 0; i < ParentTree.n; i++ )
	{
		cout << ParentTree.Treenodes[ i ].data << " ";
	}
}

//*****************************************************
//函数功能：求森林（树）高度
//输入参数：双亲表示的树（森林）
//输出参数：无
//返回值：	无
//*****************************************************
int GetTreeHeight( Ptree &ParentTree, int v )
{
	//下标在最后的肯定位于最深一层，所以数它有多少祖先结点，再加上它本身就是所求高度
	int index, height;
	index = v;
	height = 0;
	do
	{
		height++;
		index = ParentTree.Treenodes[ index ].parent;
	} while ( index != -1 );
	return height;
}

int TreeHeightEnter(Ptree &ParentTree )
{
	int i,height = 0,t;
	for (i = 1 ; i < ParentTree.n;i++)
	{
		if(ParentTree.Treenodes[i].parent == -1)
		{
			t = GetTreeHeight(ParentTree,i - 1);
			if(height < t)
			height = t;
		}
	}
	return height;
}
//*****************************************************
//函数功能：求森林（树）总结点数
//输入参数：双亲表示的树（森林）
//输出参数：无
//返回值：	无
//*****************************************************
int GetTreeNodes( Ptree &ParentTree )
{
	return ParentTree.n;
}

//*****************************************************
//函数功能：求叶结点数
//输入参数：双亲表示树
//输出参数：无
//返回值：	无
//*****************************************************
int NumOfLeaf( Ptree &ParentTree )
{
	int i, numOfP;
	numOfP = 1;		//至少有一个父节点
	for ( i = 0; i < ParentTree.n - 1; i++ )
	{
		if(ParentTree.Treenodes[i].parent == -1)
			continue;
		if ( ParentTree.Treenodes[ i ].parent == ParentTree.Treenodes[ i + 1 ].parent )	//相邻两个的父节点一样
		{
			continue;  //就继续
		}
		else
		{
			numOfP++; //否则，父节点数加一
		}
	}
	return ParentTree.n - numOfP;  //总结点数减父节点数就是叶结点数，返回
}

//*****************************************************
//函数功能：由双亲表示法创建孩子链表表示法
//输入参数：双亲表示树结构，孩子链表表示结构
//输出参数：孩子链表结构
//返回值：	true or false
//*****************************************************
bool CreateChildLink( Ptree &ParentTree, ChildLink &CL )
{
	if ( ParentTree.n == 0 )
	{
		return false;
	}
	int i, par,j;  //当前结点下标，父节点下标
	ListNode t = NULL;
	CL.len = ParentTree.n;	  //先把长度赋给CL
	for ( i = 0; i < ParentTree.n; i++ )   //然后将各结点值赋给CL的对应位置
	{
		CL.NodeTable[ i ].data = ParentTree.Treenodes[ i ].data;
		CL.NodeTable[ i ].FirstChild = new balabala; //firstchild相当于单链表的头指针，所以给它分配一个结点
		CL.NodeTable[ i ].FirstChild->next = CL.NodeTable[i].FirstChild;//把该链表弄成带尾指针的单循环链表
		//这里的CL.NodeTable[ i ].FirstChild 就相当于一般带尾指针单循环链表的R指针
	}
	//然后用一个循环来设置每个结点的孩子链表
	i = 0;
	while(i < ParentTree.n )
	{
		if(ParentTree.Treenodes[i].parent == -1)
		{
			i++;
			continue;
		}
		for ( j = i;j < ParentTree.n && ParentTree.Treenodes[j].parent != -1 ; j++ )	//根节点没有父节点，所以从1下标开始
		{
			par = ParentTree.Treenodes[ j ].parent;  //找到当前结点的父节点下标
			t = new balabala;//就新申请一个结点，加到对应父节点的孩子链表上
			t->ChildIndex = j;
			t->next = CL.NodeTable[ par ].FirstChild->next;
			CL.NodeTable[ par ].FirstChild->next = t;
			CL.NodeTable[ par ].FirstChild = t;
		}
		i = j;
	}

	return true;
}

//*****************************************************
//函数功能：销毁之前创建的孩子链表表示的树
//输入参数：孩子链表表示结构
//输出参数：无
//返回值：	无
//*****************************************************
void DestoryCLtree( ChildLink &CL )
{
	ListNode p, t;
	int i;
	for ( i = 0; i < CL.len; i++ )	   //firstchild 变量是带尾指针的单循环链表，所以就从它开始销毁
	{
		p = CL.NodeTable[ i ].FirstChild->next;
		while ( p != CL.NodeTable[ i ].FirstChild )	  //从头开始删，
		{
			t = p->next;
			delete p;
			p = t;
		}
		delete CL.NodeTable[ i ].FirstChild;	 //最后删掉尾结点本身
	}
}

//*****************************************************
//函数功能：由孩子链表表示法求叶结点数
//输入参数：孩子链表表示结构
//输出参数：无
//返回值：	结点数
//*****************************************************
int GetLeafChildLink( ChildLink &CL )
{
	int n = 0, i;
	for ( i = 0; i < CL.len; i++ )
	{
		if ( CL.NodeTable[ i ].FirstChild->next == CL.NodeTable[ i ].FirstChild )
		{
			n++;
		}
	}
	return n;
}

//*****************************************************
//函数功能：由双亲表示法求树的度
//输入参数：双亲表示树结构
//输出参数：无
//返回值：	度deg
//*****************************************************
int DegOfTree( Ptree &ParentTree )
{
	//类似于顺序表中去重的操作，双亲表示中parent表中重复次数最多的便是整个树的度
	int deg = 0, i, j;
	i = 1, j = 2; //0号下标是树根，所以从1号开始
	while ( j < ParentTree.n )
	{
		//遍历，i，j位置上的parent相同，j+1继续
		if ( ParentTree.Treenodes[ i ].parent == ParentTree.Treenodes[ j ].parent )
		{
			j++;	 //往后
			continue;
		}
		if ( deg < j - i )	//j-i，即下标之差就是当前某父节点的度，判断和之前的deg大小，从而更新deg
		{
			deg = j - i;
		}
		i = j;	  //然后从原来j那个位置继续往后看
		j++;
	}
	return deg;  //最后return这个度数
}

//*****************************************************
//函数功能：由孩子链表表示法求树的度
//输入参数：孩子链表表示的树
//输出参数：无
//返回值：	度deg
//*****************************************************
int DegOfTreeChildLink( ChildLink &CL )
{
	int i, deg, cnt;  //cnt记录每次访问结点的孩子结点数
	deg = 0;
	ListNode p = NULL;
	for ( i = 0; i < CL.len; i++ )
	{
		cnt = 1;	//每次访问前初始为1
		if ( CL.NodeTable[ i ].FirstChild->next != CL.NodeTable[ i ].FirstChild )	//该结点的孩子链表不是空表
		{
			//那就进来对它的孩子链表进行计数
			p = CL.NodeTable[ i ].FirstChild->next->next; //next->next 才是第一个子结点
			while ( p != CL.NodeTable[ i ].FirstChild )
			{
				cnt++;
				p = p->next;
			}
		}
		if ( deg < cnt )	   //当前结点的孩子表结点个数比之前deg要大
		{
			deg = cnt; //就更新deg
		}
	}
	return deg;
}

//*****************************************************
//函数功能：双亲表示法中找下标为v的结点的第一个孩子结点下标
//输入参数：双亲表示树，结点下标v
//输出参数：无
//返回值：	子节点存在返回子节点下标，否则返回-1
//*****************************************************
int GetFirstChildIndex( Ptree &ParentTree, int v )
{
	int w;
	//cout << " v is " << v << endl;
	for ( w = v + 1; w < ParentTree.n; w++ ) //孩子结点下标肯定在v之后，所以从v+1开始遍历
	{
		//cout << "w is " << w << endl;
		if ( ParentTree.Treenodes[ w ].parent == v ) //find the first child
		{
			return w;
		}
	}
	return -1;
}

//*****************************************************
//函数功能：找双亲表示树种结点v的位于w子节点的后一个子节点下标
//输入参数：双亲表示树，首子节点w
//输出参数：无
//返回值：	子节点存在返回子节点下标，否则返回-1
//*****************************************************
int NextBroIndex( Ptree &ParentTree, int w )
{
	int i;
	for ( i = w + 1; i < ParentTree.n; i++ )   //兄弟结点肯定在w之后所以从w+1开始
	{
		if ( ParentTree.Treenodes[ i ].parent == ParentTree.Treenodes[ w ].parent )
		{
			//cout << "return " << i << endl;
			return i;		//两个有相同的祖先，就返回i
		}
	}
	return -1;			//否则返回-1
}

//*****************************************************
//函数功能：递归创建一个孩子链表表示的树
//输入参数：孩子链表表示树结点，双亲表示树，结点下标
//输出参数：孩子链表表示树结点
//返回值：	无
//*****************************************************
void Create( CsRoot &csT, Ptree &ParentTree, int v )
{
	//递归的创建孩子兄弟表示的树，二叉链表表示，整个执导思想是按先序遍历的顺序创建
	int w; //结点v的第一个孩子结点的下标
	csT = new csnode;
	if ( csT == NULL )
	{
		cout << "memory allocate failed, please try again.\n";
		return;
	}
	csT->data = ParentTree.Treenodes[ v ].data;
	csT->FirstSon = NULL;
	csT->NextBro = NULL;
	w = GetFirstChildIndex( ParentTree, v ); //取第一个孩子结点的下标
	if ( w != -1 )
	{
		Create( csT->FirstSon, ParentTree, w );	  //递归创建第一个孩子结点的树
	}
	w = NextBroIndex( ParentTree, v );	   //取得v的兄弟节点，继续递归创建兄弟结点的树
	if ( w != -1 )
	{
		Create( csT->NextBro, ParentTree, w );
	}
}

//*****************************************************
//函数功能：创建孩子链表表示树的入口函数
//输入参数：孩子链表表示树结点，双亲表示树
//输出参数：孩子链表表示树结点
//返回值：	无
//*****************************************************
void CreateCS( CsRoot &csT, Ptree &ParentTree )
{
	int i;
	for ( i = 0; i < ParentTree.n; i++ ) //搜索第一个根节点
	{
		if ( ParentTree.Treenodes[ i ].parent == -1 ) //找到根节点就退出
		{
			break;
		}
	}
	if ( i < ParentTree.n )//防止越界
	{
		Create( csT, ParentTree, i );
	}
}

//*****************************************************
//函数功能：销毁孩子链表表示树
//输入参数：孩子链表表示树结点
//输出参数：无
//返回值：	无
//*****************************************************
void DestoryCStree( CsRoot &csT )
{
	//就像二叉树的销毁那样，利用后序遍历的方法
	if ( csT )
	{
		DestoryCStree( csT->FirstSon );
		DestoryCStree( csT->NextBro );
		delete csT;
		csT = NULL;
	}
}

//*****************************************************
//函数功能：先序遍历并输出层次
//输入参数：双亲表示树，层次level
//输出参数：无
//返回值：	无
//*****************************************************
void PreAndOrder( Ptree &ParentTree, int v, int level )
{
	int w;
	cout << "(" << ParentTree.Treenodes[ v ].data << "," << level << ") ";
	w = GetFirstChildIndex( ParentTree, v );//the find the first child's index recursively travel it

	while ( w != -1 )
	{
		PreAndOrder( ParentTree, w, level + 1 );
		w = NextBroIndex( ParentTree, w );	   //find w's next bro, and travel it
	}
}

//*****************************************************
//函数功能：先序遍历并输出层次函数入口
//输入参数：双亲表示树，层次level
//输出参数：无
//返回值：	无
//*****************************************************
void PreAndOrderEnter( Ptree &ParentTree)
{
	int i;
	int level = 1;
	for ( i = 0; i < ParentTree.n; i++ )
	{
		if ( ParentTree.Treenodes[ i ].parent == -1 )  //可能是森林，有多个根节点，所以这样遍历
		{
			PreAndOrder( ParentTree, i, level );
		}
	}
}

//*****************************************************
//函数功能：孩子兄弟表示法广义表输出
//输入参数：结点
//输出参数：无
//返回值：	无
//*****************************************************
void CsBreadthTable( CsRoot csT )
{
	CsRoot t;
	cout << csT->data;
	if(csT->FirstSon)
	{
		cout << "(";
		for(t = csT->FirstSon ; t->NextBro ; t = t->NextBro)
		{
			CsBreadthTable(t);
			cout << ",";
		}
		CsBreadthTable(t);
		cout << ")";
	}

}

//*****************************************************
//函数功能：孩子兄弟表示法先序遍历
//输入参数：结点
//输出参数：无
//返回值：	无
//*****************************************************
void CsPreOrder( CsRoot csT )
{
	if ( csT )
	{
		Csvisit( csT );
		CsPreOrder( csT->FirstSon );
		CsPreOrder( csT->NextBro );
	}
}
void Csvisit( CsRoot csT )
{
	cout << csT->data << " ";
}

void CsMidOrder( CsRoot csT )
{
	if ( csT )
	{
		CsPreOrder( csT->FirstSon );
		Csvisit( csT );
		CsPreOrder( csT->NextBro );
	}
}

//*****************************************************
//函数功能：孩子兄弟表示法后序遍历
//输入参数：结点
//输出参数：无
//返回值：	无
//*****************************************************
void CsLastOrder( CsRoot csT )
{
	if ( csT )
	{
		CsLastOrder( csT->FirstSon );
		CsLastOrder( csT->NextBro );
		Csvisit( csT );
	}
}

//*****************************************************
//函数功能：转换孩子兄弟表示树为双亲表示
//输入参数：孩子兄弟树结点，双亲树 ,下标，父节点下标
//输出参数：双亲树
//返回值：	无
//*****************************************************

void ChangeCStoP( CsRoot &csT, Ptree &PTree, int &index )
{
	queue<CsRoot> Q;
	int parent = -1;
	CsRoot t, root;
	root = csT;
	Q.push( root ); //先把根结点入队
	PTree.Treenodes[ index ].data = root->data;//写根结点信息
	PTree.Treenodes[ index ].parent = parent;
	index++; //下标索引加一
	parent = index - 2;  //森林的时候，后面的结点的parent紧跟根节点
	PTree.n++;//树结点数加一
	Q.pop();//根结点出队
	do
	{
		t = root->FirstSon;	 //t指向根的第一个孩子
		parent++;			 //更新父节点下标
		while ( t )			//t不空，就循环把兄弟写进PT
		{
			Q.push( t );
			PTree.Treenodes[ index ].data = t->data;
			PTree.Treenodes[ index ].parent = parent;
			PTree.n++;
			index++;
			t = t->NextBro;
			//cnt++;
		}
		root = Q.front();	   //然后取第一个孩子，继续按上述方法处理
		Q.pop();
	}while ( root->FirstSon != NULL || !Q.empty() );  //最后一个结点或者队列不空为止
}
/*void ChangeCStoP( CsRoot csT, Ptree &ParentTree, int &index, int parent )
{
	CsRoot t;
	t = csT->FirstSon;
	while ( t != NULL )
	{
		while ( csT->FirstSon != NULL )
		{
			AssistChange( csT->FirstSon, ParentTree, ++index, parent );
			csT = csT->FirstSon;
			parent++;
		}
		csT = t->NextBro;
		t = t->NextBro;

	}
}

void AssistChange( CsRoot csT, Ptree &ParentTree, int &index, int &parent )
{
	while ( csT )
	{
		ParentTree.Treenodes[ index ].data = csT->data;
		ParentTree.n++;
		ParentTree.Treenodes[ index ].parent = parent;
		index++;
		csT = csT->NextBro;
	}
}	  */
//*****************************************************
//函数功能：
//输入参数：
//输出参数：
//返回值：
//*****************************************************
