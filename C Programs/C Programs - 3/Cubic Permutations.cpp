#include <cstdio>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main()
{
    map <string, int> permutation_frequency;
    map <string, long long> smallest_cube_with_permutation;

    const int MAX_N = 1e4;
    for(long long i = 1; i <= MAX_N; i++)
    {
        long long cube = i*i*i;

        const int NO_OF_DIGITS = 10;
        vector <int> frequency(NO_OF_DIGITS, 0);
        while(cube)
        {
            frequency[cube%10]++;
            cube /= 10;
        }

        string mask;
        for(int digit = 0; digit < NO_OF_DIGITS; digit++)
        {
            while(frequency[digit])
            {
                mask += (char)('0' + digit);
                frequency[digit]--;
            }
        }

        permutation_frequency[mask]++;

        if(permutation_frequency[mask] == 1)
            smallest_cube_with_permutation[mask] = i;

        if(permutation_frequency[mask] == 5)
            printf("%lld\n", smallest_cube_with_permutation[mask]);

    }
    return 0;
}
