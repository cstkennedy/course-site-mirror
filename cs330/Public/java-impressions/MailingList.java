package mailinglist;

/**
 * A collection of names and addresses
 */
public class MailingList implements Cloneable {

	/**
	 * Create an empty mailing list
	 *
	 */
	public MailingList() {
		first = null;
		last = null;
		theSize = 0;
	}

	/**
	 *  Add a new contact to the list
	 *  @param contact new contact to add
	 */
	public void addContact(Contact contact) {
		if (first == null) {
			// add to empty list
			first = last = new ML_Node(contact, null);
			theSize = 1;
		} else if (contact.compareTo(last.contact) > 0) {
			// add to end of non-empty list
			last.next = new ML_Node(contact, null);
			last = last.next;
			++theSize;
		} else if (contact.compareTo(first.contact) < 0) {
			// add to front of non-empty list
			first = new ML_Node(contact, first);
			++theSize;
		} else {
			// search for place to insert
			ML_Node previous = first;
			ML_Node current = first.next;
			assert (current != null);
			while (contact.compareTo(current.contact) < 0) {
				previous = current;
				current = current.next;
				assert (current != null);
			}
			previous.next = new ML_Node(contact, current);
			++theSize;
		}
	}

	/**
	 *  Remove one matching contact 
	 *  @param c remove a contact equal to c
	 */
	public void removeContact(Contact c) {
		ML_Node previous = null;
		ML_Node current = first;
		while (current != null && c.compareTo(current.contact) > 0) {
			previous = current;
			current = current.next;
		}
		if (current != null && c.equals(current.contact))
			remove(previous, current);
	}

	/**
	 * Remove a contact with the indicated name
	 * @param name name of contact to remove
	 */
	public void removeContact(String name) {
		ML_Node previous = null;
		ML_Node current = first;
		while (current != null && name.compareTo(current.contact.getName()) > 0) {
			previous = current;
			current = current.next;
		}
		if (current != null && name == current.contact.getName())
			remove(previous, current);

	}

	/**
	 * Search for contacts
	 * @param name name to search for
	 * @return true if a contact with an equal name exists
	 */
	public boolean contains(String name) {
		ML_Node current = first;
		while (current != null && name.compareTo(current.contact.getName()) > 0) {
			current = current.next;
		}
		return (current != null && name == current.contact.getName());
	}

	/**
	 * Search for contacts
	 * @param name name to search for
	 * @return contact with that name if found, null if not found
	 */
	public Contact getContact(String name) {
		ML_Node current = first;
		while (current != null && name.compareTo(current.contact.getName()) > 0) {
			current = current.next;
		}
		if (current != null && name == current.contact.getName())
			return current.contact;
		else
			return null;
	}

	/**
	 * combine two mailing lists
	 *
	 */
	public void merge(MailingList anotherList) {
		// For a quick merge, we will loop around, checking the 
		// first item in each list, and always copying the smaller
		// of the two items into result
		MailingList result = new MailingList();
		ML_Node thisList = first;
		ML_Node otherList = anotherList.first;
		while (thisList != null && otherList != null) {
			if (thisList.contact.compareTo(otherList.contact) < 0) {
				result.addContact(thisList.contact);
				thisList = thisList.next;
			} else {
				result.addContact(otherList.contact);
				otherList = otherList.next;
			}
		}
		// Now, one of the two lists has been entirely copied. 
		// The other might still have stuff to copy. So we just copy
		// any remaining items from the two lists. Note that one of these
		// two loops will execute zero times.
		while (thisList != null) {
			result.addContact(thisList.contact);
			thisList = thisList.next;
		}
		while (otherList != null) {
			result.addContact(otherList.contact);
			otherList = otherList.next;
		}
		// Now result contains the merged list. Transfer that into this list.
		first = result.first;
		last = result.last;
		theSize = result.theSize;
	}

	/**
	 * How many contacts in list?
	 */
	public int size() {
		return theSize;
	}

	/**
	 * Return true if mailing lists contain equal contacts
	 */
	public boolean equals(Object anotherList) {
		MailingList right = (MailingList) anotherList;
		if (theSize != right.theSize) // (easy test first!)
			return false;
		else {
			ML_Node thisList = first;
			ML_Node otherList = right.first;
			while (thisList != null) {
				if (!thisList.contact.equals(otherList.contact))
					return false;
				thisList = thisList.next;
				otherList = otherList.next;
			}
			return true;
		}
	}

	public int hashCode() {
		int hash = 0;
		ML_Node current = first;
		while (current != null) {
			hash = 3 * hash + current.hashCode();
			current = current.next;
		}
		return hash;
	}

	public String toString() {
		StringBuffer buf = new StringBuffer("{");
		ML_Node current = first;
		while (current != null) {
			buf.append(current.toString());
			current = current.next;
			if (current != null)
				buf.append("\n");
		}
		buf.append("}");
		return buf.toString();
	}

	/**
	 * Deep copy of contacts
	 */
	public Object clone() {
		MailingList result = new MailingList();
		ML_Node current = first;
		while (current != null) {
			result.addContact((Contact) current.contact.clone());
			current = current.next;
		}
		return result;
	}

	private class ML_Node {
		public Contact contact;

		public ML_Node next;

		public ML_Node(Contact c, ML_Node nxt) {
			contact = c;
			next = nxt;
		}
	}

	private int theSize;

	private ML_Node first;

	private ML_Node last;

	// helper functions
	private void remove(ML_Node previous, ML_Node current) {
		if (previous == null) {
			// remove front of list
			first = current.next;
			if (last == current)
				last = null;
		} else if (current == last) {
			// remove end of list
			last = previous;
			last.next = null;
		} else {
			// remove interior node
			previous.next = current.next;
		}
		--theSize;
	}

}
