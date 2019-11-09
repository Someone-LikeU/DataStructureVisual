//**************************************************************
//Filename	         : LinkBiTree.cpp
//Abstract           : 该文件是二叉树的相关算法实现文件
//Author  	         : 周健军
//Accomplished Date  : 2018.12.9
//Beginning Date     : 2018.11.30
//Student ID         : 2017217866
//**************************************************************

#include "LinkBiTree.h"
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;

//*****************************************************
//函数功能：
//输入参数：
//输出参数：
//返回值：
//*****************************************************

//*****************************************************
//函数功能：访问结点，具体操作视情况，默认输出
//输入参数：树结点
//输出参数：无
//返回值：  无
//*****************************************************
void Visit( BiTree BT )
{
    cout << BT->data << " ";
}

//*****************************************************
//函数功能：递归先序遍历二叉树
//输入参数：树根结点
//输出参数：无
//返回值：     无
//*****************************************************
void PreOrderTravel( BiTree BT )
{
    if( BT )
    {
        Visit(BT);                                          //访问根节点
        PreOrderTravel( BT->Left );      //递归先序遍历左子树
        PreOrderTravel( BT->Right );    //递归先序遍历右子树
    }
}

//*****************************************************
//函数功能：递归中序遍历二叉树
//输入参数：数根结点
//输出参数：无
//返回值：     无
//*****************************************************
void MidOrderTravel( BiTree BT )
{
    if(BT)
    {
        MidOrderTravel(BT->Left);       //中序遍历左子树
        Visit(BT);                                          //访问根节点
        MidOrderTravel(BT->Right);     //中序遍历右子树
    }
}

//*****************************************************
//函数功能：递归后序遍历二叉树
//输入参数：数根结点
//输出参数：无
//返回值：     无
//*****************************************************
void LastOrderTravel( BiTree BT )
{
    if (BT)
    {
        LastOrderTravel( BT->Left );    //后续遍历左子树
        LastOrderTravel( BT->Right ); //后续遍历右子树
        Visit(BT);                                          //访问根节点
    }
}

//*****************************************************
//函数功能：非递归先序遍历二叉树
//输入参数：树根
//输出参数：无
//返回值：     无
//*****************************************************
void PreTravelNoRec( BiTree BT )
{
    BiNode *p;
    stack<BiNode*> S;       //要借助一个栈
    p = BT;            //虽然BT是形参，函数内部不会修改实参，但这样做是个好习惯
    while ( p || !S.empty() )
    {
        if ( p )
        {
            Visit(p);      //先序，所以这里先访问结点
            S.push(p);      //p指针入栈
            p = p->Left;    //然后遍历左子树
        }
        else
        {
            p = S.top();    //p为空时，将上一层的根节点指针弹出给p
            S.pop();
            p = p->Right;       //then travel right sib Tree
        }
    }
}

//*****************************************************
//函数功能：非递归中序遍历二叉树
//输入参数：树根
//输出参数：无
//返回值：     无
//*****************************************************
void MidTravelNoRec( BiTree BT )
{
    BiNode *p;
    stack<BiNode *> S;
    p = BT;
    while ( p || !S.empty() )
    {
        if ( p )            //根节点先入栈，让左子树遍历结束，返回访问根节点
        {
            S.push(p);
            p = p->Left;    //遍历左子树
        }
        else
        {
            p = S.top();    //某个子树的根节点出栈
            S.pop();
            Visit(p);           //访问它
            p = p->Right;   //遍历右子树
        }
    }
}

//*****************************************************
//函数功能：非递归后序遍历二叉树
//输入参数：树根
//输出参数：无
//返回值：     无
//*****************************************************
/*void LastTravelNoRec( BiTree BT )
{
    BiNode *p;
    stack<BiNode*> S;     //最多结点个数的栈
    int tag[MAXNODES];      //标记左右子树
    int n;
    p = BT;
    while( p != NULL || !S.empty() )
    {
        if ( p )            //p指针即当前根节点入栈，
        {                       //以备访问根节点以及访问右子树
            S.push(p);
            tag[S.top()] = 0;   //标记遍历左子树
            p = p->Right;
        }
        else        //p is NULL ,but stack is not empty
        {
            p = S.top();        //get stack top, but don't pop, to travel right sib tree
            if ( tag[S.top()] == 0 )   //this imply that left sibTree has been traveled, and right sibtree hasn't been traveled yet
            {
                tag[S.top()] = 1;        //set the tag that current node travel right sibtree
                p = p->Right;
            }
            else    //tag[S.top] == 1, this imply both right and left sibtree have been traveled
            {
                S.pop();        //then pop it
                Visit(p);       //visit a root
                //the pop operation make p useless, so let p point to NULL, go back to get next element of stack
                p = NULL;
            }
        }
    }
}*/

//*****************************************************
//函数功能：二叉树的层序遍历
//输入参数：树根
//输出参数：无
//返回值：     无
//*****************************************************
void LevelOrderTravel( BiTree BT )
{
    queue<BiNode*> Q;
    BiTree T;
    if ( !BT )                                  //空树就直接返回
        return ;
    Q.push(BT);                          //先把树跟结点push入队，
    while ( !Q.empty() )           //队列不为空，就还有结点没访问到
    {
        T = Q.front();                   //取出队头，访问它，
        Q.pop();                              //将队头pop掉
        Visit( T );                            //访问
        if ( T->Left )                       //左子树不为空，就入队，接着访问左子树
            Q.push(T->Left);
        if ( T->Right )                    //右子树不为空，入队， 下次访问右子树
            Q.push(T->Right);
    }
}

//*****************************************************
//函数功能：中序遍历二叉树并输出结点层次
//输入参数：树根，层次level
//输出参数：level
//返回值：     无
//*****************************************************
void MidTravelAndLevel( BiTree BT, int Level )
{
    //借助中序遍历思想，在visit操作后加上输出层次语句
    if ( BT )
    {
        MidTravelAndLevel( BT->Left, Level + 1 );      //中序遍历左子树
        cout << BT->data << " 在第 " << Level  << " 层 " << endl;  //输出结点信息及层次
        MidTravelAndLevel( BT->Right, Level + 1 );      //中序遍历右子树
    }
}

//*****************************************************
//函数功能：求二叉树的高度
//输入参数：树根
//输出参数：无
//返回值：     无
//*****************************************************
int GetTreeHeight( BiTree BT )
{
    int hl, hr, MaxH;
    hl = hr = MaxH = 0;
    if ( BT )                                                           //借助后续遍历的思想，
    {
        hl = GetTreeHeight(BT->Left);           //后续遍历左子树，求左子树高度
        hr = GetTreeHeight(BT->Right);        //后序遍历右子树，求右子树高度
        MaxH = (hl > hr) ? hl : hr;                      //取二者最大数
        return MaxH + 1;                                       //返回最大子树再加1
    }
    return 0;
}

//*****************************************************
//函数功能：求二叉树中所有结点数
//输入参数：树根，cnt
//输出参数：cnt
//返回值：     无
//*****************************************************
void TotalNodes( BiTree BT, int &cnt )
{
    //利用先序遍历的思想，将输出结点信息改为结点数加一
    if ( BT )
    {
        cnt++;      //node is not empty, make cnt +1
        TotalNodes( BT->Left, cnt );       //Pre order travel left sib tree
        TotalNodes( BT->Right,cnt );
    }
}

//*****************************************************
//函数功能：求二叉树中所有叶子结点数
//输入参数：树根，cnt
//输出参数：cnt
//返回值：  无
//*****************************************************
void NumOfLeaf( BiTree BT, int &cnt )
{
	//还是先序遍历的思想，
	if ( BT )
	{
		if ( !BT->Left && !BT->Right )
			cnt++;
		NumOfLeaf( BT->Left, cnt );	//先序访问左子树
		NumOfLeaf( BT->Right, cnt );//先序访问右子树
	}
}

//*****************************************************
//函数功能：输出二叉树中所有叶结点
//输入参数：树根
//输出参数：无
//返回值：     无
//*****************************************************
void ShowLeaves( BiTree BT )
{
    //类似先序遍历的思想，只不过在visit前加一句话
    if ( BT )
    {
        if ( !BT->Left && !BT->Right )  //如果左右子树都为空，则是叶结点
            Visit(BT);
        ShowLeaves( BT->Left);
        ShowLeaves( BT->Right);
    }
}

//*****************************************************
//函数功能：计数二叉树中所有2度结点
//输入参数：树根,计数变量cnt
//输出参数：cnt
//返回值：  无
//*****************************************************
void NumOfDeg2( BiTree BT, int &cnt )
{
	if ( BT )
	{
		if ( (BT->Left != NULL) && (BT->Right != NULL) ) //左右子树都不为空，就是2度
		{
			cnt++;				 //计数器+1
			//cout << BT->data << " ";
		}
		NumOfDeg2( BT->Left, cnt );	//先序访问左子树
		NumOfDeg2( BT->Right, cnt );//先序访问右子树
	}
}

//*****************************************************
//函数功能：求值为x的结点的亲戚结点
//输入参数：值x,树根
//输出参数：无
//返回值：  无
//*****************************************************
void RelativeOfNode( BiTree BT, ElementType &x )
{
	BiNode *p, *pA;//left right ancester
	p = BT;//先暂时指向树根
	pA = NULL;
	stack<BiNode*> S;
	while ( p || !S.empty() )	   //利用非递归先序遍历的思想
	{
		if ( p )
		{
			//cout << "p - >data is " << p->data << endl;
			if ( p->data == x )		//如果当前结点值和x相等，就退出循环
				break;
			S.push( p );            //否则入栈父节点，遍历左子树
			pA = p;
			p = p->Left;
		}
		else
		{
			p = S.top();
			S.pop();
			pA = p;
			p = p->Right;
		}
	}
	if ( p == NULL )//p==NULL的话说明x不在二叉树里,直接return
	{
		cout << "该结点不存在\n";
		return;
	}
	//有无父节点
	if ( pA == NULL )//父节点是空，说明是根节点
		cout << "该结点是树根，没有父节点" << endl;
	else
		cout << "该结点的父节点值为 " << pA->data << endl;
	//有无左孩子
	if ( p->Left )
		cout << "该结点左孩子结点值为 " << p->Left->data << endl;
	else
		cout << "该结点没有左孩子." << endl;
	//有无右孩子
	if ( p->Right )
		cout << "该结点右孩子结点值为 " << p->Right->data << endl;
	else
		cout << "该结点没有右孩子." << endl;
	//有无兄弟
	if ( p == pA->Left && pA->Right )
		cout << "该结点的兄弟结点值为 " << pA->Right->data << endl;
	else if ( p == pA->Left && pA->Right == NULL )
		cout << "该结点没有兄弟结点." << endl;
	else if ( p == pA->Right && pA->Left )
		cout << "该结点的兄弟结点值为 " << pA->Left->data << endl;
	else
		cout << "该结点没有兄弟结点." << endl;
}

//*****************************************************
//函数功能：求值为x的结点的层次
//输入参数：树根，层次level，待求变量x
//输出参数：无
//返回值：  	成功返回层次
//*****************************************************
void LevelOfNode( BiTree BT, ElementType &x , int level, bool &flag  )  				//借助层次遍历
{
	if ( BT )							//利用之前中序遍历同时输出节点层次的思想
	{
		LevelOfNode( BT->Left, x, level + 1, flag );
		if ( BT->data == x )
		{
			cout << "该结点在第 " << level << " 层" << endl;
			flag = true;
			return;
		}
		LevelOfNode( BT->Right, x, level + 1, flag );
	}
}

//*****************************************************
//函数功能：将顺序存储的二叉树转换为链表形式二叉树
//输入参数：顺序二叉树数组
//输出参数：无
//返回值：	二叉树根节点
//*****************************************************
void ChangeArrIntoLink( BiTree &BT,SeqBiTree &Tree, int i )
{
	BT = new BiNode;
	if ( NULL == BT )
	{
		cout << "memory allocate faile,";
		system( "pause" );
		return;
	}
	BT->data = Tree.data[ i ];	 //根结点值
	//cout << "BT ->data is " << BT->data << endl;
	BT->Left = NULL;
	BT->Right = NULL;
	if ( Tree.data[ i * 2 ] != '*'  && (i * 2) <= Tree.len )  //有左子树
		ChangeArrIntoLink( BT->Left, Tree, i * 2 );  //递归创建左子树

	if ( Tree.data[ i * 2 + 1 ] != '*'  && (i * 2 + 1 )<= Tree.len) //有右子树
		ChangeArrIntoLink( BT->Right, Tree, i * 2 + 1 ); //递归创建右子树
}

//*****************************************************
//函数功能：求二叉树中值为x的结点的孩子结点
//输入参数：树根BT，结点值x，两个子节点指针c1，c2
//输出参数：c1，c2
//返回值：	无
//*****************************************************
void GetChild( BiTree BT, ElementType &x, BiNode* &C1, BiNode* &C2 )
{
	BiNode *p = GetNode( x, BT ); //先找到值为x的那个结点
	if ( p == NULL )
	{
		cout << "该节点不存在,请重试";
		system( "pause" );
		return;
	}
	if ( p->Left == NULL )  //该结点左子树为空
	{
		cout << "该结点没有左孩子.";
		C1 = NULL;
	}
	else
	{
		C1 = p->Left;
	}
	//判断右孩子
	if ( p->Right == NULL )
	{
		cout << "该结点没有右孩子.";
		C2 = NULL;
	}
	else
	{
		C2 = p->Right;
	}
}

//*****************************************************
//函数功能：求二叉树中值为x的结点的父节点
//输入参数：树根BT，结点值x，两个子节点指针c1，c2
//输出参数：c1，c2
//返回值：	无
//*****************************************************
void GetFather( BiTree BT, ElementType &x, BiNode* &f )
{
	BiNode *p;
	stack<BiNode*> S;
	p = BT;
	while ( p || !S.empty( ))
	{
		if ( p->Left )
		{
			if ( p->Left->data == x ) //p的左孩子等于x
			{
				f = p->Left;
				break;
			}
			S.push( p );
			p = p->Left;
		}
		else if ( p->Right )
		{
			if ( p->Right->data == x )//p右孩子值等于x
			{
				f = p->Right;
				break;
			}
			S.push( p );
			p = p->Left;
		}
		else
		{
			p = S.top();
			p = p->Right;
			S.pop();
		}
	}
	if ( p == NULL  )
	{
		cout << "该二叉树没有值为" << x << "的结点" ;
	}
}

//*****************************************************
//函数功能：求二叉树中值为x的结点的兄弟节点
//输入参数：树根BT，结点值x，待求兄弟结点的引用
//输出参数：兄弟结点
//返回值：	无
//*****************************************************
void GetBro( BiTree BT, ElementType &x, BiNode* &Bro )
{
	BiNode *f, *p;
	p = GetNode( x, BT );	 //先得到值为x的结点
	if ( p == NULL )
	{
		cout << "该二叉树中没有值为 " << x << " 的结点。";
		return;
	}
	GetFather( BT, x, f );//先找到该节点的父节点，然后看这个节点的另一个孩子节点
	if ( p == f->Left && f->Right == NULL )	  //p是f的左孩子，且f的右结点为空
	{
		cout << "该结点没有兄弟节点";
	}
	else if ( p == f->Left && f->Right )  //右结点不为空
	{
		Bro = p->Right;
		cout << "找到该结点的兄弟节点.";
	}
	else if ( p == f->Right && f->Left == NULL )
	{
		cout << "该节点没有兄弟节点.";
	}
	else
	{
		Bro = p->Left;
		cout << "找到该结点的兄弟节点.";
	}
}

//*****************************************************
//函数功能：交换二叉树每个节点的左右子树
//输入参数：树根结点
//输出参数：无
//返回值：	无
//*****************************************************
void ExchangeRightLeft( BiTree BT )
{
	if(BT)
	{
		ExchangeRightLeft( BT->Left );//先递归处理左子树和右子树
		ExchangeRightLeft( BT->Right );	//即要从最高层次的子树开始交换
		BiNode *t;
		t = BT->Left;
		BT->Left = BT->Right;
		BT->Right = t;
	}

}

//*****************************************************
//函数功能：返回值为x的结点
//输入参数：待查找值x
//输出参数：无
//返回值：	找到返回结点，没找到返回空指针
//*****************************************************
BiNode* GetNode( ElementType x, BiTree BT )
{
	//利用非递归先序遍历的思想来找
	BiNode *p = BT;
	stack<BiNode*> S;
	while ( p || !S.empty() )
	{
		if ( p )
		{
			if ( p->data == x )		//找到值为x的结点就break，然后返回这个结点即可
				break;
			S.push( p );
			p = p->Left;
		}
		else
		{
			p = S.top();
			S.pop();
			p = p->Right;
		}
	}
	if ( p == NULL )
	{
		cout << "没有这个结点。\n";
		return NULL;
	}
	else
		return p;
}

//*****************************************************
//函数功能：复制一颗二叉树SourceT到另一棵树T
//输入参数：两个树根结点
//输出参数：无
//返回值：	无
//*****************************************************
void CopyTree( BiTree SourceT, BiTree &T )
{
	BiNode *p = SourceT;
	if ( p )  //如果这个结点不为空
	{
		T = new BiNode;  //就给T申请一个新节点
		T->data = p->data;	  //然后将p的值复制给T
		T->Left = NULL;		  //让后让T的left和right指向空
		T->Right = NULL;

		CopyTree( p->Left, T->Left );	   //然后递归处理SourceT的左子树和右子树
		CopyTree( p->Right, T->Right );
	}
}

//*****************************************************
//函数功能：输出二叉树每个根节点到叶结点的路径
//输入参数：树根结点,一个存放结点值的字符数组，索引i
//输出参数：无
//返回值：	无
//*****************************************************
void EachPathOfLeaf( BiTree BT, char* str, int &i )
{
	//利用先序遍历的思想,没到叶结点时就把当前结点值放入字符数组中，碰到叶结点时逆序输出这个数组的内容即为路径
	if ( BT )
	{
		if ( BT->Left == NULL && BT->Right == NULL ) //左右子树都为空，所以是叶结点
		{
			str[ i ] = BT->data;	 //将叶结点的值也写入
			//cout << BT->data << " 放入路径.\n";
			int j;
			cout << BT->data << ": ";
			for ( j = i; j >= 0; j-- )	  //然后逆序输出字符数组的值，即为叶结点到根的路径
				cout << str[ j ] << " ";
			cout << endl;
		}
		else
		{
			str[ i ] = BT->data;    //不是叶结点，暂用数组存放当前结点的值
			//cout << BT->data << " 放入路径.\n";
			i++;    //i++，更新路径长度
			EachPathOfLeaf( BT->Left, str, i );//然后先序遍历左子树
			EachPathOfLeaf( BT->Right, str, i ); //左子树找了，接着右子树，因为子树在同一层，所以i不变
			i--;  		//左右子树都遍历完后返回上一层，所以i要减一
		}
	}
}

//*****************************************************
//函数功能：找到两个结点的最近的公共祖先
//输入参数：结点值e1，e2,二叉树BT
//输出参数：无
//返回值：	成功返回祖先结点指针，失败返回空指针
//*****************************************************
BiNode* FindCommonAnc( ElementType &e1, ElementType &e2, BiTree BT )
{
	BiNode *p1, *p2, *result;
	p1 = GetNode( e1, BT );  //找到值为e1和e2的结点
	p2 = GetNode( e2, BT );
	if ( NULL == p1 || NULL == p2 )
	{
		cout << "二叉树中没有这个结点。";
		system( "pause" );
		return NULL;
	}
	if ( p1 == BT || p2 == BT )		  //二者之一是根结点就返回根节点
	{
		return BT;
	}
	char path1[ MAXN ] = {0};		 //存放结点1的路径
	char path2[ MAXN ] = {0};		 //结点2的路径
	int i1, i2, j;
	bool flag = false;
	i1 = i2 = j = 0;
	PathOfNode( p1->data, BT, path1, i1, flag ); //求p1的路径
	flag = false;
	PathOfNode( p2->data, BT, path2, i2, flag); //求p2的路径
	while ( path1[ j ] == path2[ j ] )	   //找到路径中第一个不一样的结点
	{
		j++;
	}
	j--;	 //前面那个就是公共祖先结点
	result = GetNode( path1[ j ], BT );
	return result;
}

//*****************************************************
//函数功能：找到两个结点的最近的公共祖先，方法二
//输入参数：结点值e1，e2,二叉树BT
//输出参数：无
//返回值：	成功返回祖先结点指针，失败返回空指针
//*****************************************************
BiNode* FindComAnc2( BiNode *e1, BiNode *e2, BiTree BT )
{
	//用后续遍历的思想
    if (BT == NULL || BT == e1 || BT == e2 )	//如果当前结点为空或者是两个结点之一
		return  BT;			//就返回这个结点

	BiNode *le = FindComAnc2( e1, e2, BT->Left );		//看左子树是否有目标节点
	BiNode *ri = FindComAnc2( e1, e2, BT->Right );	//看右子树是否有
	if ( le != NULL && ri != NULL ) return BT;	//都不空，说明目标结点在左右子树

	return le == NULL ? ri : le;

}
//*****************************************************
//函数功能：找到一条从根结点到值为x的结点的路径
//输入参数：值x，树根结点BT，字符串引用，位置i
//输出参数：以字符串形式表示的路径
//返回值：	无
//*****************************************************
void PathOfNode( ElementType &x, BiTree BT, char* str, int &i, bool &flag )
{
	//还是用先序遍历的思想，类似于求叶结点的路径那样
    if(BT)
	{
		if(BT->data == x)		//找到目标结点，就返回
		{
			str[i] = BT->data;
			flag = true;
			//cout << BT->data << "写入路径\n";
			i++;
			str[i] = '\0';
			return ;
		}
		else				//没有找到
		{
			str[i] = BT->data;				//将当前结点值写入路
			//cout << BT->data << "写入路径\n";
			i++;
			if ( !flag )
			{
				PathOfNode(x,BT->Left,str,i,flag);
			}
			if ( !flag )
			{
				PathOfNode(x,BT->Right,str,i,flag);  	//左右子树在同一层，所以i不用变
			}
			if( !flag )//如果不加判断条件的话，由于递归，最后i会被减到1，虽然不影响路径数组，
			{																					//但是会影响路径长度变量
				i--;	//左右子树都看完了，返回上一层，i--
			}
		}
	}
}

//*****************************************************
//函数功能：找到二叉树中一条最长的路径，并输出路径上的值
//输入参数：二叉树根BT
//输出参数：无
//返回值：	成功返回最长路径长度，失败返回0
//*****************************************************
int FindLongestPath( BiTree BT )
{
	int length = 0, leaf = 0, i;
	bool flag = false;
	NumOfLeaf( BT, leaf );	 //先求叶结点数量
	char path[MAXNODES] = {0};			//最后的结果路径
	char Tpath[MAXNODES] = {0};		//每次遍历叶结点
	i = 0;
	length = i; 		//假设i是最大路径长度
	//然后用非递归先序遍历的思想，在碰到叶结点的时候就调用计算结点路径的函数
	stack<BiNode*> S;
	BiNode *p = BT;
	while ( p || !S.empty() )
	{
		if ( p )
		{
			if ( p->Left == NULL && p->Right == NULL ) //碰到叶节点就调用求路径函数
			{
				i = 0;
				PathOfNode(p->data,BT,Tpath,i,flag);
				//cout << "叶结点" << p->data << " 的路径  " << Tpath << ",长度为 " << i << endl;
				if ( i  > length )		//第i为是结尾符，所以i-1才是路径有效长度
				{
					length = i;				//算出来某个叶结点的路径比之前的路径长，就更新length和路径数组
					strcpy(path,Tpath);
					//cout << "更新成功，目前path 是" << path << endl;
				}
				flag = false;  //并重置flag
			}
			S.push( p );   //不是叶结点，就是某个根节点，入栈
			p = p->Left;   //遍历左子树
		}
		else
		{
			p = S.top();	  //p is null, let p point to front root node
			S.pop();
			p = p->Right;  //travel right sub tree
		}
	}
	cout << "最长路径为： " << path <<endl;
	return length;   //返回最大长度
}

//*****************************************************
//函数功能：从数据文件中读取二叉树数据到一个二维字符数组中
//输入参数：二维数组，记录二维数组实际大小len
//输出参数：二维数组
//返回值：	无
//*****************************************************
void GetTreeData( char TreeData[ MAXNODES ][ 4 ], int &len )
{
	//下面的步骤先从文件读入数据到存放节点信息的二维数组中
	char name[ 10 ];   //文件名
	char path[ 20 ] = "BTdata\\"; //数据文件路径
	char Tdata[ 10 ];
	len = 0;
	char strChoose[ 1000 ];//每次从文件里读入一行
	int i = 0,j;
	bool tag = false;//二叉树文件的标识
	FILE *fp;		   //文件指针
	cout << "请输入二叉树文件名称(例如bt15.btr)：";
	cin >> name;
	strcat( path, name );			//加上完整路径
	fp = fopen( path, "r" );//打开这个数据文件
	if ( NULL == fp )
	{
		cout << "文件打开失败, 请重试." << endl;
		system( "pause" );
		return;
	}
	while ( !feof( fp ) ) //没到文件尾并且没找到标识
	{
		if ( tag == true )	//找到标记，break
		{
			//cout << "找到标记，break\n";
			break;
		}
		fgets( strChoose, 1000, fp );	   //读入一行
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
	//上面while结束后，strchoose中应该是二叉树数据标识
	if ( strcmp( strChoose, "BinaryTree\n" ) != 0 )//如果不是数据标识，就退出
	{
		cout << "该文件不是二叉树数据文件，请重新输入文件名。\n";
		return;
	}
	else		//是文件标识，接着从标识的下一行读入数据到二维数组中
	{
		while ( !feof( fp ) )
		{
			fgets( Tdata, 10, fp );	 //读入下一行的数据
			i = 0;
			j = 0;
			while ( Tdata[ i ] != '\0' )   //以空格分隔来存储数据
			{
				if ( Tdata[ i ] != ' ' )
				{
					TreeData[ len ][ j ] = Tdata[ i ];
					j++;
				}
				i++;
			}
			len++;
		}
	}
	fclose( fp );
	//上面while执行完后，strdata二维数组内存放了全部节点信息
	//strdata[ n ][0]存放结点值，
	//strdata[ n ][1]存放左子树信息
	//strdata[ n ][2]存放右子树信息
}
//*****************************************************
//函数功能：文件方式创建一个二叉树
//输入参数：数根节点的引用
//输出参数：数根节点
//返回值：	无
//*****************************************************
void CreateTreeUsingFile( BiTree &BT )
{
	char TreeData[ MAXNODES ][ 4 ];  //结点数据二维数组
	int datalen,i;
	GetTreeData( TreeData, datalen );		//从文件里读入数据
	//然后调用创建结点函数，递归的创建树
	i = 0;
	CreateNode( BT, TreeData, datalen, i );
}

//*****************************************************
//函数功能：创建二叉树的一个节点，和CreateTreeUsingFile函数配合使用
//输入参数：数根节点的引用，二叉树结点信息二维数组，数组有效长度，数组当前位置
//输出参数：数根节点
//返回值：	false or true
//*****************************************************
void CreateNode( BiTree &pNode, char data[ MAXNODES ][ 4 ], int len, int &cur )
{
	//pNode为结点指针，data为二维数据，存放结点信息
	//len是数组有效长度，即结点个数，cur是当前该第几个结点
	if ( (cur >= len) || (len == 0) ) //数据处理完毕或没有数据
	{
		return;
	}

	pNode = new BiNode;
	if(pNode == NULL)
	{
		cout << "memory allocate failed, exit.";
		return ;
	}
	pNode->data = data[ cur ][ 0 ];
	pNode->Left = NULL;
	pNode->Right = NULL;
	int precur = cur;		  //保留当前的结点编号
	if ( data[ precur ][ 1 ] == '1' )	//当前结点有左子树 ,递归创建左子树
	{
		cur++;
		//cout << "递归创建左子树\n";
		CreateNode( pNode->Left, data, len, cur );
	}

	if ( data[ precur ][ 2 ] == '1' )  //当前结点有右子树，递归创建右子树
	{
		cur++;
		//cout << "递归创建右子树\n";
		CreateNode( pNode->Right, data, len, cur );
	}
}

//*****************************************************
//函数功能：去除数据文件一行中前面的空格
//输入参数：字符串
//输出参数：字符串
//返回值：	无
//*****************************************************
void RemoveSp( char *str )
{
	int i, cnt, n ,j;
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
//函数功能：键盘交互输入方式创建一个二叉树
//输入参数：数根节点的引用
//输出参数：数根节点
//返回值：	无
//*****************************************************
void CreateTreeInteractive( BiTree &BT )
{
	ElementType data;
	int left, right;
	cout << "请按先序遍历输入二叉树结点信息，每行三个值，用空格分隔\n";
	cout << "第一个是结点值，第二个是左子树，第三个是右子树，（0代表无，1代表有）\n";
	cout << "用三个#表示输入结束 。\n";
	fflush( stdin );   //清空缓存区，避免之前操作键入的回车键造成的影响
	cout << "根节点： ";
	cin >> data >> left >> right;
	cout << endl;//换行
	AssistCreate( BT, data, left, right );	  //先创建根节点，然后递归创建子树
	cout << "创建成功。! 请继续其他操作  \n";
}

//*****************************************************
//函数功能：键盘交互输入方式创建一个二叉树的辅助函数
//输入参数：数根节点的引用，结点值x,左右子树信息
//输出参数：结点
//返回值：	无
//*****************************************************
void AssistCreate( BiNode* &p, ElementType &x, int left, int right )
{
	ElementType data;
	int l, r;
	p = new BiNode;	   //先处理根节点
	p->data = x;	   //结点值
	p->Left = NULL;	   //先将子树置为空
	p->Right = NULL;
	fflush( stdin );
	if ( left == 1 )	//先看如果有左子树，递归创建左子树
	{
		cout << "下一个结点：";
		cin >> data >> l >> r;
		cout << endl;
		AssistCreate( p->Left, data, l, r );
	}
	if ( right == 1 )    //再看如果有右子树,递归创建右子树
	{
		cout << "下一个结点：";
		cin >> data >> l >> r;
		cout << endl;
		AssistCreate( p->Right, data, l, r );
	}
}

//*****************************************************
//函数功能：销毁整棵二叉树
//输入参数：节点的引用
//输出参数：数根节点
//返回值：	无
//*****************************************************
void DestoryBiTree( BiTree &BT )
{
	//采用后续遍历的思想，因为先序和后续都要浪费一个指针来记住根节点
	if ( BT )
	{
		DestoryBiTree( BT->Left );  //递归销毁左子树
		DestoryBiTree( BT->Right );	//递归销毁右子树
		delete BT;
		BT = NULL;
	}
}

//*****************************************************
//函数功能：删除二叉树中的某个子树
//输入参数：某个结点
//输出参数：无
//返回值：	无
//*****************************************************
void DeleteSibTree( BiTree BT )
{
	ElementType x;
	BiNode *p;
	cout << "请输入要删除的子树的根节点值：";
	cin >> x;
	p = GetNode( x, BT );	   //先找到目标结点
	if ( p == NULL )
	{
		cout << "该结点不存在，请重新选择\n";
		system( "pause" );
		return;
	}
	DestoryBiTree( p );	  //然后以目标节点为根节点销毁子树
	cout << "销毁成功！";
}
