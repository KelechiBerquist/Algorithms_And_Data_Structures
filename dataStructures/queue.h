#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
	public:
		Queue();
		void* pop();
		void push(void * newValue);

	private:
		std::vector<void *> underContainer;


};


#endif


Queue::Queue()
{

}

void * Queue::pop()
{
	void * thisValue = underContainer[underContainer.begin()]
}