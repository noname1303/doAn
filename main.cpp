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
        int maHoaKiTu;
        file.open(p_fileName, ios::in);
        while(1)
        {
            // getline(file, maHoaKiTu); không thể dùng như này
            //  ==> 
            file >> maHoaKiTu;
            if(maHoaKiTu == 0)
            {
                file.close();
                return line;
            }
            line += (char)giaiMa(maHoaKiTu);
        }

    }
    void saveFile(string p_line,const char* p_fileName ) // giam bo nho
    {
        fstream file;
        file.open(p_fileName, ios::out);
        for(int i=0; i<p_line.length(); i++)
        {
            file << maHoa(p_line[i]);
            file << "\n";

        }
        file<<"viendeptrai";
        file.close();
    }
    int maHoa (int p_letter)
    {
        return p_letter + 1303;

    }
    int giaiMa(int p_letter)
    {
        return p_letter - 1303;

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
    QuanLyDangNhap app;
    app.saveFile("HoangVienRatLaDepTrai","passwords.txt");
    app.saveFile("hoangviendeptrai1303@gmail.com","users.txt");
    cout<<app.getFile("passwords.txt")<<endl;
    cout<<app.getFile("users.txt");
}
