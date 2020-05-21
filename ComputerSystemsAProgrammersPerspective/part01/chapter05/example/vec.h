/**
 * vec
 * @author Clay
 * @date 2020/5/21
 */

#ifndef FROM_UNDEFINED_TO_ANY_VEC_H
#define FROM_UNDEFINED_TO_ANY_VEC_H

typedef long int dataT;

typedef struct
{
    long int len;
    dataT *data;
} vecRec, *vecPtr;

#define IDENT 1
#define OP *

#endif //FROM_UNDEFINED_TO_ANY_VEC_H
