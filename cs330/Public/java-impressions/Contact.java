package mailinglist;
/**
 * A contact is a name and address.
 * 
 * For the purpose of this example, I have simplified matters 
 * a bit by making both of these components simple strings. 
 * In practice, we would expect Address, at least, to be a
 * more structured type.
 * 
 * @author zeil
 *
 */
public class Contact 
  implements Cloneable, Comparable<Contact> {

	private String theName;
	private String theAddress;

	/**
	 * Create a contact with empty name and address.
	 *
	 */
	public Contact ()
	{
		theName = "";
		theAddress = "";
	}

	/**
	 * Create a contact
	 * @param nm  name 
	 * @param addr address
	 */
	public Contact (String nm, String addr)
	{
		theName = nm;
		theAddress = addr;
	}


	/**
	 * Get the name of the contact
	 * @return the name
	 */
	public String getName()
	{
		return theName;
	}
	
	/**
	 * Change the name of the contact
	 * @param nm new name
	 */
	public void setName (String nm) 
	{
		theName= nm;
	}

	/**
	 * Get the address of the contact
	 * @return the address
	 */
	public String getAddress()
	{
		return theAddress;
	}
	
	/**
	 * Change the address of the contact 
	 * @param addr new address
	 */
	public void setAddress (String addr) 
	{
		theAddress = addr;
	}

	/**
	 * True if the names and addresses are equal 
	 */
	public boolean equals (Object right)
	{
		Contact r = (Contact)right;
		return theName.equals(r.theName)
		    && theAddress.equals(r.theAddress);
	}

	public int hashCode ()
	{
		return theName.hashCode() + 3 * theAddress.hashCode();
	}

	public String toString()
	{
		return theName + ": " + theAddress;
	}
	
	public Object clone()
	{
		return new Contact(theName, theAddress);
	}

	/**
	 * Compare this contact to another.
	 * Return value > 0 if this contact precedes the other,
	 * == 0 if the two are equal, and < 0 if this contact
	 * follows the other.  
	 */
	public int compareTo (Contact c)
	{
		int nmcomp = theName.compareTo(c.theName);
		if (nmcomp != 0)
			return nmcomp;
		else
			return theAddress.compareTo(c.theAddress);
	}
}
