#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class ShrubberyCreatrionForm : public AForm
{
	private:
		std::string target;
	public:
		ShrubberyCreatrionForm();
		ShrubberyCreatrionForm(const std::string& name, const std::string& target);
		ShrubberyCreatrionForm(const ShrubberyCreatrionForm& cpy);
		ShrubberyCreatrionForm& operator=(const ShrubberyCreatrionForm& rhs);
		~ShrubberyCreatrionForm();
		virtual void execute(const Bureaucrat& executor) const;
};

#endif
