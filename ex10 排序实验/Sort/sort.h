#ifndef _Sort_H
#define _Sort_H
#define SCALE1 50000		//defien the scale of text data
#define SCALE2 100000
#define SCALE3 200000
#define SCALE4 500000
#define SCALE5 1000000
#define SCALE6 5000000
typedef int ElementType ;
void ShowResult( ElementType *arr, int &len );
void InsertSort( ElementType *arr, int len, bool &Re, bool &show );
void ShellSort( ElementType *arr, int r, bool &show, int *dh, int dhlen );//希尔排序
void QuickSort( ElementType *arr, int len, int s, int t, bool &Re, int &cntComp, int &cntExchange );
void QuickShow( ElementType *arr, int len, int s, int t, bool &Re, int &cntComp, int &cntExchange );
void Partition( ElementType *arr, int s, int t, bool &Re, int &cutPoint, int &cntComp, int &cntExchange ); //快速排序的划分
void HeapSort( ElementType *arr, int len, bool &show );
void PercDown( ElementType *arr, int p, int &n );
void swap( ElementType &a, ElementType &b );
void MergeSort( ElementType A[], int N, int &cntcmp );
void Msort( ElementType A[], ElementType TmpA[], int L, int RightEnd, int &cntcmp  );
void Merge( ElementType A[], ElementType TmpA[], int L, int R, int RightEnd, int &cntcmp );

void ChooseSort( ElementType *arr, int len );
void DrawResult( ElementType *arr, int len,int i );

#endif // _Sort_H
