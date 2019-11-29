#include"iostream"
using namespace std;

class Date {
private:
	int ngay;
	int thang;
	int nam;

public:
	Date();
	Date(int, int, int);
	Date(const Date&);

	bool compare_date(const Date&, bool);
	void copy_date(const Date&);
	friend void update_date(Date&, int, int, int);
	friend ostream& operator<<(ostream&, const Date&);
	string store_string_date();

	int get_nam_sinh();
};
