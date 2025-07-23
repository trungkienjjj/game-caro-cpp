# Game Caro (Tic-Tac-Toe) Console in C++

Đây là đồ án môn học Nhập môn Lập trình, mục tiêu là xây dựng một game cờ caro (5x5) hoàn chỉnh chạy trên môi trường console, được lập trình hoàn toàn bằng ngôn ngữ C++.

![Gameplay Screenshot](https://github.com/trungkienjjj/game-caro-cpp/blob/main/Screenshot%202025-07-23%20101836.png?raw=true)
![Gameplay Screenshot](https://github.com/trungkienjjj/game-caro-cpp/blob/main/Screenshot%202025-07-23%20101945.png?raw=true)
![Gameplay Screenshot](https://github.com/trungkienjjj/game-caro-cpp/blob/main/Screenshot%202025-07-23%20102010.png?raw=true)
![Gameplay Screenshot](https://github.com/trungkienjjj/game-caro-cpp/blob/main/Screenshot%202025-07-23%20102046.png?raw=true)
![Gameplay Screenshot](https://github.com/trungkienjjj/game-caro-cpp/blob/main/image.png?raw=true)

---

## 📜 Giới thiệu dự án (About The Project)

Dự án này được thực hiện nhằm áp dụng các kiến thức lập trình C++ cơ bản và nâng cao để xây dựng một ứng dụng hoàn chỉnh. Trò chơi mô phỏng lại game cờ caro quen thuộc với luật chơi 5 ô liên tiếp trên một bàn cờ, hỗ trợ chế độ chơi cho hai người. Toàn bộ logic game, giao diện và xử lý sự kiện đều được xây dựng trên nền tảng console.

---

## ✨ Các tính năng chính (Features)

* **Bàn cờ đồ họa Console:** Giao diện bàn cờ được vẽ trực tiếp trên console, dễ dàng theo dõi.
* **Chế độ 2 người chơi:** Hỗ trợ hai người chơi thay phiên nhau đi cờ.
* **Di chuyển bằng phím mũi tên:** Người chơi sử dụng các phím mũi tên để di chuyển con trỏ và phím Enter để đặt cờ.
* **Tự động phát hiện thắng/thua/hòa:**
    * Chương trình tự động kiểm tra theo hàng dọc, hàng ngang và hai đường chéo sau mỗi nước đi.
    * Phát hiện và thông báo ngay lập tức khi có người chơi đạt được 5 ô liên tiếp.
    * Tự động kết thúc và thông báo khi bàn cờ đã đầy mà chưa có người thắng.
* **Luật chơi chặn 2 đầu:** (Tùy chọn - nếu bạn có lập trình) Áp dụng luật chặn 2 đầu, nước đi 5 ô liên tiếp sẽ không được tính là thắng nếu bị chặn ở cả hai đầu.

---

## 🛠️ Công nghệ sử dụng (Tech Stack)

* **Ngôn ngữ:** C++
* **Môi trường phát triển:** Visual Studio / Code::Blocks
* **Thư viện:** `iostream`, `conio.h`, `windows.h` (để xử lý giao diện console)

---

## 🚀 Bắt đầu (Getting Started)

Để biên dịch và chạy dự án này trên máy của bạn, hãy làm theo các bước sau.

### Yêu cầu
* Một trình biên dịch C++ (ví dụ: g++, MinGW)
* Hệ điều hành Windows (do sử dụng các thư viện `conio.h`, `windows.h`)

### Hướng dẫn biên dịch
1.  Clone repository này về máy của bạn:
    ```sh
    git clone [https://github.com/trungkienjjj/game-caro-cpp.git](https://github.com/trungkienjjj/game-caro-cpp.git)
    ```
2.  Mở Terminal hoặc Command Prompt và trỏ đến thư mục dự án:
    ```sh
    cd game-caro-cpp
    ```
3.  Biên dịch mã nguồn bằng trình biên dịch của bạn:
    ```sh
    g++ -o caro.exe *.cpp
    ```
4.  Chạy game:
    ```sh
    ./caro.exe
    ```

---

## 👥 Đội ngũ phát triển (Team)
Dự án này là sản phẩm hợp tác của nhóm sinh viên trong khuôn khổ môn học.
* **Nguyễn Lâm Phú Quý**
* **Đào Sỹ Duy Minh**
* **Bàng Mỹ Linh**
* **Nguyễn Trần Trung Kiên**
