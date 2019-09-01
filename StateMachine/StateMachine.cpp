#include <vector>
#include <unordered_map>
#include <ctype.h>
#include <iostream>
#include <stack>
#include <queue>
#include "StateMachine.h"

void PrintInvalidInput()
{
	std::cout << "Invalid input. Creating an empty state machine!\n";
}

//public:
int IndexOfStateUnion(std::vector<StateUnion*> vector, const StateUnion& state)
{
	for (unsigned i = 0; i < vector.size(); i++)
	{
		if ((*(vector[i])) == state)
		{
			return i;
		}
	}
	return -1;
}

bool ValidateRegex(String regex)
{
	char t;
	int len = regex.Length();
	bool isPreviousSpecialSymbol = false;
	for (int i = 0; i < len; i++)
	{
		t = regex[i];
		if (t == '|' || t == '*')
		{
			if (isPreviousSpecialSymbol)
			{
				return false;
			}
			isPreviousSpecialSymbol = true;
			continue;
		}
		if (t == '(' || t == ')')
		{
			isPreviousSpecialSymbol = false;
			continue;
		}
		if (isalpha(t) || isdigit(t))
		{
			isPreviousSpecialSymbol = false;
			continue;
		}
		return false;
	}

	std::stack<char> stack;
	for (int i = 0; i < len; i++)
	{
		t = regex[i];
		if (t == '(')
		{
			stack.push('(');
			continue;
		}
		if (t == ')')
		{
			if (stack.size() == 0)
			{
				return false;
			}
			stack.pop();
		}
	}

	if (stack.size() != 0)
	{
		return false;
	}
	return true;
}

StateMachine::StateMachine()
{
	this->regex = String();
	this->isReversed = false;
}

StateMachine::StateMachine(char letter)
{
	this->regex = String(letter);

	State* startState = new State();
	State* endState = new State(true);

	AddState(startState);
	AddState(endState);

	this->starts.push_back(this->IndexOfState(startState));
	this->currentState = this->starts[0];
	startState->AddTransition(Transition(letter, IndexOfState(endState)));
	this->isDeterministic = true;
	this->isReversed = false;
}

StateMachine::StateMachine(String regex)
{
	if (!ValidateRegex(regex))
	{
		std::cerr << "Invalid regex. Creating an empty state machine\n";
		*this = StateMachine();
		return;
	}

	if (regex.Length() == 0)
	{
		*this = StateMachine(' ');
		return;
	}
	if (!(regex.ContainsAny(SpecialSymbols, strlen(SpecialSymbols))))
	{
		StateMachine newMachine(regex[0]);
		for (int i = 1; i < regex.Length(); i++)
		{
			newMachine = newMachine.Concatenate(StateMachine(regex[i]));
		}
		*this = newMachine;
		this->isReversed = false;
		return;
	}
	regex = this->RegexToRPN(regex);
	*this = this->Calculate(regex);
	this->isDeterministic = this->CheckIfDeterministic();
	this->isReversed = false;
}

StateMachine::StateMachine(const StateMachine& other)
{
	CopyStateMachine(*this, other);
}

StateMachine::StateMachine(std::ifstream& is)
{
	if (!is.is_open())
	{
		std::cout << "Invalid file name. Creating an empty state machine!\n";
		*this = StateMachine();
		return;
	}
	is >> this->regex;
	if (this->regex.ContainsAny("^R", 2))
	{
		this->regex = this->regex.Substring(0, this->regex.Length() - 2);
		this->isReversed = true;
	}
	String temp;
	is >> temp;
	auto args = temp.Split();
	if (!args[args.size() - 1].TryParseToInt())
	{
		PrintInvalidInput();
		*this = StateMachine();
		return;
	}
	int maxStartStateIndex = args[args.size() - 1].ToInt();
	//add start states indexes
	for (unsigned i = 0; i < args.size(); i++)
	{
		if (!args[i].TryParseToInt())
		{
			PrintInvalidInput();
			*this = StateMachine();
			return;
		}
		this->starts.push_back(args[i].ToInt());
	}

	is >> temp;
	args = temp.Split();
	if (args.size() == 0)
	{
		PrintInvalidInput();
		*this = StateMachine();
		return;
	}
	//add all states until the last final
	if (!args[args.size() - 1].TryParseToInt())
	{
		PrintInvalidInput();
		*this = StateMachine();
		return;
	}
	int finalStatesMaxIndex = args[args.size() - 1].ToInt();
	if (maxStartStateIndex < finalStatesMaxIndex)
	{
		maxStartStateIndex = finalStatesMaxIndex;
	}
	int counter = 0;
	int i = 0;
	while (i <= finalStatesMaxIndex)
	{
		if (!args[counter].TryParseToInt())
		{
			PrintInvalidInput();
			*this = StateMachine();
			return;
		}
		if (i == args[counter].ToInt())
		{
			this->AddState(new State(true));
			counter++;
		}
		else
		{
			this->AddState(new State());
		}
		i++;
	}
	while (i <= maxStartStateIndex)
	{
		this->AddState(new State());
		i++;
	}

	//add transitions and states not added yet	
	char ch;
	while (is.get(ch))
	{
		is >> temp;
		temp.InsertAt(0, ch);

		args = temp.Split();
		if (args.size() != 3)
		{
			PrintInvalidInput();
			*this = StateMachine();
			return;
		}
		char letter = args[1][0];
		if (!args[2].TryParseToInt() || !args[0].TryParseToInt())
		{
			PrintInvalidInput();
			*this = StateMachine();
			return;
		}
		int index = args[2].ToInt();
		this->states[args[0].ToInt()]->AddTransition(Transition(letter, index));
		while (index > (int)this->states.size() - 1)
		{
			this->AddState(new State());
		}
	}
	this->isDeterministic = CheckIfDeterministic();
}

StateMachine::~StateMachine()
{
	DeleteStateMachine(*this);
}

StateMachine& StateMachine::operator=(const StateMachine& other)
{
	DeleteStateMachine(*this);
	CopyStateMachine(*this, other);
	return *this;
}

bool StateMachine::Recognize(String word)
{
	for (unsigned i = 0; i < this->starts.size(); i++)
	{
		this->currentState = this->starts[i];
		if (this->RecognizeHelper(word))
		{
			return true;
		}
	}
	return false;
}

bool StateMachine::IsLanguageEmpty() const
{
	return this->regex == "";
}

bool StateMachine::IsDeterministic() const
{
	return this->isDeterministic;
}

bool StateMachine::IsLanguageFinite() const
{
	if (this->regex.ContainsAny("*", 1))
	{
		return false;
	}
	return true;
}

StateMachine StateMachine::Union(const StateMachine& other) const
{
	if (this == &other)
	{
		return *this;
	}
	StateMachine newMachine(*this);
	newMachine.regex.Append(String(String("|") + other.regex));

	// the new start is also an end if any of the old starts are end
	bool isFinal = this->HasFinalStartState() || other.HasFinalStartState();
	State* newStart = new State(isFinal);
	newMachine.AddState(newStart);

	//add all states from the other machine
	std::unordered_map<int, int> oldStatesToNew;
	newMachine.TransferStates(other, oldStatesToNew);

	//add the functionality for the new states
	newMachine.AddMappedTransitions(other, oldStatesToNew, this->states.size() + 1);

	//Make the new start do the work of the old start of this
	std::vector<Transition> temp;
	for (unsigned k = 0; k < this->starts.size(); k++)
	{
		newStart->AddFunctionality(this->states[this->starts[k]]);
	}

	//Make the new start do the work of the starts of other
	for (unsigned k = 0; k < other.starts.size(); k++)
	{
		newStart->AddMappedFunctionality(other.states[other.starts[k]], oldStatesToNew);
	}

	newMachine.starts.clear();
	newMachine.starts.push_back(newMachine.IndexOfState(newStart));
	newMachine.currentState = newMachine.IndexOfState(newStart);
	newMachine.RemoveUnreachableStates();
	newMachine.isDeterministic = newMachine.CheckIfDeterministic();
	return newMachine;
}

StateMachine StateMachine::Concatenate(const StateMachine& other) const
{
	StateMachine newMachine(*this);
	newMachine.regex.Append(other.regex);

	//add all states from the other machine
	std::unordered_map<int, int> oldStatesToNew;
	newMachine.TransferStates(other, oldStatesToNew);

	//add the functionality for the new states
	newMachine.AddMappedTransitions(other, oldStatesToNew, this->states.size());

	//make the final states of the first do the work of the start of the second
	int endStatesCount = this->finalStates.size();
	std::vector<Transition> temp;
	for (int i = 0; i < endStatesCount; i++)
	{
		for (unsigned k = 0; k < other.starts.size(); k++)
		{
			newMachine.finalStates[i]->AddMappedFunctionality(other.states[other.starts[k]], oldStatesToNew);
		}
	}

	//the final states remain final if the start of the second was final
	if (!other.HasFinalStartState())
	{
		for (unsigned i = 0; i < this->finalStates.size(); i++)
		{
			newMachine.finalStates[i]->AddFunctionality(State(false), true);
		}
	}
	newMachine.isDeterministic = newMachine.CheckIfDeterministic();
	return newMachine;
}

StateMachine StateMachine::Iteration() const
{
	StateMachine newMachine(*this);

	// change regex
	if (this->regex.Length() == 1)
	{
		newMachine.regex = this->regex + "*";
	}
	else
	{
		newMachine.regex = "(" + this->regex + ")*";
	}
	State* newState = new State(true);
	newMachine.AddState(newState);

	//all final states do the work of the start states
	int endStatesCount = newMachine.finalStates.size();
	std::vector<Transition> t;
	for (unsigned k = 0; k < this->starts.size(); k++)
	{
		t = this->states[this->starts[k]]->GetAllTransitions();
		for (int i = 0; i < endStatesCount; i++)
		{
			for (unsigned j = 0; j < t.size(); j++)
			{
				if (!newMachine.finalStates[i]->HasTransition(t[j]))
				{
					newMachine.finalStates[i]->AddTransition(t[j]);
				}
			}
		}
	}

	newMachine.starts.clear();
	newMachine.starts.push_back(this->IndexOfState(newState));
	newMachine.currentState = newMachine.starts[0];
	newMachine.RemoveUnreachableStates();
	newMachine.isDeterministic = newMachine.CheckIfDeterministic();
	return newMachine;
}

String StateMachine::GetRegex() const
{
	if (isReversed)
	{
		return this->regex + "^R";
	}
	return this->regex;
}

void StateMachine::Determinate()
{
	if (this->isDeterministic)
	{
		return;
	}
	StateMachineDeterminizator* a = new StateMachineDeterminizator();
	a->Determinate(this);
	delete a;
	this->isDeterministic = true;
}

void StateMachine::Reverse()
{
	StateMachine newMachine;
	unsigned startsCounter = 0;
	for (unsigned i = 0; i < this->states.size(); i++)
	{
		State* state = new State();
		if (startsCounter < this->starts.size() && this->starts[startsCounter] == i)
		{
			startsCounter++;
			state->AddFunctionality(State(true), true);
		}
		if (this->states[i]->IsFinal())
		{
			newMachine.starts.push_back(i);
		}
		newMachine.AddState(state);

	}
	std::vector<Transition> t;
	int index;
	char letter;
	for (unsigned i = 0; i < this->states.size(); i++)
	{
		t = this->states[i]->GetAllTransitions();
		for (unsigned j = 0; j < t.size(); j++)
		{
			index = t[j].Transist();
			letter = t[j].GetLetter();
			newMachine.states[index]->AddTransition(Transition(letter, i));
		}
	}
	newMachine.regex = this->regex;
	newMachine.isReversed = this->isReversed;
	*this = newMachine;
	this->isReversed = !this->isReversed;
	this->isDeterministic = this->CheckIfDeterministic();
}

void StateMachine::Minimize()
{
	this->Determinate();
	this->Reverse();
	this->Determinate();
	this->Reverse();
	this->Determinate();
}

void StateMachine::Print() const
{
	this->ToString().Print();
}

String StateMachine::ToString() const
{
	String result;
	result.AppendLine(this->GetRegex());

	//add start states indexes
	for (unsigned i = 0; i < this->starts.size(); i++)
	{
		char ch[15];
		_itoa_s(this->starts[i], ch, 10);
		String temp(ch);
		temp.Append(" ");
		result.Append(temp);
	}
	result.AppendLine("");

	//add final states
	for (unsigned i = 0; i < this->states.size(); i++)
	{
		if (this->states[i]->IsFinal())
		{
			char ch[15];
			_itoa_s(i, ch, 10);
			String temp(ch);
			temp.Append(" ");
			result.Append(temp);
		}
	}
	result.AppendLine("");

	//add transitions
	result.Append(this->TransitionsToString());
	return result;
}

String StateMachine::TransitionsToString() const
{
	String result;
	for (unsigned i = 0; i < this->states.size(); i++)
	{
		std::vector<Transition> t = this->states[i]->GetAllTransitions();
		for (unsigned j = 0; j < t.size(); j++)
		{
			char ch[15];
			_itoa_s(i, ch, 10);
			String temp((ch));
			temp.Append(" ");
			temp.AppendLine(t[j].ToString());
			result.Append(temp);
		}
	}
	return result;
}

//private:
void StateMachine::AddState(State* state)
{
	if (state->IsFinal())
	{
		this->finalStates.push_back(state);
	}
	this->states.push_back(state);
}

void StateMachine::CopyStateMachine(StateMachine& dest, const StateMachine& source)
{
	dest.regex = source.regex;
	dest.starts = source.starts;
	dest.isDeterministic = source.isDeterministic;
	dest.isReversed = source.isReversed;
	int size = source.states.size();
	for (int i = 0; i < size; i++)
	{
		State* t = new State(source.states[i]);
		if (t->IsFinal())
		{
			dest.finalStates.push_back(t);
		}
		dest.states.push_back(t);
	}
	dest.RemoveUnreachableStates();
}

void StateMachine::DeleteStateMachine(StateMachine& machine)
{
	for (unsigned i = 0; i < machine.states.size(); i++)
	{
		delete machine.states[i];
	}
	int size = this->states.size();
	for (int i = 0; i < size; i++)
	{
		this->states.pop_back();
	}
	size = this->finalStates.size();
	for (int i = 0; i < size; i++)
	{
		this->finalStates.pop_back();
	}
	size = this->starts.size();
	for (int i = 0; i < size; i++)
	{
		this->starts.pop_back();
	}
}

void StateMachine::RemoveUnreachableStates()
{
	std::vector<int> deletedStatesIndexes = this->GetUnreachableStatesIndexes();
	for (size_t i = 0; i < deletedStatesIndexes.size(); i++)
	{
		delete this->states[deletedStatesIndexes[i]];
		this->states.erase(this->states.begin() + deletedStatesIndexes[i]);
	}

	this->MapTransitionsToNewIndexes(deletedStatesIndexes);
}

void StateMachine::MapTransitionsToNewIndexes(std::vector<int> deletedStatesIndexes)
{
	State* temp;
	std::vector<Transition> transitions;
	for (unsigned k = 0; k < deletedStatesIndexes.size(); k++)
	{
		for (unsigned i = 0; i < this->starts.size(); i++)
		{
			if (deletedStatesIndexes[k] < this->starts[i])
			{
				this->starts[i]--;
			}
		}
		if (deletedStatesIndexes[k] < this->currentState)
		{
			this->currentState--;;
		}
		for (unsigned i = 0; i < this->states.size(); i++)
		{
			temp = this->states[i];
			transitions = temp->GetAllTransitions();
			bool needsChange = false;
			for (unsigned j = 0; j < transitions.size(); j++)
			{
				if (transitions[j].Transist() > deletedStatesIndexes[k])
				{
					needsChange = true;
					break;
				}
			}
			if (needsChange)
			{
				State modifiedState(temp->IsFinal());
				for (unsigned g = 0; g < transitions.size(); g++)
				{
					Transition trans = transitions[g];
					if (transitions[g].Transist() > deletedStatesIndexes[k])
					{
						modifiedState.AddTransition(Transition(trans.GetLetter(), trans.Transist() - 1));
					}
					else
					{
						modifiedState.AddTransition(trans);
					}
				}

				*temp = modifiedState;
			}
		}
	}
}

void StateMachine::TransferStates(const StateMachine& other, std::unordered_map<int, int>& oldStatesToNew)
{
	std::vector<State*> tempState = other.states;
	for (unsigned i = 0; i < other.states.size(); i++)
	{
		State* t = new State(tempState[i]->IsFinal());
		oldStatesToNew[other.IndexOfState(tempState[i])] = this->states.size();
		this->AddState(t);
	}
}

bool StateMachine::HasFinalStartState() const
{
	bool isFinal = false;
	for (unsigned i = 0; i < this->starts.size() && !isFinal; i++)
	{
		isFinal = isFinal || this->states[this->starts[i]]->IsFinal();
	}
	return isFinal;
}

void StateMachine::AddMappedTransitions(const StateMachine& other, std::unordered_map<int, int>& oldStatesToNew, int startIndex)
{
	for (unsigned i = 0; i < other.states.size(); i++)
	{
		std::vector<Transition> temp = other.states[i]->GetAllTransitions();
		for (unsigned j = 0; j < temp.size(); j++)
		{
			Transition t(temp[j].GetLetter(), oldStatesToNew[temp[j].Transist()]);
			this->states[i + startIndex /*this->states.size()+1*/]->AddTransition(t);
		}
	}
}

//Creates a state machine using regular expression in reverse polish notation
StateMachine StateMachine::Calculate(String expr)
{
	std::stack<StateMachine> machines;
	for (int i = 0; i < expr.Length(); i++)
	{
		char t = expr[i];
		if (t == '|')
		{
			StateMachine a = machines.top();
			machines.pop();
			StateMachine b = machines.top();
			machines.pop();
			StateMachine un = b.Union(a);
			machines.push(un);
		}
		else if (t == '.')
		{
			StateMachine a = machines.top();
			machines.pop();
			StateMachine b = machines.top();
			machines.pop();
			StateMachine res = b.Concatenate(a);
			res.RemoveUnreachableStates();
			machines.push(res);
		}
		else if (t == '*')
		{
			StateMachine a = machines.top();
			machines.pop();
			machines.push(a.Iteration());
		}
		else
		{
			machines.push(StateMachine(t));
		}
	}
	while (machines.size() > 1)
	{
		StateMachine a = machines.top();
		machines.pop();
		StateMachine b = machines.top();
		machines.pop();
		StateMachine res = b.Concatenate(a);
		res.RemoveUnreachableStates();
		machines.push(res);
	}

	return machines.top();
}

int StateMachine::IndexOfState(const State* state) const
{
	return std::find(this->states.begin(), this->states.end(), state) - this->states.begin();
}

struct Operator
{
	char ch;
	int priority;
	Operator(char ch)
	{
		this->ch = ch;
		if (ch == '|')
		{
			this->priority = 1;
		}
		else if (ch == '.')
		{
			this->priority = 2;
		}
	}
	bool operator>(Operator& other)
	{
		return this->priority > other.priority;
	}
};

//Shunting-yard algorithm
String StateMachine::RegexToRPN(String regex) const
{
	std::queue<char> output;
	std::stack<Operator> operations;
	String newRegex = this->AddConcatenationOperator(regex);
	char curr;
	for (int i = 0; i < newRegex.Length(); i++)
	{
		curr = newRegex[i];
		if (isalpha(curr) || isdigit(curr))
		{
			output.push(curr);
		}
		else if (curr == '(')
		{
			operations.push(curr);
		}
		else if (curr == ')')
		{
			while (operations.top().ch != '(')
			{
				output.push(operations.top().ch);
				operations.pop();
			}
			operations.pop();
		}
		else if (curr == '*')
		{
			output.push(curr);
		}
		else
		{
			Operator op(curr);
			if (operations.size() == 0 || op > operations.top())
			{
				operations.push(op);
			}
			else
			{
				while (!(operations.size() == 0 || operations.top().ch == '(' || op > operations.top()))
				{
					output.push(operations.top().ch);
					operations.pop();
				}
				operations.push(op);
			}
		}
	}
	while (operations.size() > 0)
	{
		output.push(operations.top().ch);
		operations.pop();
	}
	String result;

	while (output.size() > 0)
	{
		result.Append(output.front());
		output.pop();
	}
	return result;
}

//TODO implement the proper recursive algorithm
std::vector<int> StateMachine::GetUnreachableStatesIndexes() const
{
	int size = this->states.size();
	bool* isStateReachable = new bool[size];
	for (int i = 0; i < size; i++)
	{
		isStateReachable[i] = false;
	}
	for (unsigned i = 0; i < this->starts.size(); i++)
	{
		isStateReachable[this->starts[i]] = true;
	}
	std::vector<Transition> t;
	for (int i = 0; i < size; i++)
	{
		t = this->states[i]->GetAllTransitions();
		for (unsigned j = 0; j < t.size(); j++)
		{
			isStateReachable[t[j].Transist()] = true;
		}
	}
	std::vector<int> UnreachableStatesIndexes;
	for (int i = size - 1; i >= 0; i--)
	{
		if (!isStateReachable[i])
		{
			UnreachableStatesIndexes.push_back(i);
		}
	}
	delete[] isStateReachable;
	return UnreachableStatesIndexes;
}

String StateMachine::AddConcatenationOperator(String regex) const
{
	bool isPreviousLetter = false;
	bool isPreviousRightBracket = false;
	bool isPreviousIteration = false;
	bool isLetter = false;
	bool isCurrentLeftBracket = false;
	for (int i = 0; i < regex.Length(); i++)
	{
		isLetter = isalpha(regex[i]) || isdigit(regex[i]);
		isCurrentLeftBracket = regex[i] == '(';
		isPreviousLetter = isalpha(regex[i - 1]) || isdigit(regex[i - 1]);
		if (((isPreviousLetter || isPreviousRightBracket || isPreviousIteration) && isLetter) || (isCurrentLeftBracket && isPreviousLetter))
		{
			regex.InsertAt(i, '.');
		}
		isPreviousLetter = isalpha(regex[i]) || isdigit(regex[i]);
		isPreviousRightBracket = regex[i] == ')';
		isPreviousIteration = regex[i] == '*';
	}
	return regex;
}

bool StateMachine::RecognizeHelper(String word)
{
	if (word.Length() == 0)
	{
		return this->states[currentState]->IsFinal();
	}
	std::vector<Transition> transitions = this->states[currentState]->Transist(word);
	bool recognized = false;
	for (unsigned i = 0; i < transitions.size(); i++)
	{
		this->currentState = transitions[i].Transist();
		recognized = recognized || this->RecognizeHelper(word.Substring(1));
		if (recognized)
		{
			return true;
		}
	}
	return false;
}

bool StateMachine::CheckIfDeterministic() const
{
	if (this->starts.size() > 1)
	{
		return false;
	}
	for (unsigned i = 0; i < this->states.size(); i++)
	{
		auto t = this->states[i]->GetAllTransitionsGrouped();
		for (unsigned j = 0; j < t.size(); j++)
		{
			if (t[j].size() > 1)
			{
				return false;
			}
		}
	}
	return true;
}
