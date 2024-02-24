//
// Created by jorge on 12/22/2023.
//
#include<stdio.h>
#include<stdlib.h>
 struct ListNode {
     int val;
     struct ListNode *next;
 };
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int value=0;
    struct ListNode* newNode= (struct ListNode*)malloc(sizeof(struct ListNode));
    if(l1!=NULL)
        value+=l1->val;
    if(l2!=NULL)
        value+=l2->val;
    if(l1->next!=NULL && l2->next!=NULL){}
    else if(l1->next!=NULL){}
    else if(l2->next!=NULL){}
    else{}
    return newNode;
}