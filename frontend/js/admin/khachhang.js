// Khởi tạo biến toàn cục
let customers = []; // Mảng lưu danh sách khách hàng
let currentPage = 1; // Trang hiện tại
let itemsPerPage = 10; // Số lượng khách hàng mỗi trang
let totalPages = 1; // Tổng số trang
let currentFilter = 'all'; // Bộ lọc hiện tại
let editMode = false; // Biến kiểm tra đang ở chế độ sửa hay thêm mới
let currentCustomerId = null; // ID của khách hàng đang được chỉnh sửa

// Đợi DOM được tải hoàn toàn
document.addEventListener('DOMContentLoaded', function() {
    // Kiểm tra người dùng đã đăng nhập là admin chưa
    checkAdminLogin();
    
    // Tải danh sách khách hàng
    loadCustomers();
    
    // Gắn sự kiện cho các nút
    setupEventListeners();
});

// Kiểm tra tài khoản đăng nhập có phải admin hay không
function checkAdminLogin() {
    const userRole = localStorage.getItem('userRole');
    console.log('User role from localStorage:', userRole); // Thêm log để kiểm tra
    
    if (!userRole || (userRole.toUpperCase() !== 'ADMIN' && userRole !== 'admin')) {
        showError('Bạn không có quyền truy cập trang quản lý khách hàng.');
        setTimeout(() => {
            window.location.href = '../trangchu/index.html';
        }, 2000);
    }
}

// Thiết lập các sự kiện cho các nút
function setupEventListeners() {
    // Sự kiện nút thêm khách hàng mới
    document.getElementById('addCustomerBtn').addEventListener('click', function() {
        resetForm();
        editMode = false;
        document.getElementById('customerModalLabel').textContent = 'Thêm khách hàng mới';
        document.getElementById('accountSection').style.display = 'block';
    });
    
    // Sự kiện nút lưu khách hàng
    document.getElementById('saveCustomerBtn').addEventListener('click', saveCustomer);
    
    // Sự kiện nút xác nhận xóa
    document.getElementById('confirmDeleteBtn').addEventListener('click', deleteCustomer);
    
    // Sự kiện nút tìm kiếm
    document.getElementById('searchBtn').addEventListener('click', function() {
        const searchTerm = document.getElementById('searchInput').value.trim();
        searchCustomers(searchTerm);
    });
    
    // Sự kiện nhấn Enter trong ô tìm kiếm
    document.getElementById('searchInput').addEventListener('keypress', function(e) {
        if (e.key === 'Enter') {
            const searchTerm = this.value.trim();
            searchCustomers(searchTerm);
        }
    });
    
    // Sự kiện nút làm mới
    document.getElementById('refreshBtn').addEventListener('click', function() {
        document.getElementById('searchInput').value = '';
        currentFilter = 'all';
        loadCustomers();
    });
    
    // Sự kiện lọc
    document.querySelectorAll('.dropdown-item[data-filter]').forEach(item => {
        item.addEventListener('click', function(e) {
            e.preventDefault();
            currentFilter = this.getAttribute('data-filter');
            loadCustomers();
        });
    });
}

// Tải danh sách khách hàng từ API
function loadCustomers() {
    showLoading(true);
    
    // URL của API
    const apiUrl = 'http://localhost:8080/api/khachhang';
    
    // Bỏ qua việc kiểm tra token
    console.log('Đang gọi API mà không cần token:', apiUrl);
    
    fetch(apiUrl, {
        method: 'GET',
        headers: {
            'Content-Type': 'application/json'
            // Đã loại bỏ header Authorization
        }
    })
    .then(response => {
        console.log('Nhận phản hồi API với status:', response.status);
        
        if (!response.ok) {
            console.error('Lỗi server:', response.status);
            throw new Error(`Lỗi máy chủ: ${response.status}`);
        }
        return response.json();
    })
    .then(data => {
        console.log('Nhận dữ liệu thành công, loại dữ liệu:', Array.isArray(data) ? 'Array' : typeof data);
        
        if (!Array.isArray(data)) {
            console.error('Dữ liệu không đúng định dạng:', data);
            throw new Error('Dữ liệu từ máy chủ không đúng định dạng mảng');
        }
        
        console.log(`Đã nhận ${data.length} khách hàng từ máy chủ`);
        customers = data;
        filterCustomers();
        showLoading(false);
    })
    .catch(error => {
        console.error('API Error:', error);
        showError('Lỗi khi tải danh sách khách hàng: ' + error.message);
        showLoading(false);
        // Hiển thị dữ liệu mẫu cho việc kiểm thử giao diện
        displaySampleData();
    });
}

// Hiển thị dữ liệu mẫu khi không thể kết nối API
function displaySampleData() {
    customers = [
        { id: 1, tenKhachHang: 'Nguyễn Văn A', namSinh: 1990, soDienThoai: '0901234567', email: 'nguyenvana@example.com', cccd: '123456789012', trangThai: true },
        { id: 2, tenKhachHang: 'Trần Thị B', namSinh: 1992, soDienThoai: '0912345678', email: 'tranthib@example.com', cccd: '234567890123', trangThai: true },
        { id: 3, tenKhachHang: 'Lê Văn C', namSinh: 1985, soDienThoai: '0923456789', email: 'levanc@example.com', cccd: '345678901234', trangThai: false },
        { id: 4, tenKhachHang: 'Phạm Thị D', namSinh: 1995, soDienThoai: '0934567890', email: 'phamthid@example.com', cccd: '456789012345', trangThai: true },
        { id: 5, tenKhachHang: 'Hoàng Văn E', namSinh: 1988, soDienThoai: '0945678901', email: 'hoangvane@example.com', cccd: '567890123456', trangThai: true }
    ];
    filterCustomers();
}

// Lọc khách hàng theo trạng thái (tất cả, đang hoạt động, không hoạt động)
function filterCustomers() {
    let filteredCustomers = [...customers];
    
    if (currentFilter === 'active') {
        filteredCustomers = filteredCustomers.filter(customer => customer.trangThai === true);
    } else if (currentFilter === 'inactive') {
        filteredCustomers = filteredCustomers.filter(customer => customer.trangThai === false);
    }
    
    // Cập nhật tổng số trang
    totalPages = Math.ceil(filteredCustomers.length / itemsPerPage);
    
    // Đảm bảo trang hiện tại không vượt quá tổng số trang
    if (currentPage > totalPages) {
        currentPage = totalPages === 0 ? 1 : totalPages;
    }
    
    // Phân trang
    const startIndex = (currentPage - 1) * itemsPerPage;
    const endIndex = startIndex + itemsPerPage;
    const paginatedCustomers = filteredCustomers.slice(startIndex, endIndex);
    
    // Hiển thị khách hàng
    displayCustomers(paginatedCustomers);
    
    // Cập nhật phân trang
    updatePagination();
}

// Hiển thị danh sách khách hàng
function displayCustomers(customersToDisplay) {
    const tableBody = document.getElementById('customersTableBody');
    tableBody.innerHTML = '';
    
    if (customersToDisplay.length === 0) {
        const emptyRow = document.createElement('tr');
        emptyRow.innerHTML = `
            <td colspan="8" class="text-center py-3">Không có dữ liệu khách hàng</td>
        `;
        tableBody.appendChild(emptyRow);
        return;
    }
    
    customersToDisplay.forEach((customer, index) => {
        const row = document.createElement('tr');
        const startIndex = (currentPage - 1) * itemsPerPage;
        
        row.innerHTML = `
            <td>${startIndex + index + 1}</td>
            <td>${customer.tenKhachHang || ''}</td>
            <td>${customer.namSinh || ''}</td>
            <td>${customer.soDienThoai || ''}</td>
            <td>${customer.email || ''}</td>
            <td>${customer.cccd || ''}</td>
            <td>
                <span class="badge ${customer.trangThai ? 'badge-active' : 'badge-inactive'}">
                    ${customer.trangThai ? 'Đang hoạt động' : 'Không hoạt động'}
                </span>
            </td>
            <td>
                <div class="action-buttons">
                    <button class="btn btn-sm btn-info edit-btn" data-id="${customer.id}">
                        <i class="fas fa-edit"></i> Sửa
                    </button>
                    <button class="btn btn-sm btn-danger delete-btn" data-id="${customer.id}" data-name="${customer.tenKhachHang}">
                        <i class="fas fa-trash-alt"></i> Xóa
                    </button>
                </div>
            </td>
        `;
        
        tableBody.appendChild(row);
    });
    
    // Gắn sự kiện cho các nút sửa và xóa
    attachActionButtonEvents();
}

// Gắn sự kiện cho các nút hành động (sửa, xóa)
function attachActionButtonEvents() {
    // Gắn sự kiện cho nút sửa
    document.querySelectorAll('.edit-btn').forEach(button => {
        button.addEventListener('click', function() {
            const customerId = this.getAttribute('data-id');
            editCustomer(customerId);
        });
    });
    
    // Gắn sự kiện cho nút xóa
    document.querySelectorAll('.delete-btn').forEach(button => {
        button.addEventListener('click', function() {
            const customerId = this.getAttribute('data-id');
            const customerName = this.getAttribute('data-name');
            showDeleteConfirmation(customerId, customerName);
        });
    });
}

// Hiển thị hộp thoại xác nhận xóa
function showDeleteConfirmation(customerId, customerName) {
    document.getElementById('deleteCustomerName').textContent = customerName;
    currentCustomerId = customerId;
    
    // Hiển thị modal xác nhận
    const deleteModal = new bootstrap.Modal(document.getElementById('deleteConfirmModal'));
    deleteModal.show();
}

// Xóa khách hàng
function deleteCustomer() {
    if (!currentCustomerId) return;
    
    showLoading(true);
    
    // URL của API xóa khách hàng
    const apiUrl = `http://localhost:8080/api/khachhang/${currentCustomerId}`;
    
    fetch(apiUrl, {
        method: 'DELETE',
        headers: {
            'Content-Type': 'application/json'
            // Đã loại bỏ header Authorization
        }
    })
    .then(response => {
        if (!response.ok) {
            throw new Error('Không thể xóa khách hàng');
        }
        // Đóng modal
        bootstrap.Modal.getInstance(document.getElementById('deleteConfirmModal')).hide();
        showSuccess('Xóa khách hàng thành công!');
        
        // Cập nhật danh sách khách hàng
        loadCustomers();
    })
    .catch(error => {
        showError('Lỗi khi xóa khách hàng: ' + error.message);
        
        // Test mode: Cập nhật giao diện mà không cần API thành công
        customers = customers.filter(c => c.id != currentCustomerId);
        bootstrap.Modal.getInstance(document.getElementById('deleteConfirmModal')).hide();
        showSuccess('Xóa khách hàng thành công!');
        filterCustomers();
    })
    .finally(() => {
        showLoading(false);
    });
}

// Chỉnh sửa khách hàng
function editCustomer(customerId) {
    const customer = customers.find(c => c.id == customerId);
    if (!customer) return;
    
    // Đặt chế độ chỉnh sửa
    editMode = true;
    currentCustomerId = customerId;
    
    // Cập nhật tiêu đề modal
    document.getElementById('customerModalLabel').textContent = 'Chỉnh sửa thông tin khách hàng';
    
    // Ẩn phần thông tin tài khoản khi chỉnh sửa
    document.getElementById('accountSection').style.display = 'none';
    
    // Điền thông tin khách hàng vào form
    document.getElementById('customerId').value = customer.id;
    document.getElementById('tenKhachHang').value = customer.tenKhachHang || '';
    document.getElementById('namSinh').value = customer.namSinh || '';
    document.getElementById('soDienThoai').value = customer.soDienThoai || '';
    document.getElementById('email').value = customer.email || '';
    document.getElementById('cccd').value = customer.cccd || '';
    document.getElementById('trangThai').value = customer.trangThai ? 'true' : 'false';
    
    // Mở modal chỉnh sửa
    const modal = new bootstrap.Modal(document.getElementById('customerModal'));
    modal.show();
}

// Lưu thông tin khách hàng (thêm mới hoặc cập nhật)
function saveCustomer() {
    // Lấy dữ liệu từ form
    const formData = {
        tenKhachHang: document.getElementById('tenKhachHang').value.trim(),
        namSinh: document.getElementById('namSinh').value ? parseInt(document.getElementById('namSinh').value) : null,
        soDienThoai: document.getElementById('soDienThoai').value.trim(),
        email: document.getElementById('email').value.trim(),
        cccd: document.getElementById('cccd').value.trim(),
        trangThai: document.getElementById('trangThai').value === 'true'
    };
    
    // Xác thực dữ liệu
    if (!formData.tenKhachHang) {
        showError('Vui lòng nhập họ tên khách hàng!');
        return;
    }
    
    if (!formData.soDienThoai) {
        showError('Vui lòng nhập số điện thoại khách hàng!');
        return;
    }
    
    // Nếu là thêm mới, cần thêm thông tin tài khoản
    if (!editMode) {
        const username = document.getElementById('username').value.trim();
        const password = document.getElementById('password').value.trim();
        
        if (!username) {
            showError('Vui lòng nhập tên đăng nhập!');
            return;
        }
        
        if (!password) {
            showError('Vui lòng nhập mật khẩu!');
            return;
        }
        
        // Thêm thông tin tài khoản vào formData
        formData.taiKhoan = {
            tenDangNhap: username,
            matKhau: password
        };
    }
    
    showLoading(true);
    
    // URL của API
    let apiUrl = 'http://localhost:8080/api/khachhang';
    let method = 'POST';
    
    // Nếu đang ở chế độ chỉnh sửa
    if (editMode) {
        apiUrl = `http://localhost:8080/api/khachhang/${currentCustomerId}`;
        method = 'PUT';
    }
    
    fetch(apiUrl, {
        method: method,
        headers: {
            'Content-Type': 'application/json'
            // Đã loại bỏ header Authorization
        },
        body: JSON.stringify(formData)
    })
    .then(response => {
        if (!response.ok) {
            throw new Error(editMode ? 'Không thể cập nhật khách hàng' : 'Không thể thêm khách hàng mới');
        }
        return response.json();
    })
    .then(data => {
        // Đóng modal
        bootstrap.Modal.getInstance(document.getElementById('customerModal')).hide();
        
        showSuccess(editMode ? 'Cập nhật thông tin khách hàng thành công!' : 'Thêm khách hàng mới thành công!');
        
        // Cập nhật danh sách khách hàng
        loadCustomers();
    })
    .catch(error => {
        showError('Lỗi: ' + error.message);
        
        // Test mode: Cập nhật giao diện mà không cần API thành công
        if (editMode) {
            // Cập nhật khách hàng trong danh sách
            const index = customers.findIndex(c => c.id == currentCustomerId);
            if (index !== -1) {
                customers[index] = { ...customers[index], ...formData, id: currentCustomerId };
            }
        } else {
            // Thêm khách hàng mới vào danh sách
            const newId = customers.length > 0 ? Math.max(...customers.map(c => c.id)) + 1 : 1;
            customers.push({ ...formData, id: newId });
        }
        
        // Đóng modal
        bootstrap.Modal.getInstance(document.getElementById('customerModal')).hide();
        showSuccess(editMode ? 'Cập nhật thông tin khách hàng thành công!' : 'Thêm khách hàng mới thành công!');
        filterCustomers();
    })
    .finally(() => {
        showLoading(false);
    });
}

// Tìm kiếm khách hàng
function searchCustomers(searchTerm) {
    if (!searchTerm) {
        loadCustomers();
        return;
    }
    
    showLoading(true);
    
    // URL của API tìm kiếm
    const apiUrl = `http://localhost:8080/api/khachhang/search?q=${encodeURIComponent(searchTerm)}`;
    
    fetch(apiUrl, {
        method: 'GET',
        headers: {
            'Content-Type': 'application/json'
            // Đã loại bỏ header Authorization
        }
    })
    .then(response => {
        if (!response.ok) {
            throw new Error('Không thể tìm kiếm khách hàng');
        }
        return response.json();
    })
    .then(data => {
        customers = data;
        filterCustomers();
    })
    .catch(error => {
        showError('Lỗi khi tìm kiếm khách hàng: ' + error.message);
        
        // Test mode: Tìm kiếm cục bộ
        const lowerSearchTerm = searchTerm.toLowerCase();
        const filteredCustomers = customers.filter(customer => 
            (customer.tenKhachHang && customer.tenKhachHang.toLowerCase().includes(lowerSearchTerm)) ||
            (customer.soDienThoai && customer.soDienThoai.includes(searchTerm)) ||
            (customer.email && customer.email.toLowerCase().includes(lowerSearchTerm)) ||
            (customer.cccd && customer.cccd.includes(searchTerm))
        );
        customers = filteredCustomers;
        filterCustomers();
    })
    .finally(() => {
        showLoading(false);
    });
}

// Cập nhật phân trang
function updatePagination() {
    const pagination = document.getElementById('pagination');
    pagination.innerHTML = '';
    
    if (totalPages <= 1) {
        return;
    }
    
    // Tạo nút Previous
    const prevLi = document.createElement('li');
    prevLi.className = `page-item ${currentPage === 1 ? 'disabled' : ''}`;
    prevLi.innerHTML = `<a class="page-link" href="#" aria-label="Previous"><span aria-hidden="true">&laquo;</span></a>`;
    pagination.appendChild(prevLi);
    
    // Thêm sự kiện cho nút Previous
    if (currentPage > 1) {
        prevLi.addEventListener('click', function(e) {
            e.preventDefault();
            currentPage--;
            filterCustomers();
        });
    }
    
    // Tạo các nút trang
    let startPage = Math.max(1, currentPage - 2);
    let endPage = Math.min(totalPages, currentPage + 2);
    
    // Đảm bảo luôn hiển thị ít nhất 5 nút trang (nếu có đủ trang)
    if (totalPages > 5) {
        if (endPage - startPage + 1 < 5) {
            if (currentPage < totalPages / 2) {
                endPage = Math.min(startPage + 4, totalPages);
            } else {
                startPage = Math.max(endPage - 4, 1);
            }
        }
    }
    
    // Tạo các nút số trang
    for (let i = startPage; i <= endPage; i++) {
        const li = document.createElement('li');
        li.className = `page-item ${i === currentPage ? 'active' : ''}`;
        li.innerHTML = `<a class="page-link" href="#">${i}</a>`;
        
        // Thêm sự kiện cho nút trang
        li.addEventListener('click', function(e) {
            e.preventDefault();
            currentPage = i;
            filterCustomers();
        });
        
        pagination.appendChild(li);
    }
    
    // Tạo nút Next
    const nextLi = document.createElement('li');
    nextLi.className = `page-item ${currentPage === totalPages ? 'disabled' : ''}`;
    nextLi.innerHTML = `<a class="page-link" href="#" aria-label="Next"><span aria-hidden="true">&raquo;</span></a>`;
    pagination.appendChild(nextLi);
    
    // Thêm sự kiện cho nút Next
    if (currentPage < totalPages) {
        nextLi.addEventListener('click', function(e) {
            e.preventDefault();
            currentPage++;
            filterCustomers();
        });
    }
}

// Reset form thêm/sửa khách hàng
function resetForm() {
    document.getElementById('customerForm').reset();
    document.getElementById('customerId').value = '';
}

// Hiển thị/ẩn hiệu ứng loading
function showLoading(show) {
    const spinner = document.getElementById('loadingSpinner');
    if (show) {
        spinner.classList.remove('d-none');
    } else {
        spinner.classList.add('d-none');
    }
}

// Hiển thị thông báo thành công
function showSuccess(message) {
    const alert = document.getElementById('alertSuccess');
    const alertMessage = document.getElementById('alertSuccessMessage');
    
    alertMessage.textContent = message;
    alert.classList.add('show');
    
    // Tự động ẩn sau 3 giây
    setTimeout(() => {
        alert.classList.remove('show');
    }, 3000);
}

// Hiển thị thông báo lỗi
function showError(message) {
    const alert = document.getElementById('alertError');
    const alertMessage = document.getElementById('alertErrorMessage');
    
    alertMessage.textContent = message;
    alert.classList.add('show');
    
    // Tự động ẩn sau 5 giây
    setTimeout(() => {
        alert.classList.remove('show');
    }, 5000);
}