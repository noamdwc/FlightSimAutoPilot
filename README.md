# FlightSimAutoPilot
An interpreter for a domain specific language that is used to control the FlightGear simulator.
The language control the simulator via a group of variables that exists in both the simulator and the language.
It start with 23 such variables, and more could be add by binding them to values that exists in the simulator.
The interpreter can interpret a script if run with the script path, or line by line from the console.


The language is based on the "Command" design pattern, with the following commands:
* **new var command:** <br />
      Create a new variable with a vlaue of double.
      

* **print command:**<br />
      Print text or values to the console.<br />
      when given a variable it will print it's value.<br />
      when given an input that is in quotes, it will print all the text that in the quotes.
`

* **var assign command:**<br />
      Give a var a new value


* **openDataServer command:**<br />
      Open server to listion to incoming updates form the simulator.<br />
      The input is the port the server will listen to, and the frequency it will read the data.


* **connect command:**<br />
      Connect to the simulator's server.<br />
      This connection will be used to update it about changes in variables that were bined


* **if command:**<br />
      Check if the a given expression is not 0.<br />
      If it is'nt it will run the script that inside the code block that follows it.



* **while command:**<br />
      Check if the a given expression is not 0.<br />
      If it is'nt it will run the script that inside the code block that follows it.<br />
      Then repeat it until the expression is 0.<br />
      <br />
  *Both if and while commands are recursive. meaning you can have a while inside a while, or if with while in it and so on..*


* **sleep command:**<br />
      Make the main thread to sleep x milliseconds, when x is the input


The interpreter also support assigning complex expression, like: ```var example = (3*3/3)-3 <= 0```
