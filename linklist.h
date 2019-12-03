//
// Created by anleeno on 2019/11/28.
//

#ifndef CLIONPROJECT_LINKLIST_H
#define CLIONPROJECT_LINKLIST_H

#include <stdio.h>
#include <stdlib.h>

struct Grade {
    int score;//存放成绩，相当于数据域
    struct Grade *next;//指向自身的指针，相当于指针域
};

typedef struct Grade Node;

Node *create_Linklist();

void insert_Linklist(Node *head, Node *pnew, int i);

void delete_Linklist(Node *head,int i);

void display_Linklist(Node *head);

void free_Linklist(Node *head);

#endif //CLIONPROJECT_LINKLIST_H
