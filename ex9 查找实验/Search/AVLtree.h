#ifndef _AVLtree_H
#define _AVLtree_H
typedef int TreeElement;
struct AVL;
typedef AVL *AVLnode;
typedef AVL *AVLTree;
AVLnode AVLFind( TreeElement x, AVLTree T );
AVLnode AVLFindMin( AVLTree T );
AVLnode AVLFindMax( AVLTree T );
AVLTree AVLInsert( TreeElement x, AVLTree &T );
AVLTree AVLDelete( AVLTree T, TreeElement x );
void DestoryAVLtree( AVLTree &T );
void AVLmidorderTravel( AVLTree T );
bool CreateAVLformArr( AVLTree &T, TreeElement *arr, int len );
AVLnode RotateRR( AVLTree T );  //ÓÒÓÒÐý×ª
AVLnode RotateLL( AVLTree T );  //×ó×óÐý×ª
AVLnode RotateRL( AVLTree T );  //ÓÒ×óÐý×ª
AVLnode RotateLR( AVLTree T );  //×óÓÒÐý×ª
int Max( int a, int b );
#endif // _AVLtree_H
