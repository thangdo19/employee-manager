#include<iostream>
#include"List.h"
using namespace std;

void menu() {
	cout << "1. Hien thi danh sach doi tuong" << endl;
	cout << "2. Them doi tuong" << endl;
	cout << "3. Cap nhat thong tin doi tuong" << endl;
	cout << "4. Xoa doi tuong" << endl;
	cout << "5. Tim kiem doi tuong (theo cmnd)" << endl;
	cout << "6. Sap xep danh sach doi tuong" << endl;
	cout << "0. Exit" << endl;
}

void add_employee(List& list, int i) {
	if (i == 1) {
		list.add_employee_at_first();
	}
	else if (i == 2) {
		list.add_employee_at_last();
	}
	else {
		int position_to_add = 0;
		cout << "Nhap vi tri muon them: ";
		cin >> position_to_add;

		cin.ignore();
		list.add_employee_at_specific_pos(position_to_add);
	}
}

void delete_employee(List& list, int i) {
	if (i == 1) {
		string id;

		cout << "Nhap ma nhan vien can xoa: ";
		cin.ignore();
		getline(cin, id);
		list.delete_employee(id);
	}
	else if (i == 2) {
		string ten;

		cout << "Nhap ten nhan vien can xoa: ";
		cin.ignore();
		getline(cin, ten);

		if (list.delete_employee_by_name(ten) == true)
			cout << "Da xoa" << endl;
		else
			cout << "Khong ton tai nhan vien co ten nhu vay de xoa" << endl;
	}
	else if (i == 3) {
		int position_to_remove = 0;
		cout << "Nhap vi tri muon xoa: ";
		cin >> position_to_remove;

		list.delete_employee_at_specific_pos(position_to_remove);
	}
	else if (i == 4) {
		if (list.delete_old_employee() == true)
			cout << "Da xoa" << endl;
		else
			cout << "Khong ton tai nhan vien lon tuoi de xoa" << endl;
	}
	else {
		cout << "Lua chon khong ton tai" << endl;
	}
}

int main() {
	List list;
	list.read_file();

	int choice;
	while (true) {
		menu();
		cout << "> ";
		cin >> choice;
		fflush(stdin);

		if (choice == 1) {
			list.display_list();
			list.print_statistics();
		}
		else if (choice == 2) {
			int add_employee_choice = 0;

			cout << "\t1. Them vao dau danh sach" << endl;
			cout << "\t2. Them vao cuoi danh sach" << endl;
			cout << "\t3. Them vao vi tri k trong danh sach" << endl;
			cout << "> ";

			cin >> add_employee_choice;
			cin.ignore();
			add_employee(list, add_employee_choice);
		}
		else if (choice == 3) {
			string update_id;
			cin.ignore();
			cout << "Nhap cmnd nguoi muon cap nhat: ";
			getline(cin, update_id);

			list.update_employee_info(update_id);
		}
		else if (choice == 4) {
			int delete_employee_choice = 0;

			cout << "\t1. Xoa theo ma nhan vien" << endl;
			cout << "\t2. Xoa theo ten" << endl;
			cout << "\t3. Xoa o vi tri k trong danh sach" << endl;
			cout << "\t4. Xoa nhan vien lon hon 50 tuoi" << endl;
			cout << "> ";

			cin >> delete_employee_choice;
			delete_employee(list, delete_employee_choice);
		}
		else if (choice == 5) {
			string search_id;
			cin.ignore();
			cout << "Nhap cmnd nguoi muon tim: ";
			getline(cin, search_id);

			if (list.check_if_contain(search_id) == true) {
				cout << list.search_employee_by_id(search_id);
			}
			else {
				cout << "Khong tim thay nguoi do" << endl;
			}
		}
		else if (choice == 6) {
			bool check;
			cout << "\t0. Sap xep tang dan" << endl << "\t1. Sap xep giam dan" << endl;
			cout << "> ";
			cin >> check;
			fflush(stdin);
			list.quick_sort(list.first, list.last, check);
			list.display_list();
		}
		else if (cin.fail()) {
			cout << "Lua chon khong hop le" << endl;
			cin.clear();
			cin.ignore(10000, '\n');  // skips 10000 characters to the next newline
		}
		else if (choice == 0) {
			cout << "Cam on!" << endl;
			//list.write_file();
			break;
		}
		else {
			cout << "Lua chon khong hop le" << endl;
		}
		cout << endl;
	}
}
