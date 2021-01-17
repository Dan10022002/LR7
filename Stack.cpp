#include <iostream>

struct Stack_element
{
    Stack_element* stack_prev = nullptr;
    int value = -1;
};

struct Stack_general
{
    Stack_element* stack_end;
};

void Constructor(Stack_general& Stack) //1
{
    Stack.stack_end = nullptr;
}

unsigned int Size(Stack_general& Stack) //3
{
    size_t counter = 0;
    if (Stack.stack_end == nullptr)
    {
        return counter;
    }
    else
    {
        counter += 1;
        Stack_element* stack_time;
        stack_time = Stack.stack_end;
        while (stack_time->stack_prev != nullptr)
        {
            stack_time = stack_time->stack_prev;
            counter += 1;
        }
        return counter;
    }
}

void Destructor(Stack_general& Stack) //2
{
    for (int h = 0; h < Size(Stack); h++)
    {
        Stack_element* stack_time;
        stack_time = Stack.stack_end;
        Stack.stack_end = Stack.stack_end->stack_prev;
        delete stack_time;
    }
}

void Push(Stack_general& Stack, Stack_element& Element) //4
{
        Stack_element* stack_time = new Stack_element;
        stack_time->value = Element.value;
        stack_time->stack_prev = Stack.stack_end;
        Stack.stack_end = stack_time;
}

int Pop(Stack_general& Stack) //5
{
    Stack_element* stack_time;
    stack_time = Stack.stack_end;
    int t = Stack.stack_end->value;
    Stack.stack_end = Stack.stack_end->stack_prev;
    delete stack_time;
    return t;
}

void Print(Stack_general& Stack) //6
{
    Stack_element* stack_time;
    stack_time = Stack.stack_end;
    for (int h = 0; h < Size(Stack); h++)
    {
        std::cout << stack_time->value << " ";
        stack_time = stack_time->stack_prev;
    }
}

int main()
{
    Stack_general Stack;
    Constructor(Stack);
    Stack_element Element;
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter the " << (i + 1) << " element: ";
        int Element_int;
        std::cin >> Element_int;
        Element.value = Element_int;
        Push(Stack, Element);
    }
    std::cout << "There are " << Size(Stack) << " element in stack.\n";
    std::cout << "Your stack: \n";
    Print(Stack);
    std::cout << "\n";
    std::cout << Pop(Stack);
    std::cout << "\n";
    Print(Stack);
    std::cout << "\n";
    Destructor(Stack);
    return 0;
}
