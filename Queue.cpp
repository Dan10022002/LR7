#include <iostream>

struct Queue_element
{
    Queue_element* queue_next = nullptr;
    int value;
};

struct Queue_general
{
    Queue_element* queue_begin;
    Queue_element* queue_end;
};

void Constructor (Queue_general& Queue)
{
    Queue.queue_begin = nullptr;
    Queue.queue_end = nullptr;
}

void Destructor (Queue_general& Queue)
{
    while (Queue.queue_begin != nullptr)
    {
        Queue_element* queue_time = new Queue_element;
        queue_time = Queue.queue_begin;
        Queue.queue_begin = Queue.queue_begin -> queue_next;
        delete queue_time;
    }
}

void Push (Queue_general& Queue, Queue_element& Element)
{
    if (Queue.queue_begin == nullptr)
    {
        Queue_element* queue_time = new Queue_element;
        queue_time -> value = Element.value;
        Queue.queue_begin = queue_time;
        Queue.queue_end = queue_time;
        delete queue_time;
    }
    else
    {
        Queue_element* queue_time = new Queue_element;
        queue_time -> value = Element.value;
        Queue.queue_end -> queue_next = queue_time;
        Queue.queue_end = queue_time;
        delet queue_time;
    }
}

Queue_element Pop (Queue_general& Queue)
{
    int t = Queue.queue_begin -> value;
    Queue_element Queue_pop_element;
    Queue_element* queue_time = new Queue_element;
    queue_time = Queue.queue_begin;
    Queue.queue_begin = Queue.queue_begin -> queue_next;
    Queue_pop_element.value = t;
    Queue_pop_element.queue_next = Queue.queue_begin;
    delete queue_time;
    return Queue_pop_element;
}

size_t Size (const Queue_general& Queue)
{
    size_t queue_size = 0;
    Queue_element* queue_time = new Queue_element;
    queue_time = Queue.queue_begin;
    while (queue_time != nullptr)
    {
        queue_time = queue_time -> queue_next;
        queue_size += 1;
    }
    delete queue_time;
    return queue_size;
}

void Print (Queue_general& Queue)
{
    while (Queue.queue_begin != nullptr)
    {
        int s = Queue.queue_begin -> value;
        std::cout << s << " ";
        Queue.queue_begin = Queue.queue_begin -> queue_next;
    }
}

int main()
{
    Queue_general Queue;
    Constructor (Queue);
    Queue_element Element;
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    for (int i=0; i<n; i++)
    {
        std::cout << "Enter the " << (i+1) << " element: ";
        int Element_int;
        std::cin >> Element_int;
        Element.value = Element_int;
        Push (Queue, Element);
    }
    std::cout << "There are " << Size (Queue) << " element in queue.\n";
    std::cout << "Your queue: \n";
    Print (Queue);
    std::cout << "\n";
    Destructor (Queue);
    return 0;
}
