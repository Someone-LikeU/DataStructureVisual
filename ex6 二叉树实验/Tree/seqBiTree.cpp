#include "seqBiTree.h"
#include <iostream>
#include <cstdlib>
#include <cstdbool>
#include <cstdio>
#include <cstring>
using namespace std;

//*****************************************************
//函数功能：初始化顺序二叉树
//输入参数：无
//输出参数：无
//返回值：	顺序二叉树数组指针
//*****************************************************
void InitialTree( SeqBiTree &seqTree )
{
	int i;
	for ( i = 0; i < MAXN; i++ )  //默认初始化全为空格
	{
		seqTree.data[ i ] = ' ';
	}
	seqTree.len = 0;//顺序存储二叉树长度为0
}

//*****************************************************
//函数功能：去掉数据文件中某行前面的空格
//输入参数：字符数组
//输出参数：这个数组
//返回值：	无
//*****************************************************
void removeSpace( char *str )
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
//函数功能：控制台交互式创建顺序二叉树
//输入参数：数组指针，数组长度
//输出参数：这个数组
//返回值：	0 represents success, 1 represents failure
//*****************************************************
int CreateSeqTreeInteract( SeqBiTree &seqTree )
{
	if ( seqTree.data[ 0 ] != ' ' )	   //先检查初始化操作有没有执行
	{
		cout << "未初始化，请先执行初始化操作。\n";
		system( "pause" );
		return 1;
	}
	elementType data;
	int i = 1;
	cout << "请按层次顺序输入完全二叉树结点信息,有结点输入结点值，无结点输入*\n";
	cout << "输入#结束.\n";
	cout << "结点 " << i << " :";
	cin >> data;
	while ( data != '#' )
	{
		seqTree.data[ i ] = data;
		seqTree.len++;
		i++;
		getchar();
		cout << "结点 " << i << " :";
		cin >> data;
	}
	cout << "创建成功，请执行下一步操作。\n";
	return 0;
}

//*****************************************************
//函数功能：交互方式创建二叉树的辅助函数
//输入参数：树结点的引用，二维结点信息数组，结点序号cur,
//输出参数：该结点
//返回值：	无
//*****************************************************
void HelpCreate( SeqBiTree &ST, char data[ MAXN ][ 4 ], int &cur, int node ,int len )
{
	if ( (cur >= len) || (len == 0) ) //数据处理完毕或没有数据
	{
		return;
	}
	ST.data[node] = data[ cur ][ 0 ];
	int precur = cur;
	if ( data[ precur ][ 1 ] == '1' ) //有左子树,递归创建左子树，data里树信息是按先序遍历排列的
	{
		cur++;									  //所以每次只让cur+1就行了
		HelpCreate( ST, data, cur, node * 2, len );
	}
	else	//没有左子树，就把对应子树位置的值设为*
	{
		ST.data[ node * 2 ] = '*';
	}

	if ( data[ precur ][ 2 ] == '2' ) //有右子树
	{
		cur++;
		HelpCreate( ST, data, cur, node * 2 + 1 ,len );	 //递归创建右子树
	}
	else
	{
		ST.data[ node * 2 + 1 ] = '*';
	}
}

//*****************************************************
//函数功能：文件方式创建二叉树
//输入参数：树结点的引用，二维结点信息数组，结点序号cur,
//输出参数：该结点
//返回值：	 无
//*****************************************************
void CreateSeqTreeUsingFile( SeqBiTree &seqTree )
{
	InitialTree( seqTree );
	char TreeData[ MAXN ][ 4 ];  //结点数据二维数组
	int datalen, i ,j;
	GetData( TreeData, datalen );
	i = 0;
	j = 1;
	Assist( seqTree, TreeData, datalen, i, j);
}

//*****************************************************
//函数功能：从文件获取结点数据
//输入参数：二维字符数组，记录数组长度len
//输出参数：该二维数组
//返回值：	无
//*****************************************************
void GetData( char TreeData[ MAXN ][ 4 ], int &datalen )
{
	//下面的步骤先从文件读入数据到存放节点信息的二维数组中
	char name[ 10 ];   //文件名
	char path[ 20 ] = "BTdata\\"; //数据文件路径
	char Tdata[ 10 ];
	datalen = 0;
	char strChoose[ 1000 ];//每次从文件里读入一行
	int i = 0, j;
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
			removeSpace( strChoose );
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
					TreeData[ datalen ][ j ] = Tdata[ i ];
					j++;
				}
				i++;
			}
			datalen++;
		}
	}
	fclose( fp );
}

//*****************************************************
//函数功能：辅助创建函数
//输入参数：顺序树引用，树数据数组，数组有效长度，数组下标cur，顺序树下标treeindex
//输出参数：该二维数组
//返回值：	无
//*****************************************************
void Assist( SeqBiTree &seqTree, char TreeData[ MAXN ][ 4 ], int &datalen, int &cur, int treeIndex )
{
	if ( ( cur > datalen ) || ( datalen == 0 ) ) //数据处理完毕或没有数据
	{
		return;
	}
	seqTree.data[ treeIndex ] = TreeData[ cur ][ 0 ];		//写根节点数据
	seqTree.len = treeIndex + 1;			//更新顺序树长度
	int precur = cur;			//保存当前数据数组位置
	if ( TreeData[ precur ][ 1 ] == '1' )		//有左子树，递归处理左子树
	{
		cur++;
		//cout << TreeData[ cur ][ 0 ] << "有左子树\n";
		Assist( seqTree, TreeData, datalen, cur, treeIndex * 2 );
	}

	if ( TreeData[ precur ][ 2 ] == '1' )			//有右子树，递归处理
	{
		cur++;
		//cout << TreeData[ cur ][ 0 ] << "  有right子树\n";
		Assist( seqTree, TreeData, datalen, cur, treeIndex * 2 + 1 );
	}
}

//*****************************************************
//函数功能：先序遍历
//输入参数：一个seqbitree的引用 location i
//输出参数：none
//返回值：	none
//*****************************************************
void PreTravel( SeqBiTree &seqTree, int i )
{
	if (  seqTree.data[i] != ' ' && i <= seqTree.len )
	{
		if (seqTree.data[i] != '*')
			cout << seqTree.data[ i ] << " ";
		PreTravel( seqTree, i * 2 ); //先序访问左子树
		PreTravel( seqTree, i * 2 + 1 );//right sub tree
	}
}

//*****************************************************
//函数功能：中序遍历顺序二叉树
//输入参数：一个seqbitree的引用 location i
//输出参数：none
//返回值：	none
//*****************************************************
void MidTravel( SeqBiTree &seqTree, int i )
{
	if (  seqTree.data[i] != ' ' && i <= seqTree.len)
	{
		MidTravel( seqTree, i * 2 );//left sub tree
		if (seqTree.data[i] != '*')
			cout << seqTree.data[ i ] << " ";
		MidTravel( seqTree, i * 2 + 1 );//right sub tree
	}
}

//*****************************************************
//函数功能：后序遍历顺序二叉树
//输入参数：一个seqbitree的引用 location i
//输出参数：none
//返回值：	none
//*****************************************************
void LastTravel( SeqBiTree &seqTree, int i )
{
	if ( seqTree.data[i] != ' '  && i <= seqTree.len)
	{
		LastTravel( seqTree, i * 2 );
		LastTravel( seqTree, i * 2 + 1 );
		if (seqTree.data[i] != '*')
			cout << seqTree.data[ i ] << " ";
	}
}
//*****************************************************
//函数功能：层次遍历顺序二叉树
//输入参数：一个seqbitree的引用 location i
//输出参数：none
//返回值：	none
//*****************************************************
void LevelTravel( SeqBiTree &seqTree )
{
	int i;
	for ( i = 1;  seqTree.data[ i ] != ' '  && i <= seqTree.len ; i++ )
	{
		if ( seqTree.data[ i ] != '*' )
			cout << seqTree.data[ i ] << " ";
	}
}
