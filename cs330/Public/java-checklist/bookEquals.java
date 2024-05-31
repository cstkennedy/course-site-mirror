public class Book
{
    private String authorName;
    private String title;

    public Book ()
    {
        authorName = new String();
        title = new String();
    }

    public String getAuthorName()
    {
        return authorName;
    }

    public void setAuthorName(String a)
    {
        authorName = a;
    }

    public String getTitle()
    {
        return title;
    }

    public void setTitle(String t)
    {
        title = t;
    }

    /*+*/public boolean equals(Object right)
    {
        Book b = (Book) right;
        return authorName.equals(b.authorName)
            && title.equals(b.title);
    }/*-*/
}
