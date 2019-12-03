//
// Created by anleeno on 2019/11/28.
//
#include "linklist.h"

//创建线性链表
Node *create_Linklist() {
    Node *head, *tail, *pnew;
    int score;

    head = (Node *) malloc(sizeof(Node));
    if (head == NULL) {
        printf("no enough memory!\n");
        return NULL;
    }

    head->next = NULL;//头指针指针域置空
    tail = head;//开始时尾指针指向头节点

    printf("input score:\n");
    while (1) {
        scanf("%d", &score);
        if ((score < 0) || (score > 100)) {
            break;
        }
        pnew = (Node *) malloc(sizeof(Node));//创建新节点
        if (pnew == NULL) {
            printf("no enough memory!\n");
            return NULL;
        }

        pnew->score = score;//把数据存放到新节点数据域
        pnew->next = NULL;//新节点指针域置空

        tail->next = pnew;//新节点插入到链表尾
        tail = pnew;//尾指针指向当前的尾节点
    }
    return head;//返回创建链表的头指针
}

//将pnew指向的节点插入到以head为头指针的链表的第i个节点之后
void insert_Linklist(Node *head, Node *pnew, int i) {
    Node *p;
    int j;
    p = head;
    for (j = 0; j < i && p != NULL; j++) {//将p指向要插入的第i个节点
        p = p->next;
    }
    if (p == NULL) {
        printf("the %d node do not found!", i);
        return;
    }
    pnew->next = p->next;
    p->next = pnew;
}

//删除以head为头指针的链表的第i个节点
void delete_Linklist(Node *head, int i) {
    Node *p, *q;//第i个节点的前驱节点的指针，第i个节点的指针
    int j;//循环体变量

    if (i == 0)//删除的是头指针则返回
        return;
    p = head;//从头指针开始遍历
    for (j = 1; j < i && p->next != NULL; j++) {
        p = p->next;//将p指向要删除的第i个节点的前驱节点
    }

    if(p->next==NULL){
        printf("the %d node do not found!", i);
        return;
    }

    q = p->next;//将q指向第i个节点
    //或p->next=p->next->next;
    p->next = q->next;//将p的后继节点指向要删除的第i个节点的后继节点，相当于把第i个节点的前驱节点和后继节点连起来
    free(q);//释放第i个节点
}

//销毁以head为头指针的链表
void free_Linklist(Node *head) {
    Node *p, *q;
    p = head;//将p指向要删除链表的头指针
    while (p->next != NULL) {
        q = p->next;//先将q指向第一个节点（相当于抓住犯人）
        p->next = q->next;//将p指向第二个节点（相当于审查犯人，如果不审查出下一个线索就直接解决犯人，就进行不下去了，这一步必不可少）
        free(q);//释放第一个节点
    }
    free(head);//最后释放head
}

//输出线性链表
void display_Linklist(Node *head) {
    Node *p;
    for (p = head->next; p != NULL; p = p->next) {
        printf("%d-->(%p)  ", p->score, &p->next);
    }
    printf("\n");
}
