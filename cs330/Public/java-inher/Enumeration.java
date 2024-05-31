package java.util; 
 
/** 
 * An object that implements the Enumeration interface generates a  
 * series of elements, one at a time. Successive calls to the  
 * nextElement method return successive elements of the  
 * series.  
 *  
 * For example, to print all elements of a vector <i>v</i>: 
 *  
 *     for (Enumeration e = v.elements() ; e.hasMoreElements() ;) { 
 *         System.out.println(e.nextElement()); 
 *     } 
 *  
 */  
 
public interface Enumeration { 
    /** 
     * Tests if this enumeration contains more elements. 
     */ 
    boolean hasMoreElements(); 
 
    /** 
     * Returns the next element of this enumeration. 
     */ 
    Object nextElement(); 
} 
