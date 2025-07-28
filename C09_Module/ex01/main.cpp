#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    try {
        RPN rpn;
        double result = rpn.calculate(argv[1]);

        if (result == static_cast<int>(result)) {
            std::cout << static_cast<int>(result) << std::endl;
        } else {
            std::cout << result << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
