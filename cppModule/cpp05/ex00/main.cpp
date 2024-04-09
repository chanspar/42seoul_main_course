#include "Bureaucrat.hpp"

int main() {
    try {
        std::cout << "----------check high grade-----------" << std::endl;
        Bureaucrat err1("err1", 0);
        std::cout << err1 << std::endl;
        Bureaucrat err2("err2", 4242);
        std::cout << err2 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        std::cout << "----------check low grade----------" << std::endl;
        Bureaucrat err2("err2", 4242);
        std::cout << err2 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "----------check increase ----------" << std::endl;
    try {
        Bureaucrat bureaucrat1("tom", 2);
        std::cout << bureaucrat1 << std::endl;
        bureaucrat1.incrementGrade();
        std::cout << bureaucrat1 << std::endl;
        bureaucrat1.incrementGrade();
        std::cout << bureaucrat1 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "----------check decrease ----------" << std::endl;
    try {
        Bureaucrat bureaucrat2("bob", 149);
        std::cout << bureaucrat2 << std::endl;
        bureaucrat2.decrementGrade();
        std::cout << bureaucrat2 << std::endl;
        bureaucrat2.decrementGrade();
        std::cout << bureaucrat2 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
