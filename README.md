# Cplusplus210

# Project 3 - Organize a list of produce items from text file
  This project takes a list of produce items from a file and organizes them into another file using Python. The new list
  displays each individual item and how many times said item appears in the list. Program has the ability to display 
  whole list using numbers, using a histogram list, and ability to search for specific items with corresponding amount 
  of times said item appears in list. This program uses both C++ and Python languages. 
  
# What did you do particularly well?
  The user interface is very user friendly, displaying an option to repeat the programs functions to user in case the 
  information gets lost from the screen. Using Python to open the given file and organize into an ordered list is very 
  fast and efficent and the C++ language allows for speedy user interaction. I believe the functionality of this program
  is very efficent. I changed the code in the C++ functions calling Python so the program can repeat until the user 
  wishes to end the program. I also put the list in alphabetical order to be more aesthetically pleasing.
  
# Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
  I appempted to make a function to load the file in Python and create a list to work off of, essentially only opening 
  the file once. The program would open the file, create a list and organize it, and then close the file. When I called
  on the newly created list, the list was empty. There must be a way to do this, but for a simple fix I opened the file
  and created a list each time it is called. Basically opening a file, creating a list and then closing the file every 
  time. Only opening the file and creating the list once, before the user interface is even displayed, would make the 
  program run faster and smoother. 
  
# Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
  Calling the Python functions from C++ seemed to be the most challenging. At first the functions were non-void. C++
  would call the Python function, Python would return a value and terminate the program. Thus forcing the user to open
  the program from scratch after every entry. To fix this, I changed these functions to void and printing the values to
  the screen in Python. Thus creating the same effect, but allowing C++ to continue afterwards. 

# What skills from this project will be particularly transferable to other projects or course work?
  Integrating two languages can be extremely useful. Every language has its strengths and weaknesses. The ability to
  combine these languages to get the best of the best will surely come in handy in the future. The speed to crunch
  numbers with Python and the speed from C++ to make changes on the go proved to make a fast and smooth program.
  
# How did you make this program maintainable, readable, and adaptable?
  Comments, comments, and more comments. Explaining what each functions does and how it does it is key for other
  programmers to read my code and know exactly what each functions purpose is. In the future, using better practices
  such as naming functions and variables in the "universal" syntax will improve the readability even further. Such as 
  naming variables with lowerAndThenUppercase letters and functions with UppercaseAtBegining. 


