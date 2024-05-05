#include <sstream>
#include <vector>

#include "danh_sach_lien_ket_don.h"
#include "danh_sach_lien_ket_kep.h"
#include "danh_sach_lien_ket_vong.h"
#include "mang.h"
#include "nhapXuatSinhVien.h"

#define BLUE 9
#define CYAN 11
#define WHITE 15
#define RED 4

// ------------------------------------

// Hàm đổi màu chữ
void SET_COLOR(int color)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}




enum class Field
{
    MaSV,
    Ho,
    Ten,
    Lop,
    Diem
};
template <typename T>
T getValue(const SV &sv, const string &field)
{
    if (field == "maSV")
        return sv.maSV;
    if (field == "ho")
        return sv.ho;
    if (field == "ten")
        return sv.ten;
    if (field == "lop")
        return sv.lop;
    if (field == "diem") // Thêm trường hợp cho trường "diem"
        return to_string(sv.diem);
    throw invalid_argument("Field name is invalid");
}

string getValue(const SV &sv, const string &field)
{
    std::ostringstream stream;
    if (field == "maSV")
        return sv.maSV;
    if (field == "ho")
        return sv.ho;
    if (field == "ten")
        return sv.ten;
    if (field == "lop")
        return sv.lop;
    if (field == "diem")
    {
        stream << std::fixed << std::setprecision(2) << sv.diem;
        return stream.str();
    }
    throw invalid_argument("Field name is invalid");
}

template <typename T>
int Binary_Search(SV listMang[], int left, int right, const T &x, const string &input)
{
    if (left > right)
    {
        return -1;
    }
    int mid = (left + right) / 2;
    string midValue = getValue(listMang[mid], input);

    stringstream ss;
    ss << x;
    string xAsString = ss.str();

    if (midValue == xAsString)
    {
        return mid;
    }
    else if (midValue < xAsString)
    {
        return Binary_Search(listMang, mid + 1, right, xAsString, input);
    }
    else
    {
        return Binary_Search(listMang, left, mid - 1, xAsString, input);
    }
}

// quick sort
void quickSort(SV a[], int l, int r, const string &input)
{

    string midValue = getValue(a[(l + r) / 2], input);
    // int p = a[(l+r)/2].m;
    int i = l, j = r;
    while (i < j)
    {
        while (getValue(a[i], input) < midValue)
        {
            i++;
        }
        while (getValue(a[j], input) > midValue)
        {
            j--;
        }
        if (i <= j)
        {
            SV temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    if (i < r)
    {
        quickSort(a, i, r, input);
    }
    if (l < j)
    {
        quickSort(a, l, j, input);
    }
}

// ----------------------------------------Phần dành cho DSLK Đơn

//----------------

string TenDaoNguoc(string str)
{
    string temp = str;
    reverse(temp.begin(), temp.end());
    return temp;
}
// ------------- mảng
void luaChonXuatTenDaoNguocMang(SV LIST_MANG[], int &soLuongSinhVien, const vector<int> &foundIndices, int &index, int thoiGianTimKiem)
{
    int lc;
    bool backToSearchMenu = false; // Biến để kiểm tra liệu người dùng muốn quay lại menu tìm kiếm ban đầu hay không
    while (!backToSearchMenu)      // Thực hiện trong khi người dùng không muốn quay lại menu tìm kiếm
    {
        system("cls");
        cout << "\tDa tim thay thong tin sinh vien. Ban co muon xuat ten dao nguoc khong?";
        cout << "\n\t  1. YES";
        cout << "\n\t  2. NO";
        cout << "\n\t  3. Quay lai menu tim kiem";
        cout << "\n\t - Nhap lua chon: ";
        cin >> lc;

        switch (lc)
        {
        case 1:
        {
            inTieuDe();
            for (int i : foundIndices)
            {
                string reversedName = TenDaoNguoc(LIST_MANG[i].ten);
                string reversedHo = TenDaoNguoc(LIST_MANG[i].ho);
                SET_COLOR(RED);
                xuat(LIST_MANG[i]);
                SET_COLOR(WHITE); // Thay WHITE bằng mã màu mặc định của bạn
                cout << "Ten dao nguoc: " << reversedName << " " << reversedHo << endl;
            }

            cout << "\n\t--------Thoi gian tim kiem-------: " << thoiGianTimKiem << endl;
            system("pause");
            break;
        }

        case 2:
        {
            inTieuDe();
            for (int i : foundIndices)
            {
                SET_COLOR(RED);
                xuat(LIST_MANG[i]);
                SET_COLOR(WHITE); // Thay WHITE bằng mã màu mặc định của bạn
            }
            cout << "\n\t--------Thoi gian tim kiem-------: " << thoiGianTimKiem << endl;

            system("pause");
            break;
        }

        case 3:
        {
            backToSearchMenu = true; // Đặt biến backToSearchMenu về true để thoát khỏi vòng lặp và quay lại menu tìm kiếm
            break;
        }

        default:
            break;
        }
    }
}

//----------------
void timKiemSinhVienMang(SV LIST_MANG[], int &soLuongSinhVien) //  ---------- MẠNG
{
    int lc;
    // int tgianTimKiem;
    while (true)
    {
        system("cls");
        cout << "\n\n\t\t=== CHUONG TRINH TIM KIEM SINH VIEN ===\n\n";
        cout << "\t======================= MENU =======================";
        cout << "\n\t  1. Tim theo ma sinh vien.";
        cout << "\n\t  2. Tim theo ho.";
        cout << "\n\t  3. Tim theo ten.";
        cout << "\n\t  4. Tim theo lop.";
        cout << "\n\t  5. Tim theo diem.";
        cout << "\n\t======================= END =======================";
        cout << "\n\n\t - Nhap lua chon: ";
        cin >> lc;

        switch (lc)
        {
        case 1:
        {
            cin.ignore();
            int index = 0;
            cout << "\n\tNhap ma sinh vien can tim : ";
            string mssvCanTim = "";
            getline(cin, mssvCanTim);
            formMssv(mssvCanTim);
            // --- sap xep
            quickSort(LIST_MANG, 0, soLuongSinhVien - 1, "maSV");

            //-------------------
            auto start = chrono::high_resolution_clock::now(); // Bắt đầu tính thời gian

            int result_str = Binary_Search<string>(LIST_MANG, 0, soLuongSinhVien - 1, mssvCanTim, "maSV");

            auto end = chrono::high_resolution_clock::now();                          // Kết thúc tính thời gian
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start); // Tính thời gian
            int tgianTimKiem = duration.count();
            if (result_str != -1)
            {
                vector<int> foundIndices;
                foundIndices.push_back(result_str);
                luaChonXuatTenDaoNguocMang(LIST_MANG, soLuongSinhVien, foundIndices, index, tgianTimKiem);

                system("pause"); //
            }
            else
            {
                cout << "Not found" << endl;
            }

            break;
        }

        case 2:
        {
            cin.ignore();
            int index = 0;
            cout << "\n\tNhap ho sinh vien can tim : ";
            string hoCanTim = "";
            getline(cin, hoCanTim);
            formChu(hoCanTim);

            // --- sap xep thử
            quickSort(LIST_MANG, 0, soLuongSinhVien - 1, "ho");

            //-------------------

            auto start = chrono::high_resolution_clock::now(); // Bắt đầu tính thời gian

            int result_str = Binary_Search<string>(LIST_MANG, 0, soLuongSinhVien - 1, hoCanTim, "ho");

            auto end = chrono::high_resolution_clock::now();                          // Kết thúc tính thời gian
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start); // Tính thời gian
            int tgianTimKiem = duration.count();
            if (result_str != -1)
            {
                vector<int> foundIndices;
                for (int i = 0; i < soLuongSinhVien; ++i)
                {
                    if (LIST_MANG[i].ho == hoCanTim)
                    {
                        foundIndices.push_back(i);
                    }
                }
                luaChonXuatTenDaoNguocMang(LIST_MANG, soLuongSinhVien, foundIndices, index, tgianTimKiem);

                system("pause");
            }
            else
            {
                cout << "Not found" << endl;
            }

            break;
        }

        case 3:
        {
            cin.ignore();
            int index = 0;
            cout << "\n\tNhap ten sinh vien can tim : ";
            string tenCanTim = "";
            getline(cin, tenCanTim);
            formChu(tenCanTim);

            // --- sap xep thử
            quickSort(LIST_MANG, 0, soLuongSinhVien - 1, "ten");

            //-------------------

            auto start = chrono::high_resolution_clock::now(); // Bắt đầu tính thời gian

            int result_str = Binary_Search<string>(LIST_MANG, 0, soLuongSinhVien - 1, tenCanTim, "ten");

            auto end = chrono::high_resolution_clock::now();                          // Kết thúc tính thời gian
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start); // Tính thời gian
            int tgianTimKiem = duration.count();
            if (result_str != -1)
            {
                vector<int> foundIndices;
                for (int i = 0; i < soLuongSinhVien; ++i)
                {
                    if (LIST_MANG[i].ten == tenCanTim)
                    {
                        foundIndices.push_back(i);
                    }
                }
                luaChonXuatTenDaoNguocMang(LIST_MANG, soLuongSinhVien, foundIndices, index, tgianTimKiem);

                system("pause");
            }
            else
            {
                cout << "Not found" << endl;
            }

            break;
        }

        case 4:
        {
            cin.ignore();
            int index = 0;
            cout << "\n\tNhap lop sinh vien can tim : ";
            string lopCanTim = "";
            getline(cin, lopCanTim);
            formMssv(lopCanTim);
            // --- sap xep thử
            quickSort(LIST_MANG, 0, soLuongSinhVien - 1, "lop");

            //-------------------

            auto start = chrono::high_resolution_clock::now(); // Bắt đầu tính thời gian

            int result_str = Binary_Search<string>(LIST_MANG, 0, soLuongSinhVien - 1, lopCanTim, "lop");

            auto end = chrono::high_resolution_clock::now();                          // Kết thúc tính thời gian
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start); // Tính thời gian
            int tgianTimKiem = duration.count();
            if (result_str != -1)
            {
                vector<int> foundIndices;
                for (int i = 0; i < soLuongSinhVien; ++i)
                {
                    if (LIST_MANG[i].lop == lopCanTim)
                    {
                        foundIndices.push_back(i);
                    }
                }
                luaChonXuatTenDaoNguocMang(LIST_MANG, soLuongSinhVien, foundIndices, index, tgianTimKiem);

                system("pause");
            }
            else
            {
                cout << "Not found" << endl;
            }

            break;
        }

        case 5:
        {
            int index = 0;
            cout << "\n\tNhap diem sinh vien can tim : ";
            float diemCanTim;
            cin >> diemCanTim;

            // --- sap xep thử
            quickSort(LIST_MANG, 0, soLuongSinhVien - 1, "diem");

            //-------------------

            // tìm
            int result_str = Binary_Search<float>(LIST_MANG, 0, soLuongSinhVien - 1, diemCanTim, "diem");
            auto start = chrono::high_resolution_clock::now(); // Bắt đầu tính thời gian

            vector<int> foundIndices;
            for (int i = 0; i < soLuongSinhVien; ++i)
            {
                if (LIST_MANG[i].diem == diemCanTim)
                {
                    foundIndices.push_back(i);
                }
            }
            auto end = chrono::high_resolution_clock::now();                          // Kết thúc tính thời gian
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start); // Tính thời gian
            int tgianTimKiem = duration.count();
            luaChonXuatTenDaoNguocMang(LIST_MANG, soLuongSinhVien, foundIndices, index, tgianTimKiem);

            break;
        }

        case 6:
        {
            themSinhVienMang(LIST_MANG, soLuongSinhVien, soLuongSinhVien);
            cout << "\n\tTHEM THANH CONG !!!";
            system("pause");
            break;
        }

        case 7:
        {

            for (int i = 0; i < soLuongSinhVien; i++)
            {
                xuat(LIST_MANG[i]);
                cout << endl;
            }
            break;
        }

        default:
            break;
        }
        system("pause");
    }
}

//----------------- Phần thêm SV vào cuối

//--------- dslk đơn
void luaChonXuatTenDaoNguocDSLKDon(LIST_DON listDon, const string &field, const string &value)
{
    int lc;
    bool backToSearchMenu = false;

    while (!backToSearchMenu)
    {
        system("cls"); // Xóa màn hình
        cout << "\tDa tim thay thong tin sinh vien. Ban co muon xuat ten dao nguoc khong?";
        cout << "\n\t  1. YES";
        cout << "\n\t  2. NO";
        cout << "\n\t  3. Quay lai menu tim kiem";
        cout << "\n\t - Nhap lua chon: ";
        cin >> lc;

        switch (lc)
        {
        case 1:
        {
            node_Don *p = NULL;

            p = listDon.pHead_Don;
            while (p != NULL)
            {
                if (getValue(p->data, field) == value)
                {
                   
                    string reversedName = TenDaoNguoc(p->data.ten);
                    string reversedHo = TenDaoNguoc(p->data.ho);
                    cout << "Ten dao nguoc: " << reversedName << " " << reversedHo << endl;
                    SET_COLOR(RED);
                    xuat(p->data);
                    SET_COLOR(WHITE);
                }

                p = p->pNext_Don;
            }

            system("pause");
            break;
        }

        case 2:
        {
            node_Don *p = NULL;

            p = listDon.pHead_Don;
            while (p != NULL)
            {
                if (getValue(p->data, field) == value)
                {
                    SET_COLOR(RED);

                    xuat(p->data);
                    SET_COLOR(WHITE); // Thay WHITE bằng mã màu mặc định của bạn
                }

                p = p->pNext_Don;
            }

            system("pause");
            break;
        }

        case 3:
        {
            backToSearchMenu = true;
            break;
        }

        default:
            break;
        }
    }
}

void timKiemSinhVienDanhSachLkDon(LIST_DON &listDon)
{
    int lc;
    while (true)
    {
        system("cls");
        cout << "\n\n\t\t=== CHUONG TRINH TIM KIEM SINH VIEN ===\n\n";
        cout << "\t======================= MENU =======================";
        cout << "\n\t  1. Tim theo ma sinh vien.";
        cout << "\n\t  2. Tim theo ho.";
        cout << "\n\t  3. Tim theo ten.";
        cout << "\n\t  4. Tim theo lop.";
        cout << "\n\t  5. Tim theo diem.";
        cout << "\n\t======================= END =======================";
        cout << "\n\n\t - Nhap lua chon: ";
        cin >> lc;

        switch (lc)
        {
        case 1:
        {
            cin.ignore();
            cout << "\n\tNhap ma sinh vien can tim : ";
            string mssvCanTim = "";
            getline(cin, mssvCanTim);
            formMssv(mssvCanTim);

            auto start = chrono::high_resolution_clock::now(); // Bắt đầu tính thời gian

            luaChonXuatTenDaoNguocDSLKDon(listDon, "maSV", mssvCanTim);

            auto end = chrono::high_resolution_clock::now();                          // Kết thúc tính thời gian
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start); // Tính thời gian
            int tgianTimKiem = duration.count();
            cout << "\n\t\nTHOI GIAN TIM KIEM : " << tgianTimKiem << endl;

            system("pause");
            break;
        }

        case 2:
        {
            cin.ignore();
            cout << "\n\tNhap ho sinh vien can tim : ";
            string hoCanTim = "";
            getline(cin, hoCanTim);
            formChu(hoCanTim);
            auto start = chrono::high_resolution_clock::now(); // Bắt đầu tính thời gian

            luaChonXuatTenDaoNguocDSLKDon(listDon, "ho", hoCanTim);

            auto end = chrono::high_resolution_clock::now();                          // Kết thúc tính thời gian
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start); // Tính thời gian
            int tgianTimKiem = duration.count();
            cout << "\n\t\nTHOI GIAN TIM KIEM : " << tgianTimKiem << endl;

            system("pause");
            break;
        }

        case 3:
        {
            cin.ignore();
            cout << "\n\tNhap ten sinh vien can tim : ";
            string tenCanTim = "";
            getline(cin, tenCanTim);
            formChu(tenCanTim);
            auto start = chrono::high_resolution_clock::now(); // Bắt đầu tính thời gian
            luaChonXuatTenDaoNguocDSLKDon(listDon, "ten", tenCanTim);

            auto end = chrono::high_resolution_clock::now();                          // Kết thúc tính thời gian
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start); // Tính thời gian
            int tgianTimKiem = duration.count();
            cout << "\n\t\nTHOI GIAN TIM KIEM : " << tgianTimKiem << endl;

            system("pause");
            break;
        }

        case 4:
        {
            cin.ignore();
            cout << "\n\tNhap lop sinh vien can tim : ";
            string lopCanTim = "";
            getline(cin, lopCanTim);
            formMssv(lopCanTim);
            auto start = chrono::high_resolution_clock::now(); // Bắt đầu tính thời gian

            luaChonXuatTenDaoNguocDSLKDon(listDon, "lop", lopCanTim);

            auto end = chrono::high_resolution_clock::now();                          // Kết thúc tính thời gian
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start); // Tính thời gian
            int tgianTimKiem = duration.count();
            cout << "\n\t\nTHOI GIAN TIM KIEM : " << tgianTimKiem << endl;

            system("pause");
            break;
        }

        case 5:
        {
            cout << "\n\tNhap diem sinh vien can tim : ";
            float diemCanTim;
            cin >> diemCanTim;
            ostringstream convert;
            convert << fixed << setprecision(2) << diemCanTim; // Make sure this precision matches what getValue uses
            string tam = convert.str();
            auto start = chrono::high_resolution_clock::now(); // Bắt đầu tính thời gian
            luaChonXuatTenDaoNguocDSLKDon(listDon, "diem", tam);

            auto end = chrono::high_resolution_clock::now();                          // Kết thúc tính thời gian
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start); // Tính thời gian
            int tgianTimKiem = duration.count();
            cout << "\n\t\nTHOI GIAN TIM KIEM : " << tgianTimKiem << endl;

            system("pause");
            break;
        }
        }
    }
}

void themSinhVienVaoDanhSach(LIST_DON &listDon, SV sv)
{
    pNODE_DON p = khoiTaoNodeDon(sv);
    if (listDon.pHead_Don == NULL)
    {
        listDon.pHead_Don = p;
    }
    else
    {
        p->pNext_Don = listDon.pHead_Don;
        listDon.pHead_Don = p;
    }
}

int main()
{
    // test chuong trinh mảng
    // int soLuong = 7;
    // SV listMang[100] = { {"N22DCPT001", "Hung", "An", "D22CQPT01-N", 8.55},
    //                     {"N22DCPT007", "Le", "Binh", "D22CQCN02-N", 7.0},
    //                     {"N22DCCN112", "Lenh", "Gioi", "D22CQAT01-N", 9.123},
    //                     {"N22DCAT022", "La", "Binh", "D22CQCN02 - N", 8.0555},
    //                     {"N22DCPT031", "Lung", "Binh", "D22CQAT01-N", 7.05},
    //                     {"N22DCAT037", "Nguyen", "Binh", "D22CQAT01-N", 5.4},
    //                     {"N22DCAT043", "Tinh", "Cuong", "D22CQCN02-N", 8.2101} };

    // timKiemSinhVienMang(listMang, soLuong);

    // test chuong trinh dslk đơn
    LIST_DON listDon;
    khoitaoDSLKDon(listDon);

    // Danh sách sinh viên được khởi tạo sẵn
    SV sv1 = {"N22DCPT001", "Hung", "An", "D22CQPT01-N", 8.56};
    SV sv2 = {"N22DCPT007", "Le", "Binh", "D22CQCN02-N", 7.2};
    SV sv3 = {"N22DCCN112", "Lenh", "Gioi", "D22CQAT01-N", 9.123456};
    SV sv4 = {"N22DCAT022", "La", "Binh", "D22CQCN02-N", 8.333};
    SV sv5 = {"N22DCAT037", "Nguyen", "Binh", "D22CQAT01-N", 5.0};
    SV sv6 = {"N22DCAT043", "Tinh", "Cuong", "D22CQCN02-N", 8};
    SV sv7 = {"N22DCAT043", "Tinh", "Cuong", "D22CQCN02-N", 8};
    SV sv8 = {"N22DCAT043", "Tinh", "Cuong", "D22CQCN02-N", 8};
    SV sv9 = {"N22DCAT043", "Tinh", "Cuong", "D22CQCN02-N", 8};

    themSinhVienVaoDanhSach(listDon, sv1);
    themSinhVienVaoDanhSach(listDon, sv2);
    themSinhVienVaoDanhSach(listDon, sv3);
    themSinhVienVaoDanhSach(listDon, sv4);
    themSinhVienVaoDanhSach(listDon, sv5);
    themSinhVienVaoDanhSach(listDon, sv6);
    themSinhVienVaoDanhSach(listDon, sv7);
    themSinhVienVaoDanhSach(listDon, sv8);
    themSinhVienVaoDanhSach(listDon, sv9);

    int choice;
    while (true)
    {
        system("cls");
        cout << "\n\n\t\t=== CHUONG TRINH QUAN LY SINH VIEN ===\n\n";
        cout << "\t======================= MENU =======================";
        cout << "\n\t  1. Them sinh vien.";
        cout << "\n\t  2. Tim kiem sinh vien.";
        cout << "\n\t======================= END =======================";
        cout << "\n\n\t - Nhap lua chon: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            SV newSV = nhapThongTinSinhVien();
            
            themSinhVienVaoDanhSach(listDon, newSV);
            break;
        }

        case 2:
        {
            timKiemSinhVienDanhSachLkDon(listDon);
            break;
        }

        case 3:
        {
            xuatDSLKDon(listDon);
            system("pause");
            break;
        }

        default:
            break;
        }
    }

    return 0;
}

// Comand nday