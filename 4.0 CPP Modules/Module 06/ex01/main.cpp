#include "Serializer.hpp"

int	main(void)
{
	Data	data = {.value = 12345, .string = "Hello World!"};
	uintptr_t	serializedPointerAsInt = Serializer::serialize(&data);
	Data *		deserializedPointer = Serializer::deserialize(serializedPointerAsInt);

	if (deserializedPointer == &data)
		std::cout << "Successful serialization and deserialization." << std::endl << std::endl;
	else
		std::cout <<  "Failed serialization and deserialization: " << std::endl << std::endl;
	std::cout << "Original " << data << std::endl;
	std::cout << "Pointer to data structure serialized as int: " << serializedPointerAsInt << std::endl << std::endl;
	std::cout << "Deserialized " << *deserializedPointer << std::endl;
	return (0);
}