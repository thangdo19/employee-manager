#include"Employee.h"
#include<iostream>
#include<string>
using namespace std;

// --------------------------- CONSTRUCTORS & DESTRUCTOR --------------------------- \\

Employee::Employee(string ma_nhan_vien, string ten, string don_vi, string chuc_vu, bool gioi_tinh, int he_so_luong, int ngay, int thang, int nam)
	: ma_nhan_vien(ma_nhan_vien), ten(ten), don_vi(don_vi), chuc_vu(chuc_vu), gioi_tinh(gioi_tinh), he_so_luong(he_so_luong) {
	this->ngay_sinh = new Date(ngay, thang, nam);
	this->next = nullptr;
	this->previous = nullptr;
}
Employee::Employee(const Employee& p)
	: ma_nhan_vien(p.ma_nhan_vien), ten(p.ten), don_vi(p.don_vi), chuc_vu(p.chuc_vu), gioi_tinh(p.gioi_tinh), he_so_luong(p.he_so_luong) {
	this->ngay_sinh = new Date(*p.ngay_sinh);
	this->next = nullptr;
	this->previous = nullptr;
}
Employee::Employee()
	: ma_nhan_vien(""), ten(""), don_vi(""), chuc_vu(""), gioi_tinh(false), he_so_luong(0) {
	this->ngay_sinh = new Date();
	this->next = nullptr;
	this->previous = nullptr;
}
Employee::~Employee() {
	// list's destructor will delete it, memory without pointer will be erase.
	this->next = nullptr;
	this->previous = nullptr;
	delete this->ngay_sinh;
}

void Employee::show() {
	//cout << "Ma Nhan Vien: " << this->ma_nhan_vien << endl;
	//cout << "Ten: " << this->ten << endl;

	//if (this->gioi_tinh == false) {
	//	cout << "Gioi tinh: " << "Nam" << endl;
	//}
	//else {
	//	cout << "Gioi tinh: " << "Nu" << endl;
	//}

	//cout << "Ngay sinh: " << *this->ngay_sinh << endl;

	cout << this->ma_nhan_vien << " " << this->ten << " ";
	if (this->gioi_tinh == false)
		cout << "NAM" << " ";
	else
		cout << "NU" << " ";
	cout << this->don_vi << " " << this->chuc_vu << " ";
	cout << *this->ngay_sinh << endl;
}

bool Employee::equals(const Employee& p) {
	if (this->ma_nhan_vien == p.ma_nhan_vien)
		return true;
	else
		return false;
}

bool Employee::compare_id(string id) {
	if (this->ma_nhan_vien == id) {
		return true;
	}
	else {
		return false;
	}
}
bool Employee::compare_age(const Employee& employee, bool check) {
	return this->ngay_sinh->compare_date(*employee.ngay_sinh, check);
}

void calc_hsl(const string& chuc_vu, int& hsl) {
	if (chuc_vu == "NHAN VIEN")
		hsl = 1;
	else if (chuc_vu == "TRUONG PHONG")
		hsl = 2;
	else if (chuc_vu == "GIAM DOC")
		hsl = 3;
	else
		hsl = 1;
}
void clear_input() {
	cin.clear();
	cin.ignore(10000, '\n');  // skips 10000 characters to the next newline
} // clear cin
// kiem tra xem nhap ngay co hop le khong
void check_date(int ngay, int thang, int nam) throw(string()) {
	if (thang <= 0 || thang > 12 || nam < 0)
		throw string();

	if ((thang <= 7 && thang % 2 == 1) || (thang >= 8 && thang % 2 == 0)) {
		if (ngay <= 0 || ngay > 31)
			throw string();
	}
	else if ((thang <= 7 && thang % 2 == 0) || (thang >= 8 && thang % 2 == 1)) {
		if (thang == 2) {
			if (nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0)) { // nam nhuan
				if (ngay <= 0 || ngay > 29)
					throw string();
			}
			else {
				if (ngay <= 0 || ngay > 28)
					throw string();
			}
		}
		else {
			if (ngay <= 0 || ngay > 30)
				throw string();
		}
	}
}
void to_upper_case(string& str) {
	for (char& c : str) {
		if (int(c) >= 97 && int(c) <= 122) {
			c -= 32;
		}
	}
}
string to_lower_case(string str) {
	for (char& c : str) {
		if (int(c) >= 65 && int(c) <= 90) {
			c += 32;
		}
	}
	return str;
}

ostream& operator<<(ostream& out, const Employee& employee) {
	out << employee.ma_nhan_vien << endl;
	return out;
}
istream& operator>>(istream& cin, Employee& employee) {
	cout << "Ma Nhan Vien: ";
	getline(cin, employee.ma_nhan_vien);
	to_upper_case(employee.ma_nhan_vien);
	cout << "Ten: ";
	getline(cin, employee.ten);
	to_upper_case(employee.ten);
	cout << "Don vi: ";
	getline(cin, employee.don_vi);
	to_upper_case(employee.don_vi);
	cout << "Chuc vu: ";
	getline(cin, employee.chuc_vu);
	to_upper_case(employee.chuc_vu);
	if (employee.chuc_vu != "NHAN VIEN" && employee.chuc_vu != "TRUONG PHONG" && employee.chuc_vu != "GIAM DOC") {
		employee.chuc_vu = "NHAN VIEN";
	}

	// input gioi_tinh (bool)
	do {
		try {
			int gioi_tinh;
			cout << "Gioi tinh (0: nam, 1: nu): ";
			cin >> gioi_tinh;

			if (cin.fail() || (gioi_tinh != 0 && gioi_tinh != 1)) {
				throw runtime_error("");
			}

			clear_input(); // clear o day de don dep input thua con sot lai
			employee.gioi_tinh = gioi_tinh;
			break;
		}
		catch (runtime_error e) {
			cout << "Wrong input" << endl;
			clear_input(); // clear cin
		}
	} while (true);
	// input Date
	do {
		try {
			int ngay, thang, nam; // for Date
			cout << "Ngay, thang, nam sinh: ";
			cin >> ngay >> thang >> nam;

			if (cin.fail()) {
				throw runtime_error("");
			}

			check_date(ngay, thang, nam); // kiem tra hop le ngay

			clear_input(); // clear o day de don dep input thua con sot lai
			employee.ngay_sinh = new Date(ngay, thang, nam);
			break;
		}
		catch (runtime_error e) {
			cout << "Wrong input" << endl;
			clear_input();
		}
		catch (string s) {
			cout << "Ngay thang nam khong hop le" << endl;
		}
	} while (true);

	calc_hsl(employee.chuc_vu, employee.he_so_luong);

	return cin;
}

void Employee::update_info(Employee& employee) {
	cin >> employee;
}

void Employee::copy_info(const Employee& e) {
	this->ma_nhan_vien = e.ma_nhan_vien;
	this->ten = e.ten;
	this->don_vi = e.don_vi;
	this->chuc_vu = e.chuc_vu;
	this->gioi_tinh = e.gioi_tinh;
	this->he_so_luong = e.he_so_luong;
	this->ngay_sinh->copy_date(*e.ngay_sinh);
}

int Employee::luong() {
	return this->he_so_luong * lcb;
}
double Employee::phu_cap() {
	if (this->he_so_luong == 3) // Giam doc
		return 0.4 * this->luong();
	else if (this->he_so_luong == 2) // Truong phong
		return 0.25 * this->luong();
	else
		return 0;

}
double Employee::thuc_linh() {
	return this->luong() + this->phu_cap();
}

string Employee::get_ma_nhan_vien() {
	return this->ma_nhan_vien;
}

string Employee::get_ten() {
	return this->ten;
}

string Employee::get_don_vi() {
	return this->don_vi;
}

string Employee::get_chuc_vu() {
	return this->chuc_vu;
}

int Employee::get_he_so_luong() {
	return this->he_so_luong;
}

string Employee::get_gioi_tinh() {
	if (this->gioi_tinh == false)
		return "NAM";
	else
		return "NU";
}

string Employee::get_string_date() {
	return this->ngay_sinh->store_string_date();
}

int Employee::get_nam_sinh() {
	return this->ngay_sinh->get_nam_sinh();
}
