#include"Date.h"
using namespace std;

class Employee {
private:
	string ma_nhan_vien, ten, don_vi, chuc_vu;
	int he_so_luong;
	bool gioi_tinh;
	Date* ngay_sinh;
	static const int lcb = 850;

public:
	Employee* next;
	Employee* previous;

	Employee();
	Employee(string, string, string, string, bool, int, int, int, int);
	Employee(const Employee&);
	~Employee();

	bool equals(const Employee&);
	bool compare_id(string);
	bool compare_age(const Employee&);
	bool compare_age(const Employee&, bool);
	void show();
	void update_info(Employee&);
	void copy_info(const Employee&);
	int luong();
	double phu_cap();
	double thuc_linh();

	string get_ma_nhan_vien();
	string get_ten();
	string get_don_vi();
	string get_chuc_vu();
	int get_he_so_luong();
	int get_nam_sinh();
	string get_gioi_tinh();
	string get_string_date();

	friend ostream& operator<<(ostream& o, const Employee&);
	friend istream& operator>>(istream& in, Employee&);
};