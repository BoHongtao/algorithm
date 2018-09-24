#include <stdio.h>
#include <stdlib.h>


//���ﶨ����ʺ��������ڷ�������ĳ���ڵ��ֵ
void visit(BTNode *p)
{
    return 0;
}

//�������
void preorder(BTNode *p)
{
    if(p!=NULL)
    {
        visit(p);
        //�������������
        preorder(p->lchild);
        //�������������
        preorder(p->rchild);
    }
}

//�������
void inorder(BTNode *p)
{
    if(p!=NULL)
    {
        inorder(p->lchild);
        visit(p);
        inorder(p->rchild);
    }
}

//��������
void postorder(BTNode *p)
{
    if(p!=NULL)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        postorder(p);
    }
}


//��α���
void level(BTBode *p)
{
    int front,rear;
    //����һ��ѭ�����У���������Ҫ���ʵĲ���ϵĽڵ�
    BTNode *que[maxSize];
    front = rear = 0;
    BTNode *q;
    if(p!=NUll)
    {
        rear = (rear + 1)%maxSize;
        //���ڵ����
        que[rear] = p;
        //���в��գ�����ѭ��
        while(rear!=front)
        {
            front = (front + 1)%maxSize;
            q = que[front];
            visit(q);
            //��������Ϊ�գ������������
            if(q->lchild!=NULL)
            {
                rear = (rear+1)%maxSize;
                que[rear] = q->lchild;
            }
            //��������Ϊ�գ������������
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
