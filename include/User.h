/**
 * @file User.h
 * @author Javier Izquierdo (j.izquierdoh.2021@alumnos.urjc.es)
 * @brief Header file of User.cpp
 * @version 2.0
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <string>
#include <vector>
#include <chrono>
#include <ctime>
#include <ostream>
#ifndef USER_H
#define	USER_H

class User{
friend std::ostream &operator<< (std::ostream &,const User &);
public:
  /**
  * @brief Create a new User
  * 
  * @param employeeNumber 
  * @param NIF 
  * @param name 
  */
  User(std::string number = "00000",std::string nif = "00000000",std::string name = "default");
  ~User();
  /**
  * @brief Check if the user has the input NIF
  * 
  * @param NIF 
  * @return true = is the same NIF
  * @return false = is not the same NIF
  */
  bool isSameNIF(std::string);
  /**
  * @brief Check if the user has the input employee number
  * 
  * @param employeeNumber 
  * @return true = is the same employee number
  * @return false = is not the same employee number
  */
  bool isSameEmployeeNumber(std::string);
  /**
  * @brief Returns the user name
  * 
  * @return std::string User name
  */
  std::string getName();
  /**
  * @brief Set the timestamp 
  * 
  */
  void addTimestamp();
  /**
  * @brief Returns the timestamp
  * 
  * @return std::string Timestamp
  */
  std::string getTimestamp();
  /**
  * @brief Returns the user permissions
  * 
  * @return true = has admin pemissions 
  * @return false = does not have admin permissions
  */
  bool hasAdminPermission();
  bool operator<(const User &) const;
  bool operator==(const User &) const;

protected:
  std::string name;
  std::string NIF; /* 8 digits */
  std::string employeeNumber; /* 5 digits */
  std::string lastLogTime;
  bool adminPermission;

  /**
  * @brief Set the user NIF
  * 
  * @param NIF 
  */
  void setNIF(std::string);
  /**
  * @brief Set the user employee number
  * 
  * @param employeeNumber 
  */
  void setEmployeeNumber(std::string);
};

#endif