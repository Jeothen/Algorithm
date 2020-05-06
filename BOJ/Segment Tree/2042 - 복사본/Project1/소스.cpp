

int main() {
	0; // int
	0.0; // double
	nullptr; // std::nullptr_t

	int* p1 = nullptr;
	char* p2 = nullptr;
	void(*f)() = nullptr;

//	int n1 = nullptr;   error
	int n2 = 0;

	// bool type은 직접 초기화는 허용하지만 복사 초기화는 허용되지 않는다
//	bool b1 = nullptr; error
	bool b2(nullptr);
	bool b3{ nullptr };
//	bool b4 = { nullptr; } error
}