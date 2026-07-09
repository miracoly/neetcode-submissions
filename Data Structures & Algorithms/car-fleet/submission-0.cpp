#include <bits/stdc++.h>

struct Car {
    int pos;
    int speed;
    double time;

    auto operator<=>(const Car&) const = default;
};

class Solution {
   public:
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car> cars;
        cars.reserve(position.size());
        for (size_t i{0}; i < position.size(); ++i) {
            const auto time = static_cast<double>(target - position[i]) / speed[i];
            cars.emplace_back(position[i], speed[i], time);
        }
        sort(cars.begin(), cars.end());

        int count{1};
        double time_leader{};
        bool first{true};
        for (const auto& c : cars | std::views::reverse) {
            if (first) {
                first = false;
                time_leader = c.time;
                continue;
            }

            if (c.time > time_leader) {
                count++;
                time_leader = c.time;
            }
        }

        return count;
    }
};
