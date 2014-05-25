//
//  main.c
//  BST
//
//  Created by Will Salisbury on 5/21/14.
//  Copyright (c) 2014 Will Salisbury. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <sys/random.h>

#include "BST.h"

static const u_int32_t maxVal = 100;

int main(void)
{
    BST tree = bst_create();

    bst_insert(tree, maxVal/2);
    for (int iter = 0; iter < maxVal; iter++) {
        bst_insert(tree, (const BSTType)arc4random_uniform(maxVal) );
    }

    bst_print(tree);
    fprintf(stdout, "BST Depth: %lu\n", bst_depth(tree));

    
    bst_destroy(&tree);
    assert(!tree && "<tree> still exists after <bst_destroy>!");
    exit(EXIT_SUCCESS);
}

