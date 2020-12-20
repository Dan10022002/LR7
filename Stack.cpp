#include <iostream>

struct Stack_element
{
    Stack_element* stack_prev = nullptr;
    int value;
};

struct Stack_general
{
    Stack_element* stack_begin;
    Stack_element* stack_end;
};

void Constructor (Stack_general& Stack)
{
    Stack.stack_begin = nullptr;
    Stack.stack_end = nullptr;
}

void Destructor (Stack_general& Stack)
{
    while (Stack.stack_end != nullptr)
    {
        Stack_element* stack_time = new Stack_element;
        stack_time = Stack.stack_end;
        Stack.stack_end = Stack.stack_end -> stack_prev;
        delete stack_time;
    }
}

void Push (Stack_general& Stack, Stack_element& Element)
{
    if (Stack.stack_begin == nullptr)
    {
        Stack_element* stack_time = new Stack_element;
        stack_time -> value = Element.value;
        Stack.stack_begin = stack_time;
        Stack.stack_end = stack_time;
        delete stack_time;
    }
    else
    {
        Stack_element* stack_time = new Stack_element;
        stack_time -> value = Element.value;
        stack_time -> stack_prev = Stack.stack_end;
        Stack.stack_end = stack_time;
        delete stack_time;
    }
}

Stack_element Pop (Stack_general& Stack)
{
	int t = Stack.stack_end -> value;
	Stack.stack_end = Stack.stack_end -> stack_prev;
	return t;
}

size_t Size (const Stack_general& Stack)
{
    size_t stack_size = 0;
    Stack_element* stack_time = new Stack_element;
    stack_time = Stack.stack_end;
    while (stack_time != nullptr)
    {
        stack_time = stack_time -> stack_prev;
        stack_size += 1;
    }
    delete stack_time;
    return stack_size;
}

void Print (Stack_general& Stack)
{
    while (Stack.stack_end != nullptr)
    {
        int s = Stack.stack_end -> value;
        std::cout << s << " ";
        Stack.stack_end = Stack.stack_end -> stack_prev;
    }
}

int main()
{
    Stack_general Stack;
    Constructor (Stack);
    Stack_element Element;
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    for (int i=0; i<n; i++)
    {
        std::cout << "Enter the " << (i+1) << " element: ";
        int Element_int;
        std::cin >> Element_int;
        Element.value = Element_int;
        Push (Stack, Element);
    }
    std::cout << "There are " << Size (Stack) << " element in stack.\n";
    std::cout << "Your stack: \n";
    Print (Stack);
    std::cout << "\n";
    Destructor (Stack);
    return 0;
}
