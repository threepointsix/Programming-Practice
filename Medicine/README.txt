1. Iterator

	1.1. Created a new interface IDatabase, which declares only one method Iterate(). 
	1.2. Client may iterate through databases by using this interface only, without knowing the actual type of database. 	
	1.3. Any new database must implement IDatabase, and eventually implement Iterate() method.
	1.4. Created a new interface IGenomeDatabase, common for all GenomeDatabases. Now, to create a new GenomeDatabase, it should just implement this interface.
	1.5. Also there is an option to implement SimpleGenomeDatabase as Singleton, but changing public access modifier of constructor is prohibited. And Singleton class must have private constructor...
	1.6. Passed genomeDatabase as an argument in MediaOutlet constructor. Different approach would be to pass genomeDatabase as an argument in Publish() method. Although in the second case, some boilerplate code would occur.

2. Decorator

	2.1. Created IDecorator interface, which implements IDatabase.
	2.2. IDecorator interface contains IDatabase Database property, according to the design pattern.
	2.3. All decorators overload Iterate method from the stage 1. At the same time, inside overloading I used Database.Iterate. Everything works thanks to polymorphism.

3. Visitor

	3.1. ISubject are Elements and IVaccine are visitors. So it is easy to add new vaccines, but to add new subjects the existing code must be modified.

4. Test

	4.1. Just added an iterator over simple database in Program.cs:L59