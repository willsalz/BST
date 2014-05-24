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
#include "BST.h"

int * foo(){
    
    int * bar = (int*)malloc(sizeof(int));
    *bar = 10;
    fprintf(stdout, "%d\n", *bar);
    return bar;
    
}

int bar(int* val){
    int x = *val;
    return x;
}

int main(void)
{
    /* Create the BST */
    BST tree = bst_create();
    
    /* Populate the BST with data */
    bst_insert(tree, 5);
    for (BSTType iter = 0; iter < 100; ++iter) {
        bst_insert(tree, iter);
    }
    
    /* Print the BST */
    bst_print(tree);
    
    /* Assert all the values we inserted can be found... */
    for(BSTType iter = 0; iter < 100; ++iter){
        assert(bst_find(tree, iter));
    }
    
    /* ...and that none are found that aren't! */
    for(BSTType iter = 101; iter < 1000; ++iter){
        assert(!bst_find(tree, iter));
    }
    
    /* Print the depth of the tree */
    fprintf(stdout, "BST Depth: %lu\n", bst_depth(tree));

    /* Destroy the tree */
    bst_destroy(tree);
    tree = NULL;
    
    tree = bst_create();
    bst_insert(tree, 5);
    bst_insert(tree, 4);
    bst_insert(tree, 6);
    bst_print(tree);
    
    fprintf(stdout, "%d\n", bar(foo()));
    
    bst_destroy(tree);
    exit(EXIT_SUCCESS);
}

