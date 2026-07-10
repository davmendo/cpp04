#include <iostream>
#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(Brain const &src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; ++i)
		this->ideas[i] = src.ideas[i];
}

Brain &Brain::operator=(Brain const &rhs)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 100; ++i)
			this->ideas[i] = rhs.ideas[i];
	}
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

std::string const &Brain::getIdea(int index) const
{
	static std::string const empty = "";

	if (index < 0 || index >= 100)
		return (empty);
	return (this->ideas[index]);
}

void Brain::setIdea(int index, std::string const &idea)
{
	if (index < 0 || index >= 100)
		return ;
	this->ideas[index] = idea;
}
