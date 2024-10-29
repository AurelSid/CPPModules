#ifndef PHONE_H
  #define PHONE_H

class Phonebook
{
  public:
  Contact[8];

  void  add();
  void  search();
  void  exit();

}

class Contact
{
  std::string   first_name;
  std::string   last_name;
  std::string   nichname;
  std::string   phone;

}
