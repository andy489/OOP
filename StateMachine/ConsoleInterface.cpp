#include "ConsoleInterface.h"
#include <fstream>

bool ConsoleInterface::ValidateInput(int stringIndexToInt, int parametersNeeded, std::vector<String> str) const
{
	if (str.size() != parametersNeeded)
	{
		return false;
	}
	if (!str[stringIndexToInt].TryParseToInt())
	{
		return false;
	}
	return true;
}

void ConsoleInterface::Read(std::istream& is)
{
	this->os << "Welcome to the state machinator! Type \"?\" if you need help!\n";
	this->os << "If you are new here, I suggest you start with creating a state machine with the \"reg\" command!\n";
	String s;
	while (true)
	{
		this->os << "> ";
		is >> s;
		if (s == "")
		{
			continue;
		}
		std::vector<String> parameters = s.Split();
		String command = parameters[0];
		if (command == "open")
		{
			if (parameters.size() != 2)
			{
				this->os << "Invalid parameters!\n";
				continue;
			}
			this->Open(parameters[1]);
		}
		else if (command == "?")
		{
			this->Help();
		}
		else if (command == "list")
		{
			this->List();
		}
		else if (command == "print")
		{
			if (!ValidateInput(1, 2, parameters))
			{
				this->os << "Invalid parameters!\n";
				continue;
			}
			this->Print(parameters[1]);
		}
		else if (command == "save")
		{
			if (!ValidateInput(1, 3, parameters))
			{
				this->os << "Invalid parameters!\n";
				continue;
			}
			this->Save(parameters[1], parameters[2]);
		}
		else if (command == "empty")
		{
			if (!ValidateInput(1, 2, parameters))
			{
				this->os << "Invalid parameters!\n";
				continue;
			}
			this->IsEmpty(parameters[1]);
		}
		else if (command == "deterministic")
		{
			if (!ValidateInput(1, 2, parameters))
			{
				this->os << "Invalid parameters!\n";
				continue;
			}
			this->IsDeterministic(parameters[1]);
		}
		else if (command == "recognize")
		{
			if (!ValidateInput(1, 3, parameters))
			{
				if (ValidateInput(1, 2, parameters))
				{
					parameters.push_back(" ");
				}
				else
				{
					this->os << "Invalid parameters!\n";
					continue;
				}
			}
			this->Recognize(parameters[1], parameters[2]);
		}
		else if (command == "union")
		{
			if (!(ValidateInput(1, 3, parameters) && parameters[2].TryParseToInt()))
			{
				this->os << "Invalid parameters!\n";
				continue;
			}
			this->Union(parameters[1], parameters[2]);
		}
		else if (command == "concat")
		{
			if (!(ValidateInput(1, 3, parameters) && parameters[2].TryParseToInt()))
			{
				this->os << "Invalid parameters!\n";
				continue;
			}
			this->Concat(parameters[1], parameters[2]);
		}
		else if (command == "un")
		{
			if (!ValidateInput(1, 2, parameters))
			{
				this->os << "Invalid parameters!\n";
				continue;
			}
			this->Un(parameters[1]);
		}
		else if (command == "reg")
		{
			if (parameters.size() == 1)
			{
				parameters.push_back("");
			}
			if (parameters.size() != 2)
			{
				this->os << "Invalid parameters!\n";
				continue;
			}
			this->Reg(parameters[1]);
		}
		else if (command == "minimize")
		{
			if (!ValidateInput(1, 2, parameters))
			{
				this->os << "Invalid parameters!\n";
				continue;
			}
			this->Minimize(parameters[1]);
		}
		else if (command == "determinate")
		{
			if (!ValidateInput(1, 2, parameters))
			{
				this->os << "Invalid parameters!\n";
				continue;
			}
			this->Determinate(parameters[1]);
		}
		else if (command == "reverse")
		{
			if (!ValidateInput(1, 2, parameters))
			{
				this->os << "Invalid parameters!\n";
				continue;
			}
			this->Reverse(parameters[1]);
		}
		else if (command == "language")
		{
			if (!ValidateInput(1, 2, parameters))
			{
				this->os << "Invalid parameters!\n";
				continue;
			}
			this->PrintLanguage(parameters[1]);
		}
		else if (command == "close")
		{
			this->os << "Closing the program!\n";
			return;
		}
		else if (command == "clear")
		{
			for (int i = 0; i < 50; i++)
			{
				this->os << "\n";
			}
		}
		else
		{
			this->os << "Invalid input!\n";
		}
	}
}

void ConsoleInterface::Reg(String regex)
{
	this->elements.push_back(StateMachine(regex));
	this->elementsCount++;
	this->os << "Succesfully created state machine with index " << this->elementsCount - 1 << "\n";
}

void ConsoleInterface::Recognize(int index, String word)
{
	if (index >= this->elementsCount || index < 0)
	{
		this->os << "Invalid state machine id!\n";
		return;
	}
	bool result = this->elements[index].Recognize(word);
	if (result)
	{
		this->os << "The word \"" << word << "\" is recognized by state machine with index " << index << "\n";
	}
	else
	{
		this->os << "The word \"" << word << "\" is NOT recognized by state machine with index " << index << "\n";
	}
}

ConsoleInterface::ConsoleInterface(std::istream& is, std::ostream& os) : is(is), os(os)
{
	this->elementsCount = 0;
}

void ConsoleInterface::Concat(int firstIndex, int secondIndex)
{
	int size = this->elements.size();
	if (firstIndex > size - 1 || secondIndex > size - 1 || firstIndex < 0 || secondIndex < 0)
	{
		this->os << "Invalid state machine ids!\n";
		return;
	}

	this->AddElement(this->elements[firstIndex].Concatenate(this->elements[secondIndex]));
	this->os << "Succesfully created state machine with index " << this->elementsCount - 1 << "\n";
}

void ConsoleInterface::Union(int firstIndex, int secondIndex)
{
	int size = this->elements.size();
	if (firstIndex > size - 1 || secondIndex > size - 1 || firstIndex < 0 || secondIndex < 0)
	{
		this->os << "Invalid state machine ids!\n";
		return;
	}
	this->AddElement(this->elements[firstIndex].Union(this->elements[secondIndex]));
	this->os << "Succesfully created state machine with index " << this->elementsCount - 1 << "\n";
}

void ConsoleInterface::Un(int index)
{
	if (index > (int)this->elements.size() - 1 || index < 0)
	{
		this->os << "Invalid state machine ids!\n";
		return;
	}

	this->AddElement(this->elements[index].Iteration());
	this->os << "Succesfully created state machine with index " << this->elementsCount - 1 << "\n";
}

void ConsoleInterface::AddElement(const StateMachine& st)
{
	this->elements.push_back(st);
	this->elementsCount++;
}

void ConsoleInterface::IsEmpty(int index) const
{
	if (index > (int)this->elements.size() - 1 || index < 0)
	{
		this->os << "Invalid state machine id!\n";
		return;
	}

	bool result = this->elements[index].IsLanguageEmpty();
	if (result)
	{
		this->os << "The language of state machine with id " << index << " is empty!\n";
	}
	else
	{
		this->os << "The language of state machine with id " << index << " is NOT empty!\n";
	}
}

void ConsoleInterface::IsDeterministic(int index) const
{
	if (index > (int)this->elements.size() - 1 || index < 0)
	{
		this->os << "Invalid state machine id!\n";
		return;
	}

	bool result = this->elements[index].IsDeterministic();
	if (result)
	{
		this->os << "The state machine with id " << index << " is deterministic!\n";
	}
	else
	{
		this->os << "The state machine with id " << index << " is NOT deterministic!\n";
	}
}

void ConsoleInterface::Minimize(int index)
{
	if (index > (int)this->elements.size() - 1 || index < 0)
	{
		this->os << "Invalid state machine id!\n";
		return;
	}

	this->elements[index].Minimize();
	this->os << "Succesfully minimized the state machine with id " << index << "\n";
}

void ConsoleInterface::Determinate(int index)
{
	if (index > (int)this->elements.size() - 1 || index < 0)
	{
		this->os << "Invalid state machine id!\n";
		return;
	}

	this->elements[index].Determinate();
	this->os << "Succesfully determinated the state machine with id " << index << "\n";
}

void ConsoleInterface::Reverse(int index)
{
	if (index > (int)this->elements.size() - 1 || index < 0)
	{
		this->os << "Invalid state machine id!\n";
		return;
	}
	this->elements[index].Reverse();
	this->os << "Succesfully reversed the state machine with id " << index << "\n";
}

void ConsoleInterface::PrintLanguage(int index) const
{
	if (index > (int)this->elements.size() - 1 || index < 0)
	{
		this->os << "Invalid state machine id!\n";
		return;
	}

	char* output = this->elements[index].GetRegex().ToCharArray();
	this->os << output << '\n';
	delete[] output;
}

void ConsoleInterface::IsLanguageFinite(int index) const
{
	if (index > (int)this->elements.size() - 1 || index < 0)
	{
		this->os << "Invalid state machine id!\n";
		return;
	}

	bool res = this->elements[index].IsLanguageFinite();
	this->os << "The language of state machine with index " << index << " is ";
	if (!res)
	{
		this->os << "NOT";
	}
	this->os << " finite!";
}

void ConsoleInterface::Save(int index, String fileName) const
{
	if (index > (int)this->elements.size() - 1 || index < 0)
	{
		this->os << "Invalid state machine id!\n";
		return;
	}

	char* fileNameTemp = fileName.ToCharArray();
	std::ofstream ofs(fileNameTemp);
	char* output = this->elements[index].ToString().ToCharArray();
	ofs << output;
	ofs.close();
	delete[] fileNameTemp;
	delete[] output;
	this->os << "Save successful!\n";
}

void ConsoleInterface::Print(int index) const
{
	if (index > (int)this->elements.size() - 1 || index < 0)
	{
		this->os << "Invalid state machine id!\n";
		return;
	}

	this->elements[index].TransitionsToString().Print();
}

void ConsoleInterface::Open(String fileName)
{
	char* temp = fileName.ToCharArray();
	std::ifstream ifs(temp);
	StateMachine a(ifs);
	this->AddElement(a);
	this->os << "Loaded state machine with index " << this->elementsCount - 1 << " from file " << fileName << "\n";
	delete[] temp;
}

void ConsoleInterface::List() const
{
	char* temp;
	for (unsigned i = 0; i < this->elements.size(); i++)
	{
		temp = this->elements[i].GetRegex().ToCharArray();
		this->os << "Id: " << i << " Regex: " << temp << "\n";
		delete[] temp;
	}
}

void ConsoleInterface::Help() const
{
	this->os << "Available commands:\n";
	this->os << "- reg <regex>\n";
	this->os << "- open <filename>\n";
	this->os << "- list\n";
	this->os << "- print <id>\n";
	this->os << "- save <id> <filename>\n";
	this->os << "- empty <id>\n";
	this->os << "- deterministic <id>\n";
	this->os << "- recognize <id> <word>\n";
	this->os << "- union <id1> <id2>\n";
	this->os << "- concat <id1> <id2>\n";
	this->os << "- un <id>\n";
	this->os << "- minimize <id>\n";
	this->os << "- determinate <id>\n";
	this->os << "- reverse <id>\n";
	this->os << "- language <id>\n";
	this->os << "- finite <id>\n";
	this->os << "- close\n";
	this->os << "For more information, read the README file!\n";
}
