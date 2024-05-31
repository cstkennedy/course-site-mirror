function addBook (book, branchName)
{
  bookInfo = getBookInfo(book);
  record branchName as location in bookInfo;
  /*+1*/// addToCardCatalog (bookInfo)
/*-1*/  /*+2*/add to AuthorIndex (bookInfo);
  add to SubjectIndex (bookInfo);
  add to TitleIndex (bookInfo);/*-2*/
  cardCatalog.addToAuthorIndex
  addToInventory (bookInfo, branchName);
}
