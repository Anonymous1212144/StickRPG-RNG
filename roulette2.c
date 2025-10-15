/*  Brute-force StickRPG roulette predictor
    Copyright (C) 2025 Anonymous1212144

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <stdio.h>

const int C3 = 15731;
const int C2 = 789221;
const int C1 = 1376312589;
const int MAX = 0x7FFFFFFF;
const int MASK = 0x48000000;

// Return number based on seed (simplified Adobe Flash's system)
int rng(int x)
{
    x *= 71;
    x = (x << 13 ^ x) - (x >> 21);
    x += (x * (x * x * C3 + C2) + C1) & MAX;
    x = ((x << 13 ^ x) - (x >> 21)) & MAX;
    return x;
}

// Return next seed based on current seed (Adobe Flash's system)
int next_seed(const int x)
{
    if (x & 1)
        return x >> 1 ^ MASK;
    return x >> 1;
}

int main()
{
    int inputs = 1;
    int lps = 0;
    int numbers[16];
    int T[16];
    T[0] = 0;

    printf("0? ");
    scanf("%d", &numbers[0]);

    // Knuth–Morris–Pratt algorithm to find the seed
    int seed1 = 0;
    int seed = next_seed(1);
    int going = 1;
    int i = 0;
    while (going || i)
    {
        if (going && seed == 1)
            going = 0;

        if (rng(seed) % 38 == numbers[i])
        {
            i++;
            if (i == inputs)
            {
                printf("Seed: %d\n", seed);
                if (seed1)
                {
                    printf("%d? ", inputs);
                    scanf("%d", &numbers[inputs]);
                    if (numbers[inputs] == numbers[lps])
                        lps++;
                    else
                        lps = 0;
                    T[inputs] = lps;
                    inputs++;
                    if (rng(seed1) % 38 == numbers[i])
                    {
                        printf("Seed: %d\n", seed1);
                        seed1 = next_seed(seed1);
                    }
                    else
                        seed1 = 0;
                }
                else
                {
                    seed1 = next_seed(seed);
                    i = T[i - 1];
                }
            }
            seed = next_seed(seed);
        }
        else
        {
            if (i > 0)
                i = T[i - 1];
            else
                seed = next_seed(seed);
        }
    }
    seed = seed1;

    if (!seed)
    {
        printf("Cannot find seed");
        while (getchar())
            ;
        return 1;
    }

    // Print the next 20 roulette numbers
    for (int i = 0; i < 20; i++)
    {
        printf("%d ", rng(seed) % 38);
        seed = next_seed(seed);
    }
    while (getchar())
        ;
    return 0;
}
