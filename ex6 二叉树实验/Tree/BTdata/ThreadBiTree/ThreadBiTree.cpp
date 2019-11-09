// ThreadBiTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
using namespace std;

#include "stdlib.h"
#include "..\ThreadBiTree.h"

#include "..\CreateBiTree.h"   //创建二叉树


#define _CRTDBG_MAP_ALLOC //内存泄漏检查用
#include<stdlib.h> 
#include<crtdbg.h> 



int main(int argc, char* argv[])
{
	ThreadBiTree TBT;  //线索二叉树
	
	//BiTree BT;
	btNode* T=NULL; 
	btNode* last=NULL;
	int nChoice;
	

	char strLine[100][3]; //文件数据读入到数组		
	int  nArrLen=0;  //数组长度
	int  nR=0;
	int i;

	do
	{
		//创建菜单
		cout<<"******************** 线索二叉树测试程序 ********************"<<endl;
		cout<<"*  0--退出                    |  8--先序线索遍历           *"<<endl;
		cout<<"*  1--帮助                    |  9--中序线索化             *"<<endl;
		cout<<"*  2--创建二叉树（数据文件）  |  9--中序线索遍历           *"<<endl;
		cout<<"*  3--创建二叉树（键盘交互）  | 10--后续线索化             *"<<endl;
		cout<<"*  4--遍历二叉树（递归）      | 11--后序线索遍历           *"<<endl;
		cout<<"*  5--销毁二叉树              | 12--          *"<<endl;
		cout<<"*  6--判定空树      | 13--             *"<<endl;
		cout<<"*  7--先序线索化                |           *"<<endl;
		cout<<"************************************************************"<<endl;
		cout<<"请选择操作(0-14)：";
		cin>>nChoice;
		switch(nChoice)
		{
		case 0:  //退出程序
			system("cls");  //清除屏幕
			cout<<"<-- 程序退出 -->"<<endl;  //选择退出
			break;
		case 1:
			system("cls");  //清除屏幕
			cout<<"<-- 帮助 -->"<<endl;  //选择退出
			cout<<"本程序中，二叉树类BiTree中只包含成员函数，用以操作二叉树。"<<endl;  
			cout<<"二叉树结点信息不作为类的成员。"<<endl;  			
			break;
		case 2:  //从文件创建二叉树
			system("cls");  //清除屏幕
			if(TBT.root!=NULL)  //防止重复创建，造成内存泄露
			{
				cout<<"二叉树已经存在，若需重新创建，请先销毁再创建。"<<endl;
				break;
			}
			char strFileName[100];
			cout<<"请输入二叉树数据文件名(i.e. bt3.btr)：";
			cin>>strFileName;  //控制台输入数据文件名			
			
			nArrLen=0;  //数组长度
			nR=0;
			if(!ReadFileToArray(strFileName, strLine, nArrLen))
			{
				cout<<"<--从文件创建二叉树失败。-->"<<endl;
				break;  //文件打开错误，返回
			}
			
			if(nArrLen==0)
			{
				printf("<--出错：文件中没有结点数据。-->\n");
				break;
			}   

			//for(i=0; i<nArrLen;i++)
			//	cout<<strLine[i][0]<<"-"<<strLine[i][1]<<"-"<<strLine[i][2]<<endl;

			if(CreateBiTreeFromFile(TBT.root, strLine,nArrLen, nR)) //从第1行开始
			{
				TBT.IniTag(TBT.root);  //初始化lTag和rTag为0
				cout<<"<--二叉树创建成功！-->"<<endl;
			}
			else
				cout<<"<--从文件创建二叉树失败。-->"<<endl;	
			break;
		
		
		case 3:  //键盘输入创建二叉树
			if(TBT.root!=NULL)  //防止重复创建，造成内存泄露
			{
				cout<<"二叉树已经存在，若需重新创建，请先销毁再创建。"<<endl;
				break;
			}

			TBT.CreateBtConsole(TBT.root);
			
			TBT.IniTag(TBT.root);  //初始化lTag和rTag为0
			cout<<"<--二叉树创建成功！-->"<<endl;
			
			break;		
		case 4:  //遍历二叉树--递归
			system("cls");  //清除屏幕
			cout<<"二叉树遍历结果："<<endl;
			if(TBT.Empty(TBT.root))
			{
				cout<<"<--二叉树为空树。-->"<<endl;
				break;
			}
			cout<<"先序次序：";
			TBT.PreOrder(TBT.root);   //递归先序遍历
			cout<<endl;
			cout<<"中序次序：";
			TBT.InOrder(TBT.root);    //递归中序遍历
			cout<<endl;
			cout<<"后序次序：";
			TBT.PostOrder(TBT.root);  //递归后序遍历
			cout<<endl;
			break;
		case 5:  //销毁二叉树
			system("cls");  //清除屏幕
			if (T!=NULL)
				TBT.Destroy(T);  //销毁二叉树			
			cout<<"<-- 二叉树已经销毁！-->"<<endl;
			break;
		case 6:  //判断是否空树
			system("cls");  //清除屏幕
			if(TBT.Empty(T))
				cout<<"<-- 二叉树为空树。-->"<<endl;			
			else
				cout<<"<-- 非空二叉树。-->"<<endl;			
			break;

		case 7:  //先序线索化
			system("cls");  //清除屏幕			
			TBT.PreThreading(TBT.root, last);
			TBT.isTBT=1;  //标记二叉树进行了先序线索化
			cout<<"先序线索遍历结果："<<endl;
			TBT.PreTraverseThr(TBT.root);
			cout<<endl;
			break;

/*	
		case 6:  //按元素值搜索节点，返回节点指针
			if(IsEmpty(BT))
			{
				cout<<"<--二叉树为空树。-->"<<endl;
				break;
			}
			cout<<"请输入要搜索的节点元素值(x)：";
			cin>>x;

			BiTreeSearch(BT, x, P);			
			if(P!=NULL)
				cout<<"元素 x="<<x<<" 节点找到！"<<endl;
			else
				cout<<"元素 x="<<x<<" 不在树上。"<<endl;
			P=NULL;  //恢复空指针
			break;

		case 7:  //取当前节点的孩子节点	
			if(IsEmpty(BT))
			{
				cout<<"<--二叉树为空树。-->"<<endl;
				break;
			}			
			cout<<"请输入当前节点元素：";
			cin>>x;
			P=NULL;
			nR=GetLeftChild(BT,x,P);	//取左孩子节点
			switch(nR)
			{
			case 0:
				cout<<"当前空树，不能取左子树！"<<endl;
				break;
			case 1:
				cout<<"目标元素不在树上，不能取左子树"<<endl;
				break;
			case 2:
				cout<<"元素x="<<x<<"对应的左孩子存在，值为："<<P->data<<endl;
				break;
			case 3:
				cout<<"元素x="<<x<<"对应的左子树不存在(空)！"<<endl;
				break;
			}			
			
			P=NULL;
			nR=GetRightChild(BT,x,P);	//取右孩子节点
			switch(nR)
			{
			case 0:
				cout<<"当前空树，不能取右子树！"<<endl;
				break;
			case 1:
				cout<<"目标元素不在树上，不能取右子树"<<endl;
				break;
			case 2:
				cout<<"元素x="<<x<<"对应的右孩子存在，值为："<<P->data<<endl;
				break;
			case 3:
				cout<<"元素x="<<x<<"对应的右子树不存在(空)！"<<endl;
				break;
			}
			break;

		case 8:  //取父节点
			if(IsEmpty(BT))
			{
				cout<<"<--二叉树为空树。-->"<<endl;
				break;
			}			
			cout<<"请输入当前节点元素：x=";
			cin>>x;
			P=NULL;
			GetParent(BT, x, P);  //搜索双亲节点
			if(P)
				cout<<"x="<<x<<"的双亲节点为："<<P->data<<endl;
			else
				cout<<"x="<<x<<"的双亲节点不存在。"<<endl;
			break;

        case 9:  //求叶子数量
			nR=0;
			LeafCount(BT,nR);
			cout<<"叶子数量："<<nR<<endl;
			break;
		case 10:  //取兄弟节点
			if(IsEmpty(BT))
			{
				cout<<"<--二叉树为空树。-->"<<endl;
				break;
			}			
			cout<<"请输入当前节点元素：x=";
			cin>>x;
			GetLeftSibling(BT,x);   //取左兄弟
			GetRightSibling(BT,x);  //取右兄弟
			break;

		case 11:  //求节点数
			nR=0;
			num=0;
			GetNodeNumber(BT,nR);  //引用返回
			cout<<"二叉树节点数："<<nR<<endl;
			GetNodeNumber1(BT);
			cout<<"二叉树节点数："<<num<<endl;  //全局变量求解
			break;
		case 12: //求度数为2的节点
			nR=0;
			GetNodeNumBiDegree(BT,nR);
			cout<<"度为2的节点数："<<nR<<endl;

			num=0;
			GetNodeNumDegreeOne(BT);
			cout<<"度为1的结点数："<<num<<endl;

			break;

		case 13:  //求元素x对应节点层次，并打印其祖先节点
			if(IsEmpty(BT))
			{
				cout<<"<--二叉树为空树。-->"<<endl;
				break;
			}			
			cout<<"请输入当前节点元素：x=";
			cin>>x;
			cout<<"节点 x="<<x<<" 的祖先节点：";
			GetNodeLevel(BT,  x, nR, 1);
			cout<<endl;
			if(nR>0)				
				cout<<"节点 x="<<x<<" 的层数为："<<nR<<endl;
			else
				cout<<"节点 x="<<x<<" 不在树上。"<<endl;
			break;


*/
		default:
			cout<<"功能选择错误，请在0到5之间选择，==>"<<endl;
			break;
		}
	
	}while(nChoice!=0);  //循环显示菜单，nMenu==0退出

	if (TBT.root!=NULL)
	   TBT.Destroy(TBT.root);    //销毁二叉树
	
	_CrtDumpMemoryLeaks();  //debug 模式下检测是否内存泄漏	

	return 0;
}
