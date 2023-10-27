#include <iostream>

int one_count(int num) {
	int count = 0;
	int i = 0;
	while (num >= (1 << i)) {
		if ((num & (1 << i)) != 0)
			count++;
		i++;
	}
		
	return count;
}

int reverse_bits(int num, int index1, int index2) {

	if (index1 == index2)
		return num;

	if (index1 > index2)
		std::swap(index1, index2);
	if ((num & (1 << index2)) == ((num & (1 << index1)) << (index2 - index1)))
		return num;

	if ((num & (1 << index1)) == 0) {
		num = (num & (~(1 << index2)));
		num = (num | (1 << index1));
		return num;
	}
	num = (num & (~(1 << index1)));
	num = (num | (1 << index2));
	return num;
}


int main() {
	setlocale(LC_ALL, "Russian");
	unsigned int n;

	// Задача 1. Вывод числа степение 2

	std::cout << "Задача 1.\nВведите число -> ";
	std::cin >> n;

	std::cout << "2^" << n << " = " << (1 << n) << "\n\n";

	// Задача 2. Количество 1 в двоичном виде введенного числа

	std::cout << "Задача 2.\nВведите число -> ";
	std::cin >> n;

	std::cout << "Количество двоичных 1 в числе: " << one_count(n) << "\n\n";

	// Задача 3. Перестановка бит в заданных позициях числа

	std::cout << "Задача 3.\nВведите число -> ";
	std::cin >> n;
	int ind1, ind2;

	std::cout << "Введите первую и вторую позицию битов в числе -> ";
	std::cin >> ind1 >> ind2;

	std::cout << "Итоговое число: " << reverse_bits(n, ind1, ind2) << "\n\n";




	return 0;
}