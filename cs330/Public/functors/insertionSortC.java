  public static void
      insertionSort (/*+*/Comparable/*-*/[] array)
   {
     for (int i = 1; i < array.length; ++i) {
        /*+*/Comparable/*-*/ temp = array[i];
        int p = i;
        while ((p > 0)
          && /*+*/temp.compareTo(array[p-1])/*-*/ < 0) {
           array[p] = array[p-1];
           p--;
        }
        array[p] = temp;
     }
   }
