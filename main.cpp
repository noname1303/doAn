#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class QuanLyDangNhap
{
public:
    QuanLyDangNhap()
    {

        quyenTruyCap = 0;
    }

    void dangNhap()
    {
        cout << "Nhap tai khoan va mat khau.\nTai Khoan:";
        cin >> taiKhoanTmp;

       taiKhoan = getFile("users.txt");
        if(taiKhoanTmp == taiKhoan)
        {
            cout << "Mat khau:";
            cin >> matKhauTmp;

           matKhau = getFile("passwords.txt");

            if(matKhauTmp == matKhau)
            {
                cout << "Chao mung ban den voi chuong trinh.";
                cin.get();
            }
            else
            {
                cout << "Sai mat khau." << endl;
                dangNhap();
            }
        }
        else
        {
            cout << "Ten dang nhap khong dung." << endl;
            dangNhap();
        }
    }
    string getFile(const char* p_fileName)
    {
        string line;
        fstream file;

        file.open(p_fileName, ios::in);
        if(file.is_open())
        {
            getline(file, line);
        }
        file.close();

        return line;
    }
private:
    string matKhau = "admin";
    string taiKhoan = "user@gmail.com";
    string taiKhoanTmp;
    string matKhauTmp;
    bool quyenTruyCap;
};

int main()
{
    QuanLyDangNhap QuanLyDangNhapObj;
    QuanLyDangNhapObj.dangNhap();
}
