#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
   try {
        Form form1("common project", 100, 100);
        std::cout << form1 << std::endl;
        Form form2("important project", 5, 5);
        std::cout << form2 << std::endl;
        Bureaucrat jack("jack", 50);
        jack.signForm(form1);
        jack.signForm(form1);

        jack.signForm(form2);
     //    Form form3("error project1", 0, 0);
     //    Form form4("error project2", 151, 151);
   }
   catch(const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
   }

    return 0;
}
