function addBook (book, branchName)
{
  bookInfo = getBookInfo(book);
  record branchName as location in bookInfo;
  // addToCardCatalog (bookInfo)
/*+1*/  //   add to AuthorIndex (bookInfo);
/*-1*/  /*+2*/authorList = bookInfo.getAuthors();
  for each author au in authorList {
    catalog.authorIndex.addByAuthor (au, bookInfo);
  }/*-2*/
  add to SubjectIndex (bookInfo);
  add to TitleIndex (bookInfo);
  cardCatalog.addToAuthorIndex
  addToInventory (bookInfo, branchName);
}
