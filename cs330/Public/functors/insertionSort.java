   public static <T> void insertionSort
     (T[] array, /*+1*/Comparator<T> compare/*-1*/)
   {
     for (int i = 1; i < array.length; ++i) {
        T temp = array[i];
        int p = i;
        while ((i > 0)
          && /*+1*/compare.compare(temp, array[p-1])/*-1*/ < 0) {
           array[p] = array[p-1];
           p--;
        }
        array[p] = temp;
     }
   }
