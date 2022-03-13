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



fun main() {
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
    **types:**'
    Byte
    Int
    Double -- must have a decimal, or error
    Char
    Boolean -- must be full word (`Bool` doesn't do the trick)
    String
    */
    var tester = 50L
    println(tester)

        


    println("\n")


    //random
    print("Semicolons are optional");print(", see?")

    println()
}

