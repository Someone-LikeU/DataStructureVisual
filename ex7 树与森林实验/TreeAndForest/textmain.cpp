#include "Tree.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{
	int choose, leaves, deg, nodes, height, index, parent,i;
	bool exit = false;
	Ptree PTree; //定义一个双亲表示发的树
	ChildLink CLtree; //孩子链表表示法的树
	CsRoot CStree,t; //孩子兄弟链表表示
	InitParentForm( PTree ); //first init it
	while ( !exit )
	{
		cout << "*********************************************\n";
		cout << "***************树算法测试程序************\n";
		cout << "*1.创建树（森林）    || 2.先序遍历树（森林）\n";
		cout << "*3.后序遍历树（森林）|| 4.层次遍历树（森林）\n";
		cout << "*5.求树（森林）高度  || 6.求树（森林）总结点数\n";
		cout << "*7.求树（森林）度    || 8.先序输出及层次号。 \n";
		cout << "*9.广义表形式输出    || 10.求叶结点数\n";
		cout << "*11. 退出            || 12.孩子兄弟与双亲相互转换.\n";
		cout << "************************************************\n";
		cout << "请选择：";
		cin >> choose;
		while ( choose > 12 || choose < 1 )
		{
			cout << "Error chioce.Please enter again.";
			cin >> choose;
		}
		fflush( stdin );
		switch ( choose )
		{
			case 1:														//pass
				system( "CLS" );
				if ( CreateTreeFromFile( PTree ) )//judge wether success or not to output information
				{
					cout << "创建成功，请继续其他操作。\n";
				}
				else
				{
					cout << "创建失败，请重试\n";
				}
				break;

			case 2:				//pass
				system( "CLS" );
				if ( PTree.n == 0 )	//judge if there is a tree
				{
					cout << "该树还为创建，请先执行创建操作。";
					break;
				}
				PreTraverse( PTree );
				break;

			case 3:											//pass
				system( "CLS" );
				if ( PTree.n == 0 )	//judge if there is a tree
				{
					cout << "该树还为创建，请先执行创建操作。";
					break;
				}
				LastTraverse( PTree );
				break;

			case 4:									//pass
				system( "CLS" );
				if ( PTree.n == 0 )	//judge if there is a tree
				{
					cout << "该树还为创建，请先执行创建操作。";
					break;
				}
				LevelTravel( PTree );
				break;

			case 5:												//pass
				system( "CLS" );
				if ( PTree.n == 0 )	//judge if there is a tree
				{
					cout << "该树还为创建，请先执行创建操作。";
					break;
				}
				height = TreeHeightEnter( PTree );
				cout << "树高为：" << height << endl;
				break;

			case 6:											//pass
				system( "CLS" );
				if ( PTree.n == 0 )	//judge if there is a tree
				{
					cout << "该树还为创建，请先执行创建操作。";
					break;
				}
				nodes = GetTreeNodes( PTree );
				cout << "树总结点树为： " << nodes << endl;
				break;

			case 7:														//pass
				system( "CLS" );
				if ( PTree.n == 0 )	//judge if there is a tree
				{
					cout << "该树还为创建，请先执行创建操作。";
					break;
				}
				cout << "法一：双亲法求度数,结果为 ";
				deg = DegOfTree( PTree ); //双亲法求度数
				cout << deg << endl;
				cout << "法二，孩子链表表示法求度，结果为 ";
				CreateChildLink( PTree, CLtree );
				deg = DegOfTreeChildLink( CLtree );
				cout << deg << endl;
				DestoryCLtree( CLtree );
				break;

			case 8:									//pass
				system( "CLS" );
				if ( PTree.n == 0 )	//judge if there is a tree
				{
					cout << "该树还为创建，请先执行创建操作。";
					break;
				}
				PreAndOrderEnter( PTree);
				break;

			case 9:
				system( "CLS" );
				if ( PTree.n == 0 )	//judge if there is a tree
				{
					cout << "该树还为创建，请先执行创建操作。";
					break;
				}
				CreateCS( CStree, PTree ); 	//先创建 孩子兄弟表示法的树
				CsBreadthTable( CStree );	 //然后用孩子兄弟表示来求
				break;

			case 10:
				system( "CLS" );
				if ( PTree.n == 0 )	//judge if there is a tree
				{
					cout << "该树还为创建，请先执行创建操作。";
					break;
				}
				leaves = NumOfLeaf( PTree );
				cout << "法一，双亲表示法求，结果为 ";
				cout << leaves << endl;
				cout << "法二，孩子链表表示法求，结果为： ";
				CreateChildLink( PTree, CLtree );
				leaves = GetLeafChildLink( CLtree );
				DestoryCLtree( CLtree );
				cout << leaves << endl;
				break;

			case 12:
				system( "CLS" );
				if ( PTree.n == 0 )	//judge if there is a tree
				{
					cout << "该树还为创建，请先执行创建操作。";
					break;
				}
				CreateCS( CStree, PTree );
				cout << "由双亲表示转换成孩子兄弟表表示成功，广义表输出如下：\n";
				CsBreadthTable( CStree );
				DestoryCStree(CStree);
				break;

			case 11:
				exit = true;
				break;
		}
		system( "pause" );
		system("CLS");
		fflush( stdin );
	}
	return 0;
}
