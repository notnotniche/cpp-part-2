#include <iostream>
#include <stdint.h>
#include "Data.hpp"
#include "Serializer.hpp"

int main(void)
{
	Data data;
	data.str = "time to serialize";

	uintptr_t serialized = Serializer::serialize(&data);

	Data* deserialized = Serializer::deserialize(serialized);

	if (deserialized == &data)
		std::cout << "ITS THE SAME THING" << std::endl;
	else
		std::cout << "EPIC FAIL" << std::endl;

	return (0);
}
