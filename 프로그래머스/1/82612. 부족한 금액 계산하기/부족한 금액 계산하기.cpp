using namespace std;

long long solution(int price, int money, int count)
{
    long long sum = (long long)price * count * (count + 1) / 2;
    return (sum > money ? (sum - money) : 0);
}