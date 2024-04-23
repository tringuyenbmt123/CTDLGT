 int soLuong = 7;
    SV listMang[7] = {{"N22DCPT001", "Hung", "An", "D22CQPT01-N", 8.5},
                      {"N22DCPT007", "Le", "Binh", "D22CQCN02-N", 7.0},
                      {"N22DCCN112", "Lenh", "Gioi", "D22CQAT01-N", 9.0},
                      {"N22DCAT022", "La", "Binh", "D22CQCN02 - N", 8.0},
                      {"N22DCPT031", "Lung", "Binh", "D22CQAT01-N", 7.0},
                      {"N22DCAT037", "Nguyen", "Binh", "D22CQAT01-N", 5.0},
                      {"N22DCAT043", "Tinh", "Cuong", "D22CQCN02-N", 8.1}};

    // timKiemSinhVienMang(listMang, soLuong);

    themSinhVienMang(listMang, soLuong, 1);
    for (int i = 0; i < soLuong; i++)
    {
        xuat(listMang[i]);
        cout << endl;
    }
