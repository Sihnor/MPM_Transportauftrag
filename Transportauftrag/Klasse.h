#pragma once
#pragma once
#include <string>

class Ladestelle
{
public:
	static int stellenCount;
	Ladestelle();
	Ladestelle(std::string werk_, std::string ort_, std::string street_, std::string building, int door_);
	~Ladestelle();

	std::string getWerk(System::Void);
	std::string getOrt(System::Void);
	std::string getStreet(System::Void);
	std::string getBuilding(System::Void);
	int getDoor(System::Void);

	System::Void setWerk(std::string);
	System::Void setOrt(std::string);
	System::Void setStreet(std::string);
	System::Void setBuilding(std::string);
	System::Void setPhone(int);

private:
	std::string werk;
	std::string ort;
	std::string street;
	std::string building;

	int door;
};

class Person
{
public:
	static int personCount;
	Person();
	Person(std::string firstName_, std::string lastName_, std::string email_, std::string company_);
	Person(std::string firstName_, std::string lastName_, std::string email_, std::string company_, Ladestelle stelle_);
	~Person();

	std::string getFirstname(System::Void);
	std::string getLastname(System::Void);
	std::string getDepartment(System::Void);
	std::string getEmail(System::Void);
	std::string getCompany(System::Void);
	std::string getPhone(System::Void);

	System::Void setFirstname(std::string firstName_);
	System::Void setLastname(std::string lastName_);
	System::Void setDepartment(std::string department);
	System::Void setEmail(std::string email_);
	System::Void setCompany(std::string company_);
	System::Void setPhone(std::string phone_);

private:
	std::string firstName;
	std::string lastName;
	std::string department;
	std::string email;
	std::string company;
	std::string phone;

	Ladestelle stelle;
};