#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "LinkBiTree.h"
#include "seqBiTree.h"
using namespace std;

int main()
{
    int choose, num, nodes, leaves, i, length, level;
    num = nodes = leaves = length = 0;
    bool flag;
	ElementType t, s1, s2;
	BiTree BT = NULL, BT2 = NULL;
	BiNode *p, *c1, *c2;
	SeqBiTree seqBT;
	char path[ MAXN ];			// 存放节点路径的数组
	i = 0;
	p = c1 = c2 = NULL;  //先初始化全部置空
    bool Exit = false;
    while(!Exit)
    {
        cout << "*********************************************\n";
        cout << "***************二叉树算法测试程序************\n";
        cout << "*******************创建测试******************\n";
        cout << "* 1. 键盘交互式创建 ||  2. 文件方式创建\n";
        cout << "*******************销毁测试******************\n";
        cout << "* 3.销毁二叉树。\n";
		cout << "*******************应用测试******************\n";
        cout << "* 4.先序遍历二叉树  ||   5.先序非递归遍历\n";
		cout << "* 6.中序遍历二叉树  ||   7.中序非递归遍历\n";
		cout << "* 8.后序遍历二叉树  ||   9.凑格式。。。。\n";
		cout << "*10.层序遍历二叉树  ||  11.中序遍历并输出结点层次\n";
		cout << "*12.求二叉树的高度  ||  13.求二叉树总结点数\n";
		cout << "*14.求所有叶结点数  ||  15.打印所有叶结点值\n";
		cout << "*16.求所有两度结点  ||  17.值为x的结点的亲戚结点\n";
        cout << "*18.求结点所在层次  ||  19.转换顺序二叉树为链二叉树\n";
		cout << "*20.交换左右子树    ||  21.复制二叉树T到T1\n";
        cout << "*22.所有叶结点路径  ||  23.求两个结点最近公共祖先\n";
        cout << "*24.求一条最长路径  ||  25.转顺序二叉树操作\n";
        cout << "*26.退出    	    ||  27.凑格式\n";
		cout << "************************************************\n";
		cout << "请选择：";
		cin >> choose;
		while( choose > 26 || choose < 1 )
		{
			cout << "选项错误，请重新选择: ";
			cin >> choose;
		}
		fflush( stdin );
		switch ( choose )
		{
			case 1:	  //交互创建二叉树					//PASS
				system("CLS");   //清屏
				if ( BT )   		//防止重复创建，造成内存泄漏
				{
					cout << "已经创建了一棵二叉树了，请选择其他操作.\n";
					break;
				}
				CreateTreeInteractive( BT );
				if ( BT )
				{
					cout << "创建成功，请继续其他操作。\n";
				}
				else
				{
					cout << "创建失败.请重试\n";
				}
				break;

			case 2:			   				//文件方式创建,pass
				system("CLS");
				if ( BT  )
				{
					cout << "已经创建了一棵二叉树了，请选择其他操作.\n";
					break;

				}
				CreateTreeUsingFile( BT );
				if (BT)
				{
					cout << "创建成功，请继续其他操作。\n";
				}
				else
				{
					cout << "创建失败.请重试\n";
				}
				break;

			case 3:			//销毁操作,pass
				system("CLS");
				if ( BT == NULL )  //先判断是否为空树
				{
					cout << "该树为空，不需销毁，请继续其他操作。" << endl;
				}
				else
				{
					DestoryBiTree( BT );
					cout << "销毁成功，请继续其他操作。\n";
				}
				break;

			case 4:		    //travel,pass
				system("CLS");
				if ( BT )   //有树的时候
				{
					cout << "先序遍历结点序为：";
					PreOrderTravel( BT );
					cout << endl;
				}
				else
				{
					cout << "该二叉树为空，请先创建。" << endl;
				}
				if ( BT2 )  //复制的二叉树
				{
					cout << "\n顺带刚才复制的二叉树：";
					PreOrderTravel(BT2);
					cout << endl;
				}
				break;

			case 5: 						//pass
				system("CLS");
				if ( BT )
				{
					cout << "先序非递归遍历结点序为：";
					PreTravelNoRec( BT );
					cout << endl;
				}
				else
				{
					cout << "该二叉树为空，请先创建。" << endl;
				}
				if ( BT2 )  //复制的二叉树
				{
					cout << "\n顺带刚才复制的二叉树：";
					PreTravelNoRec(BT2);
					cout << endl;
				}
				break;

			case 6:                           //pass
				system("CLS");
				if ( BT )
				{
					cout << "中序遍历结点序为：";
					MidOrderTravel( BT );
					cout << endl;
				}
				else
				{
					cout << "该二叉树为空，请先创建。" << endl;
				}
				if ( BT2 )  //复制的二叉树
				{
					cout << "\n顺带刚才复制的二叉树：";
					MidOrderTravel(BT2);
					cout << endl;
				}
				break;

			case 7:              //pass
				system("CLS");
                if( BT)
				{
					cout << "中序非递归遍历结点序为：";
					MidTravelNoRec( BT );
					cout << endl;
				}
				else
				{
					cout << "该二叉树为空，请先创建。" << endl;
				}
				if ( BT2 )  //复制的二叉树
				{
					cout << "\n顺带刚才复制的二叉树：";
					MidTravelNoRec(BT2);
					cout << endl;
				}
				break;

			case 8:										//pass
				system("CLS");
				if( BT)
				{
					cout << "后序遍历结点序为：";
					LastOrderTravel( BT );
					cout << endl;
				}
				else
				{
					cout << "该二叉树为空，请先创建。";
				}
				if ( BT2 )  //复制的二叉树
				{
					cout << "顺带刚才复制的二叉树：";
					LastOrderTravel(BT2);
					cout << endl;
				}
				break;

			case 9:
				system("CLS");
				break;

			case 10:		   //level travel,  pass
				system("CLS");
				if(BT)
				{
					cout << "层序遍历结点序为：";
					LevelOrderTravel( BT );
					cout << endl;
				}
				else
				{
					cout << "该二叉树为空，请先创建。";
				}
				if ( BT2 )  //复制的二叉树
				{
					cout << "顺带刚才复制的二叉树：";
					LevelOrderTravel(BT2);
					cout << endl;
				}
				break;

			case 11:		   //mid order travel and level of nodes     //pass
				system("CLS");
				if ( !BT )
				{
					cout << "二叉树不存在，请先创建。\n";
					break;
				}
				cout << "中序各结点层次为：\n";
				MidTravelAndLevel( BT, 1 );//默认根节点为第1层
				break;

			case 12:		 //height of tree     //pass
				system("CLS");
				if ( !BT )
				{
					cout << "二叉树不存在，请先创建。\n";
					break;
				}
				cout << "二叉树的高度为：" << GetTreeHeight( BT ) << endl;
				break;

			case 13:		//总结点数			//pass
				system("CLS");
				if ( !BT )
				{
					cout << "二叉树不存在，请先创建。\n";
					break;
				}
				nodes = 0;
				TotalNodes( BT, nodes );
				cout << "二叉树中一共有 " << nodes << " 个结点.\n";
				nodes = 0;	//前面是引用，所以这里要重置0，以免下次调用该函数时重复计数
				break;

			case 14:		 //total leaf				//pass
				system("CLS");
				if ( !BT )
				{
					cout << "二叉树不存在，请先创建。\n";
					break;
				}
				leaves = 0;
				NumOfLeaf( BT, leaves );
				cout << "二叉树中一共有 " << leaves << " 个叶结点.\n";
				leaves = 0;
				break;

			case 15:						//pass
				system("CLS");
				if ( !BT )
				{
					cout << "二叉树不存在，请先创建。\n";
					break;
				}
				cout << "所有叶结点的值为：";
				ShowLeaves( BT );
				cout << endl;
				break;

			case 16:					//pass
				system("CLS");
				if ( !BT )
				{
					cout << "二叉树不存在，请先创建。\n";
					break;
				}
				cout << "二度结点如下：\n";
				num = 0;
				NumOfDeg2( BT, num );
				cout << "共 " << num << " 个" << endl;
				num = 0;
				break;

			case 17:						//pass
				system("CLS");
				if ( !BT )
				{
					cout << "二叉树不存在，请先创建。\n";
					break;
				}
				cout << "请输入一个元素：";
				cin >> t;
				RelativeOfNode( BT, t );
				break;

			case 18:									//pass
				system("CLS");
				if ( !BT )
				{
					cout << "二叉树不存在，请先创建。\n";
					break;
				}
				cout << "请输入一个元素：";
				cin >> t;
				level = 1;
				flag = false;
				LevelOfNode( BT, t, level, flag);
				if(flag == false)
				{
					cout << "二叉树中不存在该节点,请重新选择\n";
				}
				break;

			case 19:								//pass
				system("CLS");
				num = 1;
				if (seqBT.len == 0)
				{
					cout << "请先创建顺序二叉树" << endl;
					break;
				}
				else
				{
					ChangeArrIntoLink( BT, seqBT, num );
				}
				cout << "转换成功，请继续其他操作。\n";
				break;

			case 20:							//pass
				system("CLS");
				ExchangeRightLeft( BT );
				cout << "交换成功，请继续其他操作\n";
				break;

			case 21:							//pass
				system("CLS");
				CopyTree( BT, BT2 );
				if ( BT2 == NULL )
				{
					cout << "复制前，BT2为空树。\n";
				}
				cout << "复制成功，现在BT2有如下结点：";
				PreOrderTravel( BT2 );
				cout << endl;
				break;

			case 22:							//pass
				system("CLS");
				cout << "所有叶结点路径如下：\n";
				EachPathOfLeaf( BT, path, i );
				break;

			case 23:					//pass
				system("CLS");
				cout << "请输入两个结点的元素值，用空格分隔 ：";
				cin >> s1 >> s2;
				p = FindCommonAnc( s1, s2, BT );
				if ( p == NULL )
				{
					cout << "抱歉，没找到他俩的公共祖先。 \n";
					break;
				}
				else
				{
					cout << "公共祖先值为：" << p->data << endl;
				}

				cout << "法二： "<<endl;
				c1 = GetNode(s1, BT);
				c2 = GetNode(s2,BT);
				p = FindComAnc2(c1,c2,BT);
				if ( p == NULL )
				{
					cout << "抱歉，没找到他俩的公共祖先。 \n";
				}
				else
				{
					cout << "公共祖先值为：" << p->data << endl;
				}
				break;

			case 24:						//pass
				system("CLS");
				cout << "二叉树中的";
				length = FindLongestPath( BT );
				cout << "这条路长度为：" << length << endl;
				break;

			case 25:							//pass
				system("CLS");
                cout << "**********************************************\n";
                cout << "*************顺序二叉树测试****************\n";
                cout << "*1.交互方式创建     ||     2.先序遍历" << endl;
                cout << "*3.中序遍历         ||     4.后序遍历"  <<endl;
                cout << "*5.层次遍历	    || 	   6.文件方式创建" << endl;
                cout << "*7.退出\n";
				cout << "**********************************************\n";
				cout << "请选择：";
				cin >> choose;
				while( choose > 7 || choose < 1 )
				{
					cout << "选项错误，请重新选择: ";
					cin >> choose;
				}

				switch(choose)
				{
				case 1:							//pass
					system("CLS");
					InitialTree( seqBT ); //先初始化
					CreateSeqTreeInteract( seqBT );
					system("pause");
					break;

				case 2:						//pass
					system("CLS");
					cout << "先序遍历如下：";
					i = 1;
					PreTravel(seqBT, i);
					cout << endl;
					break;

				case 3:								//pass
					system("CLS");
					cout << "中序遍历如下: " ;
					i = 1;
					MidTravel(seqBT,i);
					cout << endl;
					break;

				case 4:								//pass
					system("CLS");
					cout << "后序遍历如下： ";
					i = 1;
					LastTravel(seqBT,i);
					cout << endl;
					break;

				case 5:					//pass
					system("CLS");
					cout << "层序遍历如下：";
					LevelTravel(seqBT);
					cout << endl;
					break;

				case 6:
					system("CLS");
					CreateSeqTreeUsingFile(seqBT);
                    for ( i = seqBT.len ; i > 0 ; i-- )				//创建完后中间还有些空的位置，要补成完全二叉树
					{
						if(seqBT.data[i] == ' ')
							seqBT.data[i] = '*';
					}
					cout << "创建成功\n";
					cout << "有 "  << seqBT.len << "个结点。\n";
					cout << endl;
					break;
				case 7:
					break;
				}

				break;

			case 26:
				system("CLS");
				DestoryBiTree( BT );   //防止用户退出前没执行销毁操作，
				DestoryBiTree( BT2 );
				Exit = true;
				break;

			default:
				break;
		}
		system( "pause" );
		system( "CLS" );
		fflush(stdin);
    }
    return 0;
}
