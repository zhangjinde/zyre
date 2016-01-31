/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/
#ifndef Q_ZLIST_H
#define Q_ZLIST_H

#include "qzyre.h"

class QT_ZYRE_EXPORT QZlist : public QObject
{
    Q_OBJECT
public:

    //  Copy-construct to return the proper wrapped c types
    QZlist (zlist_t *self, QObject *qObjParent = 0);

    //  Create a new list container
    explicit QZlist (QObject *qObjParent = 0);

    //  Destroy a list container
    ~QZlist ();

    //  Return the item at the head of list. If the list is empty, returns NULL.
    //  Leaves cursor pointing at the head item, or NULL if the list is empty.  
    void * first ();

    //  Return the next item. If the list is empty, returns NULL. To move to
    //  the start of the list call zlist_first (). Advances the cursor.     
    void * next ();

    //  Return the item at the tail of list. If the list is empty, returns NULL.
    //  Leaves cursor pointing at the tail item, or NULL if the list is empty.  
    void * last ();

    //  Return first item in the list, or null, leaves the cursor
    void * head ();

    //  Return last item in the list, or null, leaves the cursor
    void * tail ();

    //  Return the current item of list. If the list is empty, returns NULL.     
    //  Leaves cursor pointing at the current item, or NULL if the list is empty.
    void * item ();

    //  Append an item to the end of the list, return 0 if OK or -1 if this  
    //  failed for some reason (out of memory). Note that if a duplicator has
    //  been set, this method will also duplicate the item.                  
    int append (void *item);

    //  Push an item to the start of the list, return 0 if OK or -1 if this  
    //  failed for some reason (out of memory). Note that if a duplicator has
    //  been set, this method will also duplicate the item.                  
    int push (void *item);

    //  Pop the item off the start of the list, if any
    void * pop ();

    //  Checks if an item already is present. Uses compare method to determine if 
    //  items are equal. If the compare method is NULL the check will only compare
    //  pointers. Returns true if item is present else false.                     
    bool exists (void *item);

    //  Remove the specified item from the list if present
    void remove (void *item);

    //  Make a copy of list. If the list has autofree set, the copied list will  
    //  duplicate all items, which must be strings. Otherwise, the list will hold
    //  pointers back to the items in the original list. If list is null, returns
    //  NULL.                                                                    
    QZlist * dup ();

    //  Purge all items from list
    void purge ();

    //  Return number of items in the list
    size_t size ();

    //  Sort the list by ascending key value using a straight ASCII comparison.
    //  The sort is not stable, so may reorder items with the same keys.       
    void sort (zlist_compare_fn compare);

    //  Set list for automatic item destruction; item values MUST be strings. 
    //  By default a list item refers to a value held elsewhere. When you set 
    //  this, each time you append or push a list item, zlist will take a copy
    //  of the string value. Then, when you destroy the list, it will free all
    //  item values automatically. If you use any other technique to allocate 
    //  list values, you must free them explicitly before destroying the list.
    //  The usual technique is to pop list items and destroy them, until the  
    //  list is empty.                                                        
    void autofree ();

    //  Sets a compare function for this list. The function compares two items.
    //  It returns an integer less than, equal to, or greater than zero if the 
    //  first item is found, respectively, to be less than, to match, or be    
    //  greater than the second item.                                          
    //  This function is used for sorting, removal and exists checking.        
    void comparefn (zlist_compare_fn fn);

    //  Set a free function for the specified list item. When the item is     
    //  destroyed, the free function, if any, is called on that item.         
    //  Use this when list items are dynamically allocated, to ensure that    
    //  you don't have memory leaks. You can pass 'free' or NULL as a free_fn.
    //  Returns the item, or NULL if there is no such item.                   
    void * freefn (void *item, zlist_free_fn fn, bool atTail);

    //  Self test of this class.
    static void test (bool verbose);

    zlist_t *self;
};
#endif //  Q_ZLIST_H
/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/
