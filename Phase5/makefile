JFLAGS = -g
SOURCES = -cp junit-4.12.jar:hamcrest-core-1.3.jar
JC = javac
.SUFFIXES: .java .class
.java.class:
	$(JC) $(JFLAGS) $*.java

CLASSES = \
	FileReader.java \
	FileWriter.java \
	Transactions.java \
	Main.java \
	TransactionTest.java \
	FileWriterTest.java \
	FileReaderTest.java


default: 
	$(JC) $(JFLAGS) $(SOURCES) $(CLASSES)

run:
	#java -cp "junit-4.12.jar::"hamcrest-core-1.3.jar org.junit.runner.JUnitCore FileWriterTest
	#java org.junit.runner.JUnitCore TransactionTest
	java org.junit.runner.JUnitCore FileReaderTest

classes: $(CLASSES:.java=.class)

clean:
	$(RM) *.class