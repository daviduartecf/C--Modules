#include "Serializer.hpp"

int main() {
    Data myData;
    myData.id = 42;
    myData.name = "Example Data";

    std::cout << "Original Data pointer: " << &myData << std::endl;
    std::cout << "Original Data values: ID = " << myData.id << ", Name = " << myData.name << std::endl;

    uintptr_t raw = Serializer::serialize(&myData);
    std::cout << "Serialized value: " << raw << std::endl;

    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << "Deserialized Data pointer: " << deserializedData << std::endl;
    std::cout << "Deserialized Data values: ID = " << deserializedData->id << ", Name = " << deserializedData->name << std::endl;
    if (&myData == deserializedData) {
        std::cout << "Success: The original and deserialized pointers match!" << std::endl;
    } else {
        std::cout << "Error: The pointers don't match!" << std::endl;
    }

    return 0;
}
