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

// ------------------------------ tu them---------------------------
pNODE_DON khoiTaoNodeDon(SV sv) // ----------- ĐƠN
{
    pNODE_DON p = new NODE_DON;
    if (p == NULL)
    {
        exit(1);
    }
    p->data = sv;
    p->pNext_Don = NULL;

    return p;
}

pNODE_KEP khoiTaoNodeKep(SV sv) // ------------ kép
{
    pNODE_KEP p = new NODE_KEP;
    if (p == NULL)
    {
        exit(1);
    }
    p->data = sv;
    p->pNext_Kep = NULL;
    p->pPrev_Kep = NULL;

    return p;
}

pNODE_VONG khoiTaoNodeVong(SV sv) // ----------- vòng
{
    pNODE_VONG p = new NODE_VONG;
    if (p == NULL)
    {
        exit(1);
    }
    p->data = sv;
    p->pNext_Vong = NULL;

    return p;
}

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
// định dạng form chữ 
string formChu(string &str) // chỉ dùng cho chữ , ko được dùng số
{
    while (str[0] == ' ')
    {
        str.erase(str.begin() + 0);
    }

    while (str[str.length() - 1] == ' ')
    {
        // xóa kí tự tại vị trí 0
        str.erase(str.begin() + str.length() - 1);
    }

    for (int i = 0; i < str.length() - 1; i++)
    {
        if (str[i] == ' ' && str[i + 1] == ' ')
        {
            str.erase(str.begin() + i);
            i--;
        }
    }

    transform(str.begin(), str.end(), str.begin(), ::tolower); // CHUYEN SANG CHU THUONG
    int i = 1;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            str[i + 1] = str[i + 1] - 32;
        }
    }
    str[0] = str[0] - 32;
    return str;
}

string formMssv(string &str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 97 && str[i] <= 122)
        {
            str[i] = str[i] - 32;
        }
    }
    return str;
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

// quick sort
void quickSort(SV a[], int l, int r, const string &input){

      string midValue = getValue(a[(l + r) / 2], input);
	//int p = a[(l+r)/2].m;
	int i = l, j = r;
	while (i < j){
		while (getValue(a[i], input) < midValue){
			i++;
		}
		while (getValue(a[j], input) > midValue){
			j--;
		}
		if (i <= j){
            SV temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}
	if (i < r){
		quickSort(a, i, r,input);
	}
	if (l < j){
		quickSort(a, l, j, input);
	}
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

//
// Phần dành cho DSLK Đơn
// template<typename T>
// T getValue(const SV& sv, Field field) {
//    switch (field) {
//    case Field::MaSV:
//        return sv.maSV;
//    case Field::Ho:
//        return sv.ho;
//    case Field::Ten:
//        return sv.ten;
//    case Field::Lop:
//        return sv.lop;
//    case Field::Diem:
//        return to_string(sv.diem);
//    default:
//        throw invalid_argument("Field name is invalid");
//    }
//}
//
// template<typename T>
// int Binary_Search(pNODE_DON head, const T& x, Field input) {
//    pNODE_DON current = head;
//    while (current) {
//        string currentValue = getValue(current->data, input); // Chuyển Field thành string ở đây
//        string xAsString = to_string(x);
//
//        if (currentValue == xAsString)
//            return 0; // Tìm thấy giá trị x
//        else if (currentValue < xAsString)
//            current = current->pNext_Don;
//        else
//            break;
//    }
//    return -1; // Không tìm thấy giá trị x
//}

//----------------

string TenDaoNguoc(string str)
{
    string temp = str;
    reverse(temp.begin(), temp.end());
    return temp;
}
void luaChonXuatTenDaoNguoc(SV LIST_MANG[], int soLuongSinhVien, const vector<int> &foundIndices, int &index, int thoiGianTimKiem)
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

//----------------- Phần thêm SV vào cuối
// Hàm thêm vào cuối DSLK Dơn
void themVaoCuoiDSLKDon(LIST_DON &listDon, pNODE_DON p)
{
    if (listDon.pHead_Don == NULL)
    {
        listDon.pHead_Don = p;
    }
    else
    {
        pNODE_DON temp = listDon.pHead_Don;
        while (temp->pNext_Don != NULL)
        {
            temp = temp->pNext_Don;
        }
        temp->pNext_Don = p;
    }
}

void themSinhVienDSLKDon(LIST_DON &listDon)
{
    cout << "- Them sinh vien tiep theo: ";
    SV sv = nhapThongTinSinhVien();
    pNODE_DON p = khoiTaoNodeDon(sv);
    themVaoCuoiDSLKDon(listDon, p);
}

//----------------
void timKiemSinhVienMang(SV LIST_MANG[], int soLuongSinhVien) //  ---------- MẠNG
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
                luaChonXuatTenDaoNguoc(LIST_MANG, soLuongSinhVien, foundIndices, index, tgianTimKiem);

                system("pause"); //
            }
            else
            {
                cout << "Not found" << endl;
            }

            cout << "Thoi gian tim kiem: " << tgianTimKiem << " micro s" << endl; // In ra thời gian

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
                luaChonXuatTenDaoNguoc(LIST_MANG, soLuongSinhVien, foundIndices, index, tgianTimKiem);

                system("pause");
            }
            else
            {
                cout << "Not found" << endl;
            }

            cout << "Thoi gian tim kiem: " << tgianTimKiem << " micro s" << endl; // In ra thời gian
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
                luaChonXuatTenDaoNguoc(LIST_MANG, soLuongSinhVien, foundIndices, index, tgianTimKiem);

                system("pause");
            }
            else
            {
                cout << "Not found" << endl;
            }

            cout << "Thoi gian tim kiem: " << tgianTimKiem << " micro s" << endl; // In ra thời gian
            break;
        }

        case 4:
        {
            cin.ignore();
            int index = 0;
            cout << "\n\tNhap lop sinh vien can tim : ";
            string lopCanTim = "";
            getline(cin, lopCanTim);
            formMssv(lopCanTim );
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
                luaChonXuatTenDaoNguoc(LIST_MANG, soLuongSinhVien, foundIndices, index, tgianTimKiem);

                system("pause");
            }
            else
            {
                cout << "Not found" << endl;
            }

            cout << "Thoi gian tim kiem: " << tgianTimKiem << " micro s" << endl; // In ra thời gian
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
            luaChonXuatTenDaoNguoc(LIST_MANG, soLuongSinhVien, foundIndices, index, tgianTimKiem);

            cout << "Thoi gian tim kiem: " << tgianTimKiem << " micro s" << endl; // In ra thời gian
            break;
        }

        default:
            break;
        }
        system("pause");
    }
}

void timKiemSinhVienDanhSachLkDon(LIST_DON &listDon) //  ---------- ĐƠN
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
            int index = 0;
            cout << "\n\tNhap ma sinh vien can tim : ";
            string mssvCanTim = "";
            getline(cin, mssvCanTim);
            // int result = Binary_Search(listDon.pHead_Don, mssvCanTim, Field::MaSV);
            /* if (result == 0)
             {
                 xuat(listDon.pHead_Don->data, index++);
                 system("pause");
             }
             else
             {
                 cout << "Not found" << endl;
             }*/
            break;
        }

        case 2:
        {
            cin.ignore();
            cout << "\n\tNhap ho sinh vien can tim : ";
            string hoCanTim = "";
            getline(cin, hoCanTim);
            break;
        }

        case 3:
        {
            cin.ignore();
            cout << "\n\tNhap ten sinh vien can tim : ";
            string tenCanTim = "";
            getline(cin, tenCanTim);
            break;
        }

        case 4:
        {
            cin.ignore();
            cout << "\n\tNhap lop sinh vien can tim : ";
            string lopCanTim = "";
            getline(cin, lopCanTim);
            break;
        }

        case 5:
        {
            cout << "\n\tNhap diem sinh vien can tim : ";
            float diemCanTim;
            cin >> diemCanTim;
            break;
        }

        default:
            break;
        }
        system("pause");
    }
}

int main()
{
    // test chuong trinh
    SV listMang[7] = { {"N22DCPT001", "Hung", "An", "D22CQPT01-N", 8.5},
                       {"N22DCPT007", "Le", "Binh", "D22CQCN02-N", 7.0},
                       {"N22DCCN112", "Lenh", "Gioi", "D22CQAT01-N", 9.0},
                        {"N22DCAT022", "La", "Binh",  "D22CQCN02 - N", 8.0},
                         {"N22DCPT031", "Lung", "Binh", "D22CQAT01-N", 7.0},
                          {"N22DCAT037", "Nguyen", "Binh", "D22CQAT01-N", 5.0},
                           {"N22DCAT043", "Tinh", "Cuong", "D22CQCN02-N", 8.1}};



                   timKiemSinhVienMang(listMang, 7);
   



    /*LIST_DON listDon;
    khoitaoDSLKDon(listDon);

    themSinhVienDSLKDon(listDon);

    timKiemSinhVienDanhSachLkDon(listDon);*/

    return 0;
}

// Comand nday