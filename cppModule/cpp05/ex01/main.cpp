#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
   try {
        Form form1("high", 1, 1);
        std::cout << form1 << std::endl;
        Form form2("low", 150, 150);
        std::cout << form2 << std::endl;
        Bureaucrat jack("jack", 50);
        jack.signForm(form2);
        jack.signForm(form2);
        jack.signForm(form1);
   }
   catch(const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
   }

    return 0;
}
