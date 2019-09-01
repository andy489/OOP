# StateMachine
Проект 4: Недетерминиран краен автомат

Да се реализира програма, която поддържа операции с недетерминиран краен автомат над азбука, състояща се от цифрите и малките латински букви. 

Operations available:

- reg \<regex> - Creates a state machine for the regular expression.
- open \<filename> - Loads a state machine from the file.
- list - Prints the id and regular expression of all loaded state machines.
- print \<id> - Prints detailed information about the selected state machine.
- save \<id> \<filename> - Erases the whole file and saves the selected state machine.
- empty \<id> - Checks if the language of the state machine language is empty.
- deterministic \<id> - Checks if the selected state machine is deterministic.
- recognize \<id> \<word> - Checks if the selected state machine recognizes the word.
- union \<id1> \<id2> - Creates a new state machine that recognizes the union of the languages of the selected state machines
- concat \<id1> \<id2> - Creates a new state machine that recognizes the concatenations of the languages of the selected state machines
- un \<id> - Creates a new state machine that recognizes the iteration of the selected state machine.
- minimize \<id> - Minimizes the selected state machine.
- determinate \<id> - Determinates the selected state machine.
- reverse \<id> - Reverses the language of the selected state machine.
- language \<id> - Prints the language of the selected state machine.
- finite \<id> - Checks if the language of the selected state machine is finite.
- close - Closes the program.
