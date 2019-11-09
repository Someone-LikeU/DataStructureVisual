#include "graph2.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
#ifdef DEBUG
int deBug1(void);
#else

void text1( char *str );
void text2( char *str );
void text3( char *str );
void text4( char *str );
void text5( char *str );
void text6( char *str );
void text7( char *str );
void text8( char *str );
void text9( char *str );
void text10( char *str );
int menu(const char *str, graph &G);
int c_graph(char str[64], graph &G);
int menu_c_graph(void);
#endif // DEBUG

int main()
{
	int ch;
	char str[64];
	graph G;
	bool exit  = false;
	#ifdef DEBUG
	std::cin >> ch;
	deBug1();
	#else
	while ( !exit )
	{
	    cout << "**********************************************************\n";
        cout << "************图测试程序********************************* \n";
        cout << "* 1.深度优先与广度优先   ||    2.求给定图的边数\n";
        cout << "* 3.从给定结点深度遍历   ||    4.从给定结点广度遍历\n";
        cout << "* 5.prim得到最小生成树   ||    6.Kruskal最小生成树\n";
        cout << "* 7.Dijkstra求最短路径   ||    8.Floyd最短路径\n";
        cout << "* 9.拓扑排序             ||    10.求AOE网的关键路径\n";
        cout << "*11.退出                 ||    12.凑格式\n";
        cout << "***********************************************************\n";
        cout << "请选择： ";
	    cin >> ch;
	    switch(ch)
	    {
	        case 1:  //pass
            system("CLS");
            cout << "第1组测试，udg8.grp\n";
            strcpy(str,"udg8.grp");
            text1( str );
            cout << "\n第2组测试，udg115.grp\n";
            strcpy(str,"udg115.grp");
            text1( str );
            cout << "\n第3组测试，dg6.grp\n";
            strcpy(str,"dg6.grp");
            text1( str );
            cout << "\n第4组测试，f14.grp\n";
            strcpy(str,"f14.grp");
            text1( str );
            break;

        case 2:   //pass
            system("CLS");
            cout << "第1组测试，udg115.grp";
            strcpy(str,"udg115.grp");
            text2(str);
            cout << "\n第2组测试，dg6.grp";
            strcpy(str,"dg6.grp");
            text2(str);
            cout << "\n第3组测试，f14.grp";
            strcpy(str,"f14.grp");;
            text2(str);
            break;

        case 3:             //pass
            system("CLS");
            cout << "第1组测试，udg8.grp";
            strcpy(str,"udg8.grp");;
            text3(str);
            cout << "\n第2组测试，dg6.grp";
            strcpy(str,"dg6.grp");;
            text3(str);
           // cout << "\n第3组测试，un8.grp";
            //strcpy(str,"un8.grp");;
            //text3(str);
            cout << "第4组测试，dn10.grp";
            strcpy(str,"dn10.grp");;
            text3(str);
            break;

        case 4:  //pass
            system("CLS");
            cout << "第1组测试，udg8.grp";
            strcpy(str,"udg8.grp");;
            text4(str);
            cout << "\n第2组测试，dg6.grp";
            strcpy(str,"dg6.grp");;
            text4(str);
           /* cout << "\n第3组测试，un8.grp";
            strcpy(str,"un8.grp");;
            text4(str);*/
            cout << "第4组测试，dn10.grp";
            strcpy(str,"dn10.grp");;
            text4(str);
            break;

        case 5:
            system("CLS");
            cout << "第1组测试，udn6.grp";
            strcpy(str,"udn6.grp");;
            text5(str);
            cout << "第2组测试，un8.grp";
            strcpy(str,"un8.grp");;
            text5(str);
            break;
        case 6:
            system("CLS");
            cout << "第1组测试，udn6.grp";
            strcpy(str,"udn6.grp");;
            text6(str);
            /*cout << "第2组测试，un8.grp";
            strcpy(str,"un8.grp");;
            text6(str);*/
            break;
        case 7:    //pass
            system("CLS");
            cout << "第1组测试，udn6.grp";
            strcpy(str,"udn6.grp");;
            text7(str);
            cout << "第2组测试，un8.grp";
            strcpy(str,"un8.grp");;
            text7(str);
            cout << "第3组测试，dn8.grp";
            strcpy(str,"dn8.grp");;
            text7(str);
            cout << "第4组测试，dn10.grp";
            strcpy(str,"dn10.grp");;
            text7(str);
            break;
        case 8:         //pass
            system("CLS");
            cout << "第1组测试，udn6.grp";
            strcpy(str,"udn6.grp");;
            text8(str);
            cout << "第2组测试，un8.grp";
            strcpy(str,"un8.grp");;
            text8(str);
            cout << "第3组测试，dn8.grp";
            strcpy(str,"dn8.grp");;
            text8(str);
            cout << "第4组测试，dn10.grp";
            strcpy(str,"dn10.grp");;
            text8(str);
            break;

         case 9:                //pass
            system("CLS");
            cout << "第1组测试，top6dg1.grp";
            strcpy(str,"top6dg1.grp");;
            text9(str);
            cout << "第2组测试，top7dg1.grp";
            strcpy(str,"top7dg1.grp");;
            text9(str);
            cout << "第3组测试，dn8.grp";
            strcpy(str,"dn8.grp");;
            text9(str);
            cout << "第4组测试，dn10.grp";
            strcpy(str,"dn10.grp");;
            text9(str);
            break;

        case 10: //pass
            system("CLS");
            cout << "第1组测试，dn8.grp";
            strcpy(str,"dn8.grp");;
            text10(str);
            cout << "第2组测试，dn10.grp";
            strcpy(str,"dn10.grp");;
            text10(str);
            break;

        case 11:
            exit = true;
            break;
	    }
	fflush(stdin);
	system("pause");
	system("CLS");
	}
	#endif // DEBUG
	return 0;
}

void text1( char *str )
{
	graph G;
	G.coverGraph(str);
	G.dfsTraversal_l();
	G.bfsTraversal_l();
}

void text2(char *str)
{
	graph G;
	G.coverGraph(str);
	cout << "该图中边(弧)的数量为:" << G.get_Enum_l() << endl;
}

void text3(char *str)
{
	graph G;
	G.coverGraph(str);
	cout << "深度遍历生成树：\n";
	G.dfsTraversal_t_l();
}

void text4(char *str)
{
	graph G;
	G.coverGraph(str);
	cout << "深度遍历生成树：\n";
	G.bfsTraversal_t_l();
}

void text5(char *str)
{
	graph G;
	G.coverGraph(str);
	cout<<"\n prim  算法如下: ";
    G.Prim_l(G.getNode_for_ID(0)) ;
}

void text6(char *str)
{
	graph G;
	G.coverGraph(str);
	cout<<"\nKruskal算法: ";
	G.Kruskal_l();
}

void text7(char *str)
{
	graph G;
	G.coverGraph(str);
	cout<<"Dijkstra算法:"<<endl;
	G.Dijkstra_l(G.getNode_for_ID(0));
}

void text8(char *str)
{
	graph G;
	G.coverGraph(str);
	cout<<"Floyd算法:\n";
	G.Floyd_l();
}

void text9(char *str)
{
	graph G;
	G.coverGraph(str);
	cout << "拓扑排序：\n";
	G.AOV_l();
}

void text10(char *str)
{
	graph G;
	G.coverGraph(str);
	cout << "AOE网关键路径：\n";
	G.AOE_l();
}

int menu(const char * str, graph & G)
{
	if(!G.empty())
	{
		std::cout << str << std::endl;
	}
	else
	{
		std::cout << "未创建图!" << std::endl;
	}
	cout << "**********************************************************\n";
    cout << "************图测试程序********************************* \n";
    cout << "* a.创建或修改图       ||   b.销毁图\n";
    cout << "* 1.深度优先与广度优先   ||    2.求给定图的边数\n";
    cout << "* 3.从给定结点深度遍历   ||    4.从给定结点广度遍历\n";
    cout << "* 5.prim得到最小生成树   ||    6.Kruskal最小生成树\n";
    cout << "* 7.Dijkstra求最短路径   ||    8.Floyd最短路径\n";
    cout << "* 9.拓扑排序             ||    10.求AOE网的关键路径\n";
    cout << "*11.退出                 ||    12.凑格式\n";
    cout << "***********************************************************\n";
    cout << "请选择： ";
	return 0;
}
