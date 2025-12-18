/*
	MITTUNIVERSITETET
	Författare: Omar Sultanzoy
	Kurs: Operativsystem - L3 Minnet
	Inlämningsdatum: 2025-12-15
	Kursanvsvarig: Jimmy Åhlander
*/
#include <iostream>
#include <string>

int main() {

	std::cout << "L3 Minnet" << std::endl;
	std::cout << "Välj chunkstorlek" << std::endl;
	std::cout << "1. 1 GiB" << std::endl;
	std::cout << "2. 1 KiB" << std::endl;
	std::cout << "Val: ";
	int val;
	std::cin >> val;
	int64_t chunk_size_byte = 0;
	int64_t total_allocated = 0;
	std::string lolz;
	switch (val)
	{
	case 1:
		std::cout << "Valde 1 GiB" << std::endl;
		chunk_size_byte = 1024 * 1024 * 1024; // 1 gib
		break;

	case 2:
		std::cout << "Valde 1 KiB" << std::endl;
		chunk_size_byte = 1024; // 1 kib
		break;
	default:
		std::cout << "Ogiltigt val" << std::endl;
	}
	const int MiB = 1024 * 1024;
	while (true)
	{
		try {
			new int[chunk_size_byte / sizeof(int)];
		}
		catch (std::bad_alloc error) {
			std::cout << "Error msg from bad_alloc: " << error.what() << std::endl;
			std::cin >> lolz;
			break;
		}
		total_allocated += chunk_size_byte;
		if ((total_allocated % MiB) == 0) {
			std::cout << "Total allocated memory: " << total_allocated / (1024 * 1024) << " MiB" << std::endl;
		}
	}
	return 0;
}
