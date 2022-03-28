//Learning Kotlin from the W3Schools tutorial at https://w3schools.com/kotlin



//Comments use this convention
/*
"This convention" includes multiline comments as well.
*/



/*
How to run:
kotlinc [source].kt -include-runtime -d [result].jar [-verbose]
 -- official command
 -- only compiles. must run `java -jar [result].jar` to execute

compkot [source].kt [result].jar [-verbose]
 -- custom command made by me
 -- compiles, and executes if compilation is successful

kompile [source].kt [result].jar [-verbose]
 -- alias for `compkot`
*/


fun firstFunction() { //kinda
	println("This is the first function that's not `main()`!")
}

class Room {
	var size = 85 //all variables must be initialized
	var wallColor = "White"
	var furniture1 = "Table"
	var furniture2 = "Chair"
}

class Car(var brand: String, var model: String, var year: Int) //called a constructor -- variables cannot be initialized!

fun main(args: Array<String>) { //command line args!
//very fun

	//intro
	println("Hello world!")
	print("Kotlin")
	print(" has `println()` and `print()`.\n") //\n!

	//ANSI
	print("\u001b[42m") //set output highlight green  -- u+001b is unicode escape | also, no closing newline
	print("This is highlighted with ANSI") //print this -- it's green | also, no closing newline
	println("\u001b[49m") //reset output formatting | also, no closing newline -- all three of the last lines operate on the same line -- this one adds newline
	
	
	println("\n")


	//variables
	var variable1 = "This is the first variable" //types are inferred
	val variable2 = "This is a variable declared with `val`"
	println(variable1)
	println(variable2)
	variable1 = "Variables declared with `var` *can* be modified"
	println(variable1)
	//variable2 = "Cannot be changed"
	//variable1 = 284484              //types must remain consistent
	val declaredWithType: String      //when declaring without init, type "annotation" is required
	declaredWithType = "This was declared without initialization, then initialized later"
	println(declaredWithType)
	/*
	**types:**
	  Whole numbers:
		Byte
		Short
		Int -- default
		Long
	  Decimals:
		Float -- must have a decimal, or error | must have an `F` after the number, or else it will try, and fail, to make Double
		Double -- default | must have a decimal, or error
	  Character stuff
		Char -- single quotes | NO ASCII
		String  -- double quotes
	Boolean -- must be full word (`Bool` doesn't do the trick)
	*/
	var testLong = 50L //L tells the compiler to make it a Long, not Int
	println("testLong is a Long: " + testLong)
	/*
	Type conversion:
		toByte()
		toShort()
		toInt()
		toLong()
		toFloat()
		toDouble()
		toChar()
	*/

	

	println("\n")


	//operators
	/*Kotlin uses standard operators
	//arithmetic: +, -, *, /, %, ++, --
	//assignment: =, +=, -=, *=, /=, %=
	//comparison: ==, !=, >, <, >=, <=
	//logical: &&, ||, !
	*/



	//strings
	var aString = "I am a string"
	println(aString)
	print(aString[0])
	print(aString[1])
	print(aString[2])
	print(aString[3])
	print(aString[4])
	print(aString[7]) //purposeful skip
	print(aString[8])
	print(aString[9])
	print(aString[10])
	print(aString[11])
	print(aString[12])
	print("\n")
	println("length of `aString`: " + aString.length)
	println(aString.uppercase())
	println(aString.lowercase())
	var anotherString = "I am a string"
	var aThirdString = "I am not a string"
	println(aString.compareTo(anotherString))
	println(aString.compareTo(aThirdString))
	println(aThirdString.compareTo(aString))
	println(aString.indexOf("am"))
	var quoteString = "Quotes shouldn't be an issue. It is often said, \"Don't make more variables when you don't have to\""
	println(quoteString)
	println("This is the first part" + ", and this is the second part")
	println("This is the first part".plus(", and this is the second part"))
	println("Guess what? $aString! And I was printed with a \"template\"!")
	

	println("\n")


	//booleans
	//all standard stuff
	var stringsMatch = (aString == anotherString) //parentheses not strictly neccesary, but improve readability


	//if/else statements!
	//the good stuff!
	if (stringsMatch) //parentheses required
	{
	  println("The strings match!")
	}
	else
	{
	  println("The strings don't match!")
	}
	val time = 9
	if(time < 12) {
	  println("Morning (Before noon)")
	} else if(time < 19) {
	  println("Afternoon (After noon)")
	} else {
	  println("Nighttime (After sunset)")
	}
	val timeOfDay = if (time < 12) { "Morning" } else if (time < 19) { "Afternoon" } else { "Nighttime" }
	println(timeOfDay)
	//single line `if`s
	if (testLong > 49L) println("testLong is greater than 49L")
	

	println("\n")

  
	//when
	val day = 4
	println("The day is...")
	val result = when (day) {
		1 -> "Monday"
		2 -> "Tuesday"
		3 -> "Wednesday"
		4 -> "Thursday"
		5 -> "Friday"
		6 -> "Saturday"
		7 -> "Sunday"
		else -> "Invalid day."
	}
	println(result)
	when (day) {
		1 -> println("Monday")
		2 -> println("Tuesday")
		3 -> println("Wednesday")
		4 -> println("Thursday")
		5 -> println("Friday")
		6 -> println("Saturday")
		7 -> println("Sunday")
		else -> println("Invalid day.")
	}


	println("\n")


	var i = 0
	while (i < 10) {
		println("`while` Loop " + i)
		i++
	}
	do {
		println("`do`/`while` loop " + i)
		i++
	} while (i < 15)
	i = 0
	while (true) {
		i++
		if (i == 4) continue
		if (i == 8) break
		println("Looping forever..." + i)
	}


	println("\n")


	//arrays
	var apples = arrayOf("Gala", "Opal", "Granny Smith", "Green Delicious")
	println(apples[0] + " apples are delicious!")
	val cars = arrayOf("Volvo", "BMW", "Ford", "Mazda")
	val nums = arrayOf(1, 5, 10, 15, 20)
	apples[3] = "Fuji"
	cars[2] = "Mustang" //apparently `val` arrays can still be changed!
	println(apples)
	println(cars)
	println(nums)
	println("Array `cars` has " + cars.size + " values")
	//if ("Toyota" not in cars) { println("Toyota is not in cars!") }
	if ("Toyota" in cars) {
		println("Toyota is in cars!")
	} else {
		println("Toyota is not in cars!")
	}
	println("Apples:")
	for (apple in apples) {
		println(apple)
	}


	println("\n")


	//ranges
	for (i in 1..5) { //warns that `i` is "shadowed" because it is used earlier
		println(i)    //
	}
	println(i) //prints 8 from when i was being used earlier.
	for (letter in 'a'..'n') {
		print(letter)
	}
	println()
	//
	//miscelaneous stuff on the `ranges` page
	//`in` can also be used for comparison, as seen above
	if (15 in nums) {
		println("15 is in `nums`")
	} else {
		println("15 is NOT in `nums`")
	}
	//also `break` and `continue` can be used in a `for` obviously


	println("\n")

	//functions
	firstFunction() //declared above
	secondFunction() //declared below -- functions DO NOT NEED to be declared above
	firstFunWithParams("tutorial-reading person")
	multipleParams("Barbara", 55)
	println(functionThatReturns(5,7))
	println(anotherReturningFunction("These should be ", "concatenated")) //use shorter function names! this is ridiculous!
	println(shorthandReturn(15,9))


	println("\n")


	//OOP
	class Person {
		var firstName = "Joe"
		var lastName = "Smith"
		var age = 19
		var hairColor = "Brown"
	}
	val person1 = Person() //doesn't have to be `val`, but that's what the tutorial did, so i just went with it
	println(person1)
	println(person1.firstName)
	println(person1.lastName)
	println(person1.age)
	println(person1.hairColor)
	val person2 = Person()
	person2.firstName = "Alan"
	person2.lastName = "Turing"
	person2.age = 41
	//var person2.committedSuicide = false //cannot add properties
	println(person2)
	println(person2.firstName)
	println(person2.lastName)
	println(person2.age)
	println(person2.hairColor)
	val room1 = Room()
	println(room1)
	println(room1.size)
	println(room1.wallColor)
	println(room1.furniture1)
	println(room1.furniture2)
	val myCar = Car("Toyota", "Prius", 2007) //constructor
	val yourCar = Car("Honda","Civic",2012) //wow easier
	yourCar.year = 2010
	println(myCar)
	println(yourCar)






	println("\n")


	//random
	print("Semicolons are optional");println(", see?");
	//cli args
	if (args.size > 1) {
		println("Ladies and Gentlemen, your ARGUMENTS!")
		for (i in args) {
			print("\t")
			println(i)
		}
		println("*audience applause*")
	} else { println("There are no arguments") }
	/*
	//hack to get dimensions of terminal -- very finnicky
	print("\u001b[s\u001b[5000;5000H") //save position and move to (5000,5000)
	//System.out.flush()
	//print("\u001b[6n")
	var termSize = "\u001b[6n" //gets position WHEN OUTPUTTED, NOT WHEN INITIALIZED
	println(termSize)
	//System.out.flush()
	println("\u001b[u\n")
	*/

}

fun secondFunction() {
	println("This is the third function really!")
}

fun firstFunWithParams(nname: String) { //type needs to be declared, or else it's not a variable!
	println("Nice to meet you, " + nname + "!")
}

fun multipleParams(name:String, age:Int) {
	println(name + " is " + age + " years old")
}

fun functionThatReturns(firstNum:Int, secondNum:Int):Int { //return value type declaration required
	return firstNum + secondNum
}

fun anotherReturningFunction(firstString:String, secondString:String):String { //return value type declaration required for all data types
	var result = firstString + secondString
	return result
}

fun shorthandReturn(x:Int,y:Int) = x - y
