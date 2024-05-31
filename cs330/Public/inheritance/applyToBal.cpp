void applyToCurrentBalance (CheckBook cbook, Transaction trans) {
   Balance b = cbook.getCurrentBalance();
   trans.apply (b);
   cbook.setCurrentBalance(b);
}
   /*...*/
CheckBook myCheckBook;
Check check;
Transaction transaction;
Balance bal;
   /*...*/
bal = myCheckBook.getCurrentBalance();
transaction.apply (bal);                         /*1*/
check.apply (bal);                               /*2*/
applyToCurrentBalance(myCheckBook, transaction); /*3*/
applyToCurrentBalance(myCheckBook, check);       /*4*/
