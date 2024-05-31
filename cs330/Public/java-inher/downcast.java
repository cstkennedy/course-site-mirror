 ArrayList animals = new ArrayList();
    //...
 for (Object obja: animals) {
     Animal a = /*+1*/(Animal)obja/*-1*/;
    System.out.println (a.name() + " " + a.eats());
 }