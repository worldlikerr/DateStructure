#include"BiTree.h"
#include<iostream>
#include<queue>
using namespace std;

/// <summary>
/// 按先序次序输入二叉树中结点的值（一个字符），空格字符表示空树,
/// 构造二叉链表表示的二叉树T.
/// </summary>
/// <param name="T"></param>
/// <returns></returns>
Status CreateBiTree(BiTree& T) {//如果函数参数是一个引用类型的指针（例如 BiTree& T），那么可以直接将它赋值为 nullptr。但如果是值传递的结构体（例如 BiTNode& T），则不能直接将 T 赋值为 nullptr，因为引用不能指向空指针。
	TElemType ch;
	cin >> ch;
	if (ch == '#')T = nullptr;
	else
	{
		T = new BiTNode;
		if (!T)exit(OVERFLOW);//检查内存分配是否成功
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return OK;
}

/// <summary>
/// 采用二叉链表存储结构，Visit是对结点操作的应用函数。
/// 先序遍历二叉树T，对每个结点调用函数Visit一次且仅一次。
/// 一旦visit（）失败，则操作失败。
/// </summary>
/// <param name="T"></param>
/// <param name="visit"></param>
/// <returns></returns>
Status PreOrderTraverse(BiTree T, Status(*visit)(TElemType)) {
	if (T == nullptr) return 1; // 空树返回成功状态
	if (!visit(T->data)) return 0; // 调用 visit 函数，失败则返回失败状态
	if (!PreOrderTraverse(T->lchild, visit)) return 0; // 递归遍历左子树
	if (!PreOrderTraverse(T->rchild, visit)) return 0; // 递归遍历右子树
	return 1; // 遍历成功
}


Status InOrderTraverse(BiTree T, Status(*visit)(TElemType)) {
	if (T == nullptr) return 1; // 空树返回成功状态
	if (!InOrderTraverse(T->lchild, visit)) return 0; // 递归遍历左子树
	if (!visit(T->data)) return 0; // 调用 visit 函数，失败则返回失败状态
	if (!InOrderTraverse(T->rchild, visit)) return 0; // 递归遍历右子树
	return 1; // 遍历成功
}

Status PostOrderTraverse(BiTree T, Status(*visit)(TElemType)) {
	if (T == nullptr) return 1; // 空树返回成功状态
	if (!PostOrderTraverse(T->lchild, visit)) return 0; // 递归遍历左子树
	if (!PostOrderTraverse(T->rchild, visit)) return 0; // 递归遍历右子树
	if (!visit(T->data)) return 0; // 调用 visit 函数，失败则返回失败状态
	return 1; // 遍历成功
}

/// <summary>
/// 采用二叉链表存储结构，Visit是对结点操作的应用函数。
/// 层序遍历二叉树T，对每个结点调用函数Visit一次且仅一次。
/// 一旦visit（）失败，则操作失败。
/// </summary>
/// <param name="T"></param>
/// <param name="visit"></param>
/// <returns></returns>
Status LevelOrderTraverse(BiTree T, Status(*visit)(TElemType)) {
	if (!T)return OK;
	queue<BiTree> Q;
	Q.push(T);
	while (!Q.empty() ){
		BiTree node = Q.front();
		Q.pop();
		if (!visit(node->data))return ERROR;
		if (node->lchild)Q.push(node->lchild);
		if (node->rchild)Q.push(node->rchild);
	}
	return OK;
}