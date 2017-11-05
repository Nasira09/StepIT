#include <iostream>
#include <string>
#include <vector>
#include "Draw.h"
using namespace std;

class Person {
	string name;
	string surname;
	int age;
	string phone;
	string email;
public:
	Person()
	{
		this->name = "some name";
		this->surname = "some surname";
		this->age = 0;
		this->phone = "some phone";
		this->email = "some email";
	}
	Person(string name, string surname, int age)
	{
		this->name = name;
		this->surname = surname;
		this->age = age;
		this->phone = "";
		this->email = "";
	}
	Person(string name, string surname, int age, string phone, string email)
	{
		this->name = name;
		this->surname = surname;
		this->age = age;
		this->phone = phone;
		this->email = email;
	}
	void setName(string name)
	{
		this->name = name;
	}
	void setSurname(string surname)
	{
		this->surname;
	}
	void setAge(int age)
	{
		if (age > 14)
		{
			this->age = age;
		}
		else
			cout << "too little to match cryterias" << endl;
	}
	void setPhone(string phone)
	{
		this->phone = phone;
	}
	void setEmail(string email)
	{
		this->email = email;
	}
	string getName()
	{
		return this->name;
	}
	string getSurname()
	{
		return this->surname;
	}
	int getAge()
	{
		return this->age;
	}
	string getPhone()
	{
		return this->phone;
	}
	string getEmaile()
	{
		return this->email;
	}

	~Person() {};
};

class Student : public Person
{
	double average;
	double presence;
public:
	Student()
	{

	}
	Student(string name, string surname, int age) : Person(name, surname, age)
	{

	}
	Student(string name, string surname, int age, double avergae, double presence) : Person(name, surname, age)
	{
		this->average = average;
		this->presence = presence;
	}
	void setAverage(double average)
	{
		this->average = average;
	}
	void setPresence(double presence)
	{
		this->presence = presence;
	}
	double getAverage()
	{
		return this->average;
	}
	double getPresecne()
	{
		return this->presence;
	}

	~Student() {};
};

class Employee : public Person
{
	int salary;
	int experience;
public:
	Employee()
	{

	}
	Employee(string name, string surname, int age) : Person(name, surname, age)
	{

	}
	Employee(string name, string surname, int age, int salary, int experience) : Person(name, surname, age)
	{
		this->salary = salary;
		this->experience = experience;
	}
	void setSalary(double salary)
	{
		this->salary = salary;
	}
	void setExperience(double experience)
	{
		this->experience = experience;
	}
	double getSalary()
	{
		return this->salary;
	}
	double getExperience()
	{
		return this->experience;
	}
	~Employee() {};
};

class Teacher : public Employee
{
	vector <string> skills;
	int experience;
public:
	Teacher()
	{

	};
	Teacher(string name, string surname, int age) : Employee(name, surname, age)
	{

	}
	void addSkill(string skill)
	{
		skills.push_back(skill.c_str());
	}

	void getSkill()
	{
		for (int i = 0; i < skills.size(); i++)
		{
			cout << skills[i] << endl;
		}
	}
	~Teacher() {};
};

class Group {
	string name;
	string subject;
	vector <Student*> students;
	vector <Teacher*> teachers;
public:
	Group() {};

	Group(string name, string subject)
	{
		this->name = name;
		this->subject = subject;
	}

	void addStudent(Student *student)
	{
		students.push_back(student);
	}

	void addTeacher(Teacher *teacher)
	{
		teachers.push_back(teacher);
	}

	string getName()
	{
		return this->name;
	}
	string getSubject()
	{
		return this->subject;
	}

	int studensAmount()
	{
		return students.size();
	}

	void teacherInfo()
	{
		for (size_t i = 0; i < teachers.size(); i++)
		{
			cout << teachers[i]->getName() << " " << teachers[i]->getSurname();
		}
	}
	double groupAverage()
	{
		double result = 0;
		for (size_t i = 0; i < students.size(); i++)
		{
			result += students[i]->getAverage();
		}
		return result / students.size();
	}

	double groupPresenceAverage()
	{
		double result = 0;
		for (size_t i = 0; i < students.size(); i++)
		{
			result += students[i]->getPresecne();
		}
		return result / students.size();
	}
	void listStudents()
	{
		for (size_t i = 0; i < students.size(); i++)
		{
			cout << students[i]->getName() << endl;
		}
	}
};

class Director : public Employee {
	double rating;
public:
	Director() {};

	Director(string name, string surname, int age) : Employee(name, surname, age)
	{

	}
	void setRating(double rating)
	{
		this->rating = rating;
	}
	double getRating()
	{
		return this->rating;
	}
};

class Academy {
	string name;
	string city;
	string address;
	int monthlyFee = 280;
	int money;
	vector <Director*> director;
	vector <Group*> designers;
	vector <Group*> programmers;
	vector <Group*> admins;
	vector <Student*> students;
	vector <Employee*> employees;
	vector <Teacher*> teachers;
public:
	Academy() {};
	Academy(string name, string city, string address)
	{
		this->name = name;
		this->city = city;
		this->address = address;
	}
	void addStudent(Student *student)
	{
		students.push_back(student);
	}
	void addEmployee(Employee *employee)
	{
		employees.push_back(employee);
	}
	void addGroupProgrammers(Group *programmer)
	{
		programmers.push_back(programmer);
	}
	void addGroupDesigners(Group *designer)
	{
		designers.push_back(designer);
	}
	void addGroupAdmins(Group *admin)
	{
		admins.push_back(admin);
	}
	void addTeacher(Teacher *teacher)
	{
		teachers.push_back(teacher);
	}
	void addDirector(Director *dir)
	{
		director.push_back(dir);
	}

	void listStudents()
	{
		for (int i = 0; i < students.size(); i++)
		{
			cout << students[i]->getName() << "\t" << students[i]->getSurname() << "\t" << students[i]->getAge() << endl;
		}
	}
	void listTeachers()
	{
		for (int i = 0; i < teachers.size(); i++)
		{
			cout << teachers[i]->getName() << "\t" << teachers[i]->getSurname() << "\t" << teachers[i]->getAge() << endl;
		}
	}
	void listEmployees()
	{
		for (int i = 0; i < employees.size(); i++)
		{
			cout << employees[i]->getName() << " " << employees[i]->getSurname() << endl;
		}
	}
	void GroupProgrammersGetName(string str)
	{
		for (size_t i = 0; i < programmers.size(); i++)
		{
			if (str.compare(programmers[i]->getName()) == 0)
			{
				cout << programmers[i]->getName();
			}
		}
	}
	void GroupAdminsGetName(string str)
	{
		for (size_t i = 0; i < admins.size(); i++)
		{
			if (str.compare(admins[i]->getName()) == 0)
			{
				cout << admins[i]->getName();
			}
		}
	}
	void GroupDesignersGetName(string str)
	{
		for (size_t i = 0; i < designers.size(); i++)
		{
			if (str.compare(designers[i]->getName()) == 0)
			{
				cout << designers[i]->getName();
			}
		}
	}
	void GroupProgrammersGetSubject(string str)
	{
		for (size_t i = 0; i < programmers.size(); i++)
		{
			if (str.compare(programmers[i]->getName()) == 0)
			{
				cout << programmers[i]->getSubject() << endl;
			}
		}
	}
	void GroupAdminsGetSubject(string str)
	{
		for (size_t i = 0; i < admins.size(); i++)
		{
			if (str.compare(admins[i]->getName()) == 0)
			{
				cout << admins[i]->getSubject() << endl;
			}
		}
	}
	void GroupDesignersGetSubject(string str)
	{
		for (size_t i = 0; i < designers.size(); i++)
		{
			if (str.compare(designers[i]->getName()) == 0)
			{
				cout << designers[i]->getSubject() << endl;
			}
		}
	}
	void listGroupProgrammers()
	{
		for (int i = 0; i < programmers.size(); i++)
		{
			cout << programmers[i]->getName() << endl;
		}
	}
	void listGroupAdmins()
	{
		for (int i = 0; i < admins.size(); i++)
		{
			cout << admins[i]->getName() << endl;
		}
	}
	void listGroupDesigners()
	{
		for (int i = 0; i < designers.size(); i++)
		{
			cout << designers[i]->getName() << endl;
		}
	}


	string getName()
	{
		return name;
	}

	string getCity()
	{
		return city;
	}
	string getAddress()
	{
		return address;
	}


	void studentCountProgers(string str)
	{
		for (size_t i = 0; i < programmers.size(); i++)
		{
			if (str.compare(programmers[i]->getName()) == 0)
			{
				cout << programmers[i]->studensAmount();
			}
		}
	}
	void studentCountAdmins(string str)
	{
		for (size_t i = 0; i < admins.size(); i++)
		{
			if (str.compare(admins[i]->getName()) == 0)
			{
				cout << admins[i]->studensAmount();
			}
		}
	}
	void studentCountDesigners(string str)
	{
		for (size_t i = 0; i < designers.size(); i++)
		{
			if (str.compare(designers[i]->getName()) == 0)
			{
				cout << designers[i]->studensAmount();
			}
		}
	}
	void teacherProgers(string str)
	{
		for (size_t i = 0; i < programmers.size(); i++)
		{
			if (str.compare(programmers[i]->getName()) == 0)
			{
				programmers[i]->teacherInfo();
			}
		}
	}
	void teacherAdmins(string str)
	{
		for (size_t i = 0; i < admins.size(); i++)
		{
			if (str.compare(admins[i]->getName()) == 0)
			{
				admins[i]->teacherInfo();
			}
		}
	}
	void teacherDesigners(string str)
	{
		for (size_t i = 0; i < designers.size(); i++)
		{
			if (str.compare(designers[i]->getName()) == 0)
			{
				designers[i]->teacherInfo();
			}
		}
	}

	void progersGroupAverage(string str)
	{
		for (size_t i = 0; i < programmers.size(); i++)
		{
			if (str.compare(programmers[i]->getName()) == 0)
			{
				cout << programmers[i]->groupAverage();
			}

		}
	}
	void adminsGroupAverage(string str)
	{
		for (size_t i = 0; i < admins.size(); i++)
		{
			if (str.compare(admins[i]->getName()) == 0)
			{
				cout << admins[i]->groupAverage();
			}

		}
	}
	void designersGroupAverage(string str)
	{
		for (size_t i = 0; i < designers.size(); i++)
		{
			if (str.compare(designers[i]->getName()) == 0)
			{
				cout << designers[i]->groupAverage();
			}

		}
	}

	void progersGroupPresenceAverage(string str)
	{
		for (size_t i = 0; i < programmers.size(); i++)
		{
			if (str.compare(programmers[i]->getName()) == 0)
			{
				cout << programmers[i]->groupPresenceAverage();
			}
		}
	}
	void adminsGroupPresenceAverage(string str)
	{
		for (size_t i = 0; i < admins.size(); i++)
		{
			if (str.compare(admins[i]->getName()) == 0)
			{
				cout << admins[i]->groupPresenceAverage();
			}
		}
	}
	void designersGroupPresenceAverage(string str)
	{
		for (size_t i = 0; i < designers.size(); i++)
		{
			if (str.compare(designers[i]->getName()) == 0)
			{
				cout << designers[i]->groupPresenceAverage();
			}
		}
	}

	void listProgrammersGroupStudents(string str)
	{
		for (size_t i = 0; i < programmers.size(); i++)
		{
			if (str.compare(programmers[i]->getName()) == 0)
			{
				programmers[i]->listStudents();
			}
		}
	}
	void listAdminssGroupStudents(string str)
	{
		for (size_t i = 0; i < admins.size(); i++)
		{
			if (str.compare(admins[i]->getName()) == 0)
			{
				admins[i]->listStudents();
			}
		}
	}
	void listDesignersGroupStudents(string str)
	{
		for (size_t i = 0; i < designers.size(); i++)
		{
			if (str.compare(designers[i]->getName()) == 0)
			{
				designers[i]->listStudents();
			}
		}
	}
	void getDetails(string str)
	{
		for (size_t i = 0; i < students.size(); i++)
		{
			if (str.compare(students[i]->getName()) == 0)
			{
				cout << "Surname: " << students[i]->getSurname() << endl;
				cout << "Age: " << students[i]->getAge() << endl;
				cout << "Average: " << students[i]->getAverage() << endl;
				cout << "Presence: " << students[i]->getPresecne() << endl;
				cout << "Phone: " << students[i]->getPhone() << endl;
				cout << "Email: " << students[i]->getEmaile() << endl;
			}
		}
	}
	void getDetailsEmployees(string str)
	{

		for (size_t i = 0; i < employees.size(); i++)
		{
			if (str.compare(employees[i]->getName()) == 0)
			{
				cout << "Surname: \t" << employees[i]->getSurname() << endl;
				cout << "Age: \t\t" << employees[i]->getAge() << endl;
				cout << "Salary: \t" << employees[i]->getSalary() << endl;
				cout << "Experience: \t" << employees[i]->getExperience() << endl;

				for (size_t j = 0; j < teachers.size(); j++)
				{
					if (str.compare(teachers[j]->getName()) == 0)
					{
						cout << "Skills: \t"; teachers[j]->getSkill();
					}
				}

				//	cout << "Contracts: "; //<< employees[i]->getEmaile() << endl;

				if (str.compare(director[0]->getName()) == 0)
				{
					cout << "Rate: \t\t" << director[0]->getRating() << endl;
				}
				cout << "Phone: \t\t" << employees[i]->getPhone() << endl;
				cout << "Email: \t\t" << employees[i]->getEmaile() << endl;
			}
		}
	}

	string bestAverageStudent()
	{
		bool flag = true;
		double max = students[0]->getAverage();
		string result;
		for (size_t i = 1; i < students.size(); i++)
		{
			if (students[i]->getAverage() > max)
			{
				max = students[i]->getAverage();
				result = students[i]->getName();
				flag = false;
			}
		}
		if (flag)
			return students[0]->getName();
		else
			return result;
	}
	string bestAverageGroup()
	{
		bool flag = true;
		int i = 0;
		int j = 0;
		int q = 0;
		string result, result1, result2;
		double max = programmers[0]->groupAverage();
		double max1 = admins[0]->groupAverage();
		double max2 = designers[0]->groupAverage();
		for (i = 1; i < programmers.size(); i++)
		{
			if (programmers[i]->groupAverage() > max)
			{
				max = programmers[i]->groupAverage();
				result = programmers[i]->getName();
				flag = false;
			}
		}
		if (admins.size() > 1)
		{
			for (j = 1; j < admins.size(); j++)
			{
				if (admins[j]->groupAverage() > max1)
				{
					max1 = admins[j]->groupAverage();
					result1 = admins[j]->getName();
					flag = false;
				}
			}
		}
		if (designers.size() > 1)
		{
			for (q = 1; q < designers.size(); q++)
			{
				if (designers[q]->groupAverage() > max2)
				{
					max2 = designers[q]->groupAverage();
					result2 = designers[q]->getName();
					flag = false;
				}
			}
		}
		if (flag)
		{
			if (max > max1 && max > max2)
			{
				return programmers[0]->getName();
			}
			else if (max1 > max && max1 > max2)
			{
				return admins[0]->getName();
			}
			else if (max2 > max && max2 > max1)
			{
				return designers[0]->getName();
			}
		}
		else
		{
			if (max > max1 && max > max2)
			{
				return programmers[i]->getName();
			}
			else if (max1 > max && max1 > max2)
			{
				return admins[j]->getName();
			}
			else if (max2 > max && max2 > max1)
			{
				return designers[q]->getName();
			}
		}
	}
	string bestPresenseGroup()
	{
		bool flag = true;
		int i = 0;
		int j = 0;
		int q = 0;
		string result, result1, result2;
		double max = programmers[0]->groupPresenceAverage();
		double max1 = admins[0]->groupPresenceAverage();
		double max2 = designers[0]->groupPresenceAverage();
		for (i = 1; i < programmers.size(); i++)
		{
			if (programmers[i]->groupAverage() > max)
			{
				max = programmers[i]->groupPresenceAverage();
				result = programmers[i]->getName();
				flag = false;
			}
		}
		if (admins.size() > 1)
		{
			for (j = 1; j < admins.size(); j++)
			{
				if (admins[j]->groupPresenceAverage() > max1)
				{
					max1 = admins[j]->groupPresenceAverage();
					result1 = admins[j]->getName();
					flag = false;
				}
			}
		}
		if (designers.size() > 1)
		{
			for (q = 1; q < designers.size(); q++)
			{
				if (designers[q]->groupPresenceAverage() > max2)
				{
					max2 = designers[q]->groupPresenceAverage();
					result2 = designers[q]->getName();
					flag = false;
				}
			}
		}
		if (flag)
		{
			if (max > max1 && max > max2)
			{
				return programmers[0]->getName();
			}
			else if (max1 > max && max1 > max2)
			{
				return admins[0]->getName();
			}
			else if (max2 > max && max2 > max1)
			{
				return designers[0]->getName();
			}
		}
		else
		{
			if (max > max1 && max > max2)
			{
				return programmers[i]->getName();
			}
			else if (max1 > max && max1 > max2)
			{
				return admins[j]->getName();
			}
			else if (max2 > max && max2 > max1)
			{
				return designers[q]->getName();
			}
		}
	}


	string bestPresenceStudent()
	{
		bool flag = true;
		double max = students[0]->getPresecne();;
		string result;
		for (size_t i = 1; i < students.size(); i++)
		{
			if (students[i]->getPresecne() > max)
			{
				max = students[i]->getPresecne();
				result = students[i]->getName();
				flag = false;
			}
		}
		if (flag)
			return students[0]->getName();
		else
			return result;
	}
	int studentCount()
	{
		int result = students.size();
		return result;
	}

	int employeeCount()
	{
		int result = employees.size();
		return result;
	}
	void dirInfo()
	{
		for (size_t i = 0; i < director.size(); i++)
		{
			director[i]->getName();
		}
	}

	int AllGroupsAmount()
	{
		int result = 0;
		result = programmers.size() + designers.size() + admins.size();
		return result;
	}
};
class Program {
public:
	static void load(Academy &Step)
	{
		//Programmers Group
		Student *p1 = new Student("Vasif", "Abbasov", 29);
		p1->setAverage(100);
		p1->setPresence(1000);
		p1->setEmail("vasif.abbasov1988@gmail.com");
		p1->setPhone("055 268 94 15");
		Student *p2 = new Student("Zahid", "Abbasli", 27);
		p2->setAverage(50);
		p2->setPresence(90);
		p2->setEmail("Zahid234@gmail.com");
		p2->setPhone("055 556 65 98");
		Student *p3 = new Student("Samir", "Musayev", 26);
		p3->setAverage(90);
		p3->setPresence(80);
		Group *Programmers = new Group("FD301", "C#");
		Group *Programmers2 = new Group("FD302", "C++");
		Step.addStudent(p1);
		Step.addStudent(p2);
		Step.addStudent(p3);
		Step.addGroupProgrammers(Programmers);
		Step.addGroupProgrammers(Programmers2);
		Programmers->addStudent(p1);
		Programmers->addStudent(p2);
		Programmers2->addStudent(p3);


		//Designers Group
		Student *d1 = new Student("Sladusik", "Mamedova", 29);
		d1->setAverage(95);
		d1->setPresence(75);
		d1->setPhone("055 555 55 55");
		d1->setEmail("aykanamazgilanka@gmail.com");
		Group *Designers = new Group("FD501", "3dMax");
		Step.addStudent(d1);
		Step.addGroupDesigners(Designers);
		Designers->addStudent(d1);

		//Admins Group
		Student *a1 = new Student("Ruslan", "Qaflanov", 28);
		a1->setAverage(999);
		a1->setPresence(100);
		a1->setEmail("ruslan324@gmail.com");
		a1->setPhone("055 659 88 19");
		Group *Admins = new Group("FD401", "CCNA");
		Step.addStudent(a1);
		Step.addGroupAdmins(Admins);
		Admins->addStudent(a1);

		//Employees
		Employee *e1 = new Employee("Parvana", "Aliyeva", 23);
		e1->setEmail("parvana@gmail.com");
		e1->setExperience(200);
		e1->setPhone("055 659 65 11");
		e1->setSalary(1000);
		Step.addEmployee(e1);

		//Teachers
		Teacher *t1 = new Teacher("Gleb", "Skripnikov", 23);
		t1->addSkill("Javascript, DataBase, WebTechnologies");
		t1->setSalary(50);
		t1->setExperience(365);
		t1->setPhone("055 566 8974");
		t1->setEmail("Gleb@gmail.com");
		Teacher *t2 = new Teacher("Aleksandr", "SomeSurname", 25);
		t2->addSkill("C++, C, Python");
		t2->setEmail("aleks@gmail.com");
		t2->setExperience(365);
		t2->setPhone("055 658 46 46");
		t2->setSalary(50);
		Teacher *t3 = new Teacher("Rovshan", "SomeSurname", 25);
		t3->addSkill("Netowork");
		t3->setEmail("rovshan@gmail.com");
		t3->setExperience(365);
		t3->setPhone("055 658 46 46");
		t3->setSalary(50);
		Teacher *t4 = new Teacher("Nargiz", "Babayeva", 26);
		t4->addSkill("Photosho[");
		t4->setEmail("nargiz@gmail.com");
		t4->setExperience(365);
		t4->setPhone("055 658 46 46");
		t4->setSalary(50);
		Step.addTeacher(t1);
		Step.addTeacher(t2);
		Step.addTeacher(t3);
		Step.addTeacher(t4);
		Step.addEmployee(t1);
		Step.addEmployee(t2);
		Step.addEmployee(t3);
		Step.addEmployee(t4);
		Programmers->addTeacher(t1);
		Programmers2->addTeacher(t2);
		Admins->addTeacher(t3);
		Designers->addTeacher(t4);

		//Director
		Director *dir = new Director("Aleksey", "Slepcov", 45);
		dir->setRating(100);
		dir->setEmail("aleksey@gmail.com");
		dir->setExperience(500);
		dir->setSalary(2000);
		dir->setPhone("055 585 56 66");
		Step.addDirector(dir);
		Step.addEmployee(dir);

	}
	//	static void save();
	static void menu(Academy &Step)
	{
		int select = 0, select2 = 0, select3 = 0, select4 = 0;
		while (true)
		{
			system("cls");
			drawData("Academy information  \t\n", DARKGREY, BLUE);
			drawData("*********************\t\n", DARKGREY, BLUE);

			if (select == 0)
				drawData("Name of Academy    ->\t\n", BLUE, LIGHTGREY);
			else
				drawData("Name of Academy      \t\n", LIGHTGREY, BLUE);
			if (select == 1)
				drawData("City of Academy    ->\t\n", BLUE, LIGHTGREY);
			else
				drawData("City of Academy      \t\n", LIGHTGREY, BLUE);
			if (select == 2)
				drawData("Adress of Academy  ->\t\n", BLUE, LIGHTGREY);
			else
				drawData("Adress of Academy    \t\n", LIGHTGREY, BLUE);
			if (select == 3)
				drawData("Amount of groups   ->\t\n", BLUE, LIGHTGREY);
			else
				drawData("Amount of groups     \t\n", LIGHTGREY, BLUE);
			if (select == 4)
				drawData("Student amount     ->\t\n", BLUE, LIGHTGREY);
			else
				drawData("Student amount       \t\n", LIGHTGREY, BLUE);
			if (select == 5)
				drawData("Employee amount    ->\t\n", BLUE, LIGHTGREY);
			else
				drawData("Employee amount      \t\n", LIGHTGREY, BLUE);
			if (select == 6)
				drawData("Director info      ->\t\n", BLUE, LIGHTGREY);
			else
				drawData("Director info        \t\n", LIGHTGREY, BLUE);

			drawData("*********************\t\n", DARKGREY, BLUE);
			drawData("List of Groups       \t\n", DARKGREY, BLUE);
			drawData("*********************\t\n", DARKGREY, BLUE);

			if (select == 7)
				drawData("Group Details      ->\t\n", BLUE, LIGHTGREY);
			else
				drawData("Group Details        \t\n", LIGHTGREY, BLUE);


			drawData("*********************\t\n", DARKGREY, BLUE);
			drawData("Student infromation  \t\n", DARKGREY, BLUE);
			drawData("*********************\t\n", DARKGREY, BLUE);

			if (select == 8)
				drawData("Student details    ->\t\n", BLUE, LIGHTGREY);
			else
				drawData("Student details      \t\n", LIGHTGREY, BLUE);

			drawData("*********************\t\n", DARKGREY, BLUE);
			drawData("Employees infromation\t\n", DARKGREY, BLUE);
			drawData("*********************\t\n", DARKGREY, BLUE);

			if (select == 9)
				drawData("Employee details   ->\t\n", BLUE, LIGHTGREY);
			else
				drawData("Employee details     \t\n", LIGHTGREY, BLUE);

			drawData("*********************\t\n", DARKGREY, BLUE);
			drawData("Ratings              \t\n", DARKGREY, BLUE);
			drawData("*********************\t\n", DARKGREY, BLUE);

			if (select == 10)
				drawData("Academy ratings    ->\t\n", BLUE, LIGHTGREY);
			else
				drawData("Academy ratings      \t\n", LIGHTGREY, BLUE);
			if (select == 11)
				drawData("Group GPT          ->\t\n", BLUE, LIGHTGREY);
			else
				drawData("Group GPT            \t\n", LIGHTGREY, BLUE);
			if (select == 12)
				drawData("Student amount     ->\t\n", BLUE, LIGHTGREY);
			else
				drawData("Student amount       \t\n", LIGHTGREY, BLUE);
			if (select == 13)
				drawData("Average attendence ->\t\n", BLUE, LIGHTGREY);
			else
				drawData("Average attendence   \t\n", LIGHTGREY, BLUE);



			int key = _getch();
			if (key == 'w' && select > 0)
				select--;
			if (key == 's' && select < 13)
				select++;

			if (key == 13)
			{
				COORDS(0, 0);
				system("cls");
				if (select == 0)
				{
					drawData(Step.getName(), LIGHTGREY, BLUE);
				}
				if (select == 1)
				{
					drawData(Step.getCity(), LIGHTGREY, BLUE);
				}
				if (select == 2)
				{
					drawData(Step.getAddress(), LIGHTGREY, BLUE);
				}
				if (select == 3)
				{
					drawData(Step.AllGroupsAmount(), LIGHTGREY, BLUE);
				}
				if (select == 4)
				{
					drawData(Step.studentCount(), LIGHTGREY, BLUE);
				}
				if (select == 5)
				{
					drawData(Step.employeeCount(), LIGHTGREY, BLUE);
				}
				if (select == 6)
				{
					//drawData(Step.dirInfo(), LIGHTGREY, BLUE);
				}
				if (select == 7)
				{
					while (true)
					{
						system("cls");
						drawData("Academy groups   \t\n", DARKGREY, BLUE);
						drawData("*****************\t\n", DARKGREY, BLUE);

						if (select2 == 0)
							drawData("Programmers    ->\t\n", BLUE, LIGHTGREY);
						else
							drawData("Programmers      \t\n", LIGHTGREY, BLUE);
						if (select2 == 1)
							drawData("Admins         ->\t\n", BLUE, LIGHTGREY);
						else
							drawData("Admins           \t\n", LIGHTGREY, BLUE);
						if (select2 == 2)
							drawData("Designers      ->\t\n", BLUE, LIGHTGREY);
						else
							drawData("Designers        \t\n", LIGHTGREY, BLUE);
						if (select2 == 3)
							drawData("Return         ->\t\n", BLUE, LIGHTGREY);
						else
							drawData("Return           \t\n", LIGHTGREY, BLUE);

						int key = _getch();
						if (key == 'w' && select2 > 0)
							select2--;
						if (key == 's' && select2 < 3)
							select2++;

						if (key == 13)
						{
							COORDS(0, 0);
							system("cls");
							if (select2 == 0)
							{
								Step.listGroupProgrammers();
								cout << "Choose Group: ";
								string str, str2 = "FD301", str3 = "FD302";
								getline(cin, str);


								cout << "Name of the group: "; Step.GroupProgrammersGetName(str);
								cout << endl;
								cout << "Subject : "; Step.GroupProgrammersGetSubject(str);
								cout << "Amount of students: "; Step.studentCountProgers(str);
								cout << endl;
								cout << "Teacher: "; Step.teacherProgers(str);
								cout << endl;
								cout << "Average point of the group: "; Step.progersGroupAverage(str);
								cout << endl;
								cout << "Average presence: "; Step.progersGroupPresenceAverage(str);

							}
							if (select2 == 1)
							{
								Step.listGroupAdmins();
								cout << "Choose Group: ";
								string str;
								getline(cin, str);

								cout << "Name of the group: "; Step.GroupAdminsGetName(str);
								cout << endl;
								cout << "Subject : "; Step.GroupAdminsGetSubject(str);
								cout << "Amount of students: "; Step.studentCountAdmins(str);
								cout << endl;
								cout << "Teacher: "; Step.teacherAdmins(str);
								cout << endl;
								cout << "Average point of the group: "; Step.adminsGroupAverage(str);
								cout << endl;
								cout << "Average presence: "; Step.adminsGroupPresenceAverage(str);

							}
							if (select2 == 2)
							{
								Step.listGroupDesigners();
								cout << "Choose Group: ";
								string str;
								getline(cin, str);

								cout << "Name of the group: "; Step.GroupDesignersGetName(str);
								cout << endl;
								cout << "Subject : "; Step.GroupDesignersGetSubject(str);
								cout << "Amount of students: "; Step.studentCountDesigners(str);
								cout << endl;
								cout << "Teacher: "; Step.teacherDesigners(str);
								cout << endl;
								cout << "Average point of the group: "; Step.designersGroupAverage(str);
								cout << endl;
								cout << "Average presence: "; Step.designersGroupPresenceAverage(str);

							}
							if (select2 == 3)
							{
								break;
							}
							_getch();
						}
					}
				}
				if (select == 8)
				{
					while (true)
					{
						system("cls");
						drawData("Academy groups   \t\n", DARKGREY, BLUE);
						drawData("*****************\t\n", DARKGREY, BLUE);

						if (select3 == 0)
							drawData("Programmers    ->\t\n", BLUE, LIGHTGREY);
						else
							drawData("Programmers      \t\n", LIGHTGREY, BLUE);
						if (select3 == 1)
							drawData("Admins         ->\t\n", BLUE, LIGHTGREY);
						else
							drawData("Admins           \t\n", LIGHTGREY, BLUE);
						if (select3 == 2)
							drawData("Designers      ->\t\n", BLUE, LIGHTGREY);
						else
							drawData("Designers        \t\n", LIGHTGREY, BLUE);
						if (select3 == 3)
							drawData("Return         ->\t\n", BLUE, LIGHTGREY);
						else
							drawData("Return           \t\n", LIGHTGREY, BLUE);

						int key = _getch();
						if (key == 'w' && select3 > 0)
							select3--;
						if (key == 's' && select3 < 3)
							select3++;

						if (key == 13)
						{
							COORDS(0, 0);
							system("cls");

							if (select3 == 0)
							{
								Step.listGroupProgrammers();
								cout << "Choose Group: ";
								string str, str1;
								getline(cin, str);

								cout << "Group Students List: \n";
								Step.listProgrammersGroupStudents(str);
								cout << "Input name for more details: ";
								getline(cin, str1);
								Step.getDetails(str1);
							}
							if (select3 == 1)
							{
								Step.listGroupAdmins();
								cout << "Choose Group: ";
								string str, str1;
								getline(cin, str);

								cout << "Group Students List: \n";
								Step.listAdminssGroupStudents(str);
								cout << "Input name for more details: ";
								getline(cin, str1);
								Step.getDetails(str1);
							}
							if (select3 == 2)
							{
								Step.listGroupDesigners();
								cout << "Choose Group: ";
								string str, str1;
								getline(cin, str);

								Step.listDesignersGroupStudents(str);
								cout << "Input name for more details: ";
								getline(cin, str1);
								Step.getDetails(str1);

							}

							if (select3 == 3)
							{
								break;
							}
							_getch();
						}
					}
				}
				if (select == 9)
				{
					while (true)
					{
						system("cls");
						drawData("Academy employees\t\n", DARKGREY, BLUE);
						drawData("*****************\t\n", DARKGREY, BLUE);

						Step.listEmployees();
						cout << "\nChoose Employee: ";
						string str;
						getline(cin, str);
						Step.getDetailsEmployees(str);
						if (key == 13)
						{
							break;
						}
						_getch();
					}
				}
				if (select == 10)
				{
					cout << "Best average student:\t" << Step.bestAverageStudent() << endl;
					cout << "Best presence student:\t" << Step.bestPresenceStudent() << endl;
					cout << "Best average group:\t" << Step.bestAverageGroup() << endl;
					cout << "Best presence group:\t" << Step.bestPresenseGroup() << endl;
				}
				_getch();
			}
		}
	};
};

void main()
{
	Academy Step("ItStep", "Baku", "KorOglu 70");
	Program p;
	p.load(Step);
	p.menu(Step);
}