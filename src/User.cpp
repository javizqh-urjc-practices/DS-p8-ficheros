/**
 * @file User.cpp
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief 
 * @version 2.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "User.h"
#include <iostream>
#include <iomanip> // I/O manipulation library

std::ostream &operator<< (std::ostream &output, const User &user){
  output << "( " << user.name << ", " << user.employeeNumber << ", " << user.NIF << " ) ";
  return output;
}

User::User(std::string employeeNumber, std::string NIF, std::string name){
  this->name = name;
  User::setEmployeeNumber(employeeNumber);
  User::setNIF(NIF);
  this->lastLogTime = "";
  this->addTimestamp();
  this->adminPermission = false;
}

bool User::operator<(const User& user) const {
   return NIF > user.NIF || employeeNumber < user.employeeNumber;  //assume that you compare the record based on a
}

bool User::operator==(const User& user) const {
   return NIF.compare(user.NIF) == 0 && employeeNumber.compare(user.employeeNumber) == 0 && name.compare(user.name) == 0;  //assume that you compare the record based on a
}

bool User::isSameNIF(std::string NIF){
  return this->NIF.compare(NIF) == 0;
};

void User::setNIF(std::string NIF){
  if (NIF.size() == 8){
    this->NIF =NIF;
  } else {
    this->NIF = "00000000";
  }
};

bool User::isSameEmployeeNumber(std::string employeeNumber){
  return this->employeeNumber.compare(employeeNumber) == 0;
};

void User::setEmployeeNumber(std::string employeeNumber){
  if (employeeNumber.size() == 5){
    this->employeeNumber = employeeNumber;
  } else {
    this->employeeNumber = "00000";
  }
};

std::string User::getName(){
  return this->name;
};

void User::addTimestamp(){
  auto date = std::chrono::system_clock::now();
  time_t t = std::chrono::system_clock::to_time_t(date);

  this->lastLogTime = std::ctime(&t);
};

std::string User::getTimestamp(){
  return this->lastLogTime;
};

bool User::hasAdminPermission(){
  return this->adminPermission;
}

User::~User(){};