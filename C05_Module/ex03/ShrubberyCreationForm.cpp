#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target) {
    std::cout << "Shrubbery Form Created" << std::endl;
}
ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "Shrubbery Form Destroyed" << std::endl;
}
ShrubberyCreationForm& ShrubberyCreationForm::operator = (const ShrubberyCreationForm& other) {
    if (this != &other) {
		_target = other.getTarget();
	}
    return *this;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other) {
    *this = other;
}

std::string ShrubberyCreationForm::getTarget() const {
    return _target;
}

void ShrubberyCreationForm::executeAction() const {
    std::ofstream outfile (this->getTarget().append("_shrubbery").c_str());
    for (int i = 0; i < 3; i++) {
        outfile <<
        "   ." << std::endl <<
        "  .           ;"  << std::endl <<
        " .           .              ;%     ;;   "<< std::endl <<
        " ,          ,                :;%  %;   "<< std::endl <<
        " :         ;                   :;%;'     .,   "<< std::endl <<
        ",.        %;     %;            ;        %;'    ,;"<< std::endl <<
        ";       ;%;  %%;        ,     %;    ;%;    ,%'"<< std::endl <<
        "%;       %;%;      ,  ;       %;  ;%;   ,%;' "<< std::endl <<
        ";%;      %;        ;%;        % ;%;  ,%;'"<< std::endl <<
        "`%;.     ;%;     %;'         `;%%;.%;'"<< std::endl <<
        "`:;%.    ;%%. %@;        %; ;@%;%'"<< std::endl <<
        "`:%;.  :;bd%;          %;@%;'"<< std::endl <<
        "`@%:.  :;%.         ;@@%;'   "<< std::endl <<
        "`@%.  `;@%.      ;@@%;      "   << std::endl <<
        "`@%%. `@%%    ;@@%;     "   << std::endl <<
        ";@%. :@%%  %@@%;     "  << std::endl <<
        "%@bd%%%bd%%:;     "<< std::endl <<
        "#@%%%%%:;;"<< std::endl <<
        "%@@%%%::;"<< std::endl <<
        "%@@@%(o);  . '      "   << std::endl <<
        "%@@@o%;:(.,'        " << std::endl <<
        "`..%@@@o%::;       "  << std::endl <<
        "  `@@@o%::;         "<< std::endl <<
        "    %@@(o)::;      "  << std::endl <<
        "    .%@@@@%::;     "   << std::endl <<
        "    ;%@@@@%::;.   "    << std::endl <<
        "    ;%@@@@%%:;;;. "<< std::endl <<
        "...;%@@@@@%%:;;;;,.."<< std::endl <<
        std::endl;
    }
    outfile.close();
}
