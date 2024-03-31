#include <bits/stdc++.h>

struct Job {
    char id;
    int deadline, profit;
};

bool comparison(Job a, Job b) {
    return (a.profit > b.profit);
}

void findMaxProfit(std::vector<Job>& jobs, int n) {
    std::sort(jobs.begin(), jobs.end(), comparison);
    int result[n];
    bool slot[n];
    for (int i = 0; i < n; i++)
        slot[i] = false;
    for (int i = 0; i < n; i++) {
        for (int j = std::min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            if (slot[j] == false) {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
        if (slot[i])
            std::cout << jobs[result[i]].id << ' ';
}

int main() {
    std::vector<Job> jobs = {{'a', 4, 20}, {'b', 1, 10}, {'c', 1, 40}, {'d', 1, 30}};
    int n = jobs.size();
    findMaxProfit(jobs, n);
    return 0;
}


//time complexity O(n.log(n))