#include<iostream>
#include<string>
#include"Date.h"
using namespace std;

Date::Date(int ngay, int thang, int nam) : ngay(ngay), thang(thang), nam(nam) {}
Date::Date() : ngay(0), thang(0), nam(0) {}
Date::Date(const Date& d) : ngay(d.ngay), thang(d.thang), nam(d.nam) {}

bool Date::compare_date(const Date& date, bool condition) {
	// condition == true : ascending, false :descending
	if (this->nam == date.nam) {
		if (this->thang == date.thang) {
			if (condition == true)
				return this->ngay <= date.ngay;
			else
				return this->ngay >= date.ngay;
		}
		else {
			if (condition == true)
				return this->thang <= date.thang;
			else
				return this->thang >= date.thang;
		}
	}
	else {
		if (condition == true)
			return this->nam <= date.nam;
		else
			return this->nam >= date.nam;
	}
}

void Date::copy_date(const Date& date) {
	this->ngay = date.ngay;
	this->thang = date.thang;
	this->nam = date.nam;
}

string Date::store_string_date() {
	string s = to_string(this->ngay) + "\t" + to_string(this->thang);
	s += "\t" + to_string(this->nam);
	return s;
}

int Date::get_nam_sinh() {
	return this->nam;
}

ostream& operator<<(ostream& o, const Date& date) {
	o << date.ngay << " " << date.thang << " " << date.nam << endl;
	return o;
}