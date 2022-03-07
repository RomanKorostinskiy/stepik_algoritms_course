#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

class Segment {
public:
	int l;
	double r;
	
	void print() {
		std::cout << l << " " << r << std::endl; 
	}

	static int FindPoints(std::vector<int>& point_array, std::vector<Segment> segments_array, int n_of_segments) {
		std::sort(segments_array.begin(), segments_array.end());

		int i = 0;
		int point_num = 0;
		int point;

		while (i < n_of_segments) {
			point = segments_array[i].r;
			point_array.push_back(point);
			point_num++;
			i++;

			while (i < n_of_segments && segments_array[i].l <= point)
				i++;
		}

		return point_num;
	}

	bool operator > (Segment X) {
		return r > X.r;
	}

	bool operator < (Segment X) {
		return r < X.r;
	}
	
	Segment(double left, double right) : l(left), r(right) {}
};

int main() {
	int n_of_segments = 0;
	std::vector<Segment> segments_array;
	Segment elem(0, 0);

	std::cin >> n_of_segments;

	for (int i = 0; i < n_of_segments; i++) {
		std::cin >> elem.l;
		std::cin >> elem.r;
		segments_array.push_back(elem);
	}

	std::vector<int> point_array;
	int point_num = Segment::FindPoints(point_array, segments_array, n_of_segments);

	std::cout << point_num << std::endl;
	for (int i = 0; i < point_num; i++)
		std::cout << point_array[i] << " ";
	std::cout << std::endl;

	return 0;
}