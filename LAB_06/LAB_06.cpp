
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
constexpr auto MAX = 50;

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)

class MATRIX {
	int _n;
	int** _a;
public:
	MATRIX() {
		_n = 0;
		_a = nullptr;
	}

	MATRIX(int a[MAX][MAX], int n) {
		_n = n;
		_a = new int* [n];
		while (_a == nullptr) {
			std::cerr << "Memory allocation failed!\n";
			_a = new int* [n];
		}

		for (int i = 0; i < n; i++) {
			_a[i] = new int[n];
			while (_a[i] == nullptr) {
				std::cerr << "Memory allocation failed!\n";
				_a[i] = new int[n];
			}

			copy(a[i], a[i] + n, _a[i]);
		}
	}

	bool setN(int n) {
		if (n < 0) {
			return false;
		}
		else if (_n == n) {
			return true;
		}
		else if (n == 0) {
			// Xoa ma tran hien tai, tra ve kich thuoc 0x0 nhu constructor default
			if (_a != nullptr) {
				for (int i = 0; i < _n; i++) {
					if (_a[i] != nullptr) {
						delete[] _a[i];
						_a[i] = nullptr;
					}
				}

				delete[] _a;
				_a = nullptr;
			}
			_n = 0;
			return true;
		}

		int** temp = new int* [n];

		// Khong cap phat duoc bo nho, tra ve false
		if (temp == nullptr) {
			std::cerr << "Memory allocation failed!\n";
			return false;
		}

		for (int i = 0; i < n; i++) {
			temp[i] = new int[n];
			if (temp[i] == nullptr) {
				std::cerr << "Memory allocation failed!\n";

				// Khong cap phat duoc bo nho tra ve false, truoc do phai xoa nhung vung nho da cap phat
				for (int j = 0; j < i; j++) {
					delete[] temp[j];
				}
				delete[] temp;
				temp = nullptr;

				return false;
			}
		}

		int minSize = min(n, _n);

		for (int i = 0; i < minSize; i++) {
			copy(_a[i], _a[i] + minSize, temp[i]);

			// Truong hop n > _n
			if (n > _n) {
				fill(temp[i] + _n, temp[i] + n, 0);
			}
		}

		// Truong hop n > _n
		for (int i = minSize; i < n; i++) {
			fill(temp[i], temp[i] + n, 0);
		}

		swap(_a, temp);
		swap(_n, n);

		if (temp != nullptr) {
			for (int i = 0; i < n; i++) {
				if (temp[i] != nullptr) {
					delete[] temp[i];
				}
				temp[i] = nullptr;
			}
		}
		delete[] temp;
		temp = nullptr;

		return true;
	}

	int getAt(int r, int c) {
		if (r < 0) {
			r = _n - abs(r) % _n;
		}
		else if (r >= _n) {
			r = r % _n;
		}

		if (c < 0) {
			c = _n - abs(r) % _n;
		}
		else if (c >= _n) {
			c = c % _n;
		}

		return _a[r][c];
	}

	~MATRIX() {
		if (_a != nullptr) {
			for (int i = 0; i < _n; i++) {
				if (_a[i] != nullptr) {
					delete[] _a[i];
					_a[i] = nullptr;
				}
			}

			delete[] _a;
			_a = nullptr;
		}
		_n = 0;
	}

	friend istream& operator>>(istream& iDev, MATRIX& m) {
		while (true) {
			cout << "Moi thay nhap kich thuoc n x n cua ma tran: ";
			iDev >> m._n;

			if (m._n > 0) {
				break;
			}

			cout << "Kich thuoc khong hop le!!!\n";
		}

		m._a = new int* [m._n];
		while (m._a == nullptr) {
			std::cerr << "Memory allocation failed!\n";
			m._a = new int* [m._n];
		}

		for (int i = 0; i < m._n; i++) {
			m._a[i] = new int[m._n];

			while (m._a[i] == nullptr) {
				std::cerr << "Memory allocation failed!\n";
				m._a[i] = new int[m._n];
			}
		}

		for (int i = 0; i < m._n; i++) {
			cout << "Moi thay nhap gia tri dong " << i << ": ";
			for (int j = 0; j < m._n; j++) {
				iDev >> m._a[i][j];
			}
		}

		return iDev;
	}

	friend ostream& operator<<(ostream& oDev, const MATRIX& m) {
		oDev << "Kich thuoc ma tran la: " << m._n << "x" << m._n << "\n";
		oDev << "Gia tri ma tran la:\n";

		for (int i = 0; i < m._n; i++) {
			for (int j = 0; j < m._n; j++) {
				oDev << m._a[i][j] << " ";
			}
			oDev << "\n";
		}
		return oDev;
	}
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int a[][MAX] = { {10,11,12,13,14},
						{15,16,17,18,19},
						{20,21,22,23,24},
						{25,26,27,28,29},
						{30,31,32,33,34} };
	int na = sizeof(a) / sizeof(a[0]);
	MATRIX M, N(a, na);
	cout << "Matrix N\n";
	cout << N;
	int r, c;
	cout << "Nhap r : ";
	cin >> r;
	cout << "Nhap c : ";
	cin >> c;
	cout << "N[" << r << "][" << c << "]:" << N.getAt(r, c) << "\n";
	//////////////////////////////////////////////////////////////////////////// 
	cin >> M;
	cout << "Matrix M(original)\n";
	cout << M;
	//////////////////////////////////////////////////////////////////////////// 
	int newN;
	cout << "Nhap kich thuoc moi cho ma tran M : ";
	cin >> newN;
	M.setN(newN);
	cout << "Matrix M(resized)\n";
	cout << M;

	return 0;
}

