#include <stdio.h>
#include <stdlib.h>


//这里定义访问函数，用于访问树的某个节点的值
void visit(BTNode *p)
{
    return 0;
}

//先序遍历
void preorder(BTNode *p)
{
    if(p!=NULL)
    {
        visit(p);
        //先序遍历左子树
        preorder(p->lchild);
        //先序遍历右子树
        preorder(p->rchild);
    }
}

//中序遍历
void inorder(BTNode *p)
{
    if(p!=NULL)
    {
        inorder(p->lchild);
        visit(p);
        inorder(p->rchild);
    }
}

//后续遍历
void postorder(BTNode *p)
{
    if(p!=NULL)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        postorder(p);
    }
}


//层次遍历
void level(BTBode *p)
{
    int front,rear;
    //定义一个循环队列，用来保存要访问的层次上的节点
    BTNode *que[maxSize];
    front = rear = 0;
    BTNode *q;
    if(p!=NUll)
    {
        rear = (rear + 1)%maxSize;
        //根节点入队
        que[rear] = p;
        //队列不空，进行循环
        while(rear!=front)
        {
            front = (front + 1)%maxSize;
            q = que[front];
            visit(q);
            //左子树不为空，左子树根入队
            if(q->lchild!=NULL)
            {
                rear = (rear+1)%maxSize;
                que[rear] = q->lchild;
            }
            //右子树不为空，右子树根入队
             if(q->rchild!=NULL)
            {
                rear = (rear+1)%maxSize;
                que[rear] = q->rchild;
            }
        }
    }
}


int main()
{
    printf("Hello world!\n");
    return 0;
}
