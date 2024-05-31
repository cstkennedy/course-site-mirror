package SpreadSheetJ.Model;


/**
 * Numeric values in the spreadsheet.
 */
public class NumericValue extends Value
{
    private double d;
    private static final String theValueKindName = "Numeric";

    public NumericValue()
    {
        this.d = 0.0;
    }

    public NumericValue(double x)
    {
        this.d = x;
    }

    /**
     * The string used to identify numeric value kinds.
     */
    public static String valueKindName()
    {
        return theValueKindName;
    }

    /**
     * Indicates what kind of value this is. For any two values, v1 and v2,
     * v1.valueKind() == v2.valueKind() if and only if they are of the
     * same kind (e.g., two numeric values). The actual character string
     * pointed to by valueKind() may be anything, but should be set to
     * something descriptive as an aid in identification and debugging.
     */
    public String valueKind()
    {
      return theValueKindName;
    }

    /**
     * Produce a string denoting this value such that the
     * string's length() <= maxWidth (assuming maxWidth > 0)
     * If maxWidth==0, then the output string may be arbitrarily long.
     * This function is intended to supply the text for display in the
     * cells of a spreadsheet.
     */
    public String render(int maxWidth)
    {
        String rendering = "" + d;

        if (rendering.indexOf('.') >= 0
         && rendering.indexOf('E') < 0
         && rendering.indexOf('e') < 0) {
            while (rendering.charAt(rendering.length()-1) == '0') {
                rendering = rendering.substring(0, rendering.length()-1);
            }

            if (rendering.charAt(rendering.length()-1) == '.') {
                rendering = rendering.substring(0, rendering.length()-1);
            }
        }

        if (maxWidth > 0 && rendering.length() > maxWidth) {
            String discarded = rendering.substring(maxWidth);
            rendering = rendering.substring(0, maxWidth);
            if (discarded.indexOf('.') >= 0) {
                // We have a problem - can't fit the decimal point into
                // the allowed width
                rendering = "****************************";
                rendering = rendering.substring(0, maxWidth);
            }
        }
        return rendering;
    }

    public Object clone()
    {
        return new NumericValue(this.d);
    }

    public double getNumericValue()
    {
        return this.d;
    }

    /**
     * pre: valueKind() == v.valueKind()
     *
     * @return true iff this value is equal to v, using a comparison
     * appropriate to the kind of value.
     */
    boolean isEqual(Value v);
    {
        NumericValue nv = (NumericValue)v;
        return this.d == nv.d;
    }
}
