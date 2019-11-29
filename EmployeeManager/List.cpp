#include "List.h"

List::List() : first(nullptr), last(nullptr) {}
List::List(Employee& employee) : first(&employee), last(&employee) {
	employee.next = nullptr;
	employee.previous = nullptr;
}
List::List(const List& list) : first(list.first), last(list.last) {}

List::~List() {
	Employee* employee = this->first;
	Employee* next_employee;

	while (employee != nullptr) {
		next_employee = employee->next;

		delete employee; // next and previous became nullptr pointer
		employee = next_employee;
	}
}

int List::size_of_list() {
	Employee* current_employee = this->first;
	int list_size = 0;

	while (current_employee != nullptr) {
		list_size++;
		current_employee = current_employee->next;
	}
	return list_size;
}

void List::display_list() {
	if (first == nullptr) { // list empty
		cout << "Khong co gi de hien thi" << endl;
		return; // do nothing
	}
	Employee* current_employee = this->first;

	while (current_employee != nullptr) {
		current_employee->show();
		current_employee = current_employee->next;
	}
}

//void calc_hsl(const string& chuc_vu, int& hsl) {
//	if (chuc_vu == "nhan vien")
//		hsl = 1;
//	else if (chuc_vu == "truong phong")
//		hsl = 2;
//	else if (chuc_vu == "giam doc")
//		hsl = 3;
//}

void List::add_employee_at_first() {
	Employee* new_employee = new Employee();
	cin >> *new_employee;

	if (this->first == nullptr) {
		this->last = new_employee;
	}
	else {
		this->first->previous = new_employee;
	}

	new_employee->previous = nullptr;
	new_employee->next = this->first;
	this->first = new_employee;
}
void List::add_employee_at_last() {
	Employee* new_employee = new Employee();
	cin >> *new_employee;

	if (this->first == nullptr) {
		this->first = new_employee;
	}
	else {
		this->last->next = new_employee;
	}

	new_employee->previous = this->last;
	new_employee->next = nullptr;
	this->last = new_employee;
}
void List::add_employee_at_last(Employee& employee) {
	Employee* new_employee = &employee;

	if (this->first == nullptr) {
		this->first = new_employee;
	}
	else {
		this->last->next = new_employee;
	}

	new_employee->previous = this->last;
	new_employee->next = nullptr;
	this->last = new_employee;
}
void List::add_employee_at_specific_pos(int k) {
	Employee* present_employee = this->first;
	int index = 0; // to find where to add new employee

	while (present_employee != nullptr) {
		if (index != k) {
			present_employee = present_employee->next;
			index++;
		}
		else {
			break; // index == k
		}
	}

	if (present_employee == nullptr) {
		if (k == this->size_of_list()) { // case k == list's size, so insert employee at the bottom of the list
			this->add_employee_at_last(); // call add last
		}
		else { // case out of list's size + 1
			cout << "Khong the them o vi tri nay" << endl;
		}
	}
	else if (present_employee == first) {
		this->add_employee_at_first(); // call add first
	}
	else { // case present_employee having previous and next != nullptr
		Employee* new_employee = new Employee();
		cin >> *new_employee;

		present_employee->previous->next = new_employee;
		new_employee->previous = present_employee->previous;
		present_employee->previous = new_employee;
		new_employee->next = present_employee;
	}
}

Employee& List::search_employee_by_id(string id) {
	Employee* current_employee = this->first;

	while (current_employee != nullptr && current_employee->compare_id(id) == false) { // search for the correct employee in the list 
		current_employee = current_employee->next;
	}

	return *current_employee; // return NULL if its not found otherwise return correct employee
}

void List::print_statistics() {
	if (first == nullptr) { // list empty
		return; // do nothing
	}

	Employee* current_employee = this->first;
	int male = 0, female = 0;
	double tong_thuc_linh = 0;

	while (current_employee != nullptr) {
		if (current_employee->get_gioi_tinh() == "NAM")
			male++;
		else
			female++;
		tong_thuc_linh += current_employee->thuc_linh();
		current_employee = current_employee->next;
	}

	cout << "So luong nhan vien nam: " << male << endl;
	cout << "So luong nhan vien nu: " << female << endl;
	cout << "Tong thuc linh: " << tong_thuc_linh << endl;
}

void List::delete_employee_at_first() {
	if (first == nullptr) { // case list empty
		return; // do nothing and return
	}
	else if (this->first == this->last) { // case list only have 1 employee
		delete first;
		first = nullptr;
		last = nullptr;
	}
	else {
		Employee* current_employee = this->first;
		this->first = this->first->next;
		this->first->previous = nullptr;

		delete current_employee;
	}
}
void List::delete_employee_at_last() {
	if (last == nullptr) { // case list empty
		return; // do nothing and return
	}
	else if (this->first == this->last) { // case list only have 1 employee
		delete last;
		first = nullptr;
		last = nullptr;
	}
	else {
		Employee* current_employee = this->last;
		this->last = this->first->previous;
		this->last->next = nullptr;

		delete current_employee;
	}
}
void List::delete_employee_at_specific_pos(int k) { // k: positon to remove employee
	Employee* employee = this->first;
	int index = 0; // to find where to add new employee

	while (employee != nullptr) {
		if (index != k) {
			employee = employee->next;
			index++;
		}
		else {
			break; // index == k
		}
	}

	if (index >= this->size_of_list()) {
		cout << "Khong tim thay nguoi nay" << endl;
		return;
	}

	if (employee != nullptr && this->size_of_list() != 1) {
		if (employee == this->first) {
			this->first = employee->next;
			employee->next->previous = nullptr;
			delete employee;
		}
		else if (employee == this->last) {
			this->last = employee->previous;
			employee->previous->next = nullptr;
			delete employee;
		}
		else {
			employee->previous->next = employee->next;
			employee->next->previous = employee->previous;
			delete employee;
		}
	}
	else if (employee != nullptr && this->size_of_list() == 1) {
		this->delete_employee_at_first();
	}
}

void upper_case(string& str) {
	for (char& c : str) {
		if (int(c) >= 97 && int(c) <= 122) {
			c -= 32;
		}
	}
}
bool List::delete_employee(string ma_nhan_vien) {
	if (first == NULL) {
		return false;
	}

	Employee* employee = first;
	while ((employee != NULL) && (employee->get_ma_nhan_vien() != ma_nhan_vien)) {
		employee = employee->next;
	}

	if (employee != nullptr && this->size_of_list() != 1) {
		if (employee == this->first) {
			this->first = employee->next;
			employee->next->previous = nullptr;
			delete employee;
		}
		else if (employee == this->last) {
			this->last = employee->previous;
			employee->previous->next = nullptr;
			delete employee;
		}
		else {
			employee->previous->next = employee->next;
			employee->next->previous = employee->previous;
			delete employee;
		}
	}
	else if (employee != nullptr && this->size_of_list() == 1) {
		this->delete_employee_at_first();
	}
	else { // employee == nullptr
		return false;
	}
	return true;
}
bool List::delete_employee_by_name(string ten) {
	if (this->first == nullptr)
		return false;

	Employee* employee = this->first;
	bool check = false;
	upper_case(ten);

	while (employee != nullptr) {
		if (employee->get_ten() == ten) {
			if (this->size_of_list() == 1) {
				this->delete_employee_at_first();
				return true;
			}
			else {
				if (employee == this->first) {
					this->first = employee->next;
					employee->next->previous = nullptr;
					delete employee;
					employee = this->first;
				}
				else if (employee == this->last) {
					this->last = employee->previous;
					employee->previous->next = nullptr;
					delete employee;
					employee = this->last;
				}
				else {
					Employee* t = employee->previous;
					employee->previous->next = employee->next;
					employee->next->previous = employee->previous;
					delete employee;
					employee = t;
				}
				check = true;
			}
		}
		employee = employee->next;
	}

	return check;
}
bool List::delete_old_employee() {
	if (this->first == nullptr)
		return false;

	Employee* employee = this->first;
	bool check = false;

	while (employee != nullptr) {
		if (2019 - employee->get_nam_sinh() >= 50) {
			if (this->size_of_list() == 1) {
				this->delete_employee_at_first();
				return true;
			}
			else {
				if (employee == this->first) {
					this->first = employee->next;
					employee->next->previous = nullptr;
					delete employee;
					employee = this->first;
				}
				else if (employee == this->last) {
					this->last = employee->previous;
					employee->previous->next = nullptr;
					delete employee;
					employee = this->last;
				}
				else {
					Employee* t = employee->previous;
					employee->previous->next = employee->next;
					employee->next->previous = employee->previous;
					delete employee;
					employee = t;
				}
				check = true;
			}
		}
		employee = employee->next;
	}

	return check;
}

void List::update_employee_info(string id) {
	Employee* employee = &search_employee_by_id(id);

	if (employee == nullptr) {
		cout << "Khong tim thay nguoi nay" << endl;
		return;
	}

	employee->update_info(*employee);
}

bool List::check_if_contain(string id) {
	Employee* current_employee = this->first;

	while (current_employee != nullptr) {
		if (current_employee->compare_id(id) == true) {
			return true;
		}
		current_employee = current_employee->next;
	}

	return false; // current_employee == nullptr 
}

// sort related
void swap(Employee* left, Employee* right) {
	Employee* temp = new Employee();
	temp->copy_info(*left);

	left->copy_info(*right);
	right->copy_info(*temp);

	delete temp;
}
Employee* partition(Employee* left, Employee* right, bool check) {
	Employee* i = left->previous;
	Employee* j = left;

	while (j != right->next) {
		if (j->compare_age(*right, check) == true) {
			if (i == nullptr)
				i = left;
			else
				i = i->next;
			swap(i, j);
		}
		j = j->next;
	}

	return i;
}
void List::quick_sort(Employee* left, Employee* right, bool check) {
	if (left != right && left != nullptr && right != nullptr) {
		Employee* q = partition(left, right, check);
		if (q->previous != nullptr && q != left->previous) {
			quick_sort(left, q->previous, check);
		}
		if (q->next != nullptr && q != left->previous) {
			quick_sort(q->next, right, check);
		}
	}
}

void tinh_hsl(const string& chuc_vu, int& hsl) {
	if (chuc_vu == "NHAN VIEN")
		hsl = 1;
	else if (chuc_vu == "TRUONG PHONG")
		hsl = 2;
	else if (chuc_vu == "GIAM DOC")
		hsl = 3;
	else
		hsl = 1;
}
void List::read_file() {
	int i = 0;
	string hoTen, maNhanVien, gioiTinhStr;
	string donVi, chucVu;
	bool gioi_tinh;

	ifstream reader("records.txt");
	if (!reader) {
		cout << "Error opening input file" << endl;
		return;
	}

	while (!reader.eof()) {
		// lay thong tin tu file
		if (i == 0)
			getline(reader, hoTen, '\t');
		else if (i == 1)
			getline(reader, maNhanVien, '\t');
		else if (i == 2) {
			getline(reader, gioiTinhStr, '\t');
			if (gioiTinhStr == "NAM")
				gioi_tinh = false;
			else
				gioi_tinh = true;
		}
		else if (i == 3)
			getline(reader, donVi, '\t');
		else if (i == 4) {
			getline(reader, chucVu, '\t');
		}
		else if (i == 5) {
			string ngay_str, thang_str, nam_str;
			int ngay, thang, nam;
			int hsl;

			getline(reader, ngay_str, '\t');
			getline(reader, thang_str, '\t');
			getline(reader, nam_str, '\n');
			tinh_hsl(chucVu, hsl);

			stringstream converter;

			converter.str(ngay_str);
			converter >> ngay;
			converter.clear();
			converter.str(thang_str);
			converter >> thang;
			converter.clear();
			converter.str(nam_str);
			converter >> nam;
			converter.clear();

			Employee* employee_new = new Employee(maNhanVien, hoTen, donVi, chucVu, gioi_tinh, hsl, ngay, thang, nam);
			this->add_employee_at_last(*employee_new);
			i = 0;
			continue;
		}
		i++;
	}
	reader.close();
}
void List::write_file() {
	ofstream writer("records.txt");
	if (!writer) {
		cout << "error opening file for output" << endl;
		return;
	}
	Employee* currentnode = this->first;
	for (currentnode; currentnode != nullptr; currentnode = currentnode->next) {
		string info = currentnode->get_ten() + "\t" + currentnode->get_ma_nhan_vien() + "\t";
		info += currentnode->get_gioi_tinh() + "\t" + currentnode->get_don_vi() + "\t";
		info += currentnode->get_chuc_vu() + "\t" + currentnode->get_string_date();

		//info = to_upper_case(info);

		writer << info << endl;
	}
	writer.close();
}
//void List::append_file(const string& str) {
//	ofstream writer("records.txt", ios::app);
//	if (!writer) {
//		cout << "Error opening file for output" << endl;
//		return;
//	}
//	i++;
//	writer << str << endl;
//	writer.close();
//}

