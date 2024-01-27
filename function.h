//
// Created by 23076 on 2024/1/21.
//

#ifndef CWORKS_FUNCTION_H
#define CWORKS_FUNCTION_H

#endif //CWORKS_FUNCTION_H

#include <stdio.h>
#include <stdlib.h>
typedef int BiElemType;
typedef struct BiNode{
    BiElemType c;
    struct BiNode* lchhid;
    struct BiNode* rchhid;
}BiNode,*BiTree;

typedef struct tag{
    BiTree p;
    struct tag* pnext;
}tag_t,*ptag_t;
