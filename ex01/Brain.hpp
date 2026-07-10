#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain
{
	private:
		std::string ideas[100];

	public:
		Brain(void);
		Brain(Brain const &src);
		Brain &operator=(Brain const &rhs);
		~Brain(void);

		std::string const &getIdea(int index) const;
		void setIdea(int index, std::string const &idea);
};

#endif
