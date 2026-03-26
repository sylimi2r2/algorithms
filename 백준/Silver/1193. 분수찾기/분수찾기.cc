#include <iostream>
int main(){int X,i=0;std::cin>>X;while((X-=i++)>i);X=i%2?i+1-X:X;std::cout<<X<<'/'<<i+1-X;}
