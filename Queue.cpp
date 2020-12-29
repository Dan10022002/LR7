#include <iostream>

struct Queue_element
{
    Queue_element* queue_next = nullptr;
    int value = -1;
};

struct Queue_general
{
    Queue_element* queue_begin;
    Queue_element* queue_end;
};

void Constructor(Queue_general& Queue) //1
{
    Queue.queue_begin = nullptr;
    Queue.queue_end = nullptr;
}

unsigned int Size(Queue_general& Queue) //3
{
    size_t counter = 0;
    if (Queue.queue_begin == nullptr)
    {
        return counter;
    }
    else
    {
        counter += 1;
        Queue_element* queue_time;
        queue_time = Queue.queue_begin;
        while (queue_time -> queue_next != nullptr)
        {
            queue_time = queue_time -> queue_next;
            counter += 1;
        }
        return counter;
    }
}

void Destructor(Queue_general& Queue) //2
{
    for (int h = 0; h < Size(Queue); h++)
    {
        Queue_element* queue_time;
        queue_time = Queue.queue_begin;
        Queue.queue_begin = Queue.queue_begin -> queue_next;
        delete queue_time;
    }
}

void Push(Queue_general& Queue, Queue_element& Element) //4
{
        Queue_element* queue_time = new Queue_element;
        queue_time->value = Element.value;
        queue_time->queue_next = nullptr;
        Queue.queue_end->queue_next = queue_time;
        Queue.queue_end = queue_time;
}

int Pop(Queue_general& Queue) //5
{
    Queue_element* queue_time;
    queue_time = Queue.queue_begin;
    int t = Queue.queue_begin->value;
    Queue.queue_begin = Queue.queue_begin -> queue_next;
    delete queue_time;
    return t;
}

void Print(Queue_general& Queue) //6
{
    Queue_element* queue_time;
    queue_time = Queue.queue_begin;
    for (int h = 0; h < Size(Queue); h++)
    {
        std::cout << queue_time -> value << " ";
        queue_time = queue_time -> queue_next;
    }
}

int main()
{
    Queue_general Queue;
    Constructor(Queue);
    Queue_element Element;
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter the " << (i + 1) << " element: ";
        int Element_int;
        std::cin >> Element_int;
        Element.value = Element_int;
        Push(Queue, Element);
    }
    std::cout << "There are " << Size(Queue) << " element in queue.\n";
    std::cout << "Your queue: \n";
    Print(Queue);
    std::cout << "\n";
    std::cout << Pop(Queue);
    std::cout << "\n";
    Print(Queue);
    std::cout << "\n";
    Destructor(Queue);
    return 0;
}
