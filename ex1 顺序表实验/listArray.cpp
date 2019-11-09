#include "listArray.h"
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

//*********************************************************
//函数功能：判断列表是否为空
//输入参数：列表指针
//输出参数：无
//返回值： 	bool型
//*********************************************************
bool IsEmpty( ptList L )
{
    return L.listLen == 0;
}

//*********************************************************
//函数功能：初始化一个表
//输入参数：表头
//输出参数：表
//返回值： 	无
//*********************************************************
void InitialList( ptList L )
{
    L.listLen = 0;
}

//*********************************************************
//函数功能：判断列表中是否存在元素x
//输入参数：列表指针，待判断元素x
//输出参数：无
//返回值： 	bool型
//*********************************************************
bool IsFull( ptList L )
{
    return L.listLen == MAXLEN;
}

//*********************************************************
//函数功能：按序号获取值
//输入参数：顺序表指针，序号i
//输出参数：待赋值变量x，
//返回值： 	0表示成功，1表示失败
//*********************************************************
int GetElement( ptList L, ElementType *x, int i )
{
    if ( IsEmpty( L ) ) //空表，返回1
    {
        printf("这是个空表");
        return 1;
    }
    if ( i < 1 || i > L.listLen ) //越界，提示重新选择位置
    {
        printf("选择位置异常，函数退出");
        return 1;
    }
    *x = L.data[i - 1];
    return 0;
}

//*********************************************************
//函数功能：在第i个结点前插入元素
//输入参数：列表指针，待插入元素x，插入位置i
//输出参数：顺序表L
//返回值： 	0表示成功，1表示失败
//*********************************************************
int InsertElement( ptList L, ElementType x, int i )
{
    if ( IsFull( L ) || i > L.listLen + 1 || i < 1 )
    {
        return 1; //表满或者插入位置越界，返回失败
    }
    int j; //将i所在位置往后所有元素都后移一位
    for ( j = L.listLen ; j > i - 1 ; j-- )
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = x;
    L.listLen++;
    return 0;
}

//*********************************************************
//函数功能：删除顺序表中第i个结点
//输入参数：表头，删除序号
//输出参数：顺序表L
//返回值： 	0表示成功，1表示失败
//*********************************************************
int DeleteElementOrder( ptList L, int i )
{
    if( IsFull( L ) || i > L.listLen || i < 1 ) //空表或越界，返回失败
    {
        return 1;
    }
    int j; //从待删除位置开始，依次用后面的元素覆盖当前元素
    for ( j = i - 1 ; j < L.listLen ; j++ )
    {
        L.data[j] = L.data[j + 1];
    }
    L.listLen--;//更新表长度
    return 0;
}

//*********************************************************
//函数功能：将元素x顺序插入一个表，使插入后的表仍热有序
//输入参数：表头L，元素x
//输出参数：表L
//返回值： 	0表示成功，1表示失败
//*********************************************************
int OrderInsert( ptList L, ElementType x )
{
    int i;
    if ( L.listLen == MAXLEN )
    {
        return 1;
    }
    for ( i = L.listLen - 1; L.data[i] >= x ; i--)
    {
        L.data[i + 1] = L.data[i];
    }
    //上面for里面的i--的副作用，所以这里要是i+1
    L.data[i + 1] = x;
    L.listLen++;
    return 0;
}

//*********************************************************
//函数功能：将表L中奇数项和偶数项分开，放到表A，C中，并输出
//输入参数：表头L，A,C
//输出参数：无
//返回值： 	0表示成功，1表示失败
//*********************************************************
int seprate( ptList L , ptList A, ptList C )
{
    if ( IsEmpty( L ) ) //空表返回失败
    {
        return 1;
    }
    InitialList( A ); //初始化表A,C，确保表空
    InitialList( C );
    int i,ia,ic;
    ia = ic = 0;
    for ( i = 0 ; i < L.listLen ; i++ )
    {
        if ( L.data[i] % 2 == 0 )//偶数，放到A中
        {
            A.data[ia++] = L.data[i];
            A.listLen++;         //更新表长度
        }
        else                      //奇数，放到C中
        {
            C.data[ic++] = L.data[i];
            C.listLen++;
        }
    }

    printf("\n原表元素：\n");
    for ( i = 0 ; i < L.listLen ; i++ )
    {
        printf("%d ",L.data[i]);
    }
    printf("\n偶数元素：\n");
    for ( i = 0 ; i < A.listLen ; i++ )
    {
        printf("%d ",A.data[i]);
    }
    printf("\n奇数元素:\n");
    for ( i = 0 ; i < C.listLen ; i++ )
    {
        printf("%d ",C.data[i]);
    }
    return 0;
}

//*********************************************************
//函数功能：求两个递增有序顺序表L1和L2中的公共元素，放入新的顺序表L3中。
//输入参数：表头L1,L2,L3
//输出参数：L3
//返回值： 	0表示成功，1表示失败
//*********************************************************
int func6( ptList L1, ptList L2, ptList L3 )
{
    int i1, i2, i3;
    i1 = i2 = i3 = 0;
    InitialList( L3 );//确保L3为空
    if (IsEmpty(L1) || IsEmpty(L2))
    {
        return 1;
    }
    while ( i1 < L1.listLen && i2 < L2.listLen )
    {
        if ( L1.data[i1] < L2.data[i2] ) //L1当前元素小于L2的
        {
            i1++;
        }
        else if ( L1.data[i1] > L2.data[i2] )
        {
            i2++;
        }
        else
        {
            L3.data[i3] = L1.data[i1];
            L3.listLen++;
            i3++;
            i1++;
            i2++;
        }
    }
    printf("表1元素：\n");
    for ( i1 = 0 ; i1 < L1.listLen ; i1++ )
    {
        printf("%d ", L1.data[i1]);
    }
    printf("\n表2元素：\n");
    for ( i2 = 0 ; i2 < L2.listLen ; i2++ )
    {
        printf("%d ", L2.data[i2]);
    }
    printf("\n公共元素：\n");
    for ( i3 = 0 ; i3 < L3.listLen ; i3++ )
    {
        printf("%d ", L3.data[i3]);
    }
    return 0;
}

//*********************************************************
//函数功能：删除有序顺序表中重复元素
//输入参数：表A
//输出参数：表A
//返回值： 	移动元素次数
//*********************************************************
int OrderedListDeleteSame( ptList A )
{
    int times = 0, i = 0, j = 1;   //times计数移动次数，i，j判断是否重复
    while (j < A.listLen )         //从第二个元素开始判断与第i个元素关系
    {
        if(A.data[j] == A.data[i]) //相等的话就j继续往后移
        {                          //直到第一个不等于第i个元素的位置
            j++;
            times++; //同时记录移动次数
            continue;
        }
        else //遇到第一个不等的，就把这个不等的覆盖i+1位置上的元素
        {
            A.data[++i] = A.data[j];
        }
        j++;
    }
    A.listLen = i + 1;          //更新表长度，
    return times;
}

//*********************************************************
//函数功能：递增有序顺序表A，B，求A = AUB，
//输入参数：表A，B
//输出参数：表A
//返回值： 	无
//*********************************************************
void AunionBtoA( ptList A, ptList B )
{
    int ia, ib,t;
    ia = ib = 0;
    t = A.listLen;//后面会更新表长度，所以先保存开始的长度
    while (ia < t && ib < B.listLen )
    {
        if (A.listLen == MAXLEN) //每次操作前都先判断表A是否满
        {
            printf("表A已满，无法再操作。\n");
            break;
        }

        if ( A.data[ia] < B.data[ib] ) //A当前元素小于B当前元素
            ia++;                    //就后移ia，继续比较
        else if ( A.data[ia] == B.data[ib] )  //相等则同时后移
        {
            ia++;
            ib++;
        }
        else      //大于，说明B当前元素肯定不在A里，就加入A
        {
            A.data[A.listLen++] = B.data[ib];
            ib++;
        }
    }
    if (ib != B.listLen) //上面while退出后，如果B还没遍历完，说明剩下的B都可以并入A
    {
        while(ib < B.listLen && A.listLen < MAXLEN)
        {
            A.data[A.listLen++] = B.data[ib];
            ib++;
        }
    }
    sort(A.data, A.data+A.listLen);
}

//*********************************************************
//函数功能：递增有序顺序表A，B，判断A是否为B的子集
//输入参数：表A，B
//输出参数：无
//返回值： 	true or false
//*********************************************************
bool IsSub( ptList A, ptList B )
{
    int ia, ib;
    ia = ib = 0;
    bool flag = true;
    while ( ia < A.listLen && ib < B.listLen )
    {
        if (A.data[ia] < B.data[ib] )//如果A当前元素小于B的当前，
        {                            //那肯定小于B往后所有的，
            flag = false;            //那这个元素就肯定不在B里面，就退出
            break;
        }
        else if (A.data[ia] > B.data[ib])//A当前元素大于B当前，
        {                                //就还得判断B后面的
            ib++;
        }
        else                         //如果相等，则继续判断A下一个元素
        {
            ia++;
            ib++;
        }
    }
    return flag;
}

//*********************************************************
//函数功能：递增有序表1，2，将两表合并后重放回1
//输入参数：表1，2
//输出参数：表1
//返回值： 	成功返回0，失败返回1
//*********************************************************
int L1pulsL2ToL1( ptList A, ptList B )
{
    //这里并没要求操作完后仍然有序，所以 直接在1表后添加2表的元素
    int ia, ib, t;
    ia = ib = 0;
    t = A.listLen;//后面会更新表长度，所以先保存开始的长度
    while (ia < t && ib < B.listLen )
    {
        if (A.listLen == MAXLEN) //每次操作前都先判断表A是否满
        {
            printf("表A已满，无法再操作。\n");
            break;
        }

        if ( A.data[ia] < B.data[ib] ) //A当前元素小于B当前元素
            ia++;                    //就后移ia，继续比较
        else if ( A.data[ia] == B.data[ib] )  //相等则同时后移
        {
            ia++;
            ib++;
        }
        else      //大于，说明B当前元素肯定不在A里，就加入A
        {
            A.data[A.listLen++] = B.data[ib];
            ib++;
        }
    }
    if (ib != B.listLen) //上面while退出后，如果B还没遍历完，说明剩下的B都可以并入A
    {
        while(ib < B.listLen && A.listLen < MAXLEN)
        {
            A.data[A.listLen++] = B.data[ib];
            ib++;
        }
    }
    return 0;
}

//*********************************************************
//函数功能：递增有序表1，2，求中位数
//输入参数：长度相同的表1，2
//输出参数：无
//返回值：  中位数n
//*********************************************************
int FindMidNum( ptList L1, ptList L2 )
{
    const int len = L1.listLen;//前提是两个表长度一样
    int i1, i2, j, num[len] = {0}; //每次比较较小的那个放入这个数组里
    i1 = i2 = j = 0;           //j控制循环
    while ( j < len )
    {
        if( L1.data[i1] < L2.data[i2] ) //1当前元素小于2当前的
        {
            num[j++] = L1.data[i1];
            i1++;
        }
        else if (L1.data[i1] > L2.data[i2]) //大于
        {
            num[j++] = L2.data[i2];
            i2++;
        }
        else //等于的话，就放如其中一个，然后更新i1，i2
        {
            num[j++] = L1.data[i1];
            i1++;
            i2++;
        }
    }
    //最后输出num数组最后一位即为中位数
    printf("中位数是  %d\n",num[len - 1]);
    return 0;
}

//*********************************************************
//函数功能：求两个集合的交集
//输入参数：递增有序表A，B
//输出参数：表C
//返回值： 	无
//*********************************************************
void Intersection( ptList A, ptList B, ptList C )
{
    InitialList( C ); //先初始化C，避免C原来有元素
    int ia, ib;
    ia = ib = 0;
    while (ia < A.listLen && ib < B.listLen )//双指针同时遍历两个表
    {
        if ( A.data[ia] == B.data[ib] )//如果相等，就放其中一个到C中
        {
            C.data[C.listLen++] = A.data[ia];
            ia++;
            ib++;
        }
        else if ( A.data[ia] < B.data[ib] ) //小于，就后移A的指针
            ia++;
        else                             //大于，就后移B
            ib++;
    }
}

//*********************************************************
//函数功能：求两个集合的并集
//输入参数：递增有序表A，B
//输出参数：表C
//返回值： 	无
//*********************************************************
void Union( ptList A, ptList B, ptList C )
{
    int ia, ib;
    ia = ib = 0;
    InitialList( C );
    while ( ia < A.listLen && ib < B.listLen ) //同样的，双指针遍历两个表
    {
        if ( A.data[ia] == B.data[ib] ) //相等就放其中一个到C中
        {
            C.data[C.listLen++] = A.data[ia];
        }
        else  //不等就两个都放
        {
            C.data[C.listLen++] = A.data[ia];
            C.data[C.listLen++] = B.data[ib];
        }
        ia++;
        ib++;
        if ( C.listLen == MAXLEN )
        {
            printf("表已满.");
            break;
        }
    }
    if ( ib < B.listLen ) //如果B还没遍历完，说明剩下的都可以并入C
    {
        ib++;
        while ( ib < B.listLen && C.listLen < MAXLEN )
        {
            if ( B.data[ib] != A.data[ia] )
                C.data[C.listLen++] = B.data[ib];
            ib++;
        }
    }
    else                    //else说明A还没遍历完，将A剩下的并入C
    {
        ia++;
        while (ia < A.listLen && C.listLen < MAXLEN )//确保C的数组不会越界
        {
            if ( A.data[ia] != B.data[ib] )
                C.data[C.listLen++] = A.data[ia];
            ia++;
        }
    }
}

//*********************************************************
//函数功能：求两个集合的差
//输入参数：递增有序表A，B
//输出参数：表C
//返回值： 	无
//*********************************************************
void setSubtract( ptList A, ptList B, ptList C )
{
    //先判断A，B的空，这里先假设A，b都不为空
    InitialList( C );
    int ia, ib;
    ia = ib = 0;
    while ( ia < A.listLen && ib < B.listLen ) //双指针遍历两个表
    {
        if ( A.data[ia] == B.data[ib] )        //相等说明A当前元素不是目标元素，
        {
            ia++;                                //后移两个指针，继续判断
            ib++;
            continue;
        }
        else if ( A.data[ia] < B.data[ib] )    //A当前元素小于B的，说明A当前元素满足差集要求
        {
            C.data[C.listLen++] = A.data[ia]; //并入C
            ia++;
        }
        else ib++;                               //大于，移动B的指针，看B后面的
    }
    if (ia < A.listLen )                        //如果A没遍历完，那A剩下的一定满足差集要求
    {
        while ( ia < A.listLen && C.listLen < MAXLEN )
        {
            C.data[C.listLen++] = A.data[ia];
            ia++;
        }
    }
}

//*********************************************************
//函数功能：取两个表的交集，再赋给A
//输入参数：递增有序表A，B
//输出参数：表A
//返回值： 	无
//*********************************************************
void InterSecToA( ptList A, ptList B )
{
    int ia = 0, ib = 0, k = 0; //k标记A后面的元素要移动到的位置
    while ( ia < A.listLen && ib < B.listLen ) //双指针同时遍历两个表
    {
        if ( A.data[ia] == B.data[ib] )    //将不是交集的元素给覆盖掉，实现在原表上操作
        {
            A.data[k] = A.data[ia];
            k++;
            ia++;
            ib++;
        }
        else if ( A.data[ia] > B.data[ib] )
            ib++;
        else
            ia++;
    }
    //由于前面k++，后缀++的副作用，所以这里只用k，而不是k+1
    A.listLen = k; //更新表长度
}

//*********************************************************
//函数功能：取两个表的差，再赋给A
//输入参数：递增有序表表A，B
//输出参数：表A
//返回值： 	无
//*********************************************************
void SubtractToA( ptList A, ptList B )
{
    int ia = 0, ib = 0, k = 0, times = 0; //times记录覆盖了多少个，用于更新表长度
    while ( ia < A.listLen && ib < B.listLen )
    {
        if ( A.data[ia] == B.data[ib] )   //相等，则不满足差集要求，继续看两个表后面的
        {
            ia++;
            ib++;
            times++;                        //同时times++
            continue;
        }
        else if ( A.data[ia] > B.data[ib] )
        {
            ib++;
            continue;
        }                                   //只有小于才说明满足差集要求，执行覆盖操作
        A.data[k] = A.data[ia];
        k++;
        ia++;
    }
    while (ia < A.listLen)//如果A没遍历完，就把剩下的依次往前面移times个位置
    {
        A.data[ia - times] = A.data[ia];
        ia++;
    }
    A.listLen -= times; //更新表长度
}

//*********************************************************
//函数功能：遍历列表元素
//输入参数：列表指针
//输出参数：无
//返回值： 	成功返回0，失败返回1
//*********************************************************
int TravelList( ptList L )
{
    if ( IsEmpty( L ) )
        return 1;
    int i;
    for ( i = 0 ; i < L.listLen ; i++ )
    {
        printf("%3d  ", L.data[i]);
    }
    printf("\n");
    return 0;
}

//*********************************************************
//函数功能：删除表里一个元素
//输入参数：列表指针，待删除元素x
//输出参数：无
//返回值： 	0表示删除成功，1元素不存在，2表示表为空
//*********************************************************
int DeleteElement( ptList L, ElementType x )
{
    int i, j;
    i = 0;
    while (L.data[i] != x && i < L.listLen)
        i++;
    if (i == L.listLen)
        return 1;
    if ( IsEmpty( L ) )
    {
        return 2;
    }
    for ( j = i - 1; j < L.listLen ; j++)
    {
        L.data[j] = L.data[j + 1];
    }
    L.data[L.listLen - 1] = 0; //将末尾置0
    L.listLen--;               //长度减一
    return 0;
}
