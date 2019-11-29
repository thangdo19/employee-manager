#include"Employee.h"
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
class List {
public:
	Employee* first;
	Employee* last;

	List();
	List(Employee&); // add first employee to the list.
	List(const List&);
	~List();

	void read_file();
	void write_file();
	void append_file(const string&);

	int size_of_list();

	void display_list();
	void add_employee_at_first();
	void add_employee_at_last();
	void add_employee_at_last(Employee&);
	void add_employee_at_specific_pos(int k); // k : position to add.
	void update_employee_info(string);
	void delete_employee_at_first();
	void delete_employee_at_last();
	void delete_employee_at_specific_pos(int k);
	bool delete_employee(string);
	bool delete_employee_by_name(string);
	bool delete_old_employee(); // delete employees thats aged >= 50
	Employee& search_employee_by_id(string);
	void sort_list_by_age();
	void print_statistics();

	//void swap(Employee*&, Employee*&);
	bool check_if_contain(string id);

	friend void swap(Employee*, Employee*);
	friend Employee* partition(Employee*, Employee*, bool);
	void quick_sort(Employee*, Employee*, bool);
};
