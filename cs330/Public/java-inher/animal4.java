public class AnimalTest {

  private static void show (String s1, String s2) {
     System.out.println (s1 + " " + s2);
  }

  public static void main (String[]) {
     Animal a = new Animal();
     Herbivore h = new Herbivore();
     Ruminant r = new Ruminant();

     Animal paa = a;
     Animal pah = h;
     Animal par = r;
     
     show(a.name(), a.eats());      // Animal ???
     show(paa.name(), paa.eats()); // Animal ???
     show(h.name(), h.eats);        // Herbivore plants
     /*+1*/show(pah.name(), pah.eats());/*-1*/ // AHRC ?pgm
     show(par.name(), par.eats()); //AHRC ?pgm
  }
}
