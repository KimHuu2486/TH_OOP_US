#include <iostream>
#include <memory>
#include <string>

class Node {
public:
	virtual ~Node() = default;
	virtual int evaluate() const = 0;
	virtual std::unique_ptr<Node> clone() const = 0;
};

class NumNode : public Node {
private:
	int m_num;
public:
	NumNode(const int& num) : Node(), m_num(num) {};

	~NumNode() {
		m_num = 0;
	};

	int evaluate() const override {
		return m_num;
	}

	std::unique_ptr<Node> clone() const override {
		return std::make_unique<NumNode>(*this);
	}
};

class CompNode : public Node {
private:
	std::string m_ope;
	std::unique_ptr<Node> m_left; // Smart pointer tự quản lí bộ nhớ, người dùng không cần phải xóa thủ công
	std::unique_ptr<Node> m_right;
public:
	CompNode(const std::string& ope) : Node(), m_ope(ope), m_left(nullptr), m_right(nullptr) {};

	CompNode(const CompNode& other) : Node(other), m_ope(other.m_ope) {
		if (other.m_left) m_left = other.m_left->clone();
		if (other.m_right) m_right = other.m_right->clone();
	}

	~CompNode() {
		m_ope = "";

		//Không cần xóa pointer m_left, m_right vì là smart pointer sẽ tự xóa vùng nhớ đã tạo
		m_left = nullptr;
		m_right = nullptr;
	};

	int evaluate() const override {
		int left = 0, right = 0;
		if (m_left != nullptr) {
			left = m_left->evaluate();
		}
		if (m_right != nullptr) {
			right = m_right->evaluate();
		}

		if (m_ope == "same") {
			if (left == right) {
				return left;
			}
			return 0;
		}
		else if (m_ope == "min") {
			if (left > right) {
				return right;
			}
			return left;
		}
		else if (m_ope == "max") {
			if (left < right) {
				return right;
			}
			return left;
		}

		// Trường hợp không phải là 1 trong 3 phép toán đề cho
		return INT_MAX;
	}

	std::unique_ptr<Node> clone() const override {
		return std::make_unique<CompNode>(*this);
	}

	void addLeft(const Node& item) {
		m_left = item.clone();
	}

	void addRight(const Node& item) {
		m_right = item.clone();
	}
};

int main() {

	CompNode n("same");
	n.addLeft(NumNode(3));
	n.addRight(NumNode(3));
	int x = n.evaluate();
	std::cout << x << std::endl;

	CompNode n1("min");
	n1.addLeft(NumNode(5));
	n1.addRight(NumNode(4));

	CompNode n2("max");
	n2.addLeft(n);
	n2.addRight(n1);
	x = n2.evaluate();
	std::cout << x << std::endl;

	CompNode n3("max");
	n3.addRight(n2);
	CompNode n5("min");
	n5.addLeft(NumNode(5));
	n5.addRight(NumNode(6));
	CompNode n6("max");
	n6.addLeft(NumNode(1));
	n6.addRight(NumNode(3));
	CompNode n4("max");
	n4.addLeft(n5);
	n4.addRight(n6);
	n3.addLeft(n4);

	std::cout << n3.evaluate() << std::endl;

	return 0;
}