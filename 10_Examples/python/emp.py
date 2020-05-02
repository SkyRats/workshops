class Employee:
  def __init__(self, name, salary):
    self.__salary = salary
    self.name = name
    
  def set_salary(self, new_value):
    self.__salary = new_value
  
  def get_salary(self):
    return self.__salary

  def present(self):
    print("Hey there, name is {} and I earn {} bucks a month".format(self.name, self.__salary))


class Employer:
  def __init__(self, name):
    self.name = name
    self.people = []

  def employ(self, employee):
    self.people.append(employee)

  def present(self):
    print("Hey there, name is {} and I hired those guys:\n".format(self.name))
    for guy_or_girl in self.people:
      print("* {} - ${}".format(guy_or_girl.name, guy_or_girl.get_salary()))