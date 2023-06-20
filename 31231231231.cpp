// nhap ma chuyen bay 
     cout << "Nhap Ma May Bay can dat: ";
     cin >> ma_chuyen_bay_dat_cho;

     // khai bao 1 co false
     bool found3 = false;

     // mo file temp1 de ghi
     ifstream file_in("temp1.txt", ios::in);

      // kiem tra xem file da mo hay chua
      if (file_in.is_open()) {
          // mo file DatCho.txt de chinh sua
          ofstream file_out("DatCho.txt", ios::app);

          // kiem tra xem file da mo hay chua
          if (file_out.is_open()) {
              // doc tat ca thong tin o file 
              while (file_in>>u.name>>u.pswd>>u.cccd>>u.phone>>u.email>> f2.MaMayBay2 >> f2.NoiDi2 >> f2.NoiDen2 >> f2.ThoiGianDi2 >> f2.ThoiGianDen2 && !found3) {
                  // kiem tra xem ma chuyen bay co trung voi ma chuyen bay can dat hay khong hay khong
                  if (f2.MaMayBay2 == ma_chuyen_bay_dat_cho) {
                      // dat co thanh dung
                      found3 = true;

                      // ghi tat ca thong tin vao file dat cho
                      file_out <<u.name << " "
                               <<u.pswd<<" "
                               <<u.cccd<<" "
                               << u.phone << " "
                               << u.email << " "
                               << f2.MaMayBay2 << " "
                               << f2.NoiDi2 << " "
                               << f2.NoiDen2 << " "
                               << f2.ThoiGianDi2 << " "
                               << f2.ThoiGianDen2 << " "
                               <<ve1.loaive<<" "
                               <<ve1.gia_ve<<" "
                               <<ve1.so_luong_ve<<" "
                               <<ve1.tong_tien<<"\n";

                      // hien thi da dat thanh cong
                      cout << "Da dat cho thanh cong.\n";
                      cout << "Ma Chuyen Bay: " << f2.MaMayBay2 << "\n";
                      cout << "Noi Di: " << f2.NoiDi2 << "\n";
                      cout << "Noi Den: " << f2.NoiDen2 << "\n";
                      cout << "Thoi Gian Di: " << f2.ThoiGianDi2 << "\n";
                      cout << "Thoi Gian Den: " << f2.ThoiGianDen2 << "\n";
                  }
              }

              // dong ca 2 file
              file_in.close();
              file_out.close();

              // kiem tra xem co co sai hay khong
              if (!found3) {
                  // hien thi loi
                  cout << "Khong tim thay giu cho.\n";
              }
          }
          else {
              // hien thi loi dong file
              cout << "Loi.Khong mo duoc file2.\n";
              file_in.close();
          }
      }

      else {
          // hien thi loi
          cout << "Loi.\n";
      }