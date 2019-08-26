#pragma once
#include <iostream>

template <typename T>
class List
{
	size_t count;
	size_t capacity;

	T *items;
	T tmp;
	bool isFull()
	{
		return count == capacity;
	}

	void growList()
	{ /* There are no safety checks, if you wish to grow the list check isFull() to see if
	  expansion is really necessary double the size and copy the old items in the new array */
		capacity *= 2;
		T* newItems = new T[capacity];
		for (size_t i = 0; i < count; i++)
		{
			newItems[i] = items[i];
		}
		/* Delete the old memory and direct the pointer to the new array */
		delete[] items;
		items = newItems;
	}

	void shrinkList()
	{	/* The safety checks are in the function
		Check if it's possible to shrink */
		if (capacity / 2 < count || capacity == 1)
		{
			//std::cout << "Failed to shrink the list, there's not enough space for all the items.\n";
			return;
		}
		/* Calculate the size that the list needs to have */
		for (capacity = 1; capacity < count; capacity *= 2);
		/* Shrink the list copying the items in a new list */
		T *newItems = new T[capacity];
		for (size_t i = 0; i < count; i++) 
		{
			newItems[i] = items[i];
		}
		/* Delete the old memory and assign the pointer to the new smaller array */
		delete[] items;
		items = newItems;
	}

	void copyAnotherListInThis(const List<T>& anotherList)
	{   /* Copies the items from a given list to this list from the start overwriting the old data
		(WITHOUT deleting the pointer) Always call delete before this if necessary */
		capacity = anotherList.capacity;
		count = anotherList.count;
		items = new T[capacity];
		for (size_t i = 0; i < count; i++)
		{
			items[i] = anotherList.items[i];
		}
	}

public:
	/* Constructors */
	List() : capacity(1), count(0), items(new T[capacity]) { }

	~List()
	{   /* Destructor */
		delete[] items;
	}

	List(const List<T>& anotherList)
	{   /* Copy constructor */
		copyAnotherListInThis(anotherList);
	}

	/* Operators */
	List<T>& operator=(const List& anotherList)
	{
		if (anotherList != this)
		{
			delete[] items;
			copyAnotherListInThis(anotherList);
		}
		return *this;
	}

	T& operator[](size_t pos)
	{
		if (pos < count && pos >= 0)
		{
			return items[pos];
		}
		return tmp;
	}

	List<T>& operator+=(const T& item)
	{
		add(item);
		return *this;
	}

	List<T>& print()
	{
		for (size_t i = 0; i < count; i++) 
		{
			std::cout << items[i] << "\n";
		}
		return *this;
	}

	/* Methods */
	List<T>& add(const T& item)
	{   /* Add an item to the end
		Check if there's enough space, if not - expand the size of the array */
		if (isFull()) 
		{
			growList();
		}
		/* Add the item */
		items[count] = item;
		count++;
		return *this;
	}

	T get(size_t indx) const
	{
		if (indx >= 0 && indx < count)
		{
			return items[indx];
		}
		return NULL;
	}

	List<T>& insertAt(const T& item, size_t indx)
	{   /* Add the item in position
		Check if the index is valid to add, if it's < 0 or it's bigger than the amount of items do nothing */
		if (indx < 0 || indx > count)
		{
			return *this;
		}
		/* Check if there's enough space, if not - expand the size of the array */
		if (isFull())
		{
			growList();
		}
		/* Shift the items right in the array to free one position for the new item to be added */
		for (size_t i = count; i >= indx; i--)
		{
			/* std::cout << items[i]; */
			items[i] = items[i - 1];
		}
		/* Add the item in the freed up position */
		items[indx] = item;
		count++;
		return *this;
	}

	const size_t Size() const
	{   /* Return the number of items */
		return count;
	}

	const size_t actualSize() const
	{   /* Returns the amount of memory that is reserved for *items, used only for debugging */
		return capacity;
	}

	List<T>& removeAt(size_t indx)
	{   /* Remove the item at position Position
	    Check if such index is valid */
		if (count <= indx || indx < 0) 
		{
			/*std::cout << "Failed to remove at index " << Index << ", no such index exists in the list.\n"; */
			return *this;
		}
		/* Shift all the items after the index left by one */
		count--;
		for (size_t i = indx; i < count; i++) 
		{
			items[i] = items[i + 1];
		}
		shrinkList();
		return *this;
	}

	List<T>& removeRange(size_t from, size_t to) 
	{   /* Remove a number of items between two positions including the positions
		Swap the 2 if one is less than the other */
		if (to < from) {
			size_t temp = from;
			from = to;
			to = temp;
		}
		/* Security check if such indexes exist */
		if (from < 0 || to < 0 || from >= count || to >= count) 
		{
			/*std::cout << "Failed to remove from index " << From << " to " << To << ", no such index exists in the list.\n"; */
			return *this;
		}
		/* Shift the items left as many as needed */
		size_t shift = to - from + 1;
		count -= shift;
		for (size_t i = from; i < count; i++) 
		{
			items[i] = items[i + shift];
		}
		shrinkList();
		return *this;
	}

	List<T>& Delete(const T& item) 
	{   /* Remove one item that is == Item */
		for (size_t i = 0; i < count; i++) 
		{
			if (items[i] == item) 
			{
				removeAt(i);
				break;
			}
		}
		return *this;
	}

	List<T>& deleteAll(const T& item) 
	{   /* Remove all items that are == item */
		for (size_t i = 0; i < count; i++) 
		{
			if (items[i] == item) 
			{
				removeAt(i);
				i--;
			}
		}
		return *this;
	}

	List<T>& Delete(bool(*removeIfTrue)(const T& item)) 
	{   /* Delete 1 item where the cheker function returns true */
		for (size_t i = 0; i < count; i++) 
		{
			if (removeIfTrue(items[i])) 
			{
				removeAt(i);
				break;
			}
		}
		return *this;
	}

	List<T>& DeleteAll(bool(*removeIfTrue)(const T& Item)) 
	{   /* Delete all items where the cheker function returns true */
		for (size_t i = 0; i < count; i++) 
		{
			if (removeIfTrue(items[i])) 
			{
				removeAt(i);
				i--;
			}
		}
		return *this;
	}

	size_t Index(const T& item) 
	{   /* Return the index of an item that is == Item */
		for (size_t i = 0; i < count; i++) 
		{
			if (items[i] == item) 
			{
				return i;
			}
		}
		return -1;
	}

	size_t Index(bool(*indexIfTrue)(const T& Item)) 
	{   /* Return the index of an item that the checker function returns to be true */
		for (size_t i = 0; i < count; i++) 
		{
			if (indexIfTrue(items[i])) 
			{
				return i;
			}
		}
		return -1;
	}

	List<T> Find(bool(*ReturnIfTrue)(const T& item)) 
	{	/* Return a list containing 1 item if such is found or empty list if no item is found
		Because something has to be returned, better return an empty list */
		List<T> newList;
		for (size_t i = 0; i < count; i++) 
		{
			if (ReturnIfTrue(items[i])) 
			{
				newList.add(items[i]);
				break;
			}
		}
		return newList;
	}

	List<T> findAll(bool(*returnIfTrue)(const T& item)) 
	{   /* Return a list containing all item matching the criteria */
		List<T> newList;
		for (size_t i = 0; i < count; i++) 
		{
			if (returnIfTrue(items[i])) 
			{
				newList.add(items[i]);
			}
		}
		return newList;
	}

	List<T>& append(const List<T>& anotherList) 
	{   /* Append another list to the end of the current one */
		for (size_t i = 0; i < anotherList.count; i++) 
		{
			add(anotherList[i]);
		}
		return *this;
	}

	List<T> concat(const List<T>& anotherList) const 
	{   /* Return a new list the concatination of this and anotherList */
		List<T> newList;
		newList.append(*this);
		newList.append(anotherList);
		return newList;
	}
};
