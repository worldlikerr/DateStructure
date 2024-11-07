#pragma once

typedef char TElemType;
typedef int Status;
#define OK 1
#define ERROR 0

//二叉树定义
typedef struct BiTNode {
	TElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode,*BiTree;

/// <summary>
/// 按先序次序输入二叉树中结点的值（一个字符），空格字符表示空树,
/// 构造二叉链表表示的二叉树T.
/// </summary>
/// <param name="T"></param>
/// <returns></returns>
Status CreateBiTree(BiTree& T);

/// <summary>
/// 采用二叉链表存储结构，Visit是对结点操作的应用函数。
/// 先序遍历二叉树T，对每个结点调用函数Visit一次且仅一次。
/// 一旦visit（）失败，则操作失败。
/// </summary>
/// <param name="T"></param>
/// <param name="visit"></param>
/// <returns></returns>
Status PreOrderTraverse(BiTree T, Status(*visit)(TElemType));

/// <summary>
/// 采用二叉链表存储结构，Visit是对结点操作的应用函数。
/// 中序遍历二叉树T，对每个结点调用函数Visit一次且仅一次。
/// 一旦visit（）失败，则操作失败。
/// </summary>
/// <param name="T"></param>
/// <param name="visit"></param>
/// <returns></returns>
Status InOrderTraverse(BiTree T, Status(*visit)(TElemType));

/// <summary>
/// 采用二叉链表存储结构，Visit是对结点操作的应用函数。
/// 后序遍历二叉树T，对每个结点调用函数Visit一次且仅一次。
/// 一旦visit（）失败，则操作失败。
/// </summary>
/// <param name="T"></param>
/// <param name="visit"></param>
/// <returns></returns>
Status PostOrderTraverse(BiTree T, Status(*visit)(TElemType));

/// <summary>
/// 采用二叉链表存储结构，Visit是对结点操作的应用函数。
/// 层序遍历二叉树T，对每个结点调用函数Visit一次且仅一次。
/// 一旦visit（）失败，则操作失败。
/// </summary>
/// <param name="T"></param>
/// <param name="visit"></param>
/// <returns></returns>
Status LevelOrderTraverse(BiTree T, Status(*visit)(TElemType));