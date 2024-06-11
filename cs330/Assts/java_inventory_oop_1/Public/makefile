# Gradle Wrapper Makefile

ASSIGNMENT=Storage
REPO_NAME=2024-Summer-CS330-Java-Inventory-OOP-1-main

all:
	chmod a+rx gradlew
	./gradlew test jar

test:
	./gradlew test

retroguard:
	./gradlew jar
	cp  build/libs/$(ASSIGNMENT).jar temp.jar
	java -cp .:/home/zeil/src/retroguard/retroguard.jar RetroGuard temp.jar $(ASSIGNMENT)-obfuscated.jar
	rm temp.jar

run: $(ASSIGNMENT).jar
	chmod a+rx gradlew
	./gradlew run

clean:
	chmod a+rx gradlew
	./gradlew clean

gradingNoRename:
	unzip main.zip
	mv $(REPO_NAME)/* .
	cp Armour.java Consumable.java src/main/java/edu/odu/cs/cs330/items/
	chmod a+rx gradlew
	./gradlew --no-daemon jar test
	-rm -r -f .gradle




