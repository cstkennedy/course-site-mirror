class Animal {
public:
  String eats() {return "food";}
  String name() {return "Animal";}
};

class Herbivore: public Animal {
public:
   String eats() {return "plants";}
   String name() {return "Herbivore";}
};

class Ruminants: public Herbivore {
public:
   String name() {return "Ruminant";}
};

class Carnivore: public Animal {
public:
   String name() {return "Carnivore";}
};

void show (String s1, String s2) {
    cout << s1 << " " << s2 << endl;
}
