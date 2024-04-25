std::vector<node_Don*> sequentialSearch(node_Don* head, const std::string& field, const T &value) {
    std::vector<node_Don*> result;  // Vector lưu trữ các nút phù hợp
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(2) << value;  // Định dạng giá trị giống như trong getValue
    std::string valueAsString = ss.str();  // Lưu chuỗi từ stringstream

    node_Don* current = head;
    while (current != nullptr) {
        std::string currentFieldValue = getValue(current->data, field);  // Lấy giá trị dựa trên trường đã cho
        if (currentFieldValue == valueAsString) {  // So sánh chuỗi
            result.push_back(current);  // Thêm nút phù hợp vào vector
        }
        current = current->pNext_Don;
    }
    return result;  // Trả về vector chứa các nút phù hợp
}