#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int N = nums.size();
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    return min((int)nums.size(), N/2);
}