#ifndef _SeqBiTree
#define _SeqBiTree
#define MAXN 100
typedef char elementType;
typedef struct TriNode			   //二叉树结点结构
{
	elementType data[MAXN];	//数据项,约定结点值为*表示空结点
	int len;
}SeqBiTree;

void InitialTree( SeqBiTree &seqTree );
void removeSpace( char *str );
void createSubtree( SeqBiTree &seqTree, int locate,char element );
void CreateSeqTreeUsingFile( SeqBiTree &seqTree );
void GetData( char TreeData[ MAXN ][ 4 ], int &datalen );
void Assist( SeqBiTree &seqTree, char TreeData[ MAXN ][ 4 ], int &datalen, int &cur,int treeIndex );
int CreateSeqTreeInteract(SeqBiTree &seqTree );//交互式创建顺序二叉树
void HelpCreate(  SeqBiTree &ST, char data[ MAXN ][ 4 ], int &cur, int node ,int len  );//文件创建二叉树辅助函数
void PreTravel( SeqBiTree &seqTree, int i );
void MidTravel( SeqBiTree &seqTtree, int i );
void LastTravel( SeqBiTree &seqTree, int i );
void LevelTravel( SeqBiTree &seqTree );
#endif
