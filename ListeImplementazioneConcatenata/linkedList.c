#include <stdlib.h>
#include "linkedList.h"

/*
 * Inserts the new key at the beginning of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLInsertAtBeginning(LLElement * first, int key) 
{
    LLElement * temp; 
    temp = (LLElement *)malloc(sizeof(LLElement));
    if(temp != NULL) 
    {
        temp->next = first;
        temp->key = key;
        first = temp;
    }
    return first;
}

/*
 * Inserts the new key at the end of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLInsertAtEnd(LLElement * first, int key) 
{
   LLElement *new;
   LLElement **temp;
   new = (LLElement*)malloc(sizeof(LLElement));
   if(new != NULL)
   {
       temp = &first;
       while(*temp != NULL)
       {
           temp = &((*temp)->next);
       }
       new->next = NULL;
       new->key = key;
       *temp = new;
   }
    

    return first;
}

/*
 * Inserts the new key at the specified positon of the list.
 * Position is zero-based, meaning that the first element is at position 0,
 * analogous to what happens in arrays.
 * 
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLInsertAtPosition(LLElement * first, int key, int position) 
{
    LLElement *new;
    LLElement **temp;
    new = (LLElement *)malloc(sizeof(LLElement));
    int i;
    if(new != NULL)
    {
        temp = &first;
        for(i=0;i<position;i++)
        {
            temp = &((*temp)->next);
        }
        new->next=*temp;
        new->key=key;
        *temp= new;        
    }   
    return first;
   }

/*
 * Returns the size of the list.
 */
int LLSize(LLElement * first) 
{
    int numelementi=0;
        while(first != NULL)
        {
            numelementi++;
            first=first->next;
        }    
    return numelementi;
}   

/*
 * Returns the key at the specified position.
 */ 
int LLGetKey(LLElement * first, int position) 
{
    int cont;
    for(cont=0;cont<position;cont++)
    {
        first=first->next;
    }
    return first->key;
}

/*
 * Returns the position of the first element, starting from startPosition, that
 * has the specified key.
 * Returns -1 if not found. 
 */ 
int LLFindKey(LLElement * first, int key, int startPosition) 
{
    int r = -1;
    int i;
    for(i=0; i<startPosition; i++) 
    {
        first = first->next;
    }
    while(first != NULL && r == -1) 
    {
        if(first->key == key) 
        {
            r = i;
        }
        first = first->next;
        i++;
    }
    return r;
}

/*
 * Remove the first element of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLRemoveFirst(LLElement * first) 
{
    LLElement *rimozione;
    if(first!=NULL)
    {
        rimozione = first;
        first = first->next;
        free(rimozione);
    }
     return first;
}

/*
 * Remove the last element of the list.
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLRemoveLast(LLElement * first) 
{
    LLElement **rimozione;
    if(first!=NULL)
    {
        rimozione = &first;
        while((*rimozione)->next != NULL)
        {
            rimozione= &((*rimozione)->next);
        }
        free(*rimozione);
        *rimozione=NULL;
    }
return first;
}

/*
 * Remove the element at the specified position.
 * Position is zero-based, meaning that the first element is at position 0,
 * analogous to what happens in arrays.
 * 
 * Returns the updated pointer to the first element of the list.
 */
LLElement * LLRemoveAtPosition(LLElement * first, int position) 
{
 LLElement ** temp;
    LLElement * posizione;
    int i;
    temp = &first;
    for(i=0; i<position; i++)
    {
        temp = &((*temp)->next);
    }
    
    posizione = *temp;
    if((*temp)->next != NULL) 
    {
        *temp = (*temp)->next;
    }
    free(posizione);
    
    return first;
}

/* Empties the list */
LLElement * LLEmptyList(LLElement *first) 
{
    LLElement *temp;
    while(first != NULL) 
    {
        temp = first;
        first = first->next;
        free(temp);
    }
    return NULL;
}

