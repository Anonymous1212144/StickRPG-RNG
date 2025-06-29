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
    x += x * (x * x * C3 + C2) + C1 & MAX;
    x = (x << 13 ^ x) - (x >> 21) & MAX;
    return x;
}

// Return next seed based on current seed (Adobe Flash's system)
int next_seed(int x)
{
    if (x & 1)
        return x >> 1 ^ MASK;
    return x >> 1;
}

int main()
{
    // Prompt for 8 roulette numbers
    int numbers[8];
    int T[8];
    int j = 0;
    T[0] = 0;
    printf("0? ");
    scanf("%d", &numbers[0]);
    for (int i = 1; i < 8; i++)
    {
        printf("%d? ", i);
        scanf("%d", &numbers[i]);
        if (numbers[i] == numbers[j])
            j++;
        else
            j = 0;
        T[i] = j;
    }
    getchar();

    // Knuth–Morris–Pratt algorithm to find the seed
    int seed = next_seed(1);
    j = 0;
    while (seed != 1)
    {
        if (rng(seed) % 38 == numbers[j])
        {
            seed = next_seed(seed);
            j++;
            if (j == 8)
            {
                printf("Seed: %d\n", seed);
                break;
            }
        }
        else
        {
            if (j > 0)
                j = T[j - 1];
            else
                seed = next_seed(seed);
        }
    }
    if (seed == 1)
    {
        printf("Cannot find seed");
        getchar();
        return 1;
    }

    // Print the next 20 roulette numbers
    for (int i = 0; i < 20; i++)
    {
        printf("%d ", rng(seed) % 38);
        seed = next_seed(seed);
    }
    getchar();
    return 0;
}
