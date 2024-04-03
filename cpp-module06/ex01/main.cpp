#include "Serializer.hpp"

int main()
{
    Data* data = new Data;

    uintptr_t raw = Serializer::serialize(data);
    Data* ptr = Serializer::deserialize(raw);

    std::cout <<"-----------------------------------" << std::endl;
    data->str = "           👻 Hi 👻 ";
    std::cout << ptr->str << std::endl;

    std::cout << "Original     Data : " << data << std::endl;
	std::cout << "Serialized   Data : " << raw << std::endl;
	std::cout << "Deserialized Data : " << ptr << std::endl;
    std::cout <<"-----------------------------------" << std::endl;
	
    delete data;	
	return 0;
}
