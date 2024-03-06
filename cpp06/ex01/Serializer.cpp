#include "Serializer.hpp"

Serializer::Serializer(){
	std::cout<<"Serializer constructor called"<<std::endl;
}

Serializer::Serializer(Serializer const &toCopy){
	if (this != &toCopy)
		*this = toCopy;
	std::cout<<"Serializer copy constructor called"<<std::endl;
}

Serializer::~Serializer(){
	std::cout<<"Serializer destructor called"<<std::endl;
}

Serializer& Serializer::operator=(Serializer const &toCopy){
	if (this != &toCopy)
		*this = toCopy;
	return (*this);
}

uintptr_t	Serializer::serialize(Data *ptr){
	return reinterpret_cast<uintptr_t>(ptr);
}

Data	*Serializer::deserialize(uintptr_t raw){
	return reinterpret_cast<Data *>(raw);
}
