void addToFront (List& list, string newData)
{
   shared_ptr<DLNode> newNode (new DLNode()); /*1*/
   newNode->data = newData;           /*2*/
   if (first == shared_ptr<DLNode>()) /*3*/
     {
       // list is empty
       first = last = newNode;   /*4*/
     }
   else
     {
      newNode->next = first;
      first->prev = newNode;
      first = newNode;
     }
}
