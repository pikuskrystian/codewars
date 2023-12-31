#include <vector>
#include <algorithm>

int sum_intervals(std::vector<std::pair<int, int>> intervals) {
    std::sort(intervals.begin(), intervals.end());

    int sum = 0;
    int start = intervals[0].first;
    int end = intervals[0].second;

    for (auto interval : intervals) {
        if (interval.first <= end) {
            end = std::max(end, interval.second);
        } else {
            sum += end - start;
            start = interval.first;
            end = interval.second;
        }
    }

    sum += end - start;
    return sum;
}
