#include "pch.h"
#include "Klasse.h"

Person::Person(){
}
Person::Person(std::string firstName_, std::string lastName_, std::string email_, std::string company_){
}
Person::Person(std::string firstName_, std::string lastName_, std::string email_, std::string company_, Ladestelle stelle_){
}
Person::~Person(){
}

std::string Person::getFirstname(System::Void){
	return firstName;
}
std::string Person::getLastname(System::Void){
	return lastName;
}
std::string Person::getDepartment(System::Void){
	return department;
}
std::string Person::getEmail(System::Void){
	return email;
}
std::string Person::getCompany(System::Void){
	return company;
}
std::string Person::getPhone(System::Void){
	return phone;
}
System::Void Person::setFirstname(std::string firstName_){
	firstName = firstName_;
	return System::Void();
}
System::Void Person::setLastname(std::string lastName_){
	lastName = lastName_;
	return System::Void();
}
System::Void Person::setDepartment(std::string department_){
	department = department_;
	return System::Void();
}
System::Void Person::setEmail(std::string email_){
	email = email_;
	return System::Void();
}
System::Void Person::setCompany(std::string company_){
	company = company_;
	return System::Void();
}
System::Void Person::setPhone(std::string phone_){
	phone = phone_;
	return System::Void();
}

Ladestelle::Ladestelle(){
}
Ladestelle::Ladestelle(std::string werk_, std::string ort_, std::string street_, std::string building, int door_){
}
Ladestelle::~Ladestelle(){
}

std::string Ladestelle::getWerk(System::Void){
	return std::string();
}
std::string Ladestelle::getOrt(System::Void){
	return std::string();
}
std::string Ladestelle::getStreet(System::Void){
	return std::string();
}
std::string Ladestelle::getBuilding(System::Void){
	return std::string();
}
int Ladestelle::getDoor(System::Void){
	return door;
}
System::Void Ladestelle::setWerk(std::string){
	return System::Void();
}
System::Void Ladestelle::setOrt(std::string){
	return System::Void();
}
System::Void Ladestelle::setStreet(std::string){
	return System::Void();
}
System::Void Ladestelle::setBuilding(std::string){
	return System::Void();
}
System::Void Ladestelle::setPhone(int){
	return System::Void();
}