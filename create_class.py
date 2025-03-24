import sys
import os

HEADER_TEMPLATE = """#ifndef {guard}
#define {guard}

#include <string>
#include <iostream>

class {class_name} {{
    public:
		//ORTHODOX CANONICAL FORM
        {class_name}();
        virtual ~{class_name}();
        {class_name}(const {class_name}& other);
        {class_name}& operator = (const {class_name}& other);
    private:
        type variable;
}};

#endif // {guard}
"""

SOURCE_TEMPLATE = """#include "{class_name}.hpp"

{class_name}::{class_name}() {{}}

{class_name}::~{class_name}() {{}}

{class_name}& {class_name}::operator = (const {class_name}& other) {{
    if (this != &other)
    {{
        this->variable = other.variable;
    }}
    return *this;
}}

{class_name}::{class_name}(const {class_name}& other) {{
    this->variable = other.variable;
}}
"""

def create_class(class_name):
    guard = f"{class_name.upper()}_HPP"
    hpp_filename = os.path.join(f"{class_name}.hpp")
    cpp_filename = os.path.join(f"{class_name}.cpp")

    with open(hpp_filename, "w") as hpp_file:
        hpp_file.write(HEADER_TEMPLATE.format(class_name=class_name, guard=guard))

    with open(cpp_filename, "w") as cpp_file:
        cpp_file.write(SOURCE_TEMPLATE.format(class_name=class_name))

    print(f"Files created: {hpp_filename}, {cpp_filename}")

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python3 create_class.py <ClassName>")
    else:
        create_class(sys.argv[1])
