#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

#define PRECISION 10e-20

bool IsGreater(double x1, double x2) {
	return x1 - x2 > PRECISION;
}

bool IsLess(double x1, double x2) {
	return x1 - x2 < PRECISION;
}

class Item {
public:
	double price = 0;
	double volume = 0;

	void ScanItem () {
		std::cin >> price >> volume;
	}

	double GetWorth () {
		return price / volume;
	}

	bool operator > (Item X) {
		return IsGreater(this->GetWorth(), X.GetWorth());
	}

	bool operator < (Item X) {
		return IsLess(this->GetWorth(), X.GetWorth());
	}
};

bool Comparator (Item item1, Item item2) {
    return item1.GetWorth() > item2.GetWorth();
}

void PrintMaxPrice (int backpack_volume, std::vector<Item> items_array, double n_of_items) {
	std::sort(items_array.begin(), items_array.end(), Comparator);

	int i = 0;
	double total_price = 0;

	while (i < n_of_items) {
		if (IsGreater(items_array[i].volume, backpack_volume)) {
			total_price += backpack_volume * items_array[i].GetWorth();
			break;
		} else {
			backpack_volume -= items_array[i].volume;
			total_price     += items_array[i].price;
		}
		i++;
	}

	std::cout << std::fixed << std::setprecision(3) << total_price << std::endl;
}

int main() {
	int n_of_items;
	double backpack_volume;
	std::vector<Item> items_array;
	Item item;

	std::cin >> n_of_items >> backpack_volume;

	for (int i = 0; i < n_of_items; i++) {
		item.ScanItem();
		items_array.push_back(item);
	}

	PrintMaxPrice(backpack_volume, items_array, n_of_items);

	return 0;
}